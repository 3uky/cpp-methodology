#pragma once

#include <mutex>
#include <condition_variable>

class MyConditionVariable
{
public:
    void IncrementCounter()
	{
        std::unique_lock<std::mutex> lck(m_mtx);

    	while (!m_ready) 
            m_cv.wait(lck);

    	m_counter++;
    }

    void Go()
	{
        std::unique_lock<std::mutex> lck(m_mtx);
        m_ready = true;
        m_cv.notify_all();
    }

    int GetCounter() const
    {
        return m_counter;
    }

private:
    std::mutex m_mtx;
    std::condition_variable m_cv;

	bool m_ready = false;
    int m_counter = 0;
};
