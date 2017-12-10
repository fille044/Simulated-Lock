#include <Servo.h>
#define DEBUG 0

Servo servo1;

/* -----------------------------------------*/
void serialDebug(void)
{
    Serial.print("A5 ");
    Serial.println(analogRead(A5));
    Serial.print("A4 ");
    Serial.println(analogRead(A4));
    Serial.print("A3 ");
    Serial.println(analogRead(A3));
    Serial.print("A2 ");
    Serial.println(analogRead(A2));
}


/* -----------------------------------------*/
int checkInput(int Input, int Answer)
{
    int Min, Max;

    if (Input < 0) {
        Input = 0;
    }

    if (Answer < 50) {
        Min = 0;
        Max = Answer + 50;
    }
    else {
        Min = Answer - 50;
        Max = Answer + 50;
    }

    if (Input >= Min && Input <= Max)
        return 1;
    else {
        return 0;
    }
}


void setLock(int State)
{
    if (State == 1) servo1.write(180);
    else if (State == 0) servo1.write(0);
}


/* -----------------------------------------*/
void setup()
{
    servo1.attach(A0);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    Serial.begin(9600);
}


/* -----------------------------------------*/
void loop()
{
    if (DEBUG == 1) {
        serialDebug();
    }

    if ((checkInput(analogRead(A5), 300) &&
        checkInput(analogRead(A4), 200) &&
        checkInput(analogRead(A3), 1000) &&
        checkInput(analogRead(A2), 750)) == 1) {
        digitalWrite(12, HIGH);
        setLock(1);
        Serial.println("HIGH");
    }
    else {
        digitalWrite(12, LOW);
        setLock(0);
        Serial.println("LOW");
    }

    delay(1000);

}
