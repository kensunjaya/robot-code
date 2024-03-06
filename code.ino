#include <Servo.h>

#define SERVO_X 2
#define SERVO_Y 3
#define SERVO_C 4
#define SERVO_Z 5
#define DELAY 20

Servo servo_x; // horizontal rotation
Servo servo_y; // vertical rotation
Servo servo_c; // grabber
Servo servo_z; // forward & backward

void setup() {
  Serial.begin(9600);
  servo_x.attach(SERVO_X);
  servo_y.attach(SERVO_Y);
  servo_c.attach(SERVO_C);
  servo_z.attach(SERVO_Z);
}

void loop() {
  int pos_x = servo_x.read();
  int pos_y = servo_y.read();
  int pos_c = servo_c.read();
  int pos_z = servo_z.read();
  
  
  servo_c.write(60);
  delay(250);
  while (pos_x > 0) {
    servo_x.write(--pos_x);
    delay(DELAY);
  }
  servo_x.detach();
  servo_z.attach(SERVO_Z);
  delay(500);
  
  while (pos_z > 60) {
    servo_z.write(--pos_z);
    delay(DELAY);
  }
  
  while (pos_z < 110) {
    servo_z.write(++pos_z);
    delay(DELAY);
  }
  servo_z.detach();
  delay(500);
  servo_y.attach(SERVO_Y);
  while (pos_y > 20) {
    servo_y.write(--pos_y);
    delay(DELAY);
  }
  servo_y.detach();
  delay(250);
  servo_c.write(0);
  delay(250);
  servo_y.attach(SERVO_Y);
  while (pos_y < 100) {
    servo_y.write(++pos_y);
    servo_c.write(0);
    delay(DELAY);
  }
  servo_y.detach();
  servo_x.attach(SERVO_X);
  while (pos_x < 180) {
    servo_x.write(++pos_x);
    servo_c.write(0);
    delay(DELAY);
  }
  delay(500);
}
