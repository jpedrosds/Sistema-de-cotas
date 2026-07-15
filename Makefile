CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJ = main.o \
      cadastrop.o \
      cadastrov.o \
      calculocotacao.o \
      relatorio.o

programa: $(OBJ)
	$(CC) $(CFLAGS) -o programa $(OBJ)

main.o: main.c cadastrop.h cadastrov.h calculocotacao.h relatorio.h
	$(CC) $(CFLAGS) -c main.c

cadastrop.o: cadastrop.c cadastrop.h
	$(CC) $(CFLAGS) -c cadastrop.c

cadastrov.o: cadastrov.c cadastrov.h
	$(CC) $(CFLAGS) -c cadastrov.c

calculocotacao.o: calculocotacao.c calculocotacao.h
	$(CC) $(CFLAGS) -c calculocotacao.c

relatorio.o: relatorio.c relatorio.h
	$(CC) $(CFLAGS) -c relatorio.c

clean:
	rm -f *.o programa