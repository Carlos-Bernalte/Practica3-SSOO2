#ifndef DEFINITIONS
#define DEFINITIONS

#define LIBROS "./libros"

#define LOG_PATH "./log"
#include "../src/QueueProtected.cpp"
#include "../src/Client.cpp"

int id_flag=-1;
std::condition_variable cv_queue;
std::mutex sem_queue;
QueueProtected requests;
std::vector<Client> vClients;

std::vector<std::string> WORDS =
{
    "lineas",
    "la",
    "palabra"
};

#endif