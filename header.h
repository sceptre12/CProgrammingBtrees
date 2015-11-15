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
        struct List *list;
} root;

struct List {
    struct List *next;
    char *currLine;
};


//##########Function Declarations

//String Functions
int sameString(char stringA[],char stringB[],int caseType);
void toUpperCase(char *word,int count);
void toLowerCase(char *word,int count);
int stringLength(char *word);
int greaterThan(char stringA[],char stringB[],int caseType);

//Command Line Function
void parseCommandLineOptions(int argc, char *argv[],int *caseSensitive,char **outputFile,char **inputFile);

//OpenFile Function
int determineRead(char *fileName);
void readFile(char *fileName, int caseSensitive);
void readFromInput(int caseSensitive);
//WriteFile Function
void determineOutput(char *fileName);
void writeToOutputFile(char *fileName);
void writeToScreen();

//BinarySort
int insertNode(struct Node *root,char *line, int caseSensitive);
void printInOrder(struct Node *root,FILE *fp);
void printPostOrder(struct Node *root);
int printLinkedList(FILE *fp, struct Node *root);
