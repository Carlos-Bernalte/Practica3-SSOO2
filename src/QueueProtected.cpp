#include <queue>
#include <mutex>
//#include "Client.cpp"

class QueueProtected
{
private:
    std::mutex access;
    std::queue<int> queue;
public:
    QueueProtected();
    void add(Client c);
    Client remove();
    bool isEmpty();
};

// QueueProtected::QueueProtected()
// {
// }

// void QueueProtected::add(Client c){
//     access.lock();
//     queue.push(c);
//     access.unlock();
// }

// Client QueueProtected::remove(){
//     access.lock();
//     Client c = queue.front();
//     queue.pop();
//     access.unlock();
//     return c;
// }

// bool QueueProtected::isEmpty(){
//     return queue.empty();
// }

