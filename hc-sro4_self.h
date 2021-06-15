#define trigPin 7
#define echoPin 6
#define arraysize 121
#define start_angle 30
#define end_angle 150
extern int picture[];
class Person{
    public:
        float distance = 0;
        int left_angle = 0;
        int right_angle = 0;
};

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
void print_picture(){
    for (int i = 0;i < arraysize; i++){
        Serial.println(picture[i]);
    }
    Serial.println();
}

void object_detection(Person person [2]){
    // int rate [arraysize-1] = {0};
    int count = 0, avg = 0, arr_size = 0 ,marker1 = 0, marker2 = 0 ;
    Serial.println("in funct ");
    for (int i = 0; i< arraysize-1 ; i++){
        //  rate [i] = abs(picture[i] - picture[i+1]);
        if (count == 2){
            break;
        }
        if (abs(picture[i] - picture[i+1]) >= 10){ //abrupt rise or drop
            marker2 = i ;
            Serial.println(marker1);
            Serial.println(marker2);
            arr_size = marker2- marker1 +1;
            Serial.print("Size = ");
            Serial.println(arr_size);
            Serial.print("arr = ");
            marker1 = marker2 +1 ;
            i ++; 
            for (int i=marker1 ; i< marker1 + arr_size;i++){
                Serial.print(picture[i]);
                Serial.print(" ");
                avg += picture[i] / arr_size ; 
            }
            Serial.print("avg = ");
            Serial.println(avg);
            if (arr_size <= 5 || arr_size >= 50 || avg >150 || avg <30){
                continue;
            }
            person[count].distance = avg ;
            person[count].left_angle = marker1 + start_angle;
            person[count].right_angle = marker2 + start_angle;
        }
    }
}

