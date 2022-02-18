#include <Wire.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial
#define BUTTON_PIN 21
WidgetMap myMap(V1);

int lastState = HIGH; // the previous state from the input pin
int currentState;     // the current reading from the input pin

char auth[] = "5ujUu4u2SRlQldW4q2z1NamydT-BEsG2"; //Auth code sent via Email
const char *ssid = "Fadh";
const char *pass = "12345678";

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
