
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
#include <atomic>
#include <colours.h>
#include "WordSearched.cpp"

class Client{
    private:
        int id;
        int init_balance;
        int balance;
        std::string objective;
        bool premium;
        
    
    public:
        Client(int id, std::string objective, int balance, int premium);
        void toString();
        int getId();
        float getBalance();
        std::string getObjective();
        bool isPremium();
        void payCredit();
        void restoreCredits();     
};

Client::Client(int id, std::string objective, int balance, int premium){
    this->id=id;
    if(premium){
        if(rand()%2==0){
            this->balance=-1;
        }else{
            this->balance=balance;
        }
    }else{
        this->balance=2;
    }
    this->init_balance=this->balance;
    this->objective = objective;
    this->premium = premium;

    toString();
}

int Client::getId(){
    return this->id;
}
float Client::getBalance(){
    return this->balance;
}
bool Client::isPremium(){
    return this->premium;
}
void Client::payCredit(){
    this->balance--;
}
void Client::restoreCredits(){
    this->balance=this->init_balance;
}

std::string Client::getObjective(){
    return this->objective;
}

void Client::toString(){
    if(this->premium){
        if(this->balance==-1){
            std::cout<<BLUE<<"[Cliente "<<id<<"]"<<"-- Cuenta: Premium -- Palabra: "<<this->objective<<" -- Saldo: UNLIMITED"<<std::endl;
        }else{
            std::cout<<BLUE<<"[Cliente "<<id<<"] -- Cuenta: Premium -- Palabra: "<<this->objective<<" -- Saldo: "<<this->balance<<std::endl;
        } 
    }else{
        std::cout<<BLUE<<"[Cliente "<<id<<"] Cuenta: Gratis -- Palabra: "<<this->objective<<" -- Saldo: "<<this->balance<<std::endl;
    }
}

#endif
