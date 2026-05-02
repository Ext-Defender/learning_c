// Linked List
/*
TODO Cleanup code
TODO implement searching
TODO pass data to addNode funcs and instantiate struct there
 */
#include <stdio.h>
#include <stdint.h>

typedef struct Node {
    struct Node* nextNode;
    char data[256];
} Node;

typedef struct {
    Node* startNode;
} LinkedList;


void printNode(Node *node)
{
     printf("%s\n", node->data);
}

void printLinkedList(LinkedList *ll)
{
    Node *currentNode = ll->startNode;

    while (currentNode != NULL) {
         printNode(currentNode);
         currentNode = currentNode->nextNode;
    }
}

void addNode(LinkedList *ll, Node *node)
{
    if (ll->startNode == NULL){
        ll->startNode = node;
    } else {
         node->nextNode = ll->startNode;
         ll->startNode = node;
    }
}

void addNodeBack(LinkedList *ll, Node *node)
{
     if (ll->startNode == NULL) {
          ll->startNode = node;
     } else {
          Node *currentNode = ll->startNode;
          while (currentNode->nextNode != NULL) {
               currentNode = currentNode->nextNode;
          }
          currentNode->nextNode = node;
     }
}

int main()
{
    Node firstNode = {NULL, "Hello"};
    Node secondNode = {NULL, "World"};
    Node thirdNode = {NULL, "last node"};
    LinkedList ll = {NULL};
    addNode(&ll, &firstNode);
    addNode(&ll, &secondNode);
    addNodeBack(&ll, &thirdNode);
    printLinkedList(&ll);
    printLinkedList(&ll);
    return 0;
}
