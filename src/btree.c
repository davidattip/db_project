#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "btree.h"

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}


void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Cas où le nœud n'a qu'un enfant ou pas d'enfant
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Cas où le nœud a deux enfants
        Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void displayTree(Node* root, int space) {
    if (root == NULL) return;

    space += 5;
    displayTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->key);
    displayTree(root->left, space);
}

void saveTree(Node* root, FILE* file) {
    if (root == NULL) {
        fprintf(file, "NULL\n");
        return;
    }
    fprintf(file, "%d\n", root->key);
    saveTree(root->left, file);
    saveTree(root->right, file);
}

Node* loadTree(FILE* file) {
    char buffer[256];
    if (!fgets(buffer, sizeof(buffer), file) || strncmp(buffer, "NULL", 4) == 0) {
        return NULL;
    }
    int key = atoi(buffer);
    Node* root = createNode(key);
    root->left = loadTree(file);
    root->right = loadTree(file);
    return root;
}
