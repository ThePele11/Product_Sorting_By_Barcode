#include <SoftwareSerial.h>
#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define sensor 4
#define button 5

int relay = 7;

Servo myservo1;
Servo myservo2;
Servo myservo3;

SoftwareSerial mySerial(2, 3); // TX, RX  
LiquidCrystal_I2C lcd(0x27, 16, 2);

char a[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
char info = '0';
int k = 0;

void setup()
{    
  lcd.clear();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); 
  lcd.print("ID: "); 

  lcd.setCursor(0, 1); 
  lcd.print("To: ");

  pinMode(button, OUTPUT);
  // Serial.begin(9600);  
  mySerial.begin(9600); 
  // Serial.println("Welcome to Thesis Project");

  pinMode(relay, OUTPUT);
  pinMode(sensor ,INPUT);

  myservo1.attach(8);  
  myservo2.attach(10);
  myservo3.attach(12);

  myservo1.write (180);
  myservo2.write (180);
  myservo3.write (180);

  digitalWrite(relay, HIGH);

}
 
void loop()
{

  int val = digitalRead(sensor);
  // Serial.print("INPUT : ");
  // Serial.println(input);
  if(val == LOW){

    delay(3500);
    digitalWrite(button, LOW);
    delay(3500);

  }
  else{

    digitalWrite(button, HIGH);

  }

  if (mySerial.available()) 
  {

    barCode();

  }
  return 0;
}

void barCode() 
{

  while (mySerial.available()) 
    {

      char info = mySerial.read(); 
      // Serial.print(info);  

      a[k] = info;
      k = k + 1;

       if (k == 8)
       {

         Serial.print("ID : ");
         Serial.print(a[0]);
         Serial.print(a[1]);
         Serial.print(a[2]);
         Serial.print(a[3]);
         Serial.print(a[4]);
         Serial.println(a[5]);

        if (a[0] == '4' && a[1] == '4' && a[2] == '2' && a[3] == '9' && a[4] == '8' && a[5] == '1') 
        {

          Serial.print("Name : ");
          Serial.println("Vientiane");
          Serial.println();

          lcd.setCursor(4, 0); 
          lcd.print("442981");

          lcd.setCursor(4, 1); 
          lcd.print("Vientiane");

          delay(7000);
          digitalWrite(relay, LOW);
          delay(3000);

          myservo1.write(0);
          delay(2000);
          myservo1.write(180);
          delay(2000);

          digitalWrite(relay, HIGH);          

        }

        else if (a[0] == '1' && a[1] == '7' && a[2] == '7' && a[3] == '8' && a[4] == '9' && a[5] == '8') 
        {

          Serial.print("Name : ");
          Serial.println("Bolikhamxay");
          Serial.println();

          lcd.setCursor(4, 0); 
          lcd.print("177898");

          lcd.setCursor(4, 1); 
          lcd.print("Bolikhamxay");

          delay(13000);
          digitalWrite(relay, LOW);
          delay(3000);

          myservo2.write(0);
          delay(2000);
          myservo2.write(180);  
          delay(2000);          
          digitalWrite(relay, HIGH);           
        }

        else if (a[0] == '4' && a[1] == '6' && a[2] == '8' && a[3] == '9' && a[4] == '1' && a[5] == '8') 
        {

          Serial.print("Name : ");
          Serial.println("Xaysomboon");
          Serial.println();

          lcd.setCursor(4, 0); 
          lcd.print("468918");

          lcd.setCursor(4, 1); 
          lcd.print("Xaysomboon");

          delay(19000);
          digitalWrite(relay, LOW);
          delay(3000);

          myservo3.write(0);
          delay(2000);
          myservo3.write(180); 
          delay(2000);          
          digitalWrite(relay, HIGH);                          

        }
        k = 0;
      }
      return 0;
    }
}
