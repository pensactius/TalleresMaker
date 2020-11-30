int pinVT = 8;
int pinA = 2;
int pinB = 3;
int pinC = 11;
int pinD = 12;

void setup() {
  Serial.begin (9600);

  pinMode (pinVT, INPUT);
  pinMode (pinA, INPUT);
  pinMode (pinB, INPUT);
  pinMode (pinC, INPUT);
  pinMode (pinD, INPUT);
}

void loop() {

  if (digitalRead(pinVT) )

  {
    Serial.print ("data available \t");
    if (digitalRead(pinA)) {
      Serial.print ("pressed button A");

    }
    if (digitalRead(pinB)) {
      Serial.print ("pressed button B");

    }
    if (digitalRead(pinC)) {
      Serial.print ("pressed button C");

    }
    if (digitalRead(pinD)) {
      Serial.print ("pressed button D");
    }

    Serial.println ("\t");
  }
}
