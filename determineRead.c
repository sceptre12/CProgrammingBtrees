#include "header.h"

int determineRead(char *fileName){
        if(fileName != NULL) {
                return readFile(fileName);
        }else{
                return readFromInput();
        }
}
