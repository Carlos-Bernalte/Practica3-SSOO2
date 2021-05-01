#ifndef QUEU
#define QUEU

#include <queue>
#include <mutex>
#include "Request.cpp"
class QueueProtected
{
private:
    
    std::mutex access;
    std::queue<Request> queue;
public:
    QueueProtected();
    void operator = (const QueueProtected &);
    void add(Request r);
    Request remove();
    bool checkEmpty();
};

QueueProtected::QueueProtected()
{
}
void QueueProtected::operator = (const QueueProtected &){
        
}
bool QueueProtected::checkEmpty(){
    return this->queue.empty();
}

void QueueProtected::add(Request r){
    access.lock();
    queue.push(r);
    access.unlock();
}

Request QueueProtected::remove(){
    access.lock();
    Request r = queue.front();
    queue.pop();
    access.unlock();
    return r;
}
 #endif
