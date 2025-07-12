#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust the I2C address if needed

String buffer = "";
String currentLine = "";  // Store the track title
int scrollPos = 0;        // For scrolling
unsigned long lastScroll = 0;
unsigned long scrollInterval = 400;  // Scroll speed (ms)

void setup() {
  Serial.begin(9600);  // Start serial communication
  lcd.init();  // Initialize the LCD
  lcd.backlight();
  lcd.clear();  // Clear the LCD screen
  lcd.setCursor(0, 0);
  lcd.print("shorturl.at");  // Static label
  lcd.setCursor(0, 1);
  lcd.print("/1PgUI");  // Display the short title
  while (!Serial.available()) {
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connected!");  // Static label
  lcd.setCursor(0, 1);
  lcd.print("");  // Display the short title
  delay(1000);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();  // Read data from serial
    if (c == '\n') {
      if (buffer != currentLine) {
      // If we reach a newline, set the track title
      currentLine = buffer;
      scrollPos = 0;  // Reset scroll position
      }
      buffer = "";  // Clear the buffer for the next string
    } else {
      buffer += c;  // Append the received character to the buffer 
    }
  }

  // Scroll if the track title is longer than 16 characters
  if (currentLine.length() > 16) {
    if (millis() - lastScroll >= scrollInterval) {
      lcd.clear();  // Clear the LCD
      lcd.setCursor(0, 0);
      lcd.print("Now Playing:");  // Display static label

      // Scroll the title
      lcd.setCursor(0, 1);
      String displayText = currentLine.substring(scrollPos, scrollPos + 16);
      lcd.print(displayText);
      Serial.println(displayText);
      if (scrollPos == 0) {
      delay(1000);
      }

      // Move scroll position
      scrollPos++;
      if (scrollPos + 16 > currentLine.length()) {
        scrollPos = 0;  // Restart scrolling when we reach the end
        delay(1000);
      }
      lastScroll = millis();
    }
  } else {
    // If the title is shorter than or equal to 16 characters, display it statically
    if (currentLine == "VLC Offline") {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Error:");  // Static label
      lcd.setCursor(0, 1);
      lcd.print(currentLine);
    } else if (currentLine == "Nothing Playing") {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(currentLine);  // Display the short title
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Now Playing:");  // Static label
      lcd.setCursor(0, 1);
      lcd.print(currentLine);  // Display the short title
    }
    delay(1000);
  }
}



