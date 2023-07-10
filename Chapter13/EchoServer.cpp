#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const int BUFFER_SIZE = 1024;
const int PORT = 8080;

int main() {
    int serverSocket, clientSocket;
    sockaddr_in serverAddress, clientAddress;
    char buffer[BUFFER_SIZE];

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    // Set up server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Failed to bind socket." << std::endl;
        return 1;
    }

    // Listen for incoming connections
    listen(serverSocket, 5);
    std::cout << "Server listening on port " << PORT << std::endl;

    // Accept incoming connection
    socklen_t clientAddressLength = sizeof(clientAddress);
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);
    if (clientSocket < 0) {
        std::cerr << "Failed to accept connection." << std::endl;
        return 1;
    }

    std::cout << "Client connected: " << inet_ntoa(clientAddress.sin_addr) << std::endl;

    // Receive and send data back to the client
    ssize_t bytesRead;
    while ((bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(clientSocket, buffer, bytesRead, 0);
        std::cout << "Received and sent " << bytesRead << " bytes." << std::endl;
    }

    if (bytesRead == 0) {
        std::cout << "Client disconnected." << std::endl;
    } else if (bytesRead == -1) {
        std::cerr << "Error in receiving data." << std::endl;
        return 1;
    }

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
