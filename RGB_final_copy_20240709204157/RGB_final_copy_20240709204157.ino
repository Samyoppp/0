

int r =0;
int g =0;
int b =  0;




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
goToRGBNumber(25, 0, 0);

delay(350);

goToRGBNumber(40, 10, 0);

delay(350);

goToRGBNumber(25, 25, 0);

delay(350);

goToRGBNumber(0, 25, 0);

delay(350);

goToRGBNumber(0, 0, 25);

delay(350);

goToRGBNumber(10, 0, 50);

delay(350);

}
void goToRGBNumber(int rN, int gN, int bN){

 while((r != rN) || (g != gN) || (b!= bN)){

if (r < rN)    {++r;}

else if (r > rN)    {--r;}
  
if (g < gN)    {++g;}

else if (g > gN)    {--g;}

if (b < bN)    {++b;}

else if (b > bN)    {--b;}
  
analogWrite(3, r);
analogWrite(5, g);
analogWrite(6, b);

Serial.print(r);
Serial.print(",");
Serial.print(g);
Serial.print(",");
Serial.println(b);

    delay(100);
 }
}