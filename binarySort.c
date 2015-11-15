#include "header.h"

int insertNode(struct Node *root, char *stringB, int caseSensitive){
        // printf("Entering Insert Node Function\n");
        // printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        // printf("Current string being inserted CaseType: %d\nString A: '%s'\nString B: '%s'\n\n", caseSensitive, root->currLine,stringB);
        // printf("Duplicate number '%d'\n", root->duplicate);
        //check if same
        int checkIfSame = sameString(root->currLine,stringB,caseSensitive);
        //check if greaterThan
        int greaterThanResult = greaterThan(root->currLine,stringB,caseSensitive);

        // printf("\t same: '%d' , greaterThan: '%d'\n", checkIfSame, greaterThanResult);

        if(checkIfSame ==1) {
                root->duplicate++;
                // printf("Duplicate number '%d'\n", root->duplicate);
                // printf("Leaving Insert Node Function\n");

                if(caseSensitive ==0) {
                        // printf("creating linked list\n");
                        // creates a temporary list
                        struct List *tempList;
                        tempList = (struct List*)malloc(sizeof(struct List));
                        tempList->currLine = stringB;
                        tempList->next = NULL;
                        if(root->list == NULL) {
                                root->list = tempList;
                        }else{
                                root->list->next = tempList;
                        }
                        return 0;
                }
                return 0; // success
        }

        if(greaterThanResult == 1) {
                // printf("String A is Greater than String B\n");
                // Means That String B is less than the value inside of root->currLine
                if(root->left != NULL) {
                        // printf("\n\tLEFT CONTAINS '%s'\n", root->left->currLine);
                        insertNode(root->left, stringB, caseSensitive);
                        // printf("\tLEFT IS NOT NULL\n");
                }else{
                        // printf("\tLEFT IS NULL\n");
                        struct Node *tempNode;
                        tempNode = (struct Node*)malloc(sizeof(struct Node));
                        tempNode->currLine = stringB;
                        tempNode->right = NULL;
                        tempNode->left = NULL;
                        tempNode->list = NULL;
                        tempNode->duplicate = 0;
                        root->left = tempNode;
                        // printf("\tAdding to LEFTNODE: '%s'\n", root->left->currLine);
                        // printf("Leaving Insert Node Function\n");
                        return 0;
                }
        }else if (greaterThanResult == 0) {
                // printf("String B is Greater than String A\n");
                if(root->right != NULL) {
                        // printf("\n\tRIGHT CONTAINS '%s'\n", root->right->currLine);
                        insertNode(root->right, stringB, caseSensitive);
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
                        tempNode->list = NULL;
                        tempNode->duplicate = 0;
                        root->right = tempNode;
                        // printf("\tAdding to RIGHTNODE: '%s'\n", root->right->currLine);
                        // printf("Leaving Insert Node Function\n");
                        return 0;
                }
        }
        // printf("Leaving Insert Node Function\n");
        return 0;
}

void printInOrder(struct Node *root,FILE *fp){
        // printf("\nEntering printOrder Function\n");
        // This is only initialized once
        static int index = 0;
        if(root != NULL) {
                // printf("Printing Out left\n");
                printInOrder(root->left,fp);

                // char *someString = root->currLine;
                // stores the values inside of this global array
                if(fp != NULL) {
                        fprintf(fp, "%s\n", root->currLine);
                        printLinkedList(fp, root);
                }else{
                        printf("Index '%d' value'%s'\n", index, root->currLine);
                        printLinkedList(fp, root);
                }

                index++;
                // printf("Printing out right\n");
                printInOrder(root->right,fp);
        }
        // printf("\nLeaving printOrder function\n");
}
int printLinkedList(FILE *fp, struct Node *root){
        // printf("Inside of printLinkedList\n");
        if(root->list == NULL) {
                return 0;
        }
        int true = 1;
        struct List *tempList;
        // printf("Linked List Items\n");
        tempList = root->list;
        while(true) {
                if(fp != NULL) {
                    char message[] = "Linked List Item: ";
                    strcat(message, tempList->currLine);
                    fprintf(fp, "%s\n", message);
                }else{
                        printf("\t\tLinkList Item: '%s'\n",tempList->currLine);
                }


                if(tempList->next == NULL) {
                        true = 0;
                }else{
                        tempList = tempList->next;
                }
        }
        // printf("Leaving printLinkedList\n");
        return 0;
}
void printPostOrder(struct Node *root){
        // printf("\nEntering printOrder Function\n");
        // This is only initialized once
        static int index = 0;
        if(root != NULL) {
                // printf("Printing Out left\n");
                printPostOrder(root->left);


                // printf("Printing out right\n");
                printPostOrder(root->right);
                free(root->currLine);
                index++;
        }
        // printf("\nLeaving printOrder function\n");
}
