#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
const int RELAY_PIN = 26;
bool isHighTrigger = false;  // CORRECT for LOW trigger relay

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  
  // Start with relay OFF
  digitalWrite(RELAY_PIN, isHighTrigger ? LOW : HIGH);
  
  SerialBT.begin("Smart Light Control");
  Serial.println(" System Ready!");
  Serial.println(" Pair Bluetooth: 'Smart Light Control'");
  Serial.println(" Relay connected to GPIO26");
  Serial.println(" LOW trigger relay confirmed");
  Serial.println("\n Bluetooth Commands:");
  Serial.println("   1 = Turn ON light");
  Serial.println("   0 = Turn OFF light");
  Serial.println("   s = Status check");
  Serial.println("   t = Toggle ON/OFF");
  
  SerialBT.println(" Smart Light Connected!");
  SerialBT.println("Commands: 1=ON, 0=OFF, t=toggle, s=status");
  SerialBT.println("Light is currently: OFF");
}

void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();
    Serial.print(" Received: ");
    Serial.println(cmd);
    
    switch(cmd) {
      case '1':
        digitalWrite(RELAY_PIN, isHighTrigger ? HIGH : LOW);
        SerialBT.println(" Light: ON");
        Serial.println(" Light turned ON");
        break;
        
      case '0':
        digitalWrite(RELAY_PIN, isHighTrigger ? LOW : HIGH);
        SerialBT.println(" Light: OFF");
        Serial.println(" Light turned OFF");
        break;
        
      case 't':
        digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN));
        if (digitalRead(RELAY_PIN) == (isHighTrigger ? HIGH : LOW)) {
          SerialBT.println(" Toggled: Light is ON");
          Serial.println(" Toggled to ON");
        } else {
          SerialBT.println(" Toggled: Light is OFF");
          Serial.println(" Toggled to OFF");
        }
        break;
        
      case 's':
        if (digitalRead(RELAY_PIN) == (isHighTrigger ? HIGH : LOW)) {
          SerialBT.println("Status: Light is ON");
        } else {
          SerialBT.println("Status: Light is OFF");
        }
        break;
        
      default:
        SerialBT.println(" Invalid command");
        SerialBT.println(" Valid: 1=ON, 0=OFF, t=toggle, s=status");
        break;
    }
  }
}
