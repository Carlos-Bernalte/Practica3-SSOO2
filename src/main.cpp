#include <iostream>
#include <cctype>
#include <fstream>
#include <regex>
#include <filesystem>
#include <vector>
#include <thread>
#include <mutex>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <definitions.h>
#include <colours.h>
#include <atomic>
#include <cstdlib>
#include <dirent.h>
#include "WordSearched.cpp"
#include "Client.cpp"
#include "PaySystem.cpp"
#include "QueueProtected.cpp"
#include "SemCounter2.cpp"

/*Funciones definidas*/
int number_of_lines(std::string file);
void create_threads(std::string file, Client& c);
void find_word(int thread,std::vector<std::string> assignedLines, int begin, int end, Client c);
std::map<int, std::vector<std::string>> shareLines(std::string file, int nLines);
std::vector<std::string> splitLine(std::string line);
std::string analizeWord(std::string word);
void printResult();
void list_dir();

void generateClient(int id);
/*Valores estáticos*/
#define NCLIENTS 4
#define NTHREADS 4
#define BUFFER 4

/*Variables globales*/

std::vector<Client> vClients;
std::vector<std::string> vLibros;

/* El main se encargara de la creación de hilos y su finalización*/
int main(int argc, char *argv[]){
    std::string word;
    word=WORDS[(rand()%WORDS.size())];
    Client c(1,"Hola Mundo",20,true);
    vClients.push_back(c);
}