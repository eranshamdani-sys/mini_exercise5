#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

std::mutex lock;

void foo(int a) {
    sleep(5);
    lock.lock();        // lock the mutex before critical section
    std::cout << a << std::endl;  // critical section involving printing
    lock.unlock();      // remember to unlock
}
int main() {
    std::thread threads[20];
    for (int i = 0; i < 20; i++){
        threads[i] = std::thread(foo, i);
    }
    for (int i = 0; i < 20; i++){
        threads[i].join();
    }
}