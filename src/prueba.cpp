
#include <vector>
#include <thread>
#include "Client.cpp"

int main(){

    std::thread t(Client(2,30));
    t.join();
    return 1;
}