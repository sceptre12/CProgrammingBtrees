#include "header.h"

void determineOutput(char *fileName, int sortedListSize){
        if(fileName != NULL) {
                writeToOutputFile(fileName,sortedListSize);
        }
        writeToScreen(sortedListSize);
}
