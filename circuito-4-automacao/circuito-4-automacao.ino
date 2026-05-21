int trig = 9;
int echo = 10;

int led = 6;
int buzzer = 7;

long duracao;
int distancia;

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Envia pulso ultrassônico
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  // Recebe o eco
  duracao = pulseIn(echo, HIGH);

  // Calcula distância
  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Detecta presença
  if (distancia < 15) {

    digitalWrite(led, HIGH);

    tone(buzzer, 1000);

  } else {

    digitalWrite(led, LOW);

    noTone(buzzer);
  }

  delay(200);
}