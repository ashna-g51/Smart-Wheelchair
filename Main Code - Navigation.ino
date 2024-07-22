const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 6; 

long duration;
int distance;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
}
void loop() {

  digitalWrite(trigPin, LOW);
  delay(20);

  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance != 0 && distance < 20)
  {
    Serial.println("TOO CLOSE BACK OFF");
    tone(buzzer, 1000); 
    delay(1000);        
    noTone(buzzer);     
    delay(1000);        
  }
}
