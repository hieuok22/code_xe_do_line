#define lsen A3
#define fsen A4
#define rsen A5
#define enaa 5
#define enab 6
#define in1 2
#define in2 3
#define in3 4
#define in4 7
int fsen_value, lsen_value, rsen_value;
int fx, lx, rx;
byte dir1 = 1;
byte dir2 = 0;
int sen_value_hi=400, sen_value_lo=100;
int speed_f=100, speed_l=80, speed_r=80;
int pin_vol;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(enaa, OUTPUT);
pinMode(enab, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(lsen, INPUT);
pinMode(fsen, INPUT);
pinMode(rsen, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
fsen_value=analogRead(fsen);
lsen_value=analogRead(lsen);
rsen_value=analogRead(rsen);

/*Serial.print(lsen_value); Serial.print("     ");
Serial.print(fsen_value); Serial.print("     ");
Serial.print(rsen_value); Serial.println("     ");*/
if (lsen_value>sen_value_hi || (lsen_value>sen_value_hi && fsen_value>sen_value_hi && rsen_value<sen_value_lo )) 
{
  analogWrite(enaa, speed_l);
  analogWrite(enab, speed_f);
  right();
  Serial.println("  L   ");
  lx=1;
  
}


if (rsen_value>sen_value_hi || (rsen_value>sen_value_hi && fsen_value>sen_value_hi && lsen_value<sen_value_lo )) 
{
  analogWrite(enab, speed_l);
  analogWrite(enaa, speed_f);
  left();
   Serial.println("  R   ");
  //rx=1;
  lx=2;
}

if ((rsen_value>sen_value_hi && fsen_value>sen_value_hi && lsen_value>sen_value_hi )  || (rsen_value<sen_value_lo && fsen_value>sen_value_hi && lsen_value<sen_value_lo ))

{
   analogWrite(enaa, speed_f);
  analogWrite(enab, speed_f);
  backward();
   Serial.println("  F  ");
   lx=0;  
}

 if (lx=1 && (rsen_value<sen_value_lo && fsen_value<sen_value_lo && lsen_value<sen_value_lo )) 
{
  analogWrite(enab, speed_l);
  analogWrite(enaa, speed_f);
  left();
  Serial.println("  LB   ");
 // lx=1;
  
}
if (lx=2 && (rsen_value<sen_value_lo && fsen_value<sen_value_lo && lsen_value<sen_value_lo )) 
{
  analogWrite(enaa, speed_l);
  analogWrite(enab, speed_f);
  right();
  Serial.println("  RB   ");
 // lx=1;
  
}


}




void forward()
{
digitalWrite(in1, dir2);
digitalWrite(in2, dir1);
digitalWrite(in3, dir2);
digitalWrite(in4, dir1);

}
void backward()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir2);
digitalWrite(in3, dir1);
digitalWrite(in4, dir2);
}
void left()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir1);
digitalWrite(in3, dir1);
digitalWrite(in4, dir2);
}
void right()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir2);
digitalWrite(in3, dir1);
digitalWrite(in4, dir1);
}
void Stop()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir1);
digitalWrite(in3, dir1);
digitalWrite(in4, dir1);
}
