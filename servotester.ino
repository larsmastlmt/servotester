#include<Servo.h>
Servo servo;
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int val=0, angle=0;

void setup() {
 servo.attach(3);
 servo.write(0);
 pinMode(A6,INPUT_PULLUP);
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  for(;;);
 }
 delay(2000);
 display.clearDisplay();
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(0,0);
 display.println("Lars");
 display.println("SERVO");
 display.println("Tester");
 display.display();
 delay (4000);
}

void loop() {

 val=analogRead(A6);
 angle= map(val,0,1023,0,178);
 display.clearDisplay();
 display.setTextSize(5);
 display.setTextColor(WHITE);
 display.setCursor(10,0);
 display.println(angle);
 display.display();
 servo.write(angle);
 delay(100);

}
