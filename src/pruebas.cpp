#include <iostream>
#include <thread>
#include "PaySystem.cpp"
#include "Client.cpp"

PaySystem ps;

int main(){
    std::thread(ps);

    

}