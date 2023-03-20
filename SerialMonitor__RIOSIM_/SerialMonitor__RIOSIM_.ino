void setup() {
  Serial.begin(115200);
  DDRB = B11111111;
  PORTB = B00000000;
}

void loop() {
  Serial.println("Enter data:");
  while (Serial.available() == 0) {}     //wait for data available
  String teststr = Serial.readString();  //read until timeout
  teststr.trim(); // remove any \r \n whitespace at the end of the String
  if (teststr == "clear") {
    PORTB = B00000000;
    Serial.println(teststr);
  }
  if (teststr == "red") {
    PORTB = B00010000;
    Serial.println(teststr);
  }
  if (teststr == "blue") {
    PORTB = B00100000;
    Serial.println(teststr);
  }
  if (teststr == "yellow") {
    PORTB = B00110000;
    Serial.println(teststr);
  }
  if (teststr == "purple") {
    PORTB = B01000000;
    Serial.println(teststr);
  }
  if (teststr == "cone") {
    PORTB = B01010000;
    Serial.println(teststr);
  }
  if (teststr == "cube") {
    PORTB = B01100000;
    Serial.println(teststr);
  }
  if (teststr == "fire") {
    PORTB = B01110000;
    Serial.println(teststr);
  }
}
