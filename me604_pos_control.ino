#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

int pos = 0;
int flag = 0;
int lowerang1 = 0;
int upperang1 = 40;
int lowerang2 = 87;
int upperang2 = 132;
int lowerang3 = 0;
int upperang3 = 85;

void setup() {
  myservo1.attach(7);
  myservo2.attach(9);
  myservo3.attach(11);
}

void loop() {
  if (flag == 0) {
    pos = lowerang1;
    
    myservo1.write(lowerang1);
//    myservo1.write(10);
    delay(15);
    myservo2.write(lowerang2);
    delay(15);
    myservo3.write(lowerang3);
    delay(1500);

    for (pos = lowerang1; pos <= upperang1; pos += 1) {
      myservo3.write(2.125 * pos);
//      myservo3.write(4.25 * pos);
      delay(8);
    }

    delay(2000);

    pos = lowerang1;
    
    for (pos = lowerang1; pos <= upperang1; pos += 1) {
      myservo1.write(pos);
      myservo2.write(-1.125 * pos + 80);
      delay(8);
    }
    
    flag = 1;

    delay(1500);
  }
  
  else if ( flag == 1) {
    for (pos = upperang1; pos >= lowerang1; pos += -1) {
      myservo1.write(pos);
      myservo2.write(-1.125 * pos + 80);
      myservo3.write(2.125 * pos);
//      myservo3.write(4.25 * pos);
      delay(15);
    }

    flag = 2;
    
  }
}
