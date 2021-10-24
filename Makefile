EXECUTAVEL = sociedadeAnel
INCLUDE = ./include
MAIN = ./main/main.c
BIN = ./bin
OBJ = ./obj
SRC = ./src

FLAGS = -O3 -Wall -std=gnu99

all: library app

library: \
	$(OBJ)/vetores.o

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) $(FLAGS) -o $@

app:
	gcc $(MAIN) $(OBJ)/*.o $(FLAGS) -I $(INCLUDE) -o $(BIN)/$(EXECUTAVEL)

run:
	$(BIN)/$(EXECUTAVEL)

cleanObj:
	rm $(OBJ)/*.o

cleanBin:
	rm $(BIN)/*

purge:
	rm $(OBJ)/*.o
	rm $(BIN)/*