.SILENT:
SHELL := /bin/bash
CFLAGS := $(shell pkg-config --cflags gtk4)
CLIBS := $(shell pkg-config --libs gtk4)

term: term.o
	gcc $(CFLAGS) -o term term.o $(CLIBS)

term.o:term.c
	gcc $(CFLAGS) -c term.c $(CLIBS)  

clean:
	rm *.o term
