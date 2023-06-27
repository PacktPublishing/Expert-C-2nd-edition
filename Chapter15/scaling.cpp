#include <iostream>
#include <thread>
#include <vector>

// Function to perform a computationally intensive task
void performTask(int start, int end, int threadId) {
    for (int i = start; i <= end; ++i) {
        // Simulating a computationally intensive task
        int result = i * i;
        std::cout << "Thread " << threadId << ": Computed result for " << i << " is " << result << std::endl;
    }
}

int main() {
    // Horizontal Scaling: Creating multiple threads to handle the workload
    int numThreads = std::thread::hardware_concurrency(); // Number of available hardware threads
    std::vector<std::thread> threads;

    int start = 1;
    int end = 100;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(performTask, start, end, i);
        start = end + 1;
        end += 100;
    }

    // Wait for all threads to complete
    for (auto& thread : threads) {
        thread.join();
    }

    // Vertical Scaling: Utilizing multi-threading to improve performance on a single machine
    int startVertical = 1;
    int endVertical = 1000;

    std::vector<std::thread> verticalThreads;

    for (int i = 0; i < numThreads; ++i) {
        verticalThreads.emplace_back(performTask, startVertical, endVertical, i);
        startVertical = endVertical + 1;
        endVertical += 1000;
    }

    // Wait for all vertical threads to complete
    for (auto& thread : verticalThreads) {
        thread.join();
    }

    return 0;
}
