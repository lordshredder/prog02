
CC = gcc    # C-Compiler + Flags
CXX = g++   # C++-Compiler + Flags
CFLAGS = -O -Wall -g
CXXFLAGS = -g -std=c++17 -pedantic -Wall -Wextra
LD = g++	# Linker + Flags
LDFLAGS =

OBJECTS = main.o InputHandler.o OutputHandler.o Person.o Birthdate.o PersonStorage.o
SRC = $(OBJECTS:%.o=%.cpp)
DEPENDFILE = .depend	# Abhängigkeitsdefinitionen
LOESCHLISTE = *.o *.exe *stackdump
RULES = make-regeln

### Ziele
all: dep ueb01

# Bereinigung des Verzeichnisses
# @ vor dem Kommando sorgt dafür, dass das Kommando selbst nicht
#   ausgegeben wird.
clean:
		@echo "Folgende Dateien werden geloescht"
		@echo $(LOESCHLISTE)
		rm -f $(LOESCHLISTE)

### Abhaengigkeiten
ueb01: $(OBJECTS)

### Anlegen der Abhängigkeitsdatei
dep: $(SRC)
	$(CXX) -MM $(SRC) > $(DEPENDFILE)

### Inkludieren der Abhängigkeiten
-include $(DEPENDFILE)

### Inkludieren der Regeln
include $(RULES)


