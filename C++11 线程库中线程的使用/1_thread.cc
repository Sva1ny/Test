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
    /* test(); */
    /* int a = 1; */
    thread th(threadFunc, 1);
    /* cout << "child thread = " << th.get_id() << endl; */
    th.join();

    return 0;
}

