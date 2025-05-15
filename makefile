SRC=./src/output/output_o/*.o
EXTRA_FLAGS=-Wall -Wextra -g3 -lm
BIN=./src/output/main
OUTPUT=./src/output
OUTPUT_O=$(OUTPUT)/output_o


all: main.o fila.o pilha.o
	@echo "Gerando arquivos executável";
	gcc $(SRC) -g $(EXTRA_FLAGS) -o $(BIN);

main.o: main.c
	@if [ ! -d $(OUTPUT) ]; then mkdir $(OUTPUT); fi;
	@if [ ! -d $(OUTPUT_O) ]; then mkdir $(OUTPUT_O); fi;
	@echo "Compilando e gerando objetos";
	gcc -c main.c -o $(OUTPUT_O)/main.o;

pilha.o: ./src/pilha.c
	gcc -c ./src/pilha.c -o $(OUTPUT_O)/pilha.o;

fila.o: ./src/fila.c
	gcc -c ./src/fila.c -o $(OUTPUT_O)fila.o;

clean:
	@echo "Apagando objetos e executáveis antigos..."
	@rm -r $(OUTPUT);

run:
	@echo ""; $(BIN); @echo "";
