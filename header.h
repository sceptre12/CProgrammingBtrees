#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>


//##########Function Declarations

//String Functions
int sameString(char stringA[],char stringB[],int caseType);
void toUpperCase(char *word,int count);
void toLowerCase(char *word,int count);
int stringLength(char *word);
int greaterThan(char stringA[],char stringB[],int caseType);

//Command Line Function
int parseCommandLineOptions(int argc, char *argv[]);

//OpenFile Function
void determineRead(char *fileName);
void readFile(char *fileName);
void readFromInput();
