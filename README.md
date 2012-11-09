CorrecteurOrthographique
========================

Licence3 : Devoir2 : Un correcteur orthographique

Le materiel se trouve ici :
http://michel.vancaneghem.perso.luminy.univmed.fr/cours/algo/devoir2/materiel4.zip

L'enonce se trouve ici
http://michel.vancaneghem.perso.luminy.univmed.fr/cours/algo/devoir2/devoir2.pdf

Dans le repertoire materiel4/ :
dico_iso.txt : dictionnaire francais en ISO-8859-15 (a utiliser pour le correcteur)
fichier des fautes a venir

pour compiler, dans dirproj/ :

compiler les dépendances :
	make dep

compilation d'un main et édition de lien :
	make nom=TextXXX
où TestXXX est le nom d'un fichier contenant un main de test dans l'extension
(e.g : make nom=TestCorr pour compiler le fichier TestCorr.cxx)

Les fichiers Test*.cxx contiennent un main pour tester trivialement une partie du code
