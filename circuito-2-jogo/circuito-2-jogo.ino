int leds[] = {2,3,4,5};
int botoes[] = {6,7,8,9};

int sequencia[100];

int fase = 0;

void setup() {

  Serial.begin(9600);
  for(int i = 0; i < 4; i++) {

    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(A0));
  novaFase();
}


void loop() {

  mostrarSequencia();
  for(int i = 0; i < fase; i++) {

    int jogada = esperarBotao();
    Serial.print("Jogador apertou: ");
    Serial.println(jogada);
    Serial.print("Esperado: ");
    Serial.println(sequencia[i]);

    if(jogada != sequencia[i]) {

      perdeu();
      return;
    }

  }
  Serial.println("PASSOU!");
  delay(1000);
  novaFase();
}

void novaFase() {
  sequencia[fase] = random(0,4);
  fase++;
  Serial.println();
  Serial.print("FASE ");
  Serial.println(fase);
}

void mostrarSequencia() {

  Serial.println("Sequencia:");

  delay(500);

  for(int i = 0; i < fase; i++) {

    int cor = sequencia[i];
    digitalWrite(leds[cor], HIGH);
    delay(500);
    digitalWrite(leds[cor], LOW);
    delay(250);
  }
  Serial.println("Sua vez!");
}

int esperarBotao() {

  while(true) {

    for(int i = 0; i < 4; i++) {
      if(digitalRead(botoes[i]) == LOW) {

        digitalWrite(leds[i], HIGH);
        delay(300);
        digitalWrite(leds[i], LOW);
        while(digitalRead(botoes[i]) == LOW);

        return i;
      }
    }
  }
}

void perdeu() {

  Serial.println("ERROU!");
  Serial.println("GAME OVER");

  for(int i = 0; i < 3; i++) {

    for(int j = 0; j < 4; j++) {
      digitalWrite(leds[j], HIGH);
    }

    delay(300);

    for(int j = 0; j < 4; j++) {
      digitalWrite(leds[j], LOW);
    }
    delay(300);
  }
  fase = 0;
  novaFase();
}
