#include "header.h"

/*
   Reads in the text from the passed in file
   and then outputs those values into a the
   binarytree creation function
 */



void readFile(char *fileName,int caseType){
        // filePath Location
        char path[254];
        if(getcwd(path, sizeof(path)) == NULL) {
                fprintf(stderr, "Error with getting path\n");
                exit(1);
        }

        FILE *fp = NULL;
        strcat(path,"/");
        strcat(path,fileName);

        fp = fopen(path,"r");

        if(!fp) {
                fprintf(stderr, "File Not Found '-%s'\n", path);
                exit(1);
        }
        root.left = NULL;
        root.right = NULL;
        root.duplicate = 0;

        char lineBuffer[254];

        char ch = NULL;
        int count = 0;
        int initalizeRoot = 0;

        /*
           Streams through the file char by char
           Creates a line from those chars
           stores those lines in an array
         */
        while((ch = getc(fp)) != EOF) {
                if((initalizeRoot == 0) && (ch == '\n') && (count != 0)){
                    // This should only be printed once
                    char *temp = (char *)malloc(sizeof(char));
                    lineBuffer[count] = '\0';
                    strcpy(temp,lineBuffer);
                    // printf("First Output '%s'\n", temp);
                    root.currLine = temp;

                    initalizeRoot++;
                    count= 0;
                }else if(ch == '\n' && count != 0 && initalizeRoot > 0) {
                        // Copies the lineBuffer String into a arrayStorage
                        char *temp = (char *)malloc(sizeof(char));
                        lineBuffer[count] = '\0';
                        // printf("Output '%s'\n", lineBuffer);
                        // printf("In the root Node '%s'\n", root.currLine);
                        strcpy(temp, lineBuffer);
                        insertNode(&root,temp,caseType);
                        count = 0;
                }
                if(ch != '\n') {
                        lineBuffer[count] = ch;
                        count++;
                }
        }

        // Closes the file
        fclose(fp);
        // printf("End of ReadFile\n\n");
        // int value = binarySort(lineStorage,index);
}
