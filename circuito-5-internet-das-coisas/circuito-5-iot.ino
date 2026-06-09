#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);

// RX, TX

int led = 6;

char comando;

void setup() {

  pinMode(led, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.println("Bluetooth iniciado");
  Serial.println("Envie 1 para ligar");
  Serial.println("Envie 0 para desligar");
}

void loop() {

  if(bluetooth.available()) {

    comando = bluetooth.read();

    // mostra no Monitor Serial
    Serial.print("Recebido: ");
    Serial.println(comando);

    // liga LED
    if(comando == '1') {

      digitalWrite(led, HIGH);

      Serial.println("LED LIGADO");
    }

    // desliga LED
    if(comando == '0') {

      digitalWrite(led, LOW);

      Serial.println("LED DESLIGADO");
    }
  }
}