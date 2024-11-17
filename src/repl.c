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
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("Erreur lors de la lecture de l'entrée. Veuillez réessayer.\n");
            continue;
        }

        
        command[strcspn(command, "\n")] = '\0';

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
                printf("Valeur non trouvée dans l'arbre.\n");
            }
        } else if (sscanf(command, "DELETE %d", &value) == 1) {
            root = deleteNode(root, value);
            printf("Valeur %d supprimée de l'arbre.\n", value);
        } else if (strncmp(command, "DISPLAY", 7) == 0) {
            printf("Affichage de l'arbre :\n");
            displayTree(root, 0);
        } else if (strncmp(command, "SAVE", 4) == 0) {
            FILE* file = fopen("tree_data.txt", "w");
            if (file != NULL) {
                saveTree(root, file);
                fclose(file);
                printf("Arbre sauvegardé avec succès.\n");
            } else {
                printf("Erreur lors de la sauvegarde.\n");
            }
        } else if (strncmp(command, "LOAD", 4) == 0) {
            FILE* file = fopen("tree_data.txt", "r");
            if (file != NULL) {
                root = loadTree(file);
                fclose(file);
                printf("Arbre chargé avec succès.\n");
            } else {
                printf("Erreur lors du chargement.\n");
            }
        } else {
            printf("Commande non reconnue. Utilisez 'INSERT <valeur>', 'SEARCH <valeur>', 'DELETE <valeur>', 'DISPLAY', 'SAVE', 'LOAD', ou 'exit'.\n");
        }
    }
}
