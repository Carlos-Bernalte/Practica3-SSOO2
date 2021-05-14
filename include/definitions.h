#ifndef DEFINITIONS
#define DEFINITIONS

#define LIBROS "./libros"

#define LOG_PATH "./log"
#include "../src/Request.cpp"
#include "../src/QueueProtected.cpp"
#include "../src/Client.cpp"
#include <queue>



int id_flag=-1;
int credits=-1;
bool end_program=false;
/*Variable para controlar a los clientes*/
std::condition_variable cv_queue;
/*Semaforo para controlar la cola de peticiones de pago*/
std::mutex sem_queue;

/*COLA QUE DA PROBLEMAS*/
QueueProtected requests;
std::vector<Client> vClients;

std::vector<std::string> WORDS =
{
    "lineas",
    "la",
    "palabra"
};

#endif