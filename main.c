#include "header.h"

//Global Declerations
int shouldBeCaseSensitive = 0;
char *outputFile = NULL;
char *inputFile = NULL;
char *sortedList[];


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

        for(index = 0; index < sortedLength; index++ ) {
            printf("Index: %d '%s'\n",index,sortedList[index] );
        }

        printf("\n");
        return 0;
}
