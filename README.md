# 2022_Franco_Alonso_Projet_capteur
 Projet capteur 4GP


# Projet Capteur Graphite GRP24

Ce Git contient les ressources nécessaire pour le projet 2021 qui s'inscrit dans l'UF *"Du capteur au banc de Test"* de l'INSA de Toulouse, 4ème année de Génie Physique.

## Sommaire

---

- [2022_Franco_Alonso_Projet_capteur](#2022_franco_alonso_projet_capteur)
- [Projet Capteur Graphite GRP24](#projet-capteur-graphite-grp24)
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
    - [Image du fichier LT SPICE](#image-du-fichier-lt-spice)
    - [Représentation électrique des composants principaux](#représentation-électrique-des-composants-principaux)
    - [Placement des composants](#placement-des-composants)
    - [Sockets KICAD pour les différents composants](#sockets-kicad-pour-les-différents-composants)
  - [Application Android APK](#application-android-apk)
    - [MIT App inventor](#mit-app-inventor)
    - [Notre application](#notre-application)
  - [Banc de test](#banc-de-test)
  - [Pistes de réflexion](#pistes-de-réflexion)
  - [Information sur les auteurs](#information-sur-les-auteurs)

## Livrables

---

- Shield PCB
- Code Arduino permettant la mesure de la resistance R et la tension, ainsi que le contrôle des fonctionnalités BT, OLED et capteur rotatoire
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
  
- Installer la bibliothèque ["Adafruit BusIOa"](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Libraries%20ajout%C3%A9es/Adafruit_BusIO-master.zip)

### Notre code arduino

Notre code Arduino permet de:

- Mesurer la tension de sortie du circuit transimpédance
- Calculer la résistance du capteur de graphite connaissant la fonction de transfert du conditionneur
- Envoie la mesure de la tension et de la resistance via Bluetooth sur 1 octet
- Affiche les mesures de tension, de résistance et possède un menu pour choisir entre un offset et un gain numérique sur un écran OLED
- Gère l'encodeur rotatoire

[_Pour télécharger le code_](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/code/code_avec_encodeur_et_gain_non_fini.ino)

[_Pour télécharger la version pour les mesures(sans encodeur rotatoire)_](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/code/code_banc_test.ino)

```C++


!!!!!! METTRE LE CODE ARDUINO !!!!!!!!



## Projet KICAD

---
Le projet sur le logiciel KICAD permet de:

- Manipuler le PCB sous forme de Shield pour carte Arduino UNO
- Interfacer capteur graphite via un circuit transimpédance
- Interfacer un module Bluetooth
- Interfacer un écran OLED
- Interfacer un encodeur rotatoire

Projet KICAD avec fichiers formats pdf et format GERBER à télécharger [_ici_](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/tree/main/kicad)

### Image du fichier LT SPICE

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/LTSPICE.png "Screenshot du fichier LT SPICE pour la conception et la simulation du circuit électrique sur le PCB")

_Aperçu du Shield PCB (empreinte GERBER)_

![PCB pdf](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/kicad/kicad-B_Cu.pdf "Aperçu du shield PCB en pdf")

### Représentation électrique des composants principaux

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/Amplificateur.png "Amplificateur")

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/Modules.png "Modules")

### Placement des composants

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/Placement.png "Placement des composants")

### Sockets KICAD pour les différents composants

- Amplificateur transimpédance

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/Amplificateur%20transimpedance.png "Amplificateur transimpédance")

- Module Blueetooth

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/Module%20BT.png "modules")

- Encodeur rotatoire

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/Encodeur%20rotatoire.png "modules")


## Application Android APK

---
L'application android développée sur MIT App Inventor sert à:

- Récupérer la mesure de tension du capteur graphite
- Récupérer la valeur de la résistance du capteur graphite (calculée par le code Arduino à partir de la tension mesurée) 
- Tracer un graphique qui décrit l'évolution de la résistance du capteur en fonction du temps

### MIT App inventor

Le site internet de création d'application [_MIT App Inventor_](https://appinventor.mit.edu/)

### Notre application

Notre code de l'application (format .aia) est à télécharger [_ici_](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/APK/Capteur_graph.aia)

Notre code de l'application (format .apk) est à télécharger [_ici_](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/APK/Capteur_graph.apk)

## Banc de test

---
Afin de tracer les courbes caractéristiques, on a mesuré la résistance du papier a l’aide d’un objet avec 7 « ponts » de différents rayons de courbure, on a déposé le capteur en papier dessus en faisant attention à reproduire à chaque mesure la même expérience et en déposant le papier au même endroit.. Les résultats sont dans notre [_datasheet_](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Datasheet.pdf)

_Image du banc de test_

![alt text](https://github.com/MOSH-Insa-Toulouse/Projet-GRP24-MOSH/blob/main/Images/BancTest.png "banc de test")

## Pistes de réflexion

---

- Changer le banc de test car les mesures étaient souvent pas très précises et cela nous a demandé de faire plusieurs capteurs différents afin d'obtenir des résultats satisfaisants.

- Finaliser le code de l'encodeur rotatoire(les résultats de mesure sont fait sans la partie encodeur rotatoire)

- Tester et caractériser plus de capteurs (plus de pistes en graphites avec des différents types de crayons à papier)

## Information sur les auteurs

---
Edouard FRANCO / Pablo ALONSO RODRIGUEZ

- edouard.franco@free.fr

Étudiants à l'INSA de Toulouse en 4ème année Génie Physique

