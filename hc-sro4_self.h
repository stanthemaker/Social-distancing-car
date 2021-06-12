#define trigPin 7
#define echoPin 6
void HC_sro4_init(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INTPUT);
}

int get_distance(){
    Serial.println("in function");
    long duration = 0 ;
    int distance_cm = 0;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance_cm = duration * 0.034 /2;
    return distance_cm;
}
