#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> g{0};         

void add(int n) {
    g += n;
}

int main() {
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    std::cout << "Display (before any join): " << g << std::endl;
    t1.join();
    std::cout << "Display (after T1.join):   " << g << std::endl;
    t2.join();
    std::cout << "Display (after T2.join):   " << g << std::endl;
    t3.join();
    std::cout << "Display (after T3.join):   " << g << std::endl;
    return 0;
}