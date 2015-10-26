#include "header.h"

extern int shouldBeCaseSensitive;

void binarySort(char **array, int length){

    int a;
    for(a = 0; a < length; a++){

      printf("%s\n",array[a]);
    }

    struct Node root;
    root.currLine = array[2];
    root.parent = NULL;
    root.left = NULL;
    root.right = NULL;
    root.duplicate = 0;

    insertNode(&root,array[3]);
    insertNode(&root,array[1]);
    insertNode(&root,array[4]);
    // insertNode(&root,array[1]);
    // insertNode(&root,array[3]);
    // insertNode(&root,array[1]);
    if(root.parent == NULL){
      printf("Wroks\n\n");
    }


}

int insertNode(struct Node *root, char *stringB){
  printf("Inside insertNode Function %s\n", root->currLine);
  if(sameString(root->currLine,stringB,shouldBeCaseSensitive)==1){
    printf("Same string\n");
    root->duplicate++;
    return 0;// success
  }
  if(greaterThan(stringB,root->currLine,shouldBeCaseSensitive) == 0){
    // Means That String B is less than the value inside of root->currLine
    if(root->left != NULL){
      insertNode(root->left, stringB);
      printf("root left is not null\n");
    }else{
      printf("root left is null\n");
      struct Node tempNode;
      tempNode.currLine = stringB;
      tempNode.parent = root;
      root->left = &tempNode;
      printf("LEFTNODE %s\n", root->left->currLine);
    }
  }else if (greaterThan(stringB,root->currLine,shouldBeCaseSensitive) ==1){
    if(root->right != NULL){
      insertNode(root->right, stringB);
      printf("root right is not null\n");
    }else{
      printf("root right is null\n");
      struct Node tempNode;
      tempNode.currLine = stringB;
      tempNode.parent = root;
      root->right = &tempNode;
      printf("RIGHTNODE %s\n", root->right->currLine);
    }
  }
  return 0;
}
