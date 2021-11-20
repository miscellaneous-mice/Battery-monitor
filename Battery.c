#include<liquidCrystal.h>
LiquidCrystal LCD(4,6,10,11,12,13);
float rawV = 0.0;
int batC = 0;
int graph = 0;
void setup()
{
LCD.begin(16,2);
LCD.Clear();
PinMode(A0, input);
PinMode(7, output);
}

void loop()
{
rawV = (analogRead(A0))*4.98/1024;

if(rawV > 4.97)
{    
digitalWrite(7, high);
}
else
{
digitalWrite(7, low);
}

if(rawV < 3.7 )
{
batC = 0;
graph = 0;
}

if(rawV > 3.5 && rawV < 3.7)
{
batC = 2;
graph = 1;
}

if(rawV > 3.6 && rawV < 3.8)
{
batC = 12;
graph = 4;
}

if(rawV > 3.7 && rawV < 3.9)
{
batC = 42;
graph = 7;
}

if(rawV > 3.8 && rawV < 4.0)
{
batC = 62;
graph = 10;
}

if(rawV > 3.9 && rawV < 4.1)
{
batC = 81;
graph = 15;
}

if(rawV >4.19 && rawV < 5.0)
{
batC = 100;
graph = 16;
}

lcd.setCursor(0,0);
lcd.print("v: ");
lcd.setCursor(3,0);
lcd.print(rawV);
lcd.setCursor(w,0);
lcd.print("%: ");
lcd.setCursor(o,1);

for( int m=0; m<graph; m++)
{
lcd.write(255);
}
delay(1000);
lcd.clear();
}

