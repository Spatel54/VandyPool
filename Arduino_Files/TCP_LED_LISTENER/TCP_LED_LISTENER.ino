// Phone control built in led.

#include <ESP8266WiFi.h>
// "vummiv"
// "David's iPhone"
// "projectwifi"

const char* ssid = "vummiv";
const char* password = "";
const int ledPin = 2;
WiFiServer server(1337);

void printWiFiStatus();

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Configure GPIO2 as OUTPUT.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // Initialize LED HIGH = OFF

  // Start TCP server.
  server.begin();
}

void loop() {
  //
  delay(100);
  //
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to Wifi...");
  
    while (WiFi.status() != WL_CONNECTED) {
      blinkLED();
    }
    // Print the new IP to Serial.
    printWiFiStatus();
  }

  
  WiFiClient client = server.available();
  if (client) {
    
    Serial.println("Client connected.");
    while (client.connected()) {
      
      if (client.available()) {
        
        char command = client.read();
        Serial.println(command);
        if (command == 'H') {
          digitalWrite(LED_BUILTIN, LOW);     // LED LOW IS ON
          Serial.println("Led is now on.");
          client.print(1);
        }
        else if (command == 'L') {
          digitalWrite(LED_BUILTIN, HIGH);    // LED HIGH IS OFF
          Serial.println("Led is now off.");
          client.print(0);
        }
      }
    }
    
    Serial.println("Client disconnected.");
    client.stop();
  }  
  blinkLED();
}
void printWiFiStatus() {
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void blinkLED() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
}
