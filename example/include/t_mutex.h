#pragma once

// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <chrono>         // std::chrono::seconds

namespace m_mutex {
    static std::mutex mtx;           // mutex for critical section
}

class T_mutex
{
public:
    static void print_block (int n, char c) {
        // critical section (exclusive access to std::cout signaled by locking mtx):
        m_mutex::mtx.lock();
        for (int i=0; i<n; ++i) { std::cout << c; }
        std::cout << '\n';
        m_mutex::mtx.unlock();
    }

    static int test_mutex() {
        std::thread th1 (print_block,5000,'*');
        std::thread th2 (print_block,5000,'$');

        th1.join();
        th2.join();

        return 0;
    }


    static void print_block_with_guard (int n, char c) {
        // critical section (exclusive access to std::cout signaled by locking mtx):
        std::lock_guard<std::mutex> lck (m_mutex::mtx);
        for (int i=0; i<n; ++i) { std::cout << c; }
        std::cout << '\n';
    }

    static int test_guard() {
        std::thread th1 (print_block_with_guard,5000,'*');
        std::thread th2 (print_block_with_guard,5000,'$');

        th1.join();
        th2.join();

        return 0;
    }

    static void pause_thread(int n) {
      std::this_thread::sleep_for (std::chrono::seconds(n));
      std::cout << "pause of " << n << " seconds ended\n";
    }


    static int test_join() {
      std::cout << "Spawning 3 threads...\n";
      std::thread t1 (pause_thread,1);
      std::thread t2 (pause_thread,2);
      std::thread t3 (pause_thread,3);
      std::cout << "Done spawning threads. Now waiting for them to join:\n";
      t1.join();
      t2.join();
      t3.join();
      std::cout << "All threads joined!\n";

    return 0;
    }

    static void test() {
        test_guard();
    }
};
