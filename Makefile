CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJ = main.o cadastrov.o cadastrop.o calculocotacao.o

programa: $(OBJ)
	$(CC) $(CFLAGS) -o programa $(OBJ)

main.o: main.c cadastrov.h cadastrop.h calculocotacao.h
	$(CC) $(CFLAGS) -c main.c

cadastrov.o: cadastrov.c cadastrov.h
	$(CC) $(CFLAGS) -c cadastrov.c

cadastrop.o: cadastrop.c cadastrop.h
	$(CC) $(CFLAGS) -c cadastrop.c

calculocotacao.o: calculocotacao.c calculocotacao.h cadastrov.h cadastrop.h
	$(CC) $(CFLAGS) -c calculocotacao.c

clean:
	rm -f *.o programa