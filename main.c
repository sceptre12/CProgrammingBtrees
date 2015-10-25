#include "header.h"

//Global Declerations
int shouldBeCaseSensitive = 0;
char *outputFile = NULL;
char *inputFile = NULL;


int main(int argc, char *argv[]){

        parseCommandLineOptions(argc,argv);
        determineRead(inputFile);

        printf("%d\n", shouldBeCaseSensitive );

        if(outputFile != NULL) {
                printf("Output File name %s\n", outputFile);
        }
        if(inputFile != NULL) {
                printf("Input File name %s", inputFile);
        }

        // shouldBeCaseSensitive = 0;
        // char test1[] = "Yolo";
        // char test2[] = "yolo";
        // printf("The string %s\nThe first index %c\nThe first index in decimal %d\n", test1, test1[0],test1[0]);
        // int length = stringLength(test1);
        // printf("Length of Test1 %d\n",length);
        //
        // printf("%d\n", sameString(test1,test2,shouldBeCaseSensitive));
        //
        // printf("Is greater than %d\n", greaterThan("aiery", "athis one",shouldBeCaseSensitive));



        printf("\n");
        return 0;
}
