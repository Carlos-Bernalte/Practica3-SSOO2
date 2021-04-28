/*********************************************
*   Project: Práctica 3 de Sistemas Operativos II 
*
*   Program name: Client.c
*
*   Author: Carlos Bernalte García-Junco
*
*   Date created: 24-03-2021
*
*   Porpuse: Clases para almacenar información relacionada con palabras buscadas.
*
*   Revision History: Se puede encontrar en el repositorio de GitHub.
|*********************************************/

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

// QueueProtected::QueueProtected()
// {
// }

// void QueueProtected::add(Client c){
//     access.lock();
//     queue.push(c);
//     access.unlock();
// }

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

