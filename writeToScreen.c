#include "header.h"

extern char *sortedList[];
void writeToScreen(int sortedListSize){
    printf("Inside of Write to Screen Function\n");

    int a;

    for(a = 0; a < sortedListSize; a++){
        puts(sortedList[a]);
    }

    printf("Leaving Write to Screen Function\n");
}
