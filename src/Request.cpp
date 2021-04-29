#ifndef REQUEST
#define REQUEST

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