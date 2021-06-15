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
void print_picture(int * picture){
    for (int i = 0;i < arraysize; i++){
        Serial.print(i+30); 
        Serial.print("*.");
        Serial.print(picture[i]);
        Serial.print(" ");
        if (!(i % 10) and (i)){
            Serial.println();
        }
    }
    Serial.println();
}
float is__object(int *arr , int size){
    int num = size ;
    if (num <= 10){
        return 0;
    }
    int avg =0;
    for (int i = 0;i<num;i++){
        avg += arr[i] / num ;
    }
    if (avg < 30 || avg > 150){
        return 0;
    }
    return avg;
}
bool assign_info (Person person, int marker1, int marker2){
    int * arr;
    bool success = false;
    int size0 = abs(marker2-marker1)+1 ; 
    arr = new int [size0]; //5-3
    Serial.print("array =  ");
    for (int i = 0;i <size0 ; i++){
        arr[i] = picture[marker1 + i];         
    }
    for (int i =0 ;i<size0;i++ ){
      Serial.print(arr[i]);
      Serial.print(" ");
    }
    Serial.println(" ");
    if (person.distance = is__object(arr , size0)){
        person.left_angle = marker1;
        person.right_angle = marker2; 
        success = true;
    }
    delete [] arr;
    return success; 
}
void object_detection(Person person [2]){
    // int rate [arraysize-1] = {0};
    int count = 0;
    int marker1, marker2 = 0;
    for (int i = 0; i< arraysize-1 ; i++){
        //  rate [i] = abs(picture[i] - picture[i+1]);
        if (count == 2){
            break;
        }
        if (abs(picture[i] - picture[i+1])>= 10){ //abrupt rise or drop
            marker2 = i ;
           
            if (assign_info(person[count],marker1,marker2)){
                count ++;
                marker1 = i+1;
            }
        }
    }
}

