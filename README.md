Projet class_db
Description
Ce projet est une implémentation d'une base de données simple en C, utilisant un arbre binaire pour stocker et gérer les données. Il inclut une interface de type REPL (Read-Eval-Print Loop) pour accepter des commandes de l'utilisateur, permettant d'insérer, de rechercher et de manipuler des données de manière interactive.

Structure du Projet
Le projet est organisé comme suit :

src/main.c : Fichier principal qui initialise le programme.
src/btree.c : Contient les fonctions pour gérer l’arbre binaire (insertion, recherche, suppression, etc.).
src/repl.c : Gère l'interface REPL pour l’interaction utilisateur.
Compilation
Le projet utilise un Makefile pour simplifier la compilation. Assurez-vous d'avoir make et gcc installés.

Pour compiler le projet, exécutez la commande suivante depuis le répertoire racine du projet :

bash
Copier le code
make
Pour nettoyer les fichiers compilés, utilisez :

bash
Copier le code
make clean
Exécution
Après compilation, exécutez le programme avec la commande suivante :

bash
Copier le code
./main
Fonctionnalités
Initialisation de l'arbre binaire : Le programme initialise un arbre binaire pour gérer les données.
Interface REPL : Une interface en ligne de commande qui permet d'entrer des commandes telles que INSERT, SELECT, etc.
Instructions pour les Commandes (à compléter au fur et à mesure du développement)
INSERT : Permet d’insérer un nouvel élément dans l’arbre.
SELECT : Rechercher un élément dans l’arbre.
DELETE : Supprimer un élément de l’arbre.
Dépendances
Le projet utilise uniquement des bibliothèques standard C (stdio.h, etc.) et ne nécessite aucune bibliothèque externe.

Auteurs
[David ATTIPOUPOU] - Développeur principal
