
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
#ifndef PAYS
#define PAYS

#include <iostream>
#include <condition_variable>
#include <queue>
#include <utility>
#include <definitions.h>
#include "Request.cpp"
#include "QueueProtected.cpp"


class PaySystem
{
private:

public:
    void operator () ();
};
void PaySystem::operator () (){
    while(1){
        if(!requests.checkEmpty()){
            std::this_thread::sleep_for (std::chrono::seconds(1));
            Request r = std::move(requests.remove());
            std::cout<<YELLOW<<"[PAYSYSTEM]"<<MAGENTA<<" Atendiendo la petición de recarga del Cliente "<<RED<<r.getID()<<RESET<<std::endl;
            id_flag=r.getID();
            credits=r.getCredit();
            cv_queue.notify_all();
        }else if(end_program){
            break;
        }
    }
    std::cout<<YELLOW<<"[PAYSYSTEM]"<<MAGENTA<<" Shutdown..."<<RESET<<std::endl;
}
    


#endif