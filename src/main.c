#include <stdio.h>
#include "btree.h"
#include "repl.h"

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 20);

    Node* found = searchNode(root, 5);
    if (found != NULL) {
        printf("Node found with key: %d\n", found->key);
    } else {
        printf("Node not found.\n");
    }
    startREPL(root);
    freeTree(root);
    return 0;
}
