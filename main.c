#include "header.h"

int main(int argc, char *argv[]){
    printf("Welcome To assignment 1\n");

    int caseSensitive = 0;
    char *outputFile = NULL;
    char *inputFile = NULL;
    parseCommandLineOptions(argc,argv,&caseSensitive,&outputFile,&inputFile);

    // printf("Case '%d' , outputFile '%s' inputfile '%s'\n",caseSensitive,outputFile,inputFile);

    int readType = determineRead(inputFile);

    // printf("Read Type '%d'\n", readType);

    if(readType){
        readFile(inputFile,caseSensitive);
    }else{
        readFromInput(caseSensitive);
    }

    determineOutput(outputFile);

    printPostOrder(&root);
    printf("End Of Assingment\n");
    return 0;
}
