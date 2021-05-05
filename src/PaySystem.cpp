
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
    int id;
    while(1){
        if(!requests.checkEmpty()){
            id = requests.remove().getID();
            for(std::size_t i=0; i< vClients.size(); i++){
                if(id==vClients[i].getId()){
                    std::cout<<"[PaySystem] Cliente: "<<id<<" atendido"<<std::endl;
                    id_flag=vClients[i].getId();
                    cv_queue.notify_all();
                    break;
                }
            }
            
        }
    }
}

#endif