int verde = 8;
int amarelo = 9;
int vermelho = 10;
int buzzer = 6;

void setup() {

  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  // VERDE
  digitalWrite(verde, HIGH);
  delay(5000);
  digitalWrite(verde, LOW);

  // AMARELO
  digitalWrite(amarelo, HIGH);
  delay(2000);
  digitalWrite(amarelo, LOW);

  // VERMELHO
  digitalWrite(vermelho, HIGH);

  tone(buzzer, 1000); // som
  delay(5000);

  noTone(buzzer);

  digitalWrite(vermelho, LOW);
}