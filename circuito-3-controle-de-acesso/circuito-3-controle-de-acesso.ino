#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

int ledVerde = 6;
int ledVermelho = 7;

// UID autorizado
String uidAutorizado = "DA 97 38 85";

void setup() {

  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Serial.println("Aproxime o cartao...");
}

void loop() {

  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  String uid = "";

  for (byte i = 0; i < rfid.uid.size; i++) {

    if (rfid.uid.uidByte[i] < 0x10)
      uid += "0";

    uid += String(rfid.uid.uidByte[i], HEX);

    if (i != rfid.uid.size - 1)
      uid += " ";
  }

  uid.toUpperCase();

  Serial.print("UID: ");
  Serial.println(uid);

  // Apaga LEDs antes
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);

  if (uid == uidAutorizado) {

    Serial.println("ACESSO LIBERADO");

    digitalWrite(ledVerde, HIGH);
    delay(3000);
    digitalWrite(ledVerde, LOW);

  } else {

    Serial.println("ACESSO NEGADO");

    digitalWrite(ledVermelho, HIGH);
    delay(3000);
    digitalWrite(ledVermelho, LOW);
  }

  rfid.PICC_HaltA();
}