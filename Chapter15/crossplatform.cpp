// main.cpp - Entry point of the cross-platform project

#include <iostream>

// Define platform-specific code using preprocessor directives
#ifdef _WIN32
    #define PLATFORM_NAME "Windows"
    // Include platform-specific headers and code
    #include <windows.h>
#elif __APPLE__
    #define PLATFORM_NAME "macOS"
    // Include platform-specific headers and code
    #include <CoreFoundation/CoreFoundation.h>
#elif __linux__
    #define PLATFORM_NAME "Linux"
    // Include platform-specific headers and code
    #include <unistd.h>
#endif

int main() {
    std::cout << "Running on " << PLATFORM_NAME << std::endl;

    // Cross-platform code
    // ...

    return 0;
}
