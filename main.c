#include "header.h"

/*
  Xavier Thomas
  Section U01
  I affirm that this program is entirely my own work and none of it is the work of any other person.
*/
//Global Declerations
int shouldBeCaseSensitive = 0;
char *outputFile = NULL;
char *inputFile = NULL;
char *sortedList[];

// manually allocated memory
char *lineBuffer;
char **lineStorage;
int lineStorageSize;

int main(int argc, char *argv[]){

        int sortedLength,index;
        // Parses the command Line to determine the function calls
        // This will set global variables that will affect the determine
        // read function
        parseCommandLineOptions(argc,argv);

        // Determines the read type, then goes into parsing the file,
        // then goes into sorting the file, which returns its result
        // as the size of the sortedList and also populates the sortedList
        sortedLength = determineRead(inputFile);

        //Determines the output type and then writes to the appropriate
        // source
        determineOutput(outputFile, sortedLength);


        printf("\n");
        return 0;
}
