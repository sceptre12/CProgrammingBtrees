#include "header.h"

void determineOutput(char *fileName){
        if(fileName != NULL) {
                writeToOutputFile(fileName);
        }else{
            writeToScreen();
        }        
}
