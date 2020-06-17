#include <Servo.h> //Arduino servo motor library

//configure the servo motors
Servo serv1;
Servo serv2;

int PosServ = 0; //the position of servo motor starts from zero degree

void setup() {
//the connection of the servo motors in the pins of arduino board
serv1.attach(5);
serv2.attach(10);
}

void loop() {
int but = digitalRead(1); 
//the button is connected in pin 1 in the arduino board, it reads the digital value of these pin

if (but == HIGH){ //if the button is pressed
for (PosServ = 0; PosServ < 180; PosServ ++) { //if the position between 0 and 180 degree 
serv1.write(PosServ); 
//the motor will start from zero degree and move in clockwise until it reach to 180 degree

serv2.write(180-PosServ); 
//the motor will start from 180 degree and move in counterclockwise  until it reach to zero degree

delay(15);
}

for (PosServ = 180; PosServ > 0; PosServ --) {
serv1.write(PosServ); 
//the motor will start from 180 degree and move in counterclockwise  until it reach to zero degree

serv2.write(180-PosServ); 
//the motor will start from zero degree and move in clockwise until it reach to 180 degree

delay(15);
}
}
else if (but == LOW){ //if the button is released
PosServ = 0;
serv1.write(PosServ); //the motor will be fixed at zero degree
serv2.write(180-PosServ); //the motor will be fixed at 180 degree
}
}
