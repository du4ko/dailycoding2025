#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <atomic> // For thread-safe stop flag

std::atomic<bool> keepRunning(true); // Flag to control the loop

void MoveMouseSmooth(int targetX, int targetY, int steps = 50, int delayMs = 5) {
    POINT currentPos;
    GetCursorPos(&currentPos);

    int startX = currentPos.x;
    int startY = currentPos.y;

    for (int i = 1; i <= steps && keepRunning.load(); i++) {
        int newX = startX + (targetX - startX) * i / steps;
        int newY = startY + (targetY - startY) * i / steps;

        SetCursorPos(newX, newY);
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

void RandomMouseMover() {
    std::srand(std::time(nullptr));

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    while (keepRunning.load()) {
        int delayMs = 1000 + (std::rand() % 2000);
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));

        int randomX = std::rand() % screenWidth;
        int randomY = std::rand() % screenHeight;

        std::cout << "Moving to (" << randomX << ", " << randomY << ")" << std::endl;

        MoveMouseSmooth(randomX, randomY);
    }
}

// Keyboard listener function
void ListenForExit() {
    while (keepRunning.load()) {
        if (GetAsyncKeyState(VK_ESCAPE)) { // Detect ESC key
            std::cout << "\n[Stopping program...]\n";
            keepRunning.store(false);
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Avoid CPU overuse
    }
}

int main() {
    std::cout << "Mouse mover started! Press ESC to stop." << std::endl;

    // Start threads
    std::thread moverThread(RandomMouseMover);
    std::thread keyListenerThread(ListenForExit);

    // Wait for threads to finish
    moverThread.join();
    keyListenerThread.join();

    std::cout << "Program exited gracefully." << std::endl;
    return 0;
}
