#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <iomanip>
#include <exception>
#include <chrono>
#include <condition_variable>

using namespace std;

int main()
{
    condition_variable condition;
    mutex mtx;
    bool ready = false;

    thread t1([&]()
              { 
        cout << "thread started" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        unique_lock<mutex> lock(mtx);
        ready = true; 
        lock.unlock(); 
        condition.notify_one(); });

    unique_lock<mutex> lock(mtx);
    cout << "Before wait" << endl;

    condition.wait(lock, [&]()
                   { return ready; });

    cout << "ready" << endl;
    t1.join();
    return 0;
}