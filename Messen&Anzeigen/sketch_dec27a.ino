#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int greenPin = A0;

int temperature0 = 0;
int temperature1 = 0;
int temperature2 = 0;
int temperature3 = 0;
int temperature4 = 0;
int finaltemp = 0;

int humidity0 = 0;
int humidity1 = 0;
int humidity2 = 0;
int humidity3 = 0;
int humidity4 = 0;
int finalhumidity = 0;

dht sensor;

void setup()
{
  
  
  
  lcd.begin(16,2); //16 by 2 character display
  
  lcd.setCursor(0,0);
  lcd.print("Sensor: DHT11");
  lcd.setCursor(0,1);
  lcd.print("Display: 16x2 LCD RGB");
  
  delay(1000);
  lcd.clear();
    
}

void loop()
{
  delay(1000); //Recommendes Delay for DH11 Sensor
  sensor.read11(greenPin); 
  lcd.setCursor(0,0);
  
  temperature0 = sensor.temperature;
  humidity0 = sensor.humidity;
  delay(1000);
  temperature1 = sensor.temperature; 
  humidity1 = sensor.humidity;
  delay(1000);
  temperature2 = sensor.temperature; 
  humidity2 = sensor.humidity;
  

  finaltemp = temperature0 + temperature1 + temperature2; //Mittelwertbildung
  finaltemp = finaltemp / 3;

  finalhumidity = humidity0 + humidity1 + humidity2;
  finalhumidity = finalhumidity / 3;

  lcd.clear();
  
  lcd.print("Humidity: ");
  lcd.print(finalhumidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print(finaltemp);
  lcd.print("C");
}
