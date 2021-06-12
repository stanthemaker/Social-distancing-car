#define trigPin 7
#define echoPin 6
void HC_sro4_init(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int get_distance(int i){
    long duration = 0 ;
    int distance_cm = 0;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance_cm = duration * 0.034 /2;
    Serial.print("angle = ");
    Serial.print(i);
    Serial.print(", distance = ");
    Serial.println(distance_cm);
    return distance_cm;
}
