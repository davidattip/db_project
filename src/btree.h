#ifndef BTREE_H
#define BTREE_H

#include <stdio.h> // Pour FILE
#include <stddef.h> // Pour NULL
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key);
Node* insertNode(Node* root, int key);
Node* searchNode(Node* root, int key);  // Ajoute cette déclaration
void freeTree(Node* root);
Node* deleteNode(Node* root, int key);
void displayTree(Node* root, int space);
void saveTree(Node* root, FILE* file);
Node* loadTree(FILE* file);




#endif
