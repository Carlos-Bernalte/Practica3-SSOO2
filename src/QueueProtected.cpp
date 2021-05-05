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
    void add(Request r);
    Request remove();
    bool checkEmpty();
};

QueueProtected::QueueProtected()
{
}
bool QueueProtected::checkEmpty(){
    std::unique_lock<std::mutex> ul(access);
    return this->queue.empty();
    
}

void QueueProtected::add(Request r){
    std::unique_lock<std::mutex> ul(access);
    queue.push(r);
}


Request QueueProtected::remove(){
    std::unique_lock<std::mutex> ul(access);
    Request r = queue.front();
    queue.pop();
    return r;
}
#endif
