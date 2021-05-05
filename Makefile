DIROBJ := bin/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
DIRLOG := log/

CFLAGS := -c -Wall -ansi
LDLIBS := -I$(DIRHEA) -pthread -std=c++17
CC := g++

all : dirs main ssooiigle


dirs:
	mkdir -p $(DIROBJ) $(DIREXE) $(DIRLOG)

main:$(DIROBJ)main.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ssooiigle: $(DIROBJ)ssooiigle.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)


wordsearched: $(DIROBJ)WordSearched.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

queueprotected: $(DIROBJ)QueueProtected.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

client: $(DIROBJ)Client.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

$(DIROBJ)%.o: $(DIRSRC)%.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

test:
	./$(DIREXE)ssooiigle

test2:
	./$(DIREXE)main

clean :
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRLOG)
