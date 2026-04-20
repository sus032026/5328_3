#define BLYNK_TEMPLATE_ID "TMPL4619HEnB0"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "eb7YdnbGsEyLqpVkMEYUMtvKDyEl"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Anker";
char pass[] = "7890543";

// Використовуємо піни 16 та 17  для серіал з'єднання
#define RX2 16
#define TX2 17

void setup() {
  
  Serial.begin(115200); // ініціалізуємо з'єднання через серіал порт з пк

  Serial2.begin(9600, SERIAL_8N1, RX2, TX2); // ініціалізуємо з'єднання з Ардуіно через серіал порт
  
  Blynk.begin(auth, ssid, pass); //Встановлюємо з'єднання з інтернетом та сервером
}

void loop() {
  Blynk.run(); //Підтримуємо зв'язок з сервером, щоб пристрій не відвалився від сервера
  
  //ESP32 перевіряє, чи прислала Arduino  дані з датчика
  if (Serial2.available()) {
    String data = Serial2.readStringUntil('\n');
    int lightValue = data.toInt();
    
    // Відправляємо значення на віртуальний пін V1 у Blynk
    Blynk.virtualWrite(V1, lightValue);
    
    // Відправляємо значення серіал порт
    Serial.print("Received from Uno: ");
    Serial.println(lightValue);
  }
}