
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLJ7fHNzIH"
#define BLYNK_DEVICE_NAME "OTA"
#define BLYNK_FIRMWARE_VERSION        "0.1.1"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
#define led 12
int st;
BlynkTimer timer;

void ledBlink()
{
  if (st == 0)
    {
      digitalWrite(led, HIGH);
      st=1;
      Serial.println(st);
    }
  else
    {
      digitalWrite(led, LOW);
      st=0;
      Serial.println(st);
    }
}



void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(led,OUTPUT);
  BlynkEdgent.begin();
  timer.setInterval(100L, ledBlink);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
