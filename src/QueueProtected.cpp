#ifndef QUEU
#define QUEU

#include <queue>
#include <mutex>
#include <future>
#include "Request.cpp"

class QueueProtected
{
private:
    std::mutex access;
    
public:
    std::queue<Request> queueRequest;
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
    return this->queueRequest.empty();
    
}

void QueueProtected::add(Request r){
    std::unique_lock<std::mutex> ul(access);
    this->queueRequest.push(std::move(r)); 
}

Request QueueProtected::remove(){
    std::unique_lock<std::mutex> ul(access);
    Request r = std::move(this->queueRequest.front());
    this->queueRequest.pop();
    return r;
}
#endif
