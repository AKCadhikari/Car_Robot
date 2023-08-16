 pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);

  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);

  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);

}


int maxspeed = 100;

void loop() {
  int vL = analogRead(A0);
  int vR = analogRead(A1);
  Serial.print(vL);
  Serial.print("_");
  Serial.println(vR);

  int mL = 0;
  int mR = 0;

  if (vL > 400) {
    mL = -maxpower;
    mR = maxpower;
  } else if (vR > 400) {
    mL = maxpower;
    mR = -maxpower;
  } else {
    mL = maxpower;
    mR = maxpower; 
  }
}


void mpower(int m1, int m2) {

  if (m1 > 0) {
    digitalWrite(inL1, HIGH);//Direction F
    digitalWrite(inL2, LOW);
  } else {
    digitalWrite(inL1, LOW);//Direction B
    digitalWrite(inL2, HIGH);
    m1 = m1 * -1; //Value to possitive
  }
  analogWrite(enL, m1); //Speed Write as PWM


  if (m2 > 0) {
    digitalWrite(inR1, HIGH);//Direction F
    digitalWrite(inR2, LOW);
  } else {
    digitalWrite(inR1, LOW);//Direction B
    digitalWrite(inR2, HIGH);
    m2 = m2 * -1; //Value to possitive
  }
  analogWrite(enR, m2); //Speed Write as PWM



}
