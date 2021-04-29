<<<<<<< HEAD
#ifndef REQUEST
#define REQUEST

=======
#pragma once
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
>>>>>>> 5c7aeae686b4ceb48ba3bf30f2ca4e0a49671d70
#include <iostream>

class Request{
    private:
        int id;
        float credit;

    public:
        Request(int id, float credit);
        int getID();
        float getCredit();
        void setCredit(float credit);
};

Request::Request(int id, float credit){
    this->id = id;
    this->credit = credit;
}

int Request::getID(){
    return this->id;
}

float Request::getCredit(){
    return this->credit;
}

void Request::setCredit(float credit){
    this->credit=credit;
}

#endif