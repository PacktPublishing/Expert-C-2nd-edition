#include <iostream>
#include <curl/curl.h>

// Callback function to receive data from cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* data) {
    size_t totalSize = size * nmemb;
    data->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main() {
    // Initialize cURL
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string url = "https://letsusedata.com/data/cpp_sample.txt";
        std::string responseData;

        // Set the URL to retrieve data from
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Provide the callback function to receive the data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL failed: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            // Data retrieval successful
            std::cout << "Data retrieved successfully:" << std::endl;
            std::cout << responseData << std::endl;
        }

        // Clean up cURL
        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "cURL initialization failed." << std::endl;
    }

    return 0;
}
