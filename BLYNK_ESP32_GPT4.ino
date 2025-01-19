#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "e-xeevx4vuc2lqzF1CEX0tN4d7FrsaII";  // Your Blynk authentication token

char ssid[] = "IOBM_STUDENTS";   // Your WiFi SSID
char pass[] = "iobm12345@#";  // Your WiFi password

int ledPin = 5;  // Pin connected to the LED

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Blynk.run();
}

// Blynk virtual pin handler
BLYNK_WRITE(V0)
{
  int ledValue = param.asInt();  // Get value from Blynk app (0 or 1)
  
  if (ledValue == 1)
  {
    digitalWrite(ledPin, HIGH);  // Turn LED ON
    Serial.println("LED is ON");
  }
  if(ledValue == 0)
  {
    digitalWrite(ledPin, LOW);  // Turn LED OFF
    Serial.println("LED is OFF");
  }
}
