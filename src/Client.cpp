
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
#ifndef CLIENT
#define CLIENT

#include <iostream>
#include <mutex>
#include <colours.h>
#include "WordSearched.cpp"

class Client{
    private:
        int id;
        int balance;
        std::string objective;
        bool premium;
        std::mutex access;
    
    public:
        Client(int id, std::string objective, int balance, bool premium);
        void toString();
        int getId();
        float getBalance();
        std::string getObjective();
        bool isPremium();
        void payCredit();
        void restoreCredits();     
};

Client::Client(int id, std::string objective, int balance, bool premium){
    this->id=id;
    // if(premium){
    //     if(rand()%2==0){
    //         this->balance=-1;
    //     }else{
    //         this->balance=balance;
    //     }
    // }else{
    //     this->balance=50;
    // }
    this->balance=balance;
    this->objective = objective;
    this->premium = premium;
    toString();
}

int Client::getId(){
    return this->id;
}
float Client::getBalance(){
    access.lock();
    return this->balance;
    access.unlock();
}
bool Client::isPremium(){
    return this->premium;
}
void Client::payCredit(){
    access.lock();
    this->balance--;
    access.unlock();
}
void Client::restoreCredits(){
    access.lock();
    this->balance=100;
    access.unlock();
}

std::string Client::getObjective(){
    return this->objective;
}

void Client::toString(){
    if(this->premium){
        if(this->balance==-1){
            std::cout<<"[Cliente "<<id<<"] Saldo: UNLIMITED"<<std::endl;
        }else{
            std::cout<<"[Cliente "<<id<<"] Palabra: "<<this->objective<<std::endl;
        } 
    }else{
        std::cout<<"[Cliente "<<id<<"]"<<std::endl;
    }
}

#endif
