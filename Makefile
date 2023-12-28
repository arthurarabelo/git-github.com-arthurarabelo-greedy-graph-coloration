CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/graph.o $(OBJ)/sort.o $(OBJ)/linkedList.o 
HDRS = $(INC)/graph.hpp $(INC)/sort.hpp $(INC)/linkedList.hpp
CFLAGS = -g -Wall -c -I $(INC)

EXE = $(BIN)/tp2.out

all: $(EXE)

$(BIN)/tp2.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp2.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

$(OBJ)/linkedList.o: $(HDRS) $(SRC)/linkedList.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/linkedList.o $(SRC)/linkedList.cpp

$(OBJ)/sort.o: $(HDRS) $(SRC)/sort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sort.o $(SRC)/sort.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out