/*
  Tennisplatzbewässerung

  Achtung:
  beim Übertragen des Programmes müssen die beiden Pulldownwiderstände an PIN 1 und 0 (1k2 Ohm) vom Arduino getrennt sein!!!

  die Taster 1 bis 6 werden den Schaltern an Tennisplätzen zugeordnet. Die Ventile 1 bis 6 werden den jeweiligen Ventilrelais zugeordnet.
  Über den Taster 0 werden sequentiel Platz 1 bis 6 für jeweils 3 Minuten bewässert.
  Der Taster 1 bis 6 haben Vorrang zum Taster 0

  Reset ist Ausschalter

  LED zeigt die Betriebsart an
  Einzelbetrieb=Ständig an
  Sequentiell Blinken 1s

  Version b
  Umlegung der I/O werden unverträglichkeit Pin 13 mit Relaisausgang
  Realisierung des Meldeausgangs Pin 13

  Version c - die Ventilausgänge wurden invertiert
  Version d - schnellere Abfrage der Tasten

 by MÖM 22.07.2018
 
*/

unsigned long tsoll = 180000;  // vorgegebene Bewässerungszeit in ms (180000 = 3 Minuten)
const int flash = 1000;  // Richtzeit in ms (1000)

// Digitaleingänge

// Pulldownwiderstände Eingänge 0 und 1 mit 1k2 Ohm Rest 10kOhm

const int tasters = 0;   // sequenz an
const int taster1 = 1;   // Platz 1 bis 6 an
const int taster2 = 2;
const int taster3 = 3;
const int taster4 = 4;
const int taster5 = 5;
const int taster6 = 6;

const int led = 13;     // Statusled

const int ventil1 = 7; //Digitalausgänge
const int ventil2 = 8;
const int ventil3 = 9;
const int ventil4 = 10;
const int ventil5 = 11;
const int ventil6 = 12; 

unsigned long tstart = 0; // Zeit Bewässerungsbeginn

void setup() {

  pinMode (tasters, INPUT);
  pinMode (taster1, INPUT);
  pinMode (taster2, INPUT);
  pinMode (taster3, INPUT);
  pinMode (taster4, INPUT);
  pinMode (taster5, INPUT);
  pinMode (taster6, INPUT);

  pinMode(led, OUTPUT);
  pinMode(ventil1, OUTPUT);
  pinMode(ventil2, OUTPUT);
  pinMode(ventil3, OUTPUT);
  pinMode(ventil4, OUTPUT);
  pinMode(ventil5, OUTPUT);
  pinMode(ventil6, OUTPUT);

  digitalWrite(ventil1, HIGH);
  digitalWrite(ventil2, HIGH);
  digitalWrite(ventil3, HIGH);
  digitalWrite(ventil4, HIGH);
  digitalWrite(ventil5, HIGH);
  digitalWrite(ventil6, HIGH);
}
void loop() {

//Variablen Tastendruck ( 0 oder 1)
int zustands = digitalRead(tasters); // sequenz
int zustand1 = digitalRead(taster1); // Platz 1 bis 6
int zustand2 = digitalRead(taster2);
int zustand3 = digitalRead(taster3);
int zustand4 = digitalRead(taster4);
int zustand5 = digitalRead(taster5);
int zustand6 = digitalRead(taster6);


  // Bedingungen Ventil 1
    if (zustand1 > 0) 
    {tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil1, LOW);
      digitalWrite(led, HIGH);}
      digitalWrite(ventil1, HIGH);
      digitalWrite(led, LOW);
      lesen();
      }
      
  // Bedingungen Ventil 2
     if (zustand2 > 0)
    {tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil2, LOW);
      digitalWrite(led, HIGH);}
      digitalWrite(ventil2, HIGH);
      digitalWrite(led, LOW);
      lesen();
      }

  // Bedingungen Ventil 3
      if (zustand3 > 0)
    {tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil3, LOW);
      digitalWrite(led, HIGH);}
      digitalWrite(ventil3, HIGH);
      digitalWrite(led, LOW);
      lesen();
      }

  // Bedingungen Ventil 4
      if (zustand4 > 0)
    {tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil4, LOW);
      digitalWrite(led, HIGH);}
      digitalWrite(ventil4, HIGH);
      digitalWrite(led, LOW);
      lesen();
      }

  // Bedingungen Ventil 5
      if (zustand5 > 0)
    {tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil5, LOW);
      digitalWrite(led, HIGH);}
      digitalWrite(ventil5, HIGH);
      digitalWrite(led, LOW);
      lesen();
      }

  // Bedingungen Ventil 6
      if (zustand6 > 0)
    {tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil6, LOW);
      digitalWrite(led, HIGH);}
      digitalWrite(ventil6, HIGH);
      digitalWrite(led, LOW);
      lesen();
      }
      
// Bedingungen Sequenz
      if (zustands > 0) 
    {tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil1, LOW);
      ledblink();}
      digitalWrite(ventil1, HIGH);

      tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil2, LOW);
      ledblink();}
      digitalWrite(ventil2, HIGH);

      tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil3, LOW);
      ledblink();}
      digitalWrite(ventil3, HIGH);

      tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil4, LOW);
      ledblink();}
      digitalWrite(ventil4, HIGH);

      tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil5, LOW);
      ledblink();}
      digitalWrite(ventil5, HIGH);

      tstart = millis();
      while (millis() < (tstart + tsoll))
      {digitalWrite(ventil6, LOW);
      ledblink();}
      digitalWrite(ventil6, HIGH);
      }
      lesen();
}    


// Blinken für Sequntielle Bewässerung
void ledblink(){
  digitalWrite(led, HIGH);
  delay (flash);
  digitalWrite(led, LOW);
  delay (flash);  
}


void lesen(){
  //Variablen Tastendruck ( 0 oder 1)
int zustands = digitalRead(tasters); // sequenz
int zustand1 = digitalRead(taster1); // Platz 1 bis 6
int zustand2 = digitalRead(taster2);
int zustand3 = digitalRead(taster3);
int zustand4 = digitalRead(taster4);
int zustand5 = digitalRead(taster5);
int zustand6 = digitalRead(taster6);
}


