#include <SoftwareSerial.h>

SoftwareSerial espSerial(2, 3); //  визначаємо RX, TX для звя'зку з esp32
int ldrPin = A1; // задаємо пін для датчика

void setup() {
  Serial.begin(9600); // ініціалізуємо звя'зок з пк через серіал порт
  espSerial.begin(9600); // ініціалізуємо звя'зок через серіал порт до ESP32
  pinMode(A1, INPUT); // Встановлюємо A1 як вхід
}

void loop() {
  int lightLevel = analogRead(ldrPin); // зчитуємо значення датчика
  
  // Відправляємо дані в ESP32
  espSerial.println(lightLevel);
  
  // Виводимо дані на консоль пк
  Serial.print("Light Level: ");
  Serial.println(lightLevel);
  
  delay(4000); // Оновлення значення раз на 4 секунди
}