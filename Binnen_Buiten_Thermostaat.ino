#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define dhtpin 7
#define DHTTYPE DHT11

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

DHT dht (dhtpin, DHT11);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float DHT11Temp = 0;
float B20Temp = 0;


void setup(void)
{
  sensors.begin();  // Start up the library
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.init();
  lcd.backlight();
}

void loop(void)
{ 
  // Send the command to get temperatures
  sensors.requestTemperatures(); 

  //print the temperature in Celsius
  B20Temp = sensors.getTempCByIndex(0);
  DHT11Temp = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("B20Temp:");
  lcd.setCursor(8, 0);
  lcd.print(B20Temp);
  lcd.setCursor(14,0);
  lcd.print((char)223);
  lcd.setCursor(15,0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("DHTTemp:");
  lcd.setCursor(8, 1);
  lcd.print(DHT11Temp);
  lcd.setCursor(14,1);
  lcd.print((char)223);
  lcd.setCursor(15,1);
  lcd.print("C");  
  
  delay(500);
}
