#ifndef REQUEST
#define REQUEST

#include <iostream>
#include <future>
#include <functional>
#include "colours.h"
class Request{
    private:
        int id;
        int credit;
        

    public:
        std::promise<int> petition;
        std::future<int> recharge;
        Request(int id, int credit);
        ~Request();
        Request(const Request &);
        int getID();
        int getCredit();
        void toString();
};

Request::Request(const Request &){

}

Request::~Request(){
    std::cout<<"Peticion: "<<this->id<<"destruida"<<std::endl;
}
Request::Request(int id, int credit){
    this->id = id;
    this->credit=credit;
    this->recharge=petition.get_future();
}
int Request::getID(){
    return this->id;
}
int Request::getCredit(){
    return this->credit;
}
void Request::toString(){
    std::cout<<"[Request "<<this->id<<"] Credit: "<<this->credit<<std::endl;
}

#endif