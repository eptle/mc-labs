#include <DHT.h>                // Работа с датчиком температуры и влажности DHT11
#include <Wire.h>               // Работа с I2C устройствами
#include <LiquidCrystal.h>      // Управление LCD-дисплеем
#include <SFE_BMP180.h>         // Работа с барометром BMP180
#include <DS3232RTC.h>          // Работа с часами реального времени DS3232

DHT dht(7, DHT11);              // Объект DHT11
SFE_BMP180 bmp180;              // Объект BMP180
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Объект LCD-дисплея с указанием пинов для подключения

void setup() { 
  lcd.begin(16, 2);             // Инициализация LCD-дисплея 16x2 символов
  dht.begin();                  // Инициализация DHT11
  Serial.begin(9600);           // Установка скорости передачи данных по serial-порту (9600 бод)
  bmp180.begin();               // Инициализация BMP180
} 
 
void loop() { 
  float h = dht.readHumidity(); // Чтение влажности с DHT11
  float t = dht.readTemperature(); // Чтение температуры с DHT11

  double p, bmpt;               // Давление и температура
  bmp180.startTemperature();    // Запуск измерения температуры на BMP180
  bmp180.startPressure(3);      // Запуск измерения давления на BMP180 с максимально точным режимом (3)
  bmp180.getPressure(p, bmpt);  // Получение давления и температуры

  lcd.setCursor(0, 0);          // Установка курсора в первую строку
  lcd.print(hour());            // Вывод текущего часа с модуля часов реального времени
  lcd.print(":"); 
  lcd.print(minute());          
  lcd.print(":"); 
  lcd.print(second());          
  lcd.print(" T: "); 
  lcd.print(t);                 // Вывод температуры с DHT11
  lcd.print("C");               // Добавление символа Цельсия

  lcd.setCursor(0, 1);          // Установка курсора во вторую строку
  lcd.print("H:"); 
  lcd.print(h);                 // Вывод влажности с DHT11
  lcd.print(" P: "); 
  lcd.print(p);                 // Вывод давления с BMP180
}