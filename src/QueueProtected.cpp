#include <queue>
#include <mutex>
#include "Client.cpp"

class QueueProtected
{
private:
    std::mutex access;
    std::queue<Client> queue;
public:
    QueueProtected();
    void add(Client c);
    Client remove();
};

QueueProtected::QueueProtected()
{
}

void QueueProtected::add(Client c){
    access.lock();
    queue.push(c);
    access.unlock();
}

Client QueueProtected::remove(){
    access.lock();
    Client c = queue.front();
    queue.pop();
    access.unlock();
    return c;
}

