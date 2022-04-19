# 2022_Franco_Alonso_Projet_capteur

Ce repository Git contient les ressources nécessaire pour le projet 2022 qui s'inscrit dans l'UF *"Du capteur au banc de Test"* de l'INSA de Toulouse, 4ème année de Génie Physique.

## Sommaire

---

- [2022_Franco_Alonso_Projet_capteur](#2022_franco_alonso_projet_capteur)
  - [Sommaire](#sommaire)
  - [Livrables](#livrables)
  - [Description](#description)
    - [Code Arduino](#code-arduino)
    - [KICAD](#kicad)
    - [Application APK](#application-apk)
  - [Arduino](#arduino)
    - [Bibliotèques](#bibliotèques)
    - [Notre code arduino](#notre-code-arduino)
  - [Projet KICAD](#projet-kicad)
  - [Application Android APK](#application-android-apk)
    - [MIT App inventor](#mit-app-inventor)
    - [Notre application](#notre-application)
  - [Banc de test](#banc-de-test)
  - [Information sur les auteurs](#information-sur-les-auteurs)

## Livrables

---

- Shield PCB
- Code Arduino permettant la mesure de la resistance et de la tension du capteur, ainsi que le contrôle des fonctionnalités Banc de Test, OLED et encodeur rotatoire
- Application android APK réalisée avec MIT APP INVENTOR
- Datasheet du capteur de déformation

## Description

---
Dans le cadre de l'UF MOSH, nous avons conçu un capteur résistif composé de matériaux peu chers. Un simple papier et un crayon nous permettent de créer ce capteur.
Ici, le phénomène physique est l'effet tunnel, en effet, il existe un lien entre la conduction des électrons et la distance interatopique du réseau percolet.
En faisant varier la distance séparant les particules du réseau (en pliant une feuille de papier sur laquelle on aura déposé du graphite par exemple), la conductivité du graphite varie, la résistivité varier également, et donc, la résistance variera aussi en fonction des dimensions du capteur. C'est cette propriété que l'on va exploiter afin de créer notre capteur résistif.
Nous avons également implémenté  un shield sur notre chaine de mesures. Ce dernier a été conçu a l'aide du logiciel KICAD et aura un rôle de conditionneur du signal. Le shield est composé d'un module Bluetooth, d'un écran OLED, d'un encodeur rotatoire,  d'un amplificateur transimpédance ainsi que d'une entrée analogique pour le capteur résistif.
Pour finir, nous avons effectué l'ensemble des tests du circuit sur le logiciel LTSpice.

Nous avons ensuite imprimé notre circuit PCB après validation de l'équipe pédagogique.
Nous avons utilisé une carte Arduino pour la lecture des mesures et la création des fonctions relatives à l'écran OLED, au module Bluetooth ainsi qu'a l'encodeur rotatoire.
Avec le site MIT App Inventor, nous avons développé une application Android qui a pour but d'envoyer et de recevoir des données via Bluetooth.
Pour tester notre capteur, nous avons utilisé différents types de crayons (B, HB, 2H). Nous avons utilité le banc de test mis a disposition en salle d'instrumentation comportant 7 bosses de rayon de courbure différent, les mesures ont été lues directement sur l'écran OLED.

### Code Arduino

Le code Arduino permet d'afficher les valeurs de tension et de résistance du capteur dans la console. Ces valeurs seront aussi affichées sur l'écran OLED et envoyées par Bluetooth à notre application APK.
L'encodeur rotatoire permet de choisir d'afficher la résistance sur l'écran OLED en Ω, kΩ ou MΩ.

### KICAD

Sur le logiciel KICAD nous avons créé les modèles pour l'écran OLED, le module Bluetooth, l'encodeur rotatoire et l'amplificateur transimpédance. Nous avons ensuite créé ou assigné des empreintes à chaque composante du circuit électronique avant de créé le chevelu du PCB et de modéliser notre PCB en 3D pour vérifier qu'aucun élément ne se superpose.

### Application APK

L'application android permet de lire la valeur de tension et de la résistance du capteur.
Grâce aux données accumulées, l'application trace une courbe représentant la variation de résistance en fonction du temps.

## Arduino

---
En résumé, notre code Arduino permet de mesurer la tension en sortie du circuit transimpédance, de calculer la résistance du associée du capteur puis d'afficher ces deux valeurs (tension et résistance) sur l'écran OLED et de les envoyer par Bluetooth à l'application APK.
Les valeurs de tension et de résistance sont aussi visibles dans le moniteur série.

### Bibliotèques

- Installer la bibliothèque ["SoftwareSerial.h"]
- Installer la bibliothèque ["Arduino.h"]
- Installer la bibliothèque ["string.h"]
- Installer la bibliothèque ["Adafruit_SSD1306.h"]


### Notre code arduino

Notre code Arduino permet de:

- Mesurer la tension de sortie du circuit transimpédance
- Calculer la résistance du capteur de graphite connaissant la fonction de transfert du conditionneur
- Envoyer la mesure de la tension et de la resistance via Bluetooth sur 1 octet
- Afficher les mesures de tension, de résistance et possède un menu pour choisir entre un offset et un gain numérique sur un écran OLED
- Gèrer l'encodeur rotatoire



!!!!!! METTRE LE CODE ARDUINO !!!!!!!!



## Projet KICAD

---
Le projet sur le logiciel KICAD permet de:

- Manipuler le PCB sous forme de Shield pour carte Arduino UNO
- Interfacer capteur graphite via un circuit transimpédance
- Interfacer un module Bluetooth
- Interfacer un écran OLED
- Interfacer un encodeur rotatoire

Projet KICAD avec fichiers formats pdf et format GERBER à télécharger [_ici_]


- Schéma du circuit électrique sur LTSpice:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/00df7a800f7fe16d923ac5965e24b1b7b5068f73/Images/LTSpice.PNG)


- Schématique de l'amplificateur opérationel LTC1050:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20de%20l'amplificateur%20op%C3%A9rationel%20LTC1050.PNG)


- Schématique du module Bluetooth HC-05:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20du%20module%20Bluetooth%20HC-05.PNG)


- Schématique de l'écran OLED:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20de%20l'%C3%A9cran%20OLED_0.91.PNG)


- Schématique de l'encodeur rotatoire KY-040:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20de%20l'encodeur%20rotatoire%20KY-040.PNG)


- Schématique des pins de la carte Arduino:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20des%20pins%20de%20la%20carte%20arduino.PNG)


- Schématique du circuit amplificateur transimpédance:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20du%20circuit%20amplificateur%20transimp%C3%A9dance.PNG)


- Empreinte de l'amplificateur opérationel LTC1050:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20de%20l'amplificateur%20op%C3%A9rationel%20LTC1050.PNG)


- Empreinte du module Bluetooth HC-05:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20du%20module%20Bluetooth%20HC-05.PNG)


- Empreinte de l'écran OLED:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20de%20l'%C3%A9cran%20OLED_0.91.PNG)


- Empreinte de l'encodeur rotatoir KY-040:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/7be68b19bb3e613d58d9b9c8b4e7bc60a2b68b1f/Images/Empreinte%20de%20l'encodeur%20rotatoire%20KY-040.PNG)


- Empreinte du PCB en entier:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20du%20PCB%20entier.PNG)


- Modélisation 3D du PCB:
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Mod%C3%A9lisation%203D%20du%20PCB.PNG)





## Application Android APK

---
L'application android développée sur MIT App Inventor sert à:

- Récupérer la mesure de tension du capteur graphite
- Récupérer la valeur de la résistance du capteur graphite (calculée par le code Arduino à partir de la tension mesurée) 
- Tracer un graphique qui décrit l'évolution de la résistance du capteur en fonction du temps

### MIT App inventor

Le site internet de création d'application [_MIT App Inventor_](https://appinventor.mit.edu/)

### Notre application

---


## Banc de test

---


## Information sur les auteurs

---
Edouard FRANCO / Pablo ALONSO RODRIGUEZ

- edouard.franco@free.fr

Étudiants à l'INSA de Toulouse en 4ème année Génie Physique

