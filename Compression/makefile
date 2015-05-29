CC = gcc
SRCS = Compression.c Dico.c Entree_Sortie.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall


EXEC = compression

	
all : $(EXEC)
	
compression : Dico.o Compression.c Entree_Sortie.o
	$(CC) $(CFLAGS) Compression.c Dico.o Entree_Sortie.o -o compression

%.o: %.c 
	$(CC) $(CFLAGS) $(LDFLAGS) -c $<


clean :
	 rm -f $(OBJS) *~ $(EXEC)
