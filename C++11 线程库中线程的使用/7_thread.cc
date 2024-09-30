#include <iostream>
#include <thread>
#include <functional>

using std::cout;
using std::endl;
using std::thread;
using std::bind;
using std::function;

void threadFunc(int x)
{
    cout << "void threadFunc(int)" << endl;
    cout << "x = " << x << endl;
    cout << "child thread id = " << std::this_thread::get_id() << endl;
}

int main(int argc, char *argv[])
{
    cout << "main thread id = " << std::this_thread::get_id() << endl;

    using namespace std::placeholders;

    thread th(bind(threadFunc, 7));
    th.join();

    return 0;
}

