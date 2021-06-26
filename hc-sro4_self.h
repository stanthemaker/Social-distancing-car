#define trigPin 7
#define echoPin 6
#define arraysize 121
#define start_angle 30
#define end_angle 150
extern float picture[];
class Person{
    public:
        double distance = 0;
        int angle = 0;
};

void HC_sro4_init(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float get_distance(){
    long duration = 0 ;
    float distance_cm = 0;
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
void print_picture_distance(){
    for (int i = 0;i < arraysize; i++){
        Serial.println(picture[i]);
    }
    Serial.println();
}
void preprocess(){
    for (int i=1; i< arraysize-1;i++){
        if (abs(picture[i] - picture [i-1]) >= 10 && abs (picture[i] - picture [i+1]) >= 10){
            if (abs(picture[i+1] - picture [i-1])<=5){
                picture[i] = (picture[i+1] + picture[i-1] )/2;
            }
        }
        picture[i] = (picture[i] > 200) ? 0 :picture[i];
    }
}
// void object_detection(Person person [2]){
//     // int rate [arraysize-1] = {0};
//     int count = 0, arr_size = 0 ,marker1 = 0, marker2 = 0 ;
//     float  avg = 0;
//     // Serial.println("in funct ");
//     for (int i = 0; i< arraysize-1 ; i++){
//         //  rate [i] = abs(picture[i] - picture[i+1]);
//         if (count == 2){
//             break;
//         }
//         if (abs(picture[i] - picture[i+1]) >= 10){ //abrupt rise or drop
//             marker2 = i ;
//             avg = 0;
//             // Serial.println(marker1);
//             // Serial.println(marker2);
//             arr_size = marker2- marker1 +1;
//             // Serial.print("Size = ");
//             // Serial.println(arr_size);
//             // Serial.print("arr = "); 
//             for (int j=marker1 ; j< marker1 + arr_size;j++){
//                 // Serial.print(picture[j]);
//                 // Serial.print(" ");
//                 avg += (picture[j] / arr_size); 
//             }
//             // Serial.print("avg = ");
//             // Serial.println(avg);
//             if (arr_size <= 20 || arr_size >= 100 || avg >150 || avg <30){
//                 marker1 = marker2 +1 ;
//                 i ++;
//                 continue;
//             }
//             person[count].distance = avg ;
//             person[count].left_angle = marker1 ;
//             person[count].right_angle = marker2 ;
//             person[count].middle_angle = (marker1 + marker2)/2;
//             marker1 = marker2 + 1 ;
//             i ++;
//             count++; 
//         }
//     }
// }
float get_correspond_distance(int marker){
    float avg = 0;
    for (int i = marker -2 ; i<= marker +2 ;i++){
        avg += picture[i] /5 ;
    }
    return avg ;
} 
double social_distance(double a, double b , double angle){
    double D = a*a + b*b -2*a*b*cos(angle*PI/180);
    return(sqrt(D));
}