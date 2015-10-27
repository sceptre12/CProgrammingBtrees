#include "header.h"

extern char *sortedList[];
void writeToOutputFile(char *fileName,int sortedListSize){
        printf("Inside of writeToOutputFile function\n");



        // get current Directory
        char path[1024];
        if(getcwd(path,sizeof(path)) == NULL) {
                fprintf(stderr, "Error with getting path\n");
                exit(1);
        }

        FILE *fp = NULL;
        strcat(path,"/");
        strcat(path,fileName);

        fp = fopen(path,"w+");

        if(!fp) {
                fprintf(stderr, "File Not Found '-%s'\n", path);
                exit(1);
        }
        int a;
        for (a = 0; a < sortedListSize; a++) {
            fprintf(fp, "%s\n", sortedList[a]);
        }
        fprintf(fp, "\n");
        fclose(fp);

        printf("End of writeToOutputFile function\n");
}
