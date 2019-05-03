CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)
LIBS = -L/SFML/lib/release/
LDLIBS = -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

.PHONY: clean

all: bin build bin/main.exe 

bin/main.exe:  build/main.o build/binding.o build/tick.o build/lev.o build/lev2.o
	g++ $^ -o $@ $(CFLAGS) $(LIBS) $(LDLIBS)

build/binding.o: src/binding.cpp src/binding.h
	$(OBJ)

build/tick.o: src/tick.cpp 
	$(OBJ)

build/lev.o: src/lev.cpp 
	$(OBJ)

build/lev2.o: src/lev2.cpp 
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