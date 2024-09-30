#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void threadFunc(int x)
{
    cout << "void threadFunc(int)" << endl;
    cout << "x = " << x << endl;
    cout << "child thread id = " << std::this_thread::get_id() << endl;
}

int main(int argc, char *argv[])
{
    cout << "main thread id = " << std::this_thread::get_id() << endl;
    typedef void (&pFunc)(int) ;//函数引用
    pFunc f = threadFunc;

    thread th(f, 22);
    th.join();

    return 0;
}

