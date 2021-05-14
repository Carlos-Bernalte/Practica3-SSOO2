
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
#include <string>
#include "WordSearched.cpp"

class Client{
    private:
        int id;
        int init_balance;
        int balance;
        std::string objective;
        bool premium;
        std::string PATH_LOG;
        
    
    public:
        Client(int id, std::string objective, int balance, int premium);
        void toString();
        int getId();
        int getBalance();
        int getInitialBalance();
        std::string getObjective();
        bool isPremium();
        void payCredit();
        void restoreCredits(int credits);    
        void writeLOG(); 
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
    this->PATH_LOG = "./log/Client_"+std::to_string(id)+".txt";
    writeLOG();
    toString();
}

int Client::getId(){
    return this->id;
}
int Client::getBalance(){
    return this->balance;
}

int Client::getInitialBalance(){
    return this->init_balance;
}
bool Client::isPremium(){
    return this->premium;
}
void Client::payCredit(){
    this->balance--;
}
void Client::restoreCredits(int credits){
    this->balance=credits;
}

std::string Client::getObjective(){
    return this->objective;
}

void Client::writeLOG(){
    std::fstream file;
    
    file.open(this->PATH_LOG,std::ios::out);
    if(!file){
        std::cout<<"File not created!"<<std::endl;
    }else{
        //std::cout<<"Escribiendo"<<std::endl;
        if(this->premium){
            if(this->balance==-1){
            
                file<<"[Cliente "+std::to_string(this->id)+"] -- Cuenta: Premium -- Palabra: "+this->objective+" -- Saldo: UNLIMITED";
            }else{
                file<<"[Cliente "+std::to_string(this->id)+"] -- Cuenta: Premium -- Palabra: "+this->objective+" -- Saldo: "+std::to_string(this->balance);
            } 
        }else{
        
        file<<"[Cliente "+std::to_string(this->id)+"] -- Cuenta: Gratis -- Palabra: "+this->objective+" -- Saldo: "+std::to_string(this->balance);
        }
    }
    //file.write("[Cliente "+std::to_string(this->id)+"] -- Cuenta: Premium -- Palabra: "+std::to_string(this->objective)+" -- Saldo: UNLIMITED");
    //file<<"[Cliente "<<this->id<<"]"<<"-- Cuenta: Premium -- Palabra: "<<this->objective<<" -- Saldo: UNLIMITED"<<std::endl;
    file.close();
}

void Client::toString(){
    if(this->premium){
        if(this->balance==-1){
            std::cout<<YELLOW<<"[Cliente "<<RED<<this->id<<YELLOW<<"]"<<MAGENTA<<":: Cuenta:"<<YELLOW<<" Premium"<<MAGENTA<<" :: Palabra: "<<CIAN<<this->objective<<MAGENTA<<" :: Saldo: "<<RED<<"UNLIMITED"<<RESET<<std::endl;
        }else{
            std::cout<<YELLOW<<"[Cliente "<<RED<<this->id<<YELLOW<<"]"<<MAGENTA<<":: Cuenta:"<<YELLOW<<" Premium"<<MAGENTA<<" :: Palabra: "<<CIAN<<this->objective<<MAGENTA<<" :: Saldo: "<<RED<<this->balance<<RESET<<std::endl;
        } 
    }else{
        std::cout<<YELLOW<<"[Cliente "<<RED<<this->id<<YELLOW<<"]"<<MAGENTA<<":: Cuenta:"<<GREEN<<" Gratis"<<MAGENTA<<" :: Palabra: "<<CIAN<<this->objective<<MAGENTA<<" :: Saldo: "<<RED<<this->balance<<RESET<<std::endl;
    }
}

#endif
