// Pour le Bluetooth
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <string.h>
#define rxPin 11 //Broche 7 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 //Broche 6 en tant que tx, à raccorder sur TX du HC-05
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


// Pour le OLED
#include <Adafruit_SSD1306.h>

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

void Affichage_OLED(float Rs){ 
  byte tailleDeCaractere=2;
  byte numeroDeLigne=1;
  boolean bCouleurInverse = false;
  ecranOLED.clearDisplay();                                   // Effaçage de l'intégralité du buffer
  ecranOLED.setTextSize(tailleDeCaractere);                   // Taille des caractères (1:1, puis 2:1, puis 3:1)
  ecranOLED.setCursor(0, 0);                                  // Déplacement du curseur en position (0,0), c'est à dire dans l'angle supérieur gauche
  ecranOLED.setTextColor(SSD1306_WHITE);                  // Affichage du texte en "blanc" (avec la couleur principale, en fait, car l'écran monochrome peut être coloré)
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

//

float Rs;
int Vcc=5;
int R1=100000;
int R3=100000;
int R5=10000;
int R2=1000;


void Bluetooth_write(float Rs){
  mySerial.println(Rs);
}


void mesure(){
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0)/4;                   //on divise par 4 pour être sur une plage de 256 et non une plage de 1024 car l'analogRead donne une valeur entre 0 et 1023
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  double Vadc = sensorValue * (5.0 / 1023.0);
  
  Rs = (1+R3/R2)*R1*(Vcc/Vadc)-R1-R5;
  Serial.println(Rs); 
  
  /*if (value == rotation){
    Bluetooth_write(Rs);  
    Affichage_OLED(Rs);
  }*/
}


// on voit sur le moniteur que Rs varie entre 35000 et 15M environ

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
     if (value != rotation){ // we use the DT pin to find out which way we turning.
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
        Affichage_OLED(Rs);
        Serial.println(Rs);
        ecranOLED.println(" k");
        ecranOLED.display();
     }
      else if (RotPosition==-2){
        //mesure();
        Serial.println(Rs/1000000);
        Bluetooth_write(Rs/1000000);
        Affichage_OLED(Rs/1000000);
        ecranOLED.println(" M");
        ecranOLED.display();
     }
     else if (RotPosition==0){
        Serial.println(Rs);
      Bluetooth_write(Rs);
      Affichage_OLED(Rs); 
     }
      else if (RotPosition==1){
        //mesure();
        Rs=Rs/1000;
        Bluetooth_write(Rs);  
        Affichage_OLED(Rs);
        Serial.println(Rs);
        ecranOLED.println(" k");
        ecranOLED.display();
     }
      else if (RotPosition==2){
        //mesure();
        Serial.println(Rs/1000000);
        Bluetooth_write(Rs/1000000);
        Affichage_OLED(Rs/1000000);
        ecranOLED.println(" M");
        ecranOLED.display();
     }
     else{
      //mesure();
      Serial.println(Rs);
      Bluetooth_write(Rs);
      Affichage_OLED(Rs);  
     }
     Serial.print("Encoder RotPosition: ");
     Serial.println(RotPosition);
     }
  

     //Serial.println(Rs);
     // this will print in the serial monitor.
 
