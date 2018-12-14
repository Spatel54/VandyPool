const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
 
void setup() 
{
   Serial.begin(9600);
}
 
 
void loop() 
{
   delay(.01);
   Serial.println(analogRead(0));
}
