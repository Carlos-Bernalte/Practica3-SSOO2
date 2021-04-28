#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <condition_variable>
#include "Client.cpp"
#include "PaySystem.cpp"
#include <vector>



int main(){
    srand(time(NULL));
    /*variable = limite_inferior+ rand()%(limite_superior + 1 - limite_inferior)*/
    PaySystem payment;
        for(int i = 0; i<10;i++){
            int num=1+rand()%(16-1);
            payment.insertClient(Client(i,true,num,"HOLA"));
            std::cout<<"[Cliente: "<<i<<"] insertado"<<std::endl;
        }
        //std::vector<int> a;
        //a.
        //std::for_each(payment.q_clients.front(), payment.q_clients.back());
        while(!payment.q_clients.empty()){
            Client aux=payment.getClient();
            std::cout<<"[Cliente: "<<aux.getID()<<"] tiene un saldo de "<<aux.getCredit()<<std::endl;
        }
        
        
        
        return 0;
}