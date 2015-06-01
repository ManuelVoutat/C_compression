
clear
gcc -c main.c Entree_Sortie.c Compression.c Dico.c
gcc main.o Compression.o Entree_Sortie.o Dico.o -o testCompression
./testCompression $1 $2