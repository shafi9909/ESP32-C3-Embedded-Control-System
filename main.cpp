/* 
ESP32-C3 Embedded Control System
Kombination aus:
- Ampelsteuerung
- Potentiometer-Auswertung
- Ultraschallsensor
- PWM-Dimmung
*/

// =====================
// PIN-DEFINITION
// =====================

int ledGruen = 10;
int ledGelb  = 2;
int ledRot   = 3;

int potiPin = 0;

int trigPin = 19;
int echoPin = 18;

long laufzeit;
int entfernung;

int helligkeit = 0;

// =====================
// SETUP
// =====================

void setup() {

  Serial.begin(9600);

  pinMode(ledGruen, OUTPUT);
  pinMode(ledGelb, OUTPUT);
  pinMode(ledRot, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// =====================
// LOOP
// =====================

void loop() {

  // -------------------
  // 1️⃣ AMPELSTEUERUNG
  // -------------------

  digitalWrite(ledRot, HIGH);
  delay(3000);

  digitalWrite(ledGelb, HIGH);
  delay(3000);

  digitalWrite(ledRot, LOW);
  digitalWrite(ledGelb, LOW);
  digitalWrite(ledGruen, HIGH);
  delay(5000);

  digitalWrite(ledGruen, LOW);
  digitalWrite(ledGelb, HIGH);
  delay(3000);
  digitalWrite(ledGelb, LOW);

  // -------------------
  // 2️⃣ POTENTIOMETER
  // -------------------

  int sensorwert = analogRead(potiPin);
  Serial.print("Poti-Wert: ");
  Serial.println(sensorwert);

  // LED-Anzeige je nach Bereich
  if(sensorwert < 1365){
    digitalWrite(ledGruen, HIGH);
    digitalWrite(ledGelb, LOW);
    digitalWrite(ledRot, LOW);
  }
  else if(sensorwert < 2730){
    digitalWrite(ledGruen, LOW);
    digitalWrite(ledGelb, HIGH);
    digitalWrite(ledRot, LOW);
  }
  else{
    digitalWrite(ledGruen, LOW);
    digitalWrite(ledGelb, LOW);
    digitalWrite(ledRot, HIGH);
  }

  delay(1000);

  // -------------------
  // 3️⃣ ULTRASCHALL
  // -------------------

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  laufzeit = pulseIn(echoPin, HIGH);
  entfernung = laufzeit * 0.017;

  Serial.print("Entfernung: ");
  Serial.println(entfernung);

  if(entfernung < 30){
    digitalWrite(ledRot, HIGH);
  }

  delay(1000);

  // -------------------
  // 4️⃣ PWM DIMMEN
  // -------------------

  for(int helligkeit = 0; helligkeit <= 255; helligkeit++){
    analogWrite(ledGruen, helligkeit);
    delay(10);
  }

  for(int helligkeit = 255; helligkeit >= 0; helligkeit--){
    analogWrite(ledGruen, helligkeit);
    delay(10);
  }

}
