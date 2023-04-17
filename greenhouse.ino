#include <DHT.h>

 int messwert1=0;

 int messwert2=0;

 int prozent=0;

void setup() {

  Serial.begin(9600);

}

 

void loop() {

 

  messwert1= 100-(analogRead(A0)/10.24); //Analogwert des Feuchtigkeitssensors ausgeben

  messwert2= 100- (analogRead(A1)/10.24);  //Analogwert in % umwandeln (minimale Feuchte = 1024)

 

  //Ausgabe

  Serial.print("Große Pflanze: \n");

  Serial.print("Feuchtigkeit : ");

  Serial.print(messwert1);

  Serial.println("%");

 

  Serial.print("Kleine Pflanze: \n");

  Serial.print("Feuchtigkeit : ");

  Serial.print(messwert2);

  Serial.println("%");

  Serial.println("\n");

 

  delay(8000);

  }
