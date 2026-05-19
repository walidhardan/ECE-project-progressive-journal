int buttonPin = 2;
int ledPin = 13;

unsigned long startTime;
unsigned long endTime;
unsigned long reactionTime;

void setup() {

  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

  randomSeed(analogRead(0));
}

void loop() {

  digitalWrite(ledPin, LOW);

  Serial.println("Get ready...");

  int waitTime = random(2000, 5000);

  delay(waitTime);

  digitalWrite(ledPin, HIGH);

  startTime = millis();

  while (digitalRead(buttonPin) == HIGH) {

  }

  endTime = millis();

  reactionTime = endTime - startTime;

  digitalWrite(ledPin, LOW);

  Serial.print("Reaction Time: ");

  Serial.print(reactionTime);

  Serial.println(" ms");

  delay(3000);
}
