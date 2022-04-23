# 2022_Franco_Alonso_Projet_capteur

Ce repository Git contient les ressources nécessaire pour le projet 2022 qui s'inscrit dans l'UF *"Du capteur au banc de Test"* de l'INSA de Toulouse, 4ème année de Génie Physique.

---
## Sommaire


- [2022_Franco_Alonso_Projet_capteur](#2022_franco_alonso_projet_capteur)
  - [Sommaire](#sommaire)
  - [1) Livrables](#1-livrables)
  - [2) Description](#2-description)
  - [3) Shield PCB](#3-shield-pcb)
  - [4) Arduino](#4-arduino)
    - [4.1) Bibliothèques](#41-bibliothèques)
    - [4.2) Code Arduino](#42-code-arduino)
  - [5) Application Android APK](#5-application-android-apk)
    - [5.1) MIT App inventor](#51-mit-app-inventor)
    - [5.2) Notre application](#52-notre-application)
  - [6) Banc de test](#6-banc-de-test)
    - [6.1) Rayon de courbure](#61-rayon-de-courbure)
    - [6.2) Répétabilité](#62-répétabilité)
  - [7) Datasheet](#7-datasheet)
  - [8) Information sur les auteurs](#8-information-sur-les-auteurs)

---
## 1) Livrables


- Shield PCB réalisé avec KiCad
- Code Arduino permettant la mesure de la resistance et de la tension du capteur, ainsi que le contrôle d'un module Bluetooth, d'un écran OLED et d'un encodeur rotatoire
- Application android APK réalisée avec MIT APP INVENTOR
- Protocole et code Arduino du Banc de test
- Datasheet du capteur de déformation

---
## 2) Description

Dans le cadre de l'UF MOSH, nous avons conçu un capteur résistif composé de matériaux peu chers. Un simple papier et un crayon nous permettent de créer ce capteur.

Ici, le phénomène physique est l'effet tunnel, en effet, il existe un lien entre la conduction des électrons et la distance interatomique du réseau percolet. En faisant varier la distance séparant les particules du réseau (en pliant une feuille de papier sur laquelle on aura déposé du graphite par exemple), la conductivité du graphite varie, la résistivité varier également, et donc, la résistance variera aussi en fonction des dimensions du capteur. C'est cette propriété que l'on va exploiter afin de créer notre capteur résistif.  

Nous avons également implémenté  un shield sur notre chaine de mesures. Ce dernier a été conçu a l'aide du logiciel KICAD et aura un rôle de conditionneur du signal. Le shield est composé d'un amplificateur transimpédance, d'un module Bluetooth, d'un écran OLED, d'un encodeur rotatoire ainsi que d'une entrée analogique pour le capteur résistif.  

Pour finir, nous avons effectué l'ensemble des tests du circuit sur le logiciel LTSpice (voir [_Rapport LTSpice_](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/8504636d878c9423babecade3b70e7a892836c6b/Rapport_LTSpice.pdf)).  

Nous avons ensuite imprimé notre circuit PCB après validation de l'équipe pédagogique.  
Nous avons utilisé une carte Arduino pour la lecture des mesures et la création des fonctions relatives à l'écran OLED, au module Bluetooth ainsi qu'a l'encodeur rotatoire.  

Avec le site MIT App Inventor, nous avons développé une application Android qui a pour but de recevoir des données via Bluetooth.  

En ce qui concerne le Banc de test, nous avons effectué un test de rayon de courbure et un test de répétabilité avec deux types de crayons (B, HB).  


---
## 3) Shield PCB

Sur le logiciel KICAD nous avons créé des modèles pour l'amplificateur transimpédance, le module Bluetooth, l'écran OLED et l'encodeur rotatoire. Nous avons ensuite créé ou assigné des empreintes à chaque composante du circuit électronique (amplificateur, Bluetooth, OLED, encodeur rotatoire mais aussi résitances et capacités). Puis, nous avons tracé le chevelu du PCB et enfin nous avons modélisé notre PCB en 3D pour vérifier qu'aucun élément ne se superpose et qu'il n'y aura pas de problème lors de la réalisation du PCB.  


Projet KICAD avec fichiers formats pdf et format GERBER à télécharger [_ici_]  



Schéma du circuit électrique sur LTSpice:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/00df7a800f7fe16d923ac5965e24b1b7b5068f73/Images/LTSpice.PNG)


Schématique de l'amplificateur opérationel LTC1050:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20de%20l'amplificateur%20op%C3%A9rationel%20LTC1050.PNG)


Schématique du module Bluetooth HC-05:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20du%20module%20Bluetooth%20HC-05.PNG)


Schématique de l'écran OLED:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20de%20l'%C3%A9cran%20OLED_0.91.PNG)


Schématique de l'encodeur rotatoire KY-040:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20de%20l'encodeur%20rotatoire%20KY-040.PNG)


Schématique des pins de la carte Arduino:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20des%20pins%20de%20la%20carte%20arduino.PNG)


Schématique du circuit amplificateur transimpédance:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/sch%C3%A9matique%20du%20circuit%20amplificateur%20transimp%C3%A9dance.PNG)


Empreinte de l'amplificateur opérationel LTC1050:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20de%20l'amplificateur%20op%C3%A9rationel%20LTC1050.PNG)


Empreinte du module Bluetooth HC-05:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20du%20module%20Bluetooth%20HC-05.PNG)


Empreinte de l'écran OLED:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20de%20l'%C3%A9cran%20OLED_0.91.PNG)


Empreinte de l'encodeur rotatoir KY-040:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/7be68b19bb3e613d58d9b9c8b4e7bc60a2b68b1f/Images/Empreinte%20de%20l'encodeur%20rotatoire%20KY-040.PNG)


Empreinte du PCB en entier:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Empreinte%20du%20PCB%20entier.PNG)


Modélisation 3D du PCB:  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/c6a64df41f9162deea475fbd48119eca13fc34bf/Images/Mod%C3%A9lisation%203D%20du%20PCB.PNG)



---
## 4) Arduino

Notre code Arduino permet :

- de mesurer la tension en sortie du circuit transimpédance
- de calculer la résistance correspondante du capteur grâce à la tension mesurée (fonction de transfert)
- de visualiser ces valeurs (tension et résistance) dans le moniteur série
- d'afficher ces deux valeurs (tension et résistance) sur l'écran OLED
- d'envoyer les valeurs de résistance par Bluetooth à l'application APK
- d'utiliser un encodeur rotatoire pour choisir d'afficher sur l'écran OLED et d'envoyer par Bluetooth les valeurs de résistance en Ω, kΩ ou MΩ


### 4.1) Bibliothèques

- Installer la bibliothèque ["SoftwareSerial.h"]
- Installer la bibliothèque ["Arduino.h"]
- Installer la bibliothèque ["string.h"]
- Installer la bibliothèque ["Adafruit_SSD1306.h"]


### 4.2) Code Arduino



!!!!!! METTRE LE CODE ARDUINO !!!!!!!!


---
## 5) Application Android APK

L'application android développée sur MIT App Inventor sert à:

- Récupérer la valeur de la résistance du capteur graphite (calculée par le code Arduino à partir de la tension mesurée)
- Afficher cette valeur de résistance
- Tracer un graphique qui décrit l'évolution de la résistance du capteur en fonction du temps


### 5.1) MIT App inventor

Le site internet de création d'application [_MIT App Inventor_](https://appinventor.mit.edu/)

### 5.2) Notre application


Capture d'écran du code


---
## 6) Banc de test


### 6.1) Rayon de courbure


Nous avons effectué différents tests pour étudier l'influence du rayon de courbure sur la résistance de notre capteur. Pour cela, nous avons créé un banc de test "low-cost" en prenant différents objets cylindriques présents dans la salle d'instrumentation du Génie Physique (GP).

![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/fd57650aebb21b7f047258168513507125dd6fa7/Images/Rayons_de_courbure_tous_les_objets.JPG)

Puis, nous avons enroulé notre capteur autour de ces objets cylindriques dans un sens comme dans l'autre (extension/compression) et mesuré les variations de résistance pour les crayons de type B et de type HB.
Nous avons alors tracé deux graphes avec leurs courbes de tendance:  

![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/0bd03763ba0da2488beb34199330a152889df189/Images/Graphe_Rayon_de_courbure.JPG)  


### 6.2) Répétabilité

Ici, nous avons voulu mesurer la répétabilité de notre capteur, c'est-à-dire, à partir de combien de mesures notre capteur n'est plus fiable.
Pour y arriver, nous avons créé notre propre banc de test à partir d'un servo-moteur (et son code Arduino), de scotch, de carton et d'un support en rigide. Nous avons agrandi l'aile fixé au servo-moteur grâce à un morceau de carton et nous avons scotché ce servo-moteur à un support rigide que nous avons lui même scotché sur le bord d'un meuble. En ce qui concerne le capteur, nous avons scotché un support rigide sur le bord du même meuble à une petite distance de notre servo-moteur, ce qui nous a permis de positionner les pinces métalliques et notre capteur face à l'aile du servo-moteur qui va effectuer des aller-retours pour que le capteur subisse des cycles d'extension/compression.  

![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/9a6179c9a64ad83f9c8b5cb9e331d1c981edc935/Images/Test_Repetabilite_01.jpg)  

![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/469d8a52910f487a39b89d7652cd1226eb0d3d92/Images/Test_Repetabilite_video.mp4)

Après des mesures pour des crayons de type B et des crayons de type HB, nous avons obtenu deux courbes représentant l'évolution de la résistance mesurée par le capteur en fonction du nombre de cyles d'extension/compression effectués.  

![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/0bd03763ba0da2488beb34199330a152889df189/Images/Graphe_Repetabilite.JPG)  

Code Arduino du servo-moteur:  
![alt text]()


---
## 7) Datasheet

Datasheet en format pdf à télécharger [_ici_](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/5e02ecc9f3577d267857b414918c29e9b6da50dd/Datasheet/Datasheet_Capteur_papier.pdf).


---
## 8) Information sur les auteurs

Edouard FRANCO / Pablo ALONSO RODRIGUEZ

- edouard.franco@free.fr
- pablo.alonsorgz@gmail.com

Étudiants à l'INSA de Toulouse en 4ème année Génie Physique
