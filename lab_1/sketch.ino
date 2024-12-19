const int led1 = 6;
const int led2 = 7; 
const int buttonPin = 5; 

bool isBlinking = false;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonState == HIGH) {
      isBlinking = !isBlinking;
    }
  }
  lastButtonState = buttonState;

  if (isBlinking) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(500);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(500);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}