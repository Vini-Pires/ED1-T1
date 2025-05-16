# Nome do executável
EXEC = so_track_boa.exe

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g3

# Arquivos fonte e objetos
SRC = main.c menu.c pilha.c fila_playlist.c fila_prio.c
OBJ = $(SRC:.c=.o)

# Regra principal
all: $(EXEC)

# Linkagem dos objetos para gerar o executável
$(EXEC): $(OBJ)
	@echo "🔧 Gerando o executável $(EXEC)..."
	$(CC) $(OBJ) -o $(EXEC)

# Compilar arquivos .c em .o
%.o: %.c
	@echo "📦 Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Executar o programa
run: $(EXEC)
	@echo "🚀 Executando o programa..."
	./$(EXEC)

# Limpar arquivos objeto e executável
clean:
	@echo "🧹 Limpando arquivos..."
	del /f /q *.o $(EXEC) 2>nul || echo "Nada para apagar"

# Ajuda
help:
	@echo ""
	@echo "Comandos disponíveis:"
	@echo "  mingw32-make        -> Compila o projeto"
	@echo "  mingw32-make run    -> Executa o programa"
	@echo "  mingw32-make clean  -> Remove .o e o .exe"
	@echo ""
