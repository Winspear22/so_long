#!/bin/bash

# Couleurs
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Compiler le programme so_long
make silent_make

# Fonction pour créer les fichiers de test
create_test_files() {
    touch "fichier sans extension"
    touch "fichier_avec_extension.txt"
    touch "fichier_avec_deux_points.txt.ber"
    touch "fichier_invalide.ber.txt"
    touch "fichier_avec_nom_seul.ber"
    touch ".ber"
    touch "dossier"
}

# Fonction pour supprimer les fichiers de test
remove_test_files() {
    rm -f "fichier sans extension"
    rm -f "fichier_avec_extension.txt"
    rm -f "fichier_avec_deux_points.txt.ber"
    rm -f "fichier_invalide.ber.txt"
    rm -f "fichier_avec_nom_seul.ber"
    rm -f ".ber"
    rm -f "dossier"
}

# Créer les fichiers de test
create_test_files

# Variable pour le numéro de test
test_num=1

# Exécuter so_long avec chaque fichier
for file in *; do
    case "$file" in
        "fichier sans extension")
            test_desc="Nom de fichier sans extension - ${YELLOW}${file}${NC}"
            ;;
        "fichier_avec_extension.txt")
            test_desc="Nom de fichier avec mauvaise extension - ${YELLOW}${file}${NC}"
            ;;
        "fichier_avec_deux_points.txt.ber")
            test_desc="Nom de fichier avec deux points - ${YELLOW}${file}${NC}"
            ;;
        "fichier_invalide.ber.txt")
            test_desc="Nom de fichier avec extension invalide - ${YELLOW}${file}${NC}"
            ;;
        "fichier_avec_nom_seul.ber")
            test_desc="Nom de fichier valide - ${YELLOW}${file}${NC}"
            ;;
        ".ber")
            test_desc="Nom de fichier valide mais caché - ${YELLOW}${file}${NC}"
            ;;
        "dossier")
            test_desc="Nom de dossier - ${YELLOW}${file}${NC}"
            ;;
        *)
            test_desc="Fichier inconnu - ${YELLOW}${file}${NC}"
            ;;
    esac

    echo "${GREEN}Test $test_num${NC} - $test_desc\n"
    ./so_long "$file"
    test_num=$((test_num + 1))
done

# Supprimer les fichiers de test
remove_test_files

# Nettoyer les fichiers générés
make silent_fclean
