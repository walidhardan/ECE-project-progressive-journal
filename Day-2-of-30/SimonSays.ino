int num[3] = {2, 4, 6};
int buttonPins[3] = {8, 12, 13};
int order[5];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(num[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(A0));

}

void loop() {
  delay(2000);

  // pattern
  for (int i = 0; i < 5; i++) {

    int x = num[random(3)];

    order[i] = x;

    digitalWrite(x, HIGH);
    delay(400);

    digitalWrite(x, LOW);
    delay(250);
  }

  // player input
  for (int i = 0; i < 5; i++) {

    int pressedButton = -1;

    while (pressedButton == -1) {
      for (int j = 0; j < 3; j++) {
        if (digitalRead(buttonPins[j]) == LOW) {

          pressedButton = num[j];

          delay(200);

        }
      }
    }
  //check
    if (pressedButton == order[i]) {

      Serial.println("Correct");

    }
    else {

      Serial.println("Wrong");

      // flash for wrong
      for (int k = 0; k < 3; k++) {
        digitalWrite(num[k], HIGH);
      }

      delay(1000);

      for (int k = 0; k < 3; k++) {
        digitalWrite(num[k], LOW);
      }

      while (true) {
      }
    }
  }

  Serial.println("You Win!");

  delay(2000);

}
