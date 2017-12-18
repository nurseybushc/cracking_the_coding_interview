#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    int val;
};

struct LinkedList {
    struct Node* first;
};

struct Node* CreateNode(int val){
    struct Node* newNode;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    
    if(newNode != NULL){
        newNode->val = val;
        newNode->next = NULL;
        return newNode;
    }
}

struct LinkedList* CreateLinkedList(){
    struct LinkedList* newLinkedList;
    newLinkedList = (struct LinkedList *) malloc(sizeof(struct LinkedList));

    if(newLinkedList != NULL){
        return newLinkedList;
    }
}

struct LinkedList* CreateLinkedListWithVal(int val){
    struct LinkedList* newLinkedList = CreateLinkedList();
    newLinkedList->first = CreateNode(val);

    return newLinkedList;
}

void AddNodeToEnd(struct LinkedList* list, struct Node* node) {
    if(list->first == NULL){
        list->first = node;
    } else {
        //traverse to end of list
        struct Node* temp = list->first;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        //temp->next should be NULL
        temp->next = node;
        node->next = NULL;
    }
}

void AddNodeToFront(struct LinkedList* list, struct Node* node) {
    if(list->first == NULL){
        list->first = node;
    } else {
        struct Node* temp = list->first;
        list->first = node;
        list->first->next = temp;
    }
}

void AddValueToEndOfList(struct LinkedList* list, int val) {
    struct Node* node = CreateNode(val);
    AddNodeToEnd(list, node);
}

void AddValueToFrontOfList(struct LinkedList* list, int val) {
    struct Node* node = CreateNode(val);
    AddNodeToFront(list, node);
}

struct Node* RemoveFirstNode(struct LinkedList* list) {
    if(list->first == NULL) return NULL;
    struct Node* temp = list->first;
    list->first = temp->next;
    return temp;
}

struct Node* RemoveLastNode(struct LinkedList* list) {
    if(list->first == NULL) return NULL;
    struct Node* temp = list->first;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node* retNode = temp->next;
    temp->next = NULL;
    return retNode;
}

struct Node* RemoveNodeAtNthPos(struct LinkedList* list, int n) {
    if(list->first == NULL) return NULL;
    struct Node* temp = list->first;
    struct Node* prev = list->first;
    int pos = 0;
    while(temp->next != NULL && pos < n) {
        prev = temp;
        temp = temp->next;
        pos++;
    }
    if(temp == list->first){
        return RemoveFirstNode(list);
    } else if(temp->next == NULL){
        return RemoveLastNode(list);
    } else {
        prev->next = temp->next;
        return temp;
    }
}

void AddNodeAtNthPos(struct LinkedList* list, struct Node* node) {

}

void PrintLinkedList(struct LinkedList* list) {
    if(list->first == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = list->first;
    printf("*(%d)->", temp->val);

    while(temp->next != NULL){
        temp = temp->next;
        printf("*(%d)->", temp->val);
    }
    printf("END\n");
}

int GetLinkedListLength(struct LinkedList* list) {
    if(list->first == NULL) return 0;
    int length = 1;
    struct Node* temp = list->first;
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

int main() {
    //struct Node* myNode = CreateNode(5);
    struct LinkedList* myLinkedList = CreateLinkedListWithVal(5);
    RemoveNodeAtNthPos(myLinkedList, 0);
    PrintLinkedList(myLinkedList);
    AddValueToEndOfList(myLinkedList, 6);
    PrintLinkedList(myLinkedList);
    AddValueToEndOfList(myLinkedList, 7);
    PrintLinkedList(myLinkedList);
    AddValueToFrontOfList(myLinkedList, 1);
    PrintLinkedList(myLinkedList);
    RemoveLastNode(myLinkedList);

    PrintLinkedList(myLinkedList);
    RemoveFirstNode(myLinkedList);
    PrintLinkedList(myLinkedList);
    printf("list is %d nodes long\n", GetLinkedListLength(myLinkedList));
    //printf("created node val = %d\n", myNode->val);
    return(0);
}
