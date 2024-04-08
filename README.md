# Installation de so_long

Ce guide vous explique comment installer so_long sur votre système.

## Prérequis

Assurez-vous d'avoir les éléments suivants installés sur votre système :
- GCC
- Make
- libx11-dev
- libbsd-dev

## Instructions d'installation

1. Installer les librairies suivantes : 
```sudo apt-get install libx11-dev```

et celle ci : 

```sudo apt-get install libbsd-dev```

Elles vont permettre le fonctionnement de la minilibix.

2. Cloner le dépôt Git de so_long :

```git clone https://github.com/Winspear22/so_long.git```

dans le dossier cloné, ouvrir le Makefile et remplacer le contenu de la variable ```INCLIB``` par le chemin où se trouve votre librairie X11 que vous venez d'installer. Ceci est impératif, sinon la minilibix ne fonctionnera pas.

## Lancement de so_long :

1. Make :

Il suffit de faire un simple ```make``` pour installer l'intégralité du programme. Vous obtiendrez un programme nommé ```so_long``` qui prend 1 argument qui est une map. Les diverses map se trouvent dans le dossier ```maps```.

2. Lancer so_long :

Pour lancer so_long, il suffit de lancer le programme avec une map existente et valide, comme par exemple :

```./so_long maps/map_valid02.ber```

Toute map invalide renverra une erreur.


sudo apt-get install pv (pour la barre du Makefile)