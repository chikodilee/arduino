int echoPin = 4;
int trigPin = 7;
int dt = 50;
int pulseDistTime;
float soundSpeed = 0.013515;
float totDist;
float distToTarget;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(echoPin, OUTPUT);
  pinMode(trigPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(echoPin, LOW);
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(dt);
  digitalWrite(echoPin, LOW);
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(dt);

  pulseDistTime = pulseIn(trigPin, HIGH);
  //Serial.println(pulseDistTime);
  totDist = 0.013515 * pulseDistTime;
  distToTarget = totDist/2.;
Serial.print("The measured distance to target is: ");
Serial.print(distToTarget);
Serial.println(" in.");
  delay(dt);

}
