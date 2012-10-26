#/**
#*
#* @File : makefile
#*
#*
#* @Synopsis : Makefile pour le devoir 2 d'algorithmique avancee
#*
#**/
include ../include/INCLUDE_H
#
COMPILER = g++ -c -I$(INCLUDE) -Wall -O3 -Werror $*.cxx
#
PROJET_O = Levenshtein.o CHashMap.o CLink.o

# Edition de liens
#
$(nom) : $(nom).o $(PROJET_O)
	g++ -o $(nom).run $(nom).o $(PROJET_O)
#
all : $(PROJET_O)
#
#
$(nom).o : $(nom).cxx $(PROJET_H)
	$(COMPILER) 
#
Levenshtein.o : Levenshtein.cxx $(PROJET_H)
	$(COMPILER)
#
CLink.o : CLink.cxx $(PROJET_H)
	$(COMPILER)
#
CHashMap.o : CHashMap.cxx $(PROJET_H)
	$(COMPILER)
#

#
# Nettoyage (repertoire courant : executables et fichiers .o, etc.)
#
clean : 
	rm -vrf *.o *.run *~ ../include/*~
#
