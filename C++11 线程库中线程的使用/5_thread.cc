#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

int main(int argc, char *argv[])
{
    cout << "main thread id = " << std::this_thread::get_id() << endl;

    thread th([](int x){
              cout << "x = " << x << endl;
              cout << "child thread id = " << std::this_thread::get_id() << endl;
              }, 4);
    th.join();

    return 0;
}

