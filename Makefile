CC = gcc
CFLAG=-Wall -g

all: build bin

build: main.o parseCommandLine.o determineRead.o stringComparisons.o binarySort.o determineOutput.o
	$(CC) $(CFLAG) -o build main.o parseCommandLineOptions.o determineRead.o readFile.o readFromInput.o stringComparisons.o binarySort.o determineOutput.o writeToOutputFile.o writeToScreen.o

main.o: main.c header.h
	$(CC) $(CFLAG) -c main.c

parseCommandLine.o: parseCommandLineOptions.c header.h
	$(CC) $(CFLAG) -c parseCommandLineOptions.c

determineRead.o: determineRead.c readFile.c readFromInput.c header.h
	$(CC) $(CFLAG) -c determineRead.c readFile.c readFromInput.c

stringComparisons.o: stringComparisons.c header.h
	$(CC) $(CFLAG) -c stringComparisons.c 

binarySort.o: binarySort.c header.h
	$(CC) $(CFLAG) -c binarySort.c

determineOutput.o: determineOutput.c writeToOutputFile.c writeToScreen.c header.h
	$(CC) $(CFLAG) -c determineOutput.c writeToOutputFile.c writeToScreen.c
bin: 
	mkdir bin
	mv *.o bin/

clean:
	rm -rf *.o bin build
