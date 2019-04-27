int x=A0;  //Analog pin 0
int y=A1;  //Analog pin 1
int z=A2;  //Analog pin 2
int BuzzerPin=9;    //Pin for Buzzer
void setup()
{
pinMode(x,INPUT);
pinMode(y,INPUT);
pinMode(z,INPUT);
pinMode(BuzzerPin,OUTPUT);
Serial.begin(9600);
}
void loop()
{ 
float i=0;
int thisPitch; 
x=analogRead(x);
Serial.print("\n\nX=");    //prints x-axis acc. due to gravity in terms of voltage level
Serial.print(x);
y=analogRead(y);
Serial.print("\nY=");      //prints y-axis acc. due to gravity in terms of voltage level
Serial.print(y);
z=analogRead(z);
Serial.print("\nZ=");     //prints z-axis acc. due to gravity in terms of voltage level
Serial.print(z);
i=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
Serial.print("\nI=");       //root square intensity value
Serial.print(i);
if(i>700)
{
thisPitch=map(i,400,1000,120,1500);    //frequency range
tone(BuzzerPin,thisPitch,0);          //0% Duty Cycle
delay(1000);
}
else if(i>650&&i<700) 
{
thisPitch=map(i,400,1000,120,1500);   //frequency range
tone(BuzzerPin,thisPitch,64);        //25% Duty Cycle
delay(1000);
} 
else if(i>500&&i<600) 
{
thisPitch=map(i,400,1000,120,1500);  //frequency range
tone(BuzzerPin,thisPitch,127);        //50% Duty Cycle
delay(1000);
 }
 delay(1000);
}
