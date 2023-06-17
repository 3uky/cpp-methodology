#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

namespace parallel_programming
{

class MyCriticalSection
{
public:
    // critical section (exclusive access to std::cout signaled by locking mtx):
	void PrintBlock(int n, char c)
	{
        mtx.lock();
        for (int i = 0; i < n; ++i) {
	        cout << c;
        }
        mtx.unlock();
    }

    // critical section (exclusive access to std::cout signaled by locking mtx):
    void PrintBlockWithGuard(int n, char c) {
        lock_guard<std::mutex> lck(mtx);

    	for (int i = 0; i < n; ++i) {
	        cout << c;
        }
    }

    void PauseThread(int n) {
        std::this_thread::sleep_for(std::chrono::seconds(n));
        std::cout << "pause of " << n << " seconds ended" << endl;
    }

    std::mutex mtx;
};

}