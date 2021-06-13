#define trigPin 7
#define echoPin 6
#define arraysize 121
void HC_sro4_init(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int get_distance(){
    long duration = 0 ;
    int distance_cm = 0;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance_cm = duration * 0.034 /2;
    // Serial.print(", distance = ");
    // Serial.println(distance_cm);
    return distance_cm;
}
void print_picture(int * picture){
    for (int i = 0;i < arraysize; i++){
        Serial.print(i+30);
        Serial.print("*.");
        Serial.print(picture[i]);
        Serial.print(" ");
        if (!(i % 20) and (i)){
            Serial.println();
        }
    }
    Serial.println();
}