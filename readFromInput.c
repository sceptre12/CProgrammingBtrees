#include "header.h"



void readFromInput(int caseSensitive){
        // intiate reading from the terminal input
        // printf("Inside of Read Input function\n");

        //Creates root node
        root.left = NULL;
        root.right = NULL;
        root.list = NULL;
        root.duplicate = 0;

        int end = 0;
        char *inputString = (char *)malloc(sizeof(char));
        char *rootVal = (char *)malloc(sizeof(char));
        printf("Enter Values To Sort\n");
        scanf("%[^\n]", rootVal );
        root.currLine = rootVal;
        // printf("Root Value '%s'\n", root.currLine);

        // Loops through users inputs then creates nodes for the tree
        while(end == 0){
            // Scanf needs spaces infront of it so that it can ignore
            // the \n which was created by the previous scanf
            printf("Enter Values To Sort\n");
            scanf(" %[^\n]", inputString );
            printf("You Typed '%s'\n", inputString);
            char *temp = (char *)malloc(sizeof(char));
            strcpy(temp, inputString);
            // printf("The value of root '%s'\n", root.currLine);
            insertNode(&root, temp, caseSensitive);
            printf("Enter 1 to stop and 0 to continue\n");

            scanf(" %d", &end );
        };
        printf("Thank you\n");
}
