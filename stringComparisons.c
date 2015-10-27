#include "header.h"

int stringLength(char *word){
        int count = 0;
        while(word[count]) count++;
        return count;
}
void toUpperCase(char *word, int count){
        int a =0;
        for(a = 0; a < count; a++) {
                if(word[a] > 96) {
                        word[a] = word[a] - 32;
                }
        }
}
void toLowerCase(char *word, int count){
        int a =0;
        for(a = 0; a < count; a++) {
                if(word[a] < 96) {
                        word[a] = word[a] + 32;
                }
        }
}

/*
   Returns 1 if true or 0 if false
 */

int sameString(char stringA[], char stringB[], int caseType){
        /*
           Case type will determine if method should be ran with
           checking for case or not
           1 = true
           0 = false
         */
        // printf("\t a:%s | b:%s type:%d\n",stringA,stringB,caseType);
        int lengthA = stringLength(stringA);
        int lengthB = stringLength(stringB);
        if(lengthA != lengthB) return 0;

        // Creates temporary placeholders
        char tempA[lengthA], tempB[lengthB];

        strcpy(tempA,stringA);
        strcpy(tempB,stringB);
        int size = 0;
        // Does not check for case
        if(caseType == 0) {
          // printf("\tDoes not check for case\n");
                toUpperCase(tempA, lengthA);
                toUpperCase(tempB, lengthA);
                for(size = 0; size < lengthA; size++) {
                        if(tempA[size] != tempB[size]) {
                                return 0;
                        }
                }
                return 1;
        }
        // Case checking matters
        for(size = 0; size < lengthA; size++) {
                if(tempA[size] != tempB[size]) {
                  // printf("\tTEst\n");
                        return 0;
                }
        }

        return 1;
}

/*
   This program will essentially determine if stringA is greater than  StringB
   It will return:
   0 if stringA is less than StringB
   1 if stringA is greater than StringB
 */
int greaterThan(char stringA[],char stringB[],int caseType){
        /*
           Determines if one string is greater than the other
           This gets called on after the method that determines if
           the strings are the same
           Case types
           0 = false;
           1 = true;
         */

        int lengthA = stringLength(stringA);
        int lengthB = stringLength(stringB);
        // Temporary holders
        char tempA[lengthA], tempB[lengthB];
        strcpy(tempA,stringA);
        strcpy(tempB,stringB);

        int count = 0;
        // Does not check for case
        if(caseType == 0) {
                toUpperCase(tempA, lengthA);
                toUpperCase(tempB, lengthB);
                if(lengthB < lengthA ) {
                        for(count = 0; count < lengthB; count++) {
                                if(tempA[count] != tempB[count]) {
                                        if(tempA[count] > tempB[count]) {
                                                return 1;
                                        }else{
                                                return 0;
                                        }
                                }
                        }
                }else {
                    // printf("Inside of String comparison Less Than\n");
                        for(count = 0; count < lengthA; count++) {
                                if(tempA[count] != tempB[count]) {
                                        if(tempA[count] > tempB[count]) {
                                                return 1;
                                        }else{
                                                return 0;
                                        }
                                }
                        }
                }
        }
        if(lengthB < lengthA ) {
                for(count = 0; count < lengthB; count++) {
                        if(tempA[count] != tempB[count]) {
                                if(tempA[count] > tempB[count]) {
                                        return 1;
                                }else{
                                        return 0;
                                }
                        }
                }
        }else {
                for(count = 0; count < lengthA; count++) {
                        if(tempA[count] != tempB[count]) {
                                if(tempA[count] > tempB[count]) {
                                        return 1;
                                }else{
                                        return 0;
                                }
                        }
                }
        }
        return 0;
}
