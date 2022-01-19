#ifndef T_CONDITION_VARIABLE_H
#define T_CONDITION_VARIABLE_H

#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

namespace cv {
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false;
}

class T_condition_variable
{
public:
    static void print_id (int id) {
        std::unique_lock<std::mutex> lck(cv::mtx);
        while (!cv::ready) cv::cv.wait(lck);
        // ...
        std::cout << "thread " << id << '\n';
    }

    static void go() {
        std::unique_lock<std::mutex> lck(cv::mtx);
        cv::ready = true;
        cv::cv.notify_all();
    }

    static int test ()
    {
        std::thread threads[10];
        // spawn 10 threads:
        for (int i=0; i<10; ++i)
        threads[i] = std::thread(print_id,i);

        std::cout << "10 threads ready to race...\n";
        go();                       // go!

        for (auto& th : threads) th.join();

        return 0;
    }
};

#endif // T_CONDITION_VARIABLE_H
