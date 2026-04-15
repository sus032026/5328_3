int ledPin = 11; // Define the LED pin at D5
void setup () {
  pinMode (ledPin, OUTPUT); // initialize ledpin as an output.
}
void loop () {
  for (int value = 0; value<255; value = value + 1) {
  analogWrite (ledPin, value); // LED lights gradually light up
  delay (5); // delay 5 ms
  }
  for (int value = 255; value>0; value = value-1) {
  analogWrite (ledPin, value); // LED gradually goes out
  delay (5); // delay 5 ms
  }
}