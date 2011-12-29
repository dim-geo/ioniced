CC = gcc
CFLAGS = -O2 -Wall -g
OBJ = utils.o pid-handler.o config-handler.o main.o
DEPS = utils.h pid-handler.h config-handler.h
INSTALL = install



all: ioniced

ioniced: $(OBJ) 
	$(CC) -o ioniced $^ $ $(CFLAGS)


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

install: ioniced
	strip ./ioniced
	$(INSTALL) -m 755 -s ./ioniced /usr/bin/ioniced
clean:
	-rm -f ./$(OBJ) ./ioniced

