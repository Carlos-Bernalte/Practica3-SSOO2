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
    void add(Request&& r);
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

void QueueProtected::add(Request&& r){
    std::unique_lock<std::mutex> ul(access);
    std::cout<<RED<<"[PUSH] Antes "<<queue.size()<<RESET<<std::endl;
    r.toString();
    this->queue.push(r);
    std::cout<<RED<<"[PUSH] Despues "<<queue.size()<<RESET<<std::endl;
    Request ra = Request (std::move(queue.back()));
    ra.toString();
}


Request QueueProtected::remove(){
    std::unique_lock<std::mutex> ul(access);
    std::cout<<RED<<"[POP]"<<RESET<<std::endl;
    this->queue.front().toString();
    Request r = std::move(queue.front());
    queue.pop();
    return r;
}
#endif
