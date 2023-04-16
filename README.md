# Projet Systèmes 2022-2023 : FindTheCat

Responsable du projet : Maiwenn Racouchot <<maiwenn.racouchot@telecomnancy.eu>>

## Membres du groupe 
* Lucie Boucher <<lucie.boucher@telecomnancy.eu>>
* Lola Montignier <<lola.montignier@telecomnancy.eu>> 

## Description du projet

Un code FindTheCat afin de trouver des fichiers/dossiers en fonction de différentes options et de leur paramètres associés.
[Le sujet détaillé est disponible en version PDF](./projet-2022-ftc.pdf)

### Comment utiliser notre programme

La simple commande make permet de compiler l'ensemble du projet puis d'indiquer en ligne de commande les critères voulus sur les fichiers/dossiers recherchés. L'instruction en ligne de commande doit avoir le format suivant:
1. ./ftc
2. une root
3. une option
4. un paramètre associé qui selon les options peut être optionnel

Autant d'options que voulues peuvent être indiquées.

### Exemple 

"./ftc /home/Documents/Systèmes -size +4k -color"

Cette instruction permet de trouver l'intégralité des fichiers à partir de la racine "/home/Documents/Systèmes" ayant une taille supérieure ou égale à 4k et d'afficher le nom des fichiers en couleurs.

### Liste des options disponibles
* name
* size
* date
* mime
* ctc
* dir
* color
* perm
