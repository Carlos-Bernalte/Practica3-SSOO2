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

void write_log(Client c){
    std::string PATH_LOG = "./log/Client_"+std::to_string(c.getId())+".txt";
    std::ofstream fd;
    std::string aux = "*****[CLIENTE "+std::to_string(c.getId())+"]::"+"[TIEMPO: "+std::to_string(c.time)+"segundos]*****\n";
    fd.open(PATH_LOG.c_str(),std::fstream::app);
    fd << aux;
    fd.close();

}

std::vector<std::string> WORDS =
{
    "lineas",
    "la",
    "palabra",
    "ley"
};

#endif