/*********************************************
*   Project: Práctica 2 de Sistemas Operativos II 
*
*   Program name: WordSearched.c
*
*   Author: Carlos Bernalte García-Junco
*
*   Date created: 19-03-2021
*
*   Porpuse: Clases para almacenar información relacionada con palabras buscadas.
*
*   Revision History: Se puede encontrar en el repositorio de GitHub.
|*********************************************/
#ifndef WORD
#define WORD
#include <iostream>
#include "Client.cpp"
#include <colours.h>


class WordSearched
{
private:
    std::string objetivo;
    int nThread;
    int begin;
    int end;
    int line;
    std::string word_before;
    std::string word;
    std::string word_after;

public:
    WordSearched(std::string objetivo, int nThread, int begin, int end, int line, std::string word_before, std::string word, std::string word_after);
    void toString(int client);
    void write_log(int id);
};



WordSearched::WordSearched(std::string objetivo,int nThread, int begin, int end, int line, std::string word_before, std::string word, std::string word_after)
{
    this->objetivo=objetivo;
    this->nThread=nThread;
    this->begin=begin;
    this->end=end;
    this->line=line;
    this->word_before=word_before;
    this->word=word;
    this->word_after=word_after;
}

void WordSearched::toString(int client){
    std::cout<< YELLOW<<"[Client "<<RED<<client<<YELLOW<<"]"<<MAGENTA<<"::"<<RESULT("[Hilo ")<< RED <<std::to_string(this->nThread) << RESULT(" inicio: ")<< RED<< std::to_string(this->begin)<<  RESULT(" – final: ")<< RED << std::to_string(this->end)<<  RESULT("] :: línea ")<< RED <<std::to_string(this->line)<<RESULT(" :: ")<< CIAN <<"... "+this->word_before<<" "<< ULINE <<this->word<< RESET<< CIAN<<" "<<this->word_after<<" ..."<<std::endl;
}

void WordSearched::write_log(int id){
    std::string PATH_LOG = "./log/Client_"+std::to_string(id)+".txt";
    std::ofstream fd;
    std::string aux = "[PALABRA: "+this->word+"] "+":: [Hilo "+std::to_string(this->nThread)+" inicio "+std::to_string(this->begin)+" – final: "+std::to_string(this->end)+"] :: línea "+std::to_string(this->line)+" :: ..."+this->word_before+" "+this->word+" "+this->word_after+" ... \n";
    fd.open(PATH_LOG.c_str(),std::fstream::app);
    fd << aux;
    fd.close();
}

#endif