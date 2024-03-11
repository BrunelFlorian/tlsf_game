# On purge la liste des suffixes utilisés pour les rôles implicites
.SUFFIXES:

# On ajoute simplement les extensions dont l'on a besoin
.SUFFIXES:.cpp .o

# Nom de l'exécutable
EXEC=main

# Dossiers
INCLUDE_DIR=/usr/include/SDL2
SRC_DIR=src
OBJ_DIR=build
BIN_DIR=bin

# Liste des fichiers sources séparés par des espaces
SOURCES=$(wildcard $(SRC_DIR)/DataLayer/*.cpp) \
		$(wildcard $(SRC_DIR)/PresentationLayer/*.cpp) \
		$(wildcard $(SRC_DIR)/BusinessLogicLayer/*.cpp)
# Liste des fichiers objets
OBJETS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Compilateur et options de compilation
CXX=g++
LFLAGS= -O0 -Wall -Wextra -g
CXXFLAGS= -std=c++11 -g -O0 -Wall -Wextra -I$(INCLUDE_DIR)

# Bibliothèques
LIBRARIES=-lSDL2 -lSDL2_mixer

# Rôle explicite de construction de l'exécutable
$(BIN_DIR)/$(EXEC): $(OBJETS) $(SRC_DIR)/main.cpp | $(BIN_DIR) Makefile
	$(CXX) -o $@ $(OBJETS) $(SRC_DIR)/main.cpp $(LFLAGS) $(LIBRARIES)

# Rôle implicite pour la construction des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Création du dossier de destination s'il n'existe pas
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Nettoyage des fichiers objets et de l'exécutable
clear: clean
	rm -f $(BIN_DIR)/$(EXEC)

# Génération des dépendances
depend:
	sed -e "/^#DEPENDANCIES/,$$ d" Makefile >dependances
	echo "#DEPENDANCIES" >> dependances
	$(CXX) -MM $(SOURCES) | sed 's|^|$(OBJ_DIR)/|' >> dependances
	cat dependances >Makefile
	rm dependances

# Inclusion des dépendances
-include dependances