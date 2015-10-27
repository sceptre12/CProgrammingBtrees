#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

// Struct Declartions
struct Node {
        char *currLine;
        int duplicate;
        struct Node *left;
        struct Node *right;
};


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
int determineRead(char *fileName);
int readFile(char *fileName);
int readFromInput();

//WriteFile Function
void determineOutput(char *fileName, int sortedListSize);
void writeToOutputFile(char *fileName, int sortedListSize);
void writeToScreen(int sortedListSize);

//BinarySort
int binarySort(char **array, int length);
int insertNode(struct Node *root,char *line);
void printInOrder(struct Node *root);
