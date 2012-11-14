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
CC = g++
CFLAGS = -I$(INCLUDE) -Wall -Werror -O3
COMPILER = $(CC) -c $(CFLAGS) $*.cxx
#
PROJET_O = Levenshtein.o Jaccard.o MathUtil.o IHash.o IComp.o \
           CHashMap.o CHashStr.o CLink.o                      \
           Correcteur.o

#
# Edition de liens
#
$(nom) : $(nom).o $(PROJET_O)
	$(CC) -o $(nom).run $(nom).o $(PROJET_O)
#
dep : $(PROJET_O)
#
#

#
# Compilation
#
$(nom).o : $(nom).cxx $(SDD_H) $(UTIL_H) $(CORR_H)
	$(COMPILER)
#
Levenshtein.o : Levenshtein.cxx $(UTIL_H)
	$(COMPILER)
#
Jaccard.o : Jaccard.cxx $(UTIL_H)
	$(COMPILER)
#
MathUtil.o : MathUtil.cxx $(UTIL_H)
	$(COMPILER)
#
IHash.o : IHash.cxx $(UTIL_H)
	$(COMPILER)
#
IComp.o : IComp.cxx $(UTIL_H)
	$(COMPILER)
#
CHashMap.o : CHashMap.cxx $(UTIL_H) $(SDD_H)
	$(COMPILER)
#
CHashStr.o : CHashStr.cxx $(UTIL_H) $(SDD_H)
	$(COMPILER)
#
CLink.o : CLink.cxx $(UTIL_H) $(SDD_H)
	$(COMPILER)
#
Correcteur.o : Correcteur.cxx $(SDD_H) $(UTIL_H) $(CORR_H)
	$(COMPILER)
#

#
# Nettoyage (repertoire courant : executables et fichiers .o, etc.)
#
clean : 
	rm -vrf *.o *.run *~ ../include/*~
#
