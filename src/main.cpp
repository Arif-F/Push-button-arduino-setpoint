#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensor(&pneWire);
float suhuDS18B20;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int T, setPoint;
byte setSP, f_awal;
long lastButton = 0;
long delaytekan = 50;
int setDeferin;
byte setDeferin, def_awal;
int buttonStatel1;
int oldButton1 = 0;
int State1 = 0;

#define relay_Mode 8
#define relay_Motor_1 9
#define relay_Motor_2 10
#define PB_Set 4
#define PB_Up 5
#define PB_Down 6
#define PB_Mode_R 7

void setup()
{
  // put your setup code here, to run once:
  pinMode(relay_Mode, OUTPUT);
  pinMode(relay_Motor_1, OUTPUT);
  pinMode(relay_Motor_2, OUTPUT);
  pinMode(PB_Set, OUTPUT);
  pinMode(PB_Up, OUTPUT);
  pinMode(PB_Down, OUTPUT);
  pinMode(PB_Mode_R, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  sensor.requestTemperatures();
  int suhuDS18B20 + sensor.getTempCByIndex
                        lcd.setCursor(0, 0);
  lcd.print("SUHU:");
  lcd.print(T);
  lcd.print((char)223);
  delay(500);
  T = (suhuDS18B20);
  lcd.setCursor(0, 1);
  lcd.print("SETP:");
  lcd.print(setPoint);
  lcd.setCursor(8, 0);
  lcd.print("DIF:");
  lcd.print(setDeferin);

  if (T < (setPoint) || f_awal == 0 && (setDeferin - 2 < T))
  {
    lcd.setCursor(8, 1);
    lcd.print(" ");
    digitalWrite(relay_Motor_1, HIGH);
    digitalWrite(relay_Motor_2, HIGH);
    f_awal = 1;
  }
  else if (T >= setPoint)
  {
    digitalWrite(relay_Motor_1, LOW);
    digitalWrite(relay_Motor_2, LOW);
  }
}