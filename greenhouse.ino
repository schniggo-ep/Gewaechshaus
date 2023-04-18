#include <DHT.h>

 int messwert1=0;

 int messwert2=0;

 int prozent=0;

void setup() {
  // Initialisiere die Pins als Ausgänge
  pinMode(pumpPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // Starte die serielle Kommunikation
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

 // Definiere die Pins
const int sensorPin = A0;    // Analoger Pin für den Temperatursensor
const int pumpPin = 9;       // Digitaler Pin für die Wasserpumpe
const int ledPin = 13;       // Digitaler Pin für die LED

// Definiere die Schwellenwerte
const int temperatureThreshold = 25; // Temperatur-Schwellenwert in Grad Celsius
const int moistureThreshold = 500;   // Feuchtigkeits-Schwellenwert für die Bewässerung

  // Lese den Temperatursensor aus
  int sensorValue = analogRead(sensorPin);

  // Konvertiere den Rohwert in Grad Celsius
  float temperature = sensorValue * 0.48828125;

  // Schreibe die Temperatur in die serielle Schnittstelle
  Serial.print("Temperatur: ");
  Serial.print(temperature);
  Serial.println("°C");
  // Überprüfe, ob die Temperatur den Schwellenwert überschreitet
  if (temperature > temperatureThreshold) {
    // Schalte die LED ein
    digitalWrite(ledPin, HIGH);
    // Überprüfe, ob die Bodenfeuchtigkeit niedrig ist
    if (messwert1&&messwert2 < moistureThreshold) {
      // Schalte die Wasserpumpe ein
      digitalWrite(pumpPin, HIGH);
      // Warte für 5 Sekunden
      delay(5000);
      // Schalte die Wasserpumpe aus
      digitalWrite(pumpPin, LOW);
    }
  } else {
    // Schalte die LED aus
    digitalWrite(ledPin, LOW);
  }
  // Warte für eine Sekunde
  delay(1000);
}
