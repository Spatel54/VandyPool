#include <SD.h>                // need to include the SD library
#define SD_ChipSelectPin 4
//#define SD_ChipSelectPin 4 10 53 //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
TMRpcm audio;

int audiofile = 0;
unsigned long i = 0;
bool recmode = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Board Reset");
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);

  SD.begin(SD_ChipSelectPin);
  Serial.println("SD setup");
  audio.CSPin = SD_ChipSelectPin;
  Serial.println("AudioPin Setup");
}

void loop() {
  i++;
  String record1 = (String(i) + ".wav").c_str();
  String record2 = (String(i) + "b.wav").c_str();
  delay(1000);

  
  Serial.print("Beginning recording " + String(i) + "...");
  digitalWrite(LED_BUILTIN, HIGH);

  audio.startRecording((String(i) + ".wav").c_str(), 16000, A0);
  delay(10000);
  audio.startRecording((String(i) + "b.wav").c_str(), 16000, A0);
  digitalWrite(LED_BUILTIN, LOW);
  audio.stopRecording((String(i) + ".wav").c_str());

  audio.stopRecording((String(i) + ".wav").c_str());
  Serial.println("Ended recording");
}

void record(String recName) {

}
