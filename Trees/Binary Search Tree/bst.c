#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node** children;
    int key;
};

struct Bst {
    struct Node* root;
};

struct Node* CreateNode(int key){
    struct Node* newNode;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    
    if(newNode != NULL){
        newNode->key = key;
        newNode->children = NULL;
        return newNode;
    }
}

struct Bst* CreateBst(){
    struct Bst* newBst;
    newBst = (struct Bst *) malloc(sizeof(struct Bst));

    if(newBst != NULL){
        return newBst;
    }
}

struct Bst* CreateBstWithRoot(int key){
    struct Bst* newBst = CreateBst();
    newBst->root = CreateNode(key);

    return newBst;
}


int main() {
    printf("Hello World!");
    return(0);
}
