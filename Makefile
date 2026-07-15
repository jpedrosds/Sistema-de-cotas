CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJ = main.o \
      cadastrop.o \
      cadastrov.o \
      cotacao.o \
      relatorio.o \
      arquivo.o

programa: $(OBJ)
	$(CC) $(CFLAGS) -o programa $(OBJ)

main.o: main.c cadastrop.h cadastrov.h cotacao.h relatorio.h arquivo.h
	$(CC) $(CFLAGS) -c main.c

cadastrop.o: cadastrop.c cadastrop.h
	$(CC) $(CFLAGS) -c cadastrop.c

cadastrov.o: cadastrov.c cadastrov.h
	$(CC) $(CFLAGS) -c cadastrov.c

calculocotacao.o: cotacao.c cotacao.h
	$(CC) $(CFLAGS) -c calculocotacao.c

relatorio.o: relatorio.c relatorio.h cotacao.h
	$(CC) $(CFLAGS) -c relatorio.c

arquivo.o: arquivo.c arquivo.h cotacao.h
	$(CC) $(CFLAGS) -c arquivo.c

clean:
	rm -f *.o programa