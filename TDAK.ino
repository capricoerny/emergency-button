#include <Wire.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial
#define BUTTON_PIN 21

int lastState = HIGH;
int currentState;

char auth[] = "Auth code yang dikirm ke email pendaftaran";
const char *ssid = "Nama Wifi";
const char *pass = "Password";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}
void loop() {
  // put your main code here, to run repeatedly:
  currentState = digitalRead(BUTTON_PIN);
  Blynk.run();

  if(lastState == LOW && currentState == HIGH)
  {
  Blynk.notify("TOLONG!");
  }
  lastState = currentState;
}
