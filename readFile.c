#include "header.h"

/*
   Reads in the text from the passed in file
   and then outputs those values into a the
   binarytree creation function
 */

//Determines the case type
extern int shouldBeCaseSensitive;
extern char *lineBuffer;
extern char **lineStorage;
extern int lineStorageSize;

int readFile(char *fileName){
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

        int maxSize = 128, changingSize = maxSize,a = 0;

        /*
           Malloc allocates a memory block of a specific size
           Calloc allocates n number of memory blocks with any amount of size
         */
        lineBuffer = (char *)malloc(maxSize);
        lineStorage = malloc(maxSize);

        if(lineBuffer == NULL || lineStorage == NULL) {
                fprintf(stderr, "Memory Not allocated\n");
                exit(1);
        }
        lineStorageSize = maxSize;
        // InOrder to create an array of Strings i need to allocate
        // memory for each index
        for(a = 0; a < maxSize; a++) {
                lineStorage[a] = malloc( maxSize);
                if(lineStorage[a] == NULL) {
                        fprintf(stderr, "Memory Not allocated\n");
                        exit(1);
                }
        }

        char ch = NULL;
        int count = 0, index = 0;

        /*
           Streams through the file char by char
           Creates a line from those chars
           stores those lines in an array
         */
        while((ch = getc(fp)) != EOF) {
                if((count >= changingSize -1) && (ch != '\n')) {
                        changingSize += maxSize;
                        lineBuffer = (char *)realloc(lineBuffer, changingSize);
                        if(lineBuffer == NULL) {
                                fprintf(stderr, "Memory Not reallocated 1\n");
                                exit(1);
                        }
                }
                if(ch == '\n' && count != 0) {

                        // Not Needed For now

                        // a = 0;
                        // for(a = 0; a < maxSize; a++){
                        //   printf("%d", a);
                        //   lineStorage[a] = (char *)realloc(lineStorage[a], changingSize);
                        //   if(lineStorage[a] == NULL) {
                        //           fprintf(stderr, "Memory Not allocated\n");
                        //           exit(1);
                        //   }
                        // }

                        // Copies the lineBuffer String into a arrayStorage

                        strcpy(lineStorage[index], lineBuffer);
                        index++;
                        for(a = 0; a < changingSize; a++) {
                                lineBuffer[a] = '\0';
                        }

                        count = 0;
                }
                if(ch != '\n') {
                        lineBuffer[count] = ch;
                        count++;
                }
        }

        // Closes the file
        fclose(fp);
        printf("End of ReadFile\n\n");
        int value = binarySort(lineStorage,index);

        return value;
}
