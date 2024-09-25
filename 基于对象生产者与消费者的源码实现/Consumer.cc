#include "Consumer.h"
#include "TaskQueue.h"
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

Consumer::Consumer()
{

}

Consumer::~Consumer()
{

}

void Consumer::consume(TaskQueue &taskQue)
{
    int cnt = 20;
    while(cnt--)
    {
        int number = taskQue.pop();
        cout << "<<BO.Consumer consume number = " << number << endl;
        sleep(1);
    }
}
