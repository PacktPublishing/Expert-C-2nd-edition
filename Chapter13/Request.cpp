#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Request {
private:
    std::string action;
    std::vector<std::pair<std::string, std::string>> headers;
    std::string body;

public:
    // Constructor
    Request(const std::string& action, const std::vector<std::pair<std::string, std::string>>& headers, const std::string& body)
        : action(action), headers(headers), body(body) {}

    // Getter methods
    std::string getAction() const {
        return action;
    }

    std::vector<std::pair<std::string, std::string>> getHeaders() const {
        return headers;
    }

    std::string getBody() const {
        return body;
    }

    // Serialize the request to a string for transmission
    std::string serialize() const {
        std::string serializedRequest = action + "\n";
        
        for (const auto& header : headers) {
            serializedRequest += header.first + ": " + header.second + "\n";
        }

        serializedRequest += "\n" + body;

        return serializedRequest;
    }

    // Deserialize the received string into a Request object
    static Request deserialize(const std::string& serializedRequest) {
        std::vector<std::string> lines;
        std::string line;
        std::istringstream iss(serializedRequest);

        while (std::getline(iss, line)) {
            lines.push_back(line);
        }

        std::string action = lines[0];

        std::vector<std::pair<std::string, std::string>> headers;
        for (std::size_t i = 1; i < lines.size(); ++i) {
            std::size_t colonPos = lines[i].find(':');
            std::string headerName = lines[i].substr(0, colonPos);
            std::string headerValue = lines[i].substr(colonPos + 2);  // Skip the colon and space after it
            headers.emplace_back(headerName, headerValue);
        }

        std::string body;
        bool bodyStarted = false;
        for (std::size_t i = 1; i < lines.size(); ++i) {
            if (bodyStarted) {
                body += lines[i] + "\n";
            }
            else if (lines[i].empty()) {
                bodyStarted = true;
            }
        }

        return Request(action, headers, body);
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string action = "GET";
    std::vector<std::pair<std::string, std::string>> headers = { {"Content-Type", "application/json"}, {"Authorization", "Bearer token123"} };
    std::string body = "{\"filename\": \"example.txt\"}";

    // Create a request object
    std::ostringstream oss;
    oss << action << "\n";
    for (const auto& header : headers) {
        oss << header.first << ": " << header.second << "\n";
    }
    oss << "\n" << body;

    std::string serializedRequest = oss.str();

    // Print the serialized request
    std::cout << "Serialized Request: " << serializedRequest << std::endl;

    // Deserialize the received string into a Request object
    std::istringstream iss(serializedRequest);
    std::string line;

    std::getline(iss, line); // Read the first line (action)
    std::string actionDeserialized = line;

    std::vector<std::pair<std::string, std::string>> headersDeserialized;
    while (std::getline(iss, line) && !line.empty()) {
        std::size_t colonPos = line.find(':');
        std::string headerName = line.substr(0, colonPos);
        std::string headerValue = line.substr(colonPos + 2);  // Skip the colon and space after it
        headersDeserialized.emplace_back(headerName, headerValue);
    }

    std::string bodyDeserialized;
    while (std::getline(iss, line)) {
        bodyDeserialized += line + "\n";
    }

    // Print the deserialized request details
    std::cout << "Deserialized Request: " << std::endl;
    std::cout << "Action: " << actionDeserialized << std::endl;
    std::cout << "Headers: " << std::endl;
    for (const auto& header : headersDeserialized) {
        std::cout << header.first << ": " << header.second << std::endl;
    }
    std::cout << "Body: " << bodyDeserialized << std::endl;

    return 0;
}