CC = gcc
CFLAG=-Wall -g

all: build bin

#	Creates the executable file build
build: main.o stringCompare.o parseCommandLine.o determineRead.o read.o
	$(CC) $(CFLAG) -o build main.o stringComparisons.o parseCommandLineOptions.o determineRead.o readFile.o readFromInput.o

main.o: main.c header.h
	$(CC) $(CFLAG) -c main.c

stringCompare.o: stringComparisons.c header.h
	$(CC) $(CFLAG) -c stringComparisons.c

parseCommandLine.o: parseCommandLineOptions.c header.h
	$(CC) $(CFLAG) -c parseCommandLineOptions.c 

determineRead.o: determineRead.c header.h
	$(CC) $(CFLAG) -c determineRead.c

read.o:  readFromInput.c readFile.c header.h
	$(CC) $(CFLAG) -c readFile.c readFromInput.c

bin: 
	mkdir bin
	mv *.o bin/
clean: 
	rm -rf *.o bin build
