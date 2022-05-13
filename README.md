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

Dans le cadre de l'UF MOSH, nous avons conçu un capteur résistif composé de matériaux peu chers : un simple papier et un crayon suffisent à créer ce capteur.

Ici, le phénomène physique observé est l'effet tunnel. En effet, il existe un lien entre la conduction des électrons et la distance interatomique du réseau percolet. En faisant varier la distance séparant les particules du réseau (en pliant une feuille de papier sur laquelle on aura déposé du graphite par exemple), la conductivité du graphite varie, la résistivité varie également, et donc, la résistance variera aussi en fonction des dimensions du capteur. C'est cette propriété que l'on va exploiter afin de créer notre capteur résistif.  

Nous avons également implémenté  un shield sur notre chaine de mesures. Ce dernier a été conçu a l'aide du logiciel KICAD et aura un rôle de conditionneur du signal. Le shield est composé d'un amplificateur transimpédance, d'un module Bluetooth, d'un écran OLED, d'un encodeur rotatoire ainsi que d'une entrée analogique pour le capteur résistif.  

Pour finir, nous avons effectué l'ensemble des tests du circuit sur le logiciel LTSpice (voir [_Rapport LTSpice_](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/8504636d878c9423babecade3b70e7a892836c6b/Rapport_LTSpice.pdf)).  

Nous avons ensuite imprimé notre circuit PCB après validation de l'équipe pédagogique.  

Puis, nous avons utilisé une carte Arduino pour la lecture des mesures et la création des fonctions relatives à l'écran OLED, au module Bluetooth ainsi qu'a l'encodeur rotatoire.  

Ensuite, avec le site MIT App Inventor, nous avons développé une application Android qui a pour but de recevoir des données via Bluetooth.  

Et enfin, nous avons réalisé notre propre banc de test : nous avons effectué un test de rayon de courbure et un test de répétabilité avec deux types de crayons (B, HB).  


---
## 3) Shield PCB

Sur le logiciel KICAD nous avons créé des modèles pour l'amplificateur transimpédance, le module Bluetooth, l'écran OLED et l'encodeur rotatoire. Nous avons ensuite créé ou assigné des empreintes à chaque composante du circuit électronique (amplificateur, Bluetooth, OLED, encodeur rotatoire mais aussi résitances et capacités). Puis, nous avons tracé le chevelu du PCB et enfin nous avons modélisé notre PCB en 3D pour vérifier qu'aucun élément ne se superpose et qu'il n'y aura pas de problème lors de la réalisation du PCB.  



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

Voici notre code Arduino qui permet de :

- mesurer la tension en sortie du circuit transimpédance
- calculer la résistance correspondante du capteur grâce à la tension mesurée (fonction de transfert)
- visualiser ces valeurs (tension et résistance) dans le moniteur série
- afficher ces deux valeurs (tension et résistance) sur l'écran OLED
- envoyer les valeurs de résistance par Bluetooth à l'application APK
- utiliser un encodeur rotatoire pour choisir d'afficher sur l'écran OLED et d'envoyer par Bluetooth les valeurs de résistance en Ω, kΩ ou MΩ  


```
// Pour le Bluetooth
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <string.h>
#define rxPin 11 //Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 //Broche 10 en tant que tx, à raccorder sur TX du HC-05
#define baudrate 9600
#define encoder0PinA  2  //CLK Output A Do not use other pin for clock as we are using interrupt
#define encoder0PinB  3  //DT Output B
#define Switch 5 // Switch connection if available
int value;
int rotation;
int RotPosition = 0;
boolean LeftRight;
float Rs2=0;
volatile unsigned int encoder0Pos = 0;
SoftwareSerial mySerial(rxPin ,txPin); //Définition du software serial

float Vadc;

// Pour le OLED
#include <Adafruit_SSD1306.h>

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Affichage_OLED(float Rs, float Vadc){ 
  byte tailleDeCaractere=2;
  byte numeroDeLigne=1;
  boolean bCouleurInverse = false;
  ecranOLED.clearDisplay();                                   // Effaçage de l'intégralité du buffer
  ecranOLED.setTextSize(tailleDeCaractere);                   // Taille des caractères (1:1, puis 2:1, puis 3:1)
  ecranOLED.setCursor(0, 0);                                  // Déplacement du curseur en position (0,0), c'est à dire dans l'angle supérieur gauche
  ecranOLED.setTextColor(SSD1306_WHITE);                  // Affichage du texte en "blanc" (avec la couleur principale, en fait, car l'écran monochrome peut être coloré)
  ecranOLED.print("V= ");
  ecranOLED.print(Vadc);
  ecranOLED.println(" V");
  ecranOLED.print("R= ");
  ecranOLED.print(Rs);
  bCouleurInverse = !bCouleurInverse;
  ecranOLED.display();                            // Transfert le buffer à l'écran

  // ***********************************************************************
  // Affichage de 8 lignes à couleurs alternées, dans chaque écran successif
  // ***********************************************************************
  
  /*if(bCouleurInverse)
    ecranOLED.setTextColor(SSD1306_BLACK, SSD1306_WHITE);   // Couleur du texte, et couleur du fond
  else
    
  delay(500);*/
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double Rs;
int Vcc=5;
int R1=100000;
int R3=100000;
int R5=10000;
int R2=1000;


void Bluetooth_write(double Rs){
  double Res = Rs;
  mySerial.println(Res);
  delay(500);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mesure(){
  // read the input on analog pin 0:
  double  sensorValue = analogRead(A0);         //on divise par 4 pour être sur une plage de 256 et non une plage de 1024 car l'analogRead donne une valeur entre 0 et 1023
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Vadc = sensorValue * (Vcc / 1023.0);
 
  Rs = ((1+R3/R2)*R1*(1023/Vadc))-R1-R5;
  //Serial.println(Vadc); 
}

// on voit sur le moniteur que Rs varie entre 35000 et 15M environ

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  mySerial.begin(9600);
  ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED);
  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
  rotation = digitalRead(encoder0PinA); 
}


void loop() {
 value = digitalRead(encoder0PinA);
     if (value != rotation){ // we use the DT pin to find out which way we are turning.
     if (digitalRead(encoder0PinB) != value) {  // Clockwise
       RotPosition ++; 
       if (RotPosition==3){
        RotPosition=0;
       }
     } else { //Counterclockwise
       RotPosition--;
       if (RotPosition==-3){
        RotPosition=0;
       }
     }
     rotation = value;
     }
    mesure();
      if (RotPosition==-1){
        //mesure();
        Rs=Rs/1000;
        Bluetooth_write(Rs);  
        Affichage_OLED(Rs, Vadc);
        //Serial.println(Rs);
        ecranOLED.println(" k");
        ecranOLED.display();
     }
      else if (RotPosition==-2){
        //mesure();
        //Serial.println(Rs/1000000);
        Bluetooth_write(Rs/1000000);
        Affichage_OLED(Rs/1000000, Vadc);
        ecranOLED.println(" M");
        ecranOLED.display();
     }
     else if (RotPosition==0){
        //Serial.println(Rs);
      Bluetooth_write(Rs);
      Affichage_OLED(Rs, Vadc); 
     }
      else if (RotPosition==1){
        //mesure();
        Rs=Rs/1000;
        Bluetooth_write(Rs);  
        Affichage_OLED(Rs, Vadc);
        //Serial.println(Rs);
        ecranOLED.println(" k");
        ecranOLED.display();
     }
      else if (RotPosition==2){
        //mesure();
       // Serial.println(Rs/1000000);
        Bluetooth_write(Rs/1000000);
        Affichage_OLED(Rs/1000000, Vadc);
        ecranOLED.println(" M");
        ecranOLED.display();
     }
     else{
      //mesure();
      //Serial.println(Rs);
      Bluetooth_write(Rs);
      Affichage_OLED(Rs, Vadc);  
     }
     //Serial.print("Encoder RotPosition: ");
     //Serial.println(RotPosition);
     
     Serial.println(Rs);
     //Serial.println(Vadc);
     // this will print in the serial monitor.  
}
```


---
## 5) Application Android APK

L'application android développée sur MIT App Inventor sert à:

- Récupérer la valeur de la résistance du capteur graphite (calculée par le code Arduino à partir de la tension mesurée)
- Afficher cette valeur de résistance
- Tracer un graphique qui décrit l'évolution de la résistance du capteur en fonction du temps


### 5.1) MIT App inventor

Le site internet de création d'application [_MIT App Inventor_](https://appinventor.mit.edu/)

### 5.2) Notre application

Interface de l'application sur un smartphone :  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/2fc7368aa926cd5d8d8e4a7a305ebf312bf52df6/Images/Interface_application.JPG)  

Schéma en block du code de l'application :  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/24223030ee5c42ca74b3d679e8572a6390a79d57/Images/Code_application_01.JPG)  
![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/a57c8098e7a8a3ac23fe8205c63536212a115214/Images/Code_application_02.JPG)  


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
Pour y arriver, nous avons créé notre propre banc de test à partir d'un servo-moteur (et son code Arduino), de scotch, de carton et d'un support en rigide. Nous avons agrandi l'aile fixé au servo-moteur grâce à un morceau de carton et nous avons scotché ce servo-moteur à un support rigide que nous avons lui même scotché sur le bord d'un meuble. En ce qui concerne le capteur, nous avons scotché un support rigide sur le bord du même meuble à une petite distance de notre servo-moteur, ce qui nous a permis de positionner les pinces métalliques et notre capteur face à l'aile du servo-moteur qui va effectuer des aller-retours pour que le capteur subisse des cycles d'extension/compression (voir [_Vidéo test de répétabilité_](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/469d8a52910f487a39b89d7652cd1226eb0d3d92/Images/Test_Repetabilite_video.mp4)).  

![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/9a6179c9a64ad83f9c8b5cb9e331d1c981edc935/Images/Test_Repetabilite_01.jpg)  


Après des mesures pour des crayons de type B et des crayons de type HB, nous avons obtenu deux courbes représentant l'évolution de la résistance mesurée par le capteur en fonction du nombre de cyles d'extension/compression effectués.  

![alt text](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/0bd03763ba0da2488beb34199330a152889df189/Images/Graphe_Repetabilite.JPG)  

Code Arduino du servo-moteur:  

```
// Sweep by BARRAGAN
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  for(pos = 30; pos <= 150; pos += 1)  // goes from 30 degrees to 150 degrees
  {                                  // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(5);                       // waits 5ms for the servo to reach the position
  }
  for(pos = 150; pos>=31; pos-=1)     // goes from 150 degrees to 30 degrees
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(5);                       // waits 5ms for the servo to reach the position
  }
} 
```


---
## 7) Datasheet

Datasheet en format pdf à télécharger [_ici_](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/540ff39c7f5d5399cfc770728529d42a2bad8d82/Datasheet/Datasheet_Capteur_papier.pdf).


---
## 8) Information sur les auteurs

Edouard FRANCO / Pablo ALONSO RODRIGUEZ

- edouard.franco@free.fr
- pablo.alonsorgz@gmail.com

Étudiants à l'INSA de Toulouse en 4ème année Génie Physique
