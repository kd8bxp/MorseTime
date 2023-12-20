#include <WiFi.h>
#include "time.h"
#include "creds.h"
#include "src/M5StickC/M5StickC.h"
//#include "AlienAlphabet_nRRqJ12pt7b.h" //AlienAlphabet_nRRqJ12pt7b works sorta
//#include "Code3xR_D2320pt7b.h" //Code3xR_D2320pt7b
//#include "DotliriumRegular_45Gx12pt7b.h" //DotliriumRegular_45Gx12pt7b 
//#include "KixBarcode_y5De12pt7b.h" //KixBarcode_y5De12pt7b works sorta
//#include "MorseCode_wlGw10pt7b.h" //MorseCode_wlGw10pt7b works sorta
//#include "MorsoKode_dnXX10pt7b.h" //MorsoKode_dnXX10pt7b not really
//#include "UnicodeBmpFallbackSil_R3KA12pt7b.h" //UnicodeBmpFallbackSil_R3KA12pt7b works sorta

//#include "AlienAlphabet_nRRqJ15pt7b.h" //AlienAlphabet_nRRqJ15pt7b works need to adjust location for screen
//#include "KixBarcode_y5De10pt7b.h" //KixBarcode_y5De10pt7b works need to adjust location for screen
//#include "UnicodeBmpFallbackSil_R3KA10pt7b.h" //UnicodeBmpFallbackSil_R3KA10pt7b works need to adjust location for screen
//#include "MorseCode_wlGw12pt7b.h" //MorseCode_wlGw12pt7b not really
//#include "MorseCode_wlGw15pt7b.h" //MorseCode_wlGw15pt7b not really
//#include "MorsoKode_dnXX7pt7b.h" //MorsoKode_dnXX7pt7b not really
//#include "MorseCode_wlGw25pt7b.h" //MorseCode_wlGw25pt7b to large sorta works
#include "MorseCode_wlGw20pt7b.h" //MorseCode_wlGw20pt7b works if in the right screen location

#define RGB(r, g, b) (((r&0xF8)<<8)|((g&0xFC)<<3)|(b>>3))

/*
 Project started many years ago (late 2019 maybe), and finally figured out how to finished it. By LeRoy F. Miller, KD8BXP (C) 2023
*/

/*
 * Swatch Internet Time:
 * 
 * https://en.wikipedia.org/wiki/Swatch_Internet_Time
 * https://www.timeanddate.com/time/internettime.html
 * https://www.swatch.com/en_us/internet-time/
 * Internet Time invited by the Swatch Watch company in 1999 at the start of the age of the internet
 * 
 * New Eath Time Clock
 * http://www.csgnetwork.com/csgnetstdtime.html
 * http://newearthtime.net/
 * https://en.wikipedia.org/wiki/New_Earth_Time
 * 
 * Decimal Time
 * https://en.wikipedia.org/wiki/Decimal_time
 * 
 * See more notes at end of sketch
 * 
 */

 /*
  * July 29, 2023 Minor changes to output sent to mastodon, added the @ sign for beats time
  * and added 0x to hex time.
  * Also added a esp.reboot on a couple of fail conditions.
  * 
  */ 

//Version 1.0.1 July 29, 2023  
//Version 1.0.2 Aug 12, 2023 Fixed errors in .beats time, added unix time, and moved credentials to own tab

/*
Morse Code Display with various fonts - (c) Dec 17, 2023 By LeRoy Miller, KD8BXP
Display a interesting font (time) on a M5StickC.
The fonts used here were all found from fontspace.com
This based on the useless clock code, but only uses UTC for display - the other times are displayed out to the serial monitor.
Minor changes will need to be made to the location of the clock for each font above
near line 169 and 172
Fonts change be changed by uncommenting the font you'd like above and changing the font name (also near line 169)
TTF fonts were converted using https://rop.nl/truetype2gfx/
*/

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0; //UTC for Internet Time
const int   daylightOffset_sec = 0; 

float beats; //Swatch Internet Time
int net_hour, net_minute, net_second;
float dec_hour, dec_minute, dec_second;
float rel_hour, rel_minute, rel_second;

String message;
String months[] = {"January", "February", "March", "April", "May", "June", "July", "Auguest", "September", "October", "Novermber", "December"};
String days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void printLocalTime() {
  time_t now;
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    ESP.restart();
    return;
  }
  time(&now);
  
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  char buff[100];
  message = String(days[timeinfo.tm_wday]) + ", " + String(months[timeinfo.tm_mon]) + " " + String(timeinfo.tm_mday) + " " + String(timeinfo.tm_year + 1900) + " "; 
    if (timeinfo.tm_hour < 10) { message = message + "0" + String(timeinfo.tm_hour) + ":"; } else { message = message + String(timeinfo.tm_hour) + ":";}
    if (timeinfo.tm_min < 10) {message = message + "0" + String(timeinfo.tm_min) + ":"; } else {message = message + String(timeinfo.tm_min) + ":";}
    if (timeinfo.tm_sec < 10) {message = message + "0" + String(timeinfo.tm_sec); } else {message = message + String(timeinfo.tm_sec); }
    message = message + " UTC\n";



 Serial.print("Unix Time: ");Serial.println(now);
 message = message + "Unix Time: " + String(now) + "\n";

  int tempBeatHour = timeinfo.tm_hour + 1;
  if (tempBeatHour == 24) {tempBeatHour = 0;}
  //beats = ((timeinfo.tm_sec) + ((timeinfo.tm_min) * 60) + ((timeinfo.tm_hour+1) * 3600)) / 86.4;
  beats = ((timeinfo.tm_sec) + ((timeinfo.tm_min) * 60) + ((tempBeatHour) * 3600)) / 86.4;
  Serial.print("@"); Serial.print(beats); Serial.println(" .beats");
  message = message +"@" + String(beats) + " .beats \n";

  //New Earth Time
  net_second = ((timeinfo.tm_min % 4) * 60 /4) + abs(timeinfo.tm_sec/4); 
  net_minute = (timeinfo.tm_min /4);
  net_hour = (timeinfo.tm_hour * 15) + net_minute;
  Serial.print("NET: "); Serial.printf("%03d", net_hour); Serial.print("* ");Serial.printf("%02d", net_second); Serial.println("'");
  sprintf(buff, "%03d* %02d'",net_hour, net_second); String tempMsg(buff);
  message = message + "New Earth Time: " + tempMsg + "\n";

  //Decimal Time
  dec_second = timeinfo.tm_sec / 10.0;
  dec_minute = timeinfo.tm_min / 10.0;
  dec_hour = timeinfo.tm_hour / 10.0;
  Serial.print("Decimal Time: "); Serial.print(dec_hour); Serial.print(":"); Serial.print(dec_minute); Serial.print(":"); Serial.println(dec_second);
  message = message + "Decimal Time: " + String(dec_hour) + ":" + String(dec_minute) + ":" + String(dec_second) + "\n";

  //Different Decimal Time
  //https://www.timecalculator.net/time-to-decimal
  float tempH, tempS, tempM;
  tempH = timeinfo.tm_hour;
  tempM = timeinfo.tm_min;
  tempS = timeinfo.tm_sec;
  float decimalTime;
  dec_hour = tempH + (tempM / 60) + (tempS / 3600);
  dec_minute = (tempH * 60) + tempM + (tempS / 60);
  dec_second = (tempH * 3600) + (tempM * 60) + tempS;
  decimalTime = dec_hour + dec_minute + dec_second;
  ////Serial.print("Other Decimal Time: "); Serial.println(decimalTime);
  Serial.print("More Decimal Time: "); Serial.print(dec_hour); Serial.print(":"); Serial.print(dec_minute); Serial.print(":"); Serial.println(dec_second);
  message = message + "Decimal Time 2: " + String(dec_hour) + ":" + String(dec_minute) + ":" + String(dec_second) + "\n";
  
  //Rels
  rel_second = timeinfo.tm_sec / 1.2;
  rel_minute = (timeinfo.tm_min * 60) / 1.2;
  rel_hour  = timeinfo.tm_hour * 3000;
  Serial.print("Rel: "); Serial.print( rel_second + rel_minute + rel_hour); Serial.println (" rels");
  message = message + "Rel: " + String(rel_second + rel_minute + rel_hour) + " rels \n";

  //French Fraction of day time (French Decimal Time) https://hackaday.com/2016/12/14/set-your-clocks-to-decimal-time/
  float fdecimalTime;
  if (tempH == 0) {fdecimalTime = ((tempM)+32); } else {fdecimalTime = ((tempH * tempM )+34); }
  fdecimalTime = fdecimalTime / (60 * 24);
  Serial.print("Fractional: "); Serial.println(fdecimalTime, 6);
  message = message + "French Fractional Time: " + String(fdecimalTime, 6) + "\n";
  
  ////Serial.print("Stardate: ");Serial.print((timeinfo.tm_year+1900) - 2000 );Serial.print(timeinfo.tm_mon+1);Serial.println(timeinfo.tm_mday + fdecimalTime, 4);
  Serial.print("Stardate: ");Serial.print((timeinfo.tm_year+1900) - 2000 ); Serial.println(calculateDayOfYear(timeinfo.tm_mday,timeinfo.tm_mon+1,(timeinfo.tm_year+1900)) + fdecimalTime,4);
  message = message + "A Stardate: " + String((timeinfo.tm_year+1900) - 2000) + String(calculateDayOfYear(timeinfo.tm_mday,timeinfo.tm_mon+1,(timeinfo.tm_year+1900)) + fdecimalTime,4) + "\n";
  
  //https://minkukel.com/en/clocks/hexadecimal-clock/
  int hex_second = timeinfo.tm_sec;
  int hex_minute = timeinfo.tm_min;
  int hex_hour = timeinfo.tm_hour;
  Serial.print("#"); Serial.printf("%02X",hex_hour); Serial.printf("%02X",hex_minute); Serial.printf("%02X\n",hex_second);
  sprintf(buff, "%02X%02X%02X",hex_hour,hex_minute,hex_second); String tempMsg2(buff);
  message = message + "Hex Time: 0x" + tempMsg2 + "\n";

M5.Lcd.fillScreen(BLACK);
m5.lcd.setFreeFont(&MorseCode_wlGw20pt7b);
M5.Lcd.setCursor(0,30);
M5.Lcd.println(&timeinfo, "%H%M%S");
m5.lcd.setFreeFont(&FreeMono12pt7b);
M5.Lcd.setCursor(15,46);
M5.Lcd.println(&timeinfo, "%H:%M:%S");

Serial.println(); // Serial.print(message);

   
message = "";

}



int calculateDayOfYear(int day, int month, int year) {
  
  // Given a day, month, and year (4 digit), returns 
  // the day of year. Errors return 999.
  
  int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  
  // Verify we got a 4-digit year
  if (year < 1000) {
    return 999;
  }
  
  // Check if it is a leap year, this is confusing business
  // See: https://support.microsoft.com/en-us/kb/214019
  if (year%4  == 0) {
    if (year%100 != 0) {
      daysInMonth[1] = 29;
    }
    else {
      if (year%400 == 0) {
        daysInMonth[1] = 29;
      }
    }
   }

  // Make sure we are on a valid day of the month
  if (day < 1) 
  {
    return 999;
  } else if (day > daysInMonth[month-1]) {
    return 999;
  }
  
  int doy = 0;
  for (int i = 0; i < month - 1; i++) {
    doy += daysInMonth[i];
  }
  
  doy += day;
  return doy;
}

static void authCb(bool ok, const char *_authToken) {
    if (ok) {
        Serial.println("Authorisation OK, ready to toot");
        authToken = _authToken;
    } else {
        Serial.println("Authorisation failure");
    }
}


void setup()
{
  M5.begin();
  Serial.begin(115200);
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextSize(0);
  M5.Lcd.setTextColor(0x02EE);
  
  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  
  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 
}



void loop()
{
  
  printLocalTime();
  delay(1000);
 
}

/*
some info about the time library used here
https://forum.arduino.cc/index.php?topic=536464.0

Member  Type  Meaning Range
tm_sec  int seconds after the minute  0-61*
tm_min  int minutes after the hour  0-59
tm_hour int hours since midnight  0-23
tm_mday int day of the month  1-31
tm_mon  int months since January  0-11
tm_year int years since 1900  
tm_wday int days since Sunday 0-6
tm_yday int days since January 1  0-365
tm_isdst  int Daylight Saving Time flag 
*/
