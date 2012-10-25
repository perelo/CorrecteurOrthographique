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


# Edition de liens
#
all : Levenshtein.o
# 
#
Levenshtein.o : Levenshtein.cxx $(PROJET_H)
	$(COMPILER)

#
# Nettoyage (repertoire courant : executables et fichiers .o, etc.)
#
clean : 
	rm -vrf *.o *.run *~ ../include/*~
#
