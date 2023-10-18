# Compilador e opcoes
CC := g++ -std=c++23
CXXFLAGS := -Wall -Wextra -Werror
LDFLAGS  := -lstdc++ -lm
CFLAGS   := -fsanitize=address,undefined -fno-omit-frame-pointer -g
INCLUDE  := -Iinclude

# Diretorios
BUILD   := ./build
SRC_DIR := src
OBJ_DIR := $(BUILD)/objects
APP_DIR := $(BUILD)/

# Lista de pastas de origem (adicionar mais conforme necessario)
SOURCE_FOLDERS := util tree graph tests

# Lista de arquivos de origem em cada pasta
SOURCE_FILES := $(foreach folder,$(SOURCE_FOLDERS),$(wildcard $(SRC_DIR)/$(folder)/*.cpp)) $(SRC_DIR)/main.cpp

# Lista de arquivos de objeto correspondentes
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE_FILES))

# Nome do executavel final
TARGET := $(APP_DIR)/app

# Regra padrao para construir o alvo
all: $(TARGET)

# Regra para construir o alvo
$(TARGET): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) $(CFLAGS) $^ -o $@

# Regra generica para compilar arquivos de origem em objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# Garante que as pastas de destino existam
$(shell mkdir -p $(OBJ_DIR))

# Garante que a pasta bin e os diretorios existam quando executa o make
$(shell mkdir -p $(OBJ_DIR) $(foreach folder,$(SOURCE_FOLDERS),$(OBJ_DIR)/$(folder)))

# Limpar arquivos intermediarios e o alvo
clean:
	rm -rvf $(OBJ_DIR) $(TARGET)

run:
	./$(TARGET)

.PHONY: all clean

r: all run