
CC = gcc    # C-Compiler + Flags
CXX = g++   # C++-Compiler + Flags
CFLAGS = -O -Wall -g
CXXFLAGS = -g -std=c++17 -pedantic -Wall -Wextra
LD = g++	# Linker + Flags
LDFLAGS =

OBJECTS = main.o Article.o Storage.o StorageDialogue.o
SRC = $(OBJECTS:%.o=%.cpp)
DEPENDFILE = .depend	# Abhaengigkeitsdefinitionen
LOESCHLISTE = *.o *.exe *stackdump
RULES = make-regeln

### Ziele
all: dep main

# Bereinigung des Verzeichnisses
# @ vor dem Kommando sorgt dafuer, dass das Kommando selbst nicht
#   ausgegeben wird.
clean:
		@echo "Folgende Dateien werden geloescht"
		@echo $(LOESCHLISTE)
		rm -f $(LOESCHLISTE)

### Abhaengigkeiten
main: $(OBJECTS)

### Anlegen der Abhängigkeitsdatei
dep: $(SRC)
	$(CXX) -MM $(SRC) > $(DEPENDFILE)

### Inkludieren der Abhängigkeiten
-include $(DEPENDFILE)

### Inkludieren der Regeln
include $(RULES)


