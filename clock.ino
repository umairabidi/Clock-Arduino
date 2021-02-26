//Numbers 0-9.
int numberArray[10][7] = {
  { 0, 0, 0, 0, 0, 0, 1 }, //0
  { 1, 0, 0, 1, 1, 1, 1 }, //1
  { 0, 0, 1, 0, 0, 1, 0 }, //2
  { 0, 0, 0, 0, 1, 1, 0 }, //3
  { 1, 0, 0, 1, 1, 0, 0 }, //4
  { 0, 1, 0, 0, 1, 0, 0 }, //5
  { 0, 1, 0, 0, 0, 0, 0 }, //6
  { 0, 0, 0, 1, 1, 1, 1 }, //7
  { 0, 0, 0, 0, 0, 0, 0 }, //8
  { 0, 0, 0, 0, 1, 0, 0 }, //9
};

int sec;
int tenSec=5;
int mins=4;
int tenMin;

void setup() {
  for (int i = 12; i >= 2; i--) { //set all necessary pins as outputs
    pinMode(i, OUTPUT);
  }
  pinMode(1,INPUT);
  reset();
}

void loop() {
  for (sec=0; sec <=9; sec++) {
    cycle();        //count up the seconds, then display them for an amount of time
  }
  if (sec = 9) {    //when seconds reach 9, count up the ten seconds by one
    tenSec++;
  }
  if (tenSec == 6) {//when then seconds reach 60, reset it and increment the minutes
    tenSec -= 6;
    mins++;
  }
  if (mins == 9) {//when minutes reach 9, reset and increment ten minutes
    mins -= 9;
    tenMin++;
  }
  if (mins == 3 && tenMin == 1) { //when total minutes reaches 12, reset to 01:00
    mins -= 2;
    tenMin -= 1;
  }
}

//make the displays show a single digit number
void digit(int number) {
  for (int i = 12; i >= 6; i--) {
    digitalWrite(i, numberArray[number][12 - i]);
  }
}

//all displays off
void off(int Display) {
  digitalWrite(6 - Display, 0);
}

//all displays on (nothing showing)
void on(int Display) {
  digitalWrite(6 - Display, 1);
}

//Display nothing on all segments (common anode --> high = off)
void reset() {
  for (int pin = 12; pin >= 6; pin--) {
    digitalWrite(pin, 1);
  }
}


void cycle() {
  for (int repeat = 0; repeat <= 20 ; repeat++) { //2920 is fast about 7 minutes per 7.5 hours
                                                    //2875 estimate
    on(1); digit(tenMin); delay(5); off(1);         //print the ten minutes
    on(2); digit(mins); delay(5); off(2);           //print the minutes
    on(3); digit(tenSec); delay(5); off(3);         //print the ten seconds
    on(4); digit(sec); delay(5); off(4);            //print the seconds
  }
}

void oneToTen() {
  for (int x = 0; x <= 9; x++) {
    digit(x);
    delay(400);
  }
}

