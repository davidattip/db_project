#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.h"

void startREPL(Node* root) {
    char command[256];
    int value;

    printf("Bienvenue dans l'interface REPL. Tapez 'exit' pour quitter.\n");

    while (1) {
        printf("> ");
        fgets(command, 256, stdin);

        if (strncmp(command, "exit", 4) == 0) {
            break;
        } else if (sscanf(command, "INSERT %d", &value) == 1) {
            root = insertNode(root, value);
            printf("Valeur %d insérée dans l'arbre.\n", value);
        } else if (sscanf(command, "SEARCH %d", &value) == 1) {
            Node* found = searchNode(root, value);
            if (found != NULL) {
                printf("Valeur %d trouvée dans l'arbre.\n", value);
            } else {
                printf("Valeur %d non trouvée dans l'arbre.\n", value);
            }
        } else if (sscanf(command, "DELETE %d", &value) == 1) {
            root = deleteNode(root, value);
            printf("Valeur %d supprimée de l'arbre.\n", value);
        } else {
            printf("Commande non reconnue. Utilisez 'INSERT <valeur>', 'SEARCH <valeur>', 'DELETE <valeur>', ou 'exit'.\n");
        }
    }
}

