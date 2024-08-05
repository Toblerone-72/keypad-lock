#include <LiquidCrystal.h>
#include <LCDKeypad.h>
#include <Keypad.h>

LCDKeypad lcd;

const byte rows = 4;
const byte cols = 4;

char keyMap[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[rows] = {22, 24, 26, 28};
byte colPins[cols] = {23, 25, 27, 29};

Keypad customKeypad = Keypad(makeKeymap(keyMap), rowPins, colPins, rows, cols);

String startupPhrase = "ACTIVE";
String loadString = "**********";
String kString;
String cString = "1397ADBC"; // enter correct code here

int start;
int attempt = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.blink();
  lcd.print("STARTING: ");
  delay(1720);
  lcd.setCursor(3, 1);
  for(int i = 0; loadString[i] != '\0'; i++) {
    lcd.print(loadString[i]);
    delay(242);
  }
  delay(720);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(startupPhrase);
  start = 1;
}
  
void loop() {
  char kIn = customKeypad.getKey();
  if(start == 1 && kIn && kIn != '#' && kIn != '*') {
    lcd.clear();
    lcd.print(kIn);
    kString += kIn;
    start = 0;
  }
  else if(kIn) {
    if(attempt == 5) {
      digitalWrite(31, HIGH);
    }
    else if(kIn == '#') {
      lcd.clear();
      kString = "";
    }
    else if(kIn == '*') {
      lcd.setCursor(0, 1);
      lcd.print(kString);
      lcd.print(" | ");
      lcd.print(attempt);
      delay(4200);
      lcd.clear();
      if(kString == cString) {
        lcd.print("****ACCEPTED*****");
        digitalWrite(30, HIGH);
        delay(4200);
        kString = "";
        lcd.clear();
        delay(4200);
        digitalWrite(30, LOW);
      }
      else {
        lcd.print("**NOT ACCEPTED**");
        kString = "";
        attempt++;
        lcd.print(", ");
        lcd.print(attempt);
      }
    }
    else {
      lcd.print(kIn);
      kString += kIn;
      Serial.print("WEEEEEEE");
    }
  }
  else {
    Serial.print("need more input");
  }
}