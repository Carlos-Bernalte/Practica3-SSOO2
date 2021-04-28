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

#include <iostream>
#include <condition_variable>
#include "Client.cpp"
#include "QueueProtected.cpp"
class PaySystem
{
private:
    std::condition_variable cv_queue;
    QueueProtected q_clients;

public:
    PaySystem();
    void rechargeBalance();
};

PaySystem::PaySystem()
{
}
void PaySystem::rechargeBalance()
{
    while (1)
    {

    }
}