#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Example
{
public:
    void operator()(int x)
    {
        cout << "void operator()(int)" << endl;
        cout << "x = " << x << endl;
        cout << "child thread id = " << std::this_thread::get_id() << endl;
    }
};

int main(int argc, char *argv[])
{
    cout << "main thread id = " << std::this_thread::get_id() << endl;

    Example ex;
    /* ex(3); */

    thread th(ex, 3);
    th.join();

    return 0;
}

