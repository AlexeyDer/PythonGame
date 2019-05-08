CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)
LIBS = -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

.PHONY: all clean

EXECUTABLE = bin/main.exe 

all: $(EXECUTABLE)
	$(EXECUTABLE)

$(EXECUTABLE):  build/main.o build/binding.o build/tick.o build/lev.o build/lev2.o
	g++ $^ -o $@ $(CFLAGS) $(LIBS) 

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

clean:
	rm build/*.o
	rm bin/*.exe
