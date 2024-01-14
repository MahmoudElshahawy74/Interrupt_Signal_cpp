#include <iostream>
#include <csignal>
#include <cstdlib>
#include <thread>
#include <chrono>

// Signal handler function
void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received. Cleaning up and exiting.\n";
    
    // Your custom cleanup logic here, if needed

    // Terminate the program
    std::exit(signum);
}

int main() {
    // Register the signal handler
    std::signal(SIGINT, signalHandler);

    std::cout << "Press Ctrl+C to trigger the interrupt signal...\n";

    // Simulate some work in the main program
    for (int i = 0; i < 10; ++i) {
        std::cout << "Working... " << i + 1 << "/10\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Program completed successfully.\n";

    return 0;
}
