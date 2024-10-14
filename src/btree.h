#ifndef BTREE_H
#define BTREE_H

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key);
Node* insertNode(Node* root, int key);
Node* searchNode(Node* root, int key);  // Ajoute cette déclaration
void freeTree(Node* root);

#endif
