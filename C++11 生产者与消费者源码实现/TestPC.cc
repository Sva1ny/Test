#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void test()
{
    TaskQueue taskQue(10);

    Producer producer;
    Consumer consumer;

    thread  pro(&Producer::produce, &producer, std::ref(taskQue));
    thread  con(&Consumer::consume, &consumer, std::ref(taskQue));

    pro.join();
    con.join();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

