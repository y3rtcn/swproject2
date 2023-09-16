#define PIN_LED 13
unsigned int count, toggle;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(115200);
}
void loop() {
    // turn the LED on (HIGH is the voltage level)
    Serial.println(++count);
    digitalWrite(PIN_LED, HIGH);
    delay(1000); // wait for a second
    // turn the LED off by making the voltage LOW

    digitalWrite(PIN_LED, LOW); 
    delay(1000); // wait for a second
}
