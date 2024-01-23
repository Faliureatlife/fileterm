.SILENT:
SHELL := /bin/bash
CFLAGS := $(shell pkg-config --cflags gtk4)
CLIBS := $(shell pkg-config --libs gtk4)

term: termui.o
	gcc $(CFLAGS) -o term termui.o $(CLIBS)

termui.o:termui.c
	gcc $(CFLAGS) -c termui.c $(CLIBS)  

clean:
	rm term.o 
