CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)

.PHONY: clean

all: bin build bin/main.exe 

bin/main.exe:  build/main.o build/binding.o 
	g++ $^ -o $@ $(CFLAGS) 

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
    
