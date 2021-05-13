
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
            Request r = Request(requests.remove());
            qRequests.pop();
            std::cout<<MAGENTA<<"[PAYSYSTEM] Atendiendo la petición de recarga del Cliente "<<RESET<<r.getID()<<std::endl;
            std::cout<<RED<<"[PAYSYSTEM]"<<RESET<<std::endl;
            r.toString();
            r.petition.set_value(r.getCredit());
        }
    }
}

#endif