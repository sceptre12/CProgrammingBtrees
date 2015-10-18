CFLAG=-Wall -g

clean:
	rm -rf compareStrings

all: run

run: compareStrings
