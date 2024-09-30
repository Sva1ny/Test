#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::unique_lock;
using std::thread;

mutex mtx;
int gCnt = 0;

void threadFunc()
{
    for(int idx = 0; idx < 10000000; ++idx)
    {
        unique_lock<mutex> ul(mtx);
        ++gCnt;
        //...
        //...
        /* ul.unlock(); */
        //xxxxx
        /* ul.lock(); */
        //yyyyy
        /* ul.unlock(); */
        //zzzz
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

