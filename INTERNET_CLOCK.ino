#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



const char *ssid     = "Pritam";
const char *password = "01234567";


LiquidCrystal_I2C lcd(0x3F,16,2); 


const long utcOffsetInSeconds = 19800;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(115200);
    
    lcd.init();                    
  lcd.init();
  lcd.backlight();

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
    
     lcd.setCursor(0,0);
 lcd.print(daysOfTheWeek[timeClient.getDay()]);
    
  lcd.setCursor(0,1);
  lcd.print(timeClient.getHours());
    
    
      lcd.setCursor(3,1);
  lcd.print(timeClient.getMinutes());
    
     lcd.setCursor(6,1);
  lcd.print(timeClient.getSeconds());
    
    

  //Serial.println(timeClient.getFormattedTime());

  delay(1000);
}