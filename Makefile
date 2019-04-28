.PHONY: clean

CFLAGS = -Wall -Werror -Ibin/include/ -std=c++11
EFLAG = -Lbin/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -lm
OBJ = g++ -c $< -o $@ $(CFLAGS)

all: bin build bin/main.exe 

bin/main.exe:  build/main.o build/binding.o 
	g++ $^ -o $@ $(CFLAGS)  $(EFLAG)

build/binding.o: src/binding.cpp src/binding.h
	$(OBJ)

build/main.o: src/main.cpp 
	$(OBJ)

bin: 
	mkdir bin
build:
	mkdir build

clean:
	rm build/*.o
	rm bin/*.exe
    
