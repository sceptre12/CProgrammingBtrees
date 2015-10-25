#include "header.h"

/*
  Reads in the text from the passed in file
  and then outputs those values into a the
  binarytree creation function
*/
extern int shouldBeCaseSensitive;

void readFile(char *fileName){
        // filePath Location
        char path[254];
        if(getcwd(path, sizeof(path)) != NULL) {
                FILE *fp;
                strcat(path,"/");
                strcat(path,fileName);

                fp = fopen(path,"r");

                if(!fp) {
                        fprintf(stderr, "File Not Found '-%s'\n", path);
                        exit(1);
                }

                int maxSize = 128, changingSize = maxSize;
                // dynamically allocating memory for the lineBuffer;
                char *lineBuffer = (char *)malloc(sizeof(char) * maxSize);
                char *lineStorage = (char *)calloc(maxSize,maxSize);

                if(lineBuffer == NULL || lineStorage == NULL) {
                        fprintf(stderr, "Memory Not allocated'-%s'\n", path);
                        exit(1);
                }
                char *linesArr;

                char ch = getc(fp);
                int count = 0;
                while(ch != EOF) {
                        if((count >= changingSize) && (ch != '\n')) {
                                changingSize += maxSize;
                                lineBuffer = realloc(lineBuffer, changingSize);
                                if(lineBuffer == NULL) {
                                        fprintf(stderr, "Memory Not reallocated'-%s'\n", path);
                                        exit(1);
                                }
                        }

                        count++;
                }

                free(lineBuffer);
                free(lineStorage);
                printf("End of ReadFile\n");
        }

}
