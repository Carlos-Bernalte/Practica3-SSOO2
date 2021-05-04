#ifndef REQUEST
#define REQUEST

#include <iostream>

class Request{
    private:
        int id;
        int credit;

    public:
        Request(int id, int credit);
        int getID();
        int getCredit();
        void setCredit(int credit);
};

Request::Request(int id, int credit){
    this->id = id;
    this->credit = credit;
}

int Request::getID(){
    return this->id;
}

int Request::getCredit(){
    return this->credit;
}

void Request::setCredit(int credit){
    this->credit=credit;
}

#endif