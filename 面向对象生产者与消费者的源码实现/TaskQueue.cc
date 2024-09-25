#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queSize)
: _queSize(queSize)
, _que()
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{

}

TaskQueue::~TaskQueue()
{

}

//添加任务
void TaskQueue::push(const int &value)
{
    //1、上锁
    MutexLockGuard autoLock(_mutex);

    //2、是不是满
    while(full())
    {
        //2.1、如果队列是满的，生产者需要睡眠
        _notFull.wait();
    }
    //2.2、如果队列不为满才能进行push操作
    _que.push(value);
    //并且将消费者唤醒
    _notEmpty.notify();
}

//获取任务
int TaskQueue::pop()
{
    MutexLockGuard autoLock(_mutex);

    while(empty())
    {
        _notEmpty.wait();
    }

    int tmp = _que.front();
    _que.pop();
    _notFull.notify();

    return tmp;
}

//任务队列是空与满
bool TaskQueue::full() const
{
    return _queSize == _que.size();
}

bool TaskQueue::empty() const
{
    return 0 == _que.size();
}
