
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
#include <colours.h>

class Client
{
    private:
        int id;
        float balance;
        std::string objective;
        bool premium;
    
    public:
        Client(int id, std::string objective);
        Client(int id, float balance, std::string objective);
        void toString();
        int getId();
        float getBalance();
        bool isPremium();
        void payCredit();
        void restoreCredits();
        void operator () ();
};
void Client::operator () (){
        
    }

Client::Client(int id, std::string objective)
{   
    this->id=id;
    this->objective = objective;
    this->premium = false;
    toString();
}
Client::Client(int id, float balance, std::string objective)
{   
    this->id=id;
    this->balance = balance;
    this->objective = objective;
    this->premium = true;
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
    this->balance=100;
}

void Client::toString(){
    if(this->premium){
        if(this->balance==-1){
            std::cout<<"[Cliente "<<id<<"] Saldo: UNLIMITED"<<std::endl;
        }else{
            std::cout<<"[Cliente "<<id<<"] Saldo: "<<balance<<std::endl;
        } 
    }else{
        std::cout<<"[Cliente "<<id<<"]"<<std::endl;
    }
}

#endif
