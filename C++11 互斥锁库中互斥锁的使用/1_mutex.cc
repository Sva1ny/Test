#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;

mutex mtx;
int gCnt = 0;

void threadFunc()
{
    for(int idx = 0; idx < 10000000; ++idx)
    {
        mtx.lock();
        ++gCnt;
        mtx.unlock();
    }
}

int main(int argc, char *argv[])
{
    thread th1(threadFunc);
    thread th2(threadFunc);

    th1.join();
    th2.join();

    cout << "gCnt = " << gCnt << endl;
    return 0;
}

