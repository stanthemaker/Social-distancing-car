#define trigPin 7
#define echoPin 6
void HC_sro4_init(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, OUTPUT);
}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
long get_distance(){
    long duration, distance_cm;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance_cm = microsecondsToCentimeters(duration);
    Serial.print("cm :");
    Serial.println(distance_cm);
    return distance_cm;
}
