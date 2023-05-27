# CY-Shop 


Ceci est notre projet d'informatique de fin de semestre dans le cadre de notre cursus de préIng1 MIM à CY Tech.

## Summary
- [Content](#Content) Explain what the project is.
- [Preview](#Preview) Pictures of the program while runing.
- [Instructions](#Instructions) All informations that you need to compile and run the program.
- [Bugs](#Bugs) A list of known bugs.

## Content

Le but est de créé un programme en C permettant de gérer des stocks et des fichiers clients pour un magasin de vente de pièces détachés de voiture. 

Le programme permet de choisir entre trois modes. Le mode de gestion, le mode d'achat ou le mode Customer. 

### Mode Gestion
Le mode gestion permet d'afficher et d'augmenter les stocks actuels dans la limite de l'espace disponible *(100 places)*.

### Mode Achat 
Le mode achat permet d'effectuer des achats à l'aide de son compte client. Il peut aussi permettre de rechercher des produits en stock à l'aide de leur nom ou de leur numéro de référence.

### Mode Customer
Le mode customer permet uniquement de supprimer son compte client de la base de donnée.

## Preview

(mettre photo du programme lancé)


## Instructions

1. Open a terminal window 
2. Clone the git repository to a location of your choice   
```sh
   git clone https://github.com/MI6-Pikes00/Projet-preing1
   ```

### Compile and Run
3. Enter the new folder
   ```sh
   cd Projet-preing1
   ```
4. Compile and run the project with *make* :
   ```sh
   make && ./CY-Shop
   ```


## Known Bugs

- Problème avec le *Delete Account*: Nécessite une deuxième entrée après la validation dans la console pour la bonne suppression du compte. 
- Problème d'*indentation* lors de l'affichage des stocks.
