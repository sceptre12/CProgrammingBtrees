#include <stdio.h>
#include <string.h>

// Function Declarations
int sameString(char stringA[],char stringB[],int caseType);
void toUpperCase(char *word,int count);
void toLowerCase(char *word,int count);
int stringLength(char *word);
int greaterThan(char stringA[],char stringB[,int caseType];)

int main(int argc, char *argv[]){
    /*
      This program will essentially determine if one string is greater than another
      It will return:
      0 if they are equal
      1 if string a > string b
      -1 if string a < string b
    */
    char test1[] = "Yolo";
    char test2[] = "yolo";
    printf("The string %s\nThe first index %c\nThe first index in decimal %d\n", test1, test1[0],test1[0]);
    int length = stringLength(test1);
    printf("Length of Test1 %d\n",length);

    int boolean = sameString(test1,test2,0);

    printf("%d\n", boolean);

    printf("\n");
    return 0;
}

int stringLength(char *word){
  int count = 0;
  while(word[count]) count++;
  return count;
}
void toUpperCase(char *word, int count){
    int a =0;
    for(a = 0; a < count; a++){
      if(word[a] > 96){
        word[a] = word[a] - 32;
      }
    }
}
void toLowerCase(char *word, int count){
    int a =0;
    for(a = 0; a < count; a++){
      if(word[a] < 96){
        word[a] = word[a] + 32;
      }
    }
}

/*
  Returns 1 if true or 0 if false
*/
int sameString(char stringA[], char stringB[], int caseType){
  printf("Inside of SameString func\n");
  /*
    Case type will determine if method should be ran with
    checking for case or not
    1 = true
    0 = false
  */
  int lengthA = stringLength(stringA);
  int lengthB = stringLength(stringB);
  if(lengthA != lengthB) return 0;

  // Creates temporary placeholders
  char tempA[lengthA], tempB[lengthB];
  strcpy(tempA,stringA);
  strcpy(tempB,stringB);
  int size = 0;

  if(caseType == 0){

      toUpperCase(tempA, lengthA);
      toUpperCase(tempB, lengthA);
      for(size = 0; size < lengthA; size++){
        if(tempA[size] != tempB[size]){
          return 0;
        }
      }
      return 1;
  }

  for(size = 0; size < lengthA; size++){
    if(tempA[size] != tempB[size]){
      return 0;
    }
  }
  return 1;
}

/*
  Returns 1 if true or 0 if false
*/
int greaterThan(char stringA[],char stringB[],int caseType){
  
}
