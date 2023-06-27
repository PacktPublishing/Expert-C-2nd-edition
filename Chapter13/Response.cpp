#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Response {
private:
    int statusCode;
    std::vector<std::pair<std::string, std::string>> headers;
    std::string body;

public:
    // Constructor
    Response(int statusCode, const std::vector<std::pair<std::string, std::string>>& headers, const std::string& body)
        : statusCode(statusCode), headers(headers), body(body) {}

    // Getter methods
    int getStatusCode() const {
        return statusCode;
    }

    std::vector<std::pair<std::string, std::string>> getHeaders() const {
        return headers;
    }

    std::string getBody() const {
        return body;
    }

    // Serialize the response to a string for transmission
    std::string serialize() const {
        std::ostringstream oss;
        oss << "HTTP/1.1 " << statusCode << "\n";
        
        for (const auto& header : headers) {
            oss << header.first << ": " << header.second << "\n";
        }

        oss << "\n" << body;

        return oss.str();
    }

    // Deserialize the received string into a Response object
    static Response deserialize(const std::string& serializedResponse) {
        std::vector<std::string> lines;
        std::string line;
        std::istringstream iss(serializedResponse);

        while (std::getline(iss, line)) {
            lines.push_back(line);
        }

        std::size_t statusCodePos = lines[0].find(' ');
        int statusCode = std::stoi(lines[0].substr(statusCodePos + 1));

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

        return Response(statusCode, headers, body);
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    int statusCode = 200;
    std::vector<std::pair<std::string, std::string>> headers = { {"Content-Type", "application/json"}, {"Content-Length", "123"} };
    std::string body = "{\"message\": \"Response body example\"}";

    // Create a response object
    std::ostringstream oss;
    oss << "HTTP/1.1 " << statusCode << "\n";
    for (const auto& header : headers) {
        oss << header.first << ": " << header.second << "\n";
    }
    oss << "\n" << body;

    std::string serializedResponse = oss.str();

    // Print the serialized response
    std::cout << "Serialized Response: " << serializedResponse << std::endl;

    // Deserialize the received string into a Response object
    std::istringstream iss(serializedResponse);
    std::string line;

    std::getline(iss, line); // Read the first line (status code)
    std::size_t statusCodePos = line.find(' ');
    int statusCodeDeserialized = std::stoi(line.substr(statusCodePos + 1));

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

    // Print the deserialized response details
    std::cout << "Deserialized Response: " << std::endl;
    std::cout << "Status Code: " << statusCodeDeserialized << std::endl;
    std::cout << "Headers: " << std::endl;
    for (const auto& header : headersDeserialized) {
        std::cout << header.first << ": " << header.second << std::endl;
    }
    std::cout << "Body: " << bodyDeserialized << std::endl;

    return 0;
}
