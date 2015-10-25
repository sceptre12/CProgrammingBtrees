#include "header.h"

void determineRead(char *fileName){
        if(fileName != NULL) {
          readFile(fileName);
        }else{
          readFromInput();
        }
}
