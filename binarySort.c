#include "header.h"

//Determines the case
extern int shouldBeCaseSensitive;

// Stores sorted list of input
extern char *sortedList[];

// TODO: Place the creation of a struct in a function

int binarySort(char **array, int length){
        printf("\tEntering Binary Sort\n");


        struct Node root;
        root.currLine = array[0];
        root.left = NULL;
        root.right = NULL;
        root.duplicate = 0;

        // Outputs String Array
        int a;
        for (a  = 0; a < length; a++) {
                printf("%s\n",array[a]);
        }
        // struct Node *start = &root;
        //Creating binary Tree
        for(a = 1; a < length; a++) {
                insertNode(&root,array[a]);
        }
        // Prints out the sorted values from the tree
        printInOrder(&root);

        for(a = 0; a < length; a++) {
                printf("Index: %d '%s'\n", a,sortedList[a]);
        }
        printf("\tLeaving Binary Sort\n");
        return length;
}

int insertNode(struct Node *root, char *stringB){
        printf("Entering Insert Node Function\n");
        // printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        // printf("Current string being inserted CaseType: %d\nString A: '%s'\nString B: '%s'\n\n", shouldBeCaseSensitive, root->currLine,stringB);
        // printf("Duplicate number '%d'\n", root->duplicate);
        //check if same
        int checkIfSame = sameString(root->currLine,stringB,shouldBeCaseSensitive);
        //check if greaterThan
        // int greaterThanResult = greaterThan(stringB,root->currLine,shouldBeCaseSensitive);

        int greaterThanResult = greaterThan(root->currLine,stringB,shouldBeCaseSensitive);

        // printf("\t same: '%d' , greaterThan: '%d'\n", checkIfSame, greaterThanResult);

        if(checkIfSame ==1) {

                root->duplicate++;
                // printf("Duplicate number '%d'\n", root->duplicate);
                printf("Leaving Insert Node Function\n");
                return 0; // success
        }

        if(greaterThanResult == 1) {
                // printf("String A is Greater than String B\n");
                // Means That String B is less than the value inside of root->currLine
                if(root->left != NULL) {
                        // printf("\n\tLEFT CONTAINS '%s'\n", root->left->currLine);
                        insertNode(root->left, stringB);
                        // printf("\tLEFT IS NOT NULL\n");
                }else{
                        // printf("\tLEFT IS NULL\n");
                        struct Node *tempNode;
                        tempNode = (struct Node*)malloc(sizeof(struct Node));
                        tempNode->currLine = stringB;
                        tempNode->right = NULL;
                        tempNode->left = NULL;
                        tempNode->duplicate = 0;
                        root->left = tempNode;
                        // printf("\tAdding to LEFTNODE: '%s'\n", root->left->currLine);
                        printf("Leaving Insert Node Function\n");
                        return 0;
                }
        }else if (greaterThanResult == 0) {
                // printf("String B is Greater than String A\n");
                if(root->right != NULL) {
                        // printf("\n\tRIGHT CONTAINS '%s'\n", root->right->currLine);
                        insertNode(root->right, stringB);
                        // printf("\tRIGHT IS NOT NULL\n");
                }else{
                        // printf("\tRIGHT IS NULL\n");
                        /*
                           For my own understanding:
                           SO i was trying to create a variable tempNode and then
                           assign it some values and then store the &tempNode (memory Location)
                           in the root->right (pointer) location. The problem with this
                           was that i never allocated memory for this ever changing Struct
                           So you need to create a new struct Node pointer
                           and then allocate memory for it and then pass in the values
                           to that allocated memory location
                         */
                        struct Node *tempNode;
                        tempNode = (struct Node*)malloc(sizeof(struct Node));
                        tempNode->currLine = stringB;
                        tempNode->right = NULL;
                        tempNode->left = NULL;
                        tempNode->duplicate = 0;
                        root->right = tempNode;
                        // printf("\tAdding to RIGHTNODE: '%s'\n", root->right->currLine);
                        printf("Leaving Insert Node Function\n");
                        return 0;
                }
        }
        printf("Leaving Insert Node Function\n");
        return 0;
}

void printInOrder(struct Node *root){
        // printf("\nEntering printOrder Function\n");
        // This is only initialized once
        static int index = 0;
        if(root != NULL) {

                // printf("Printing Out left\n");
                printInOrder(root->left);

                char *someString = root->currLine;
                // stores the values inside of this global array
                sortedList[index] = someString;
                index++;
                // printf("Printing out right\n");
                printInOrder(root->right);
        }
        // printf("\nLeaving printOrder function\n");
}
