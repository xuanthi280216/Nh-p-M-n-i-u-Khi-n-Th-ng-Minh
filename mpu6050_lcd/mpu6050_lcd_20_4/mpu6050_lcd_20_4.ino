

 
 /*
 * 
 * This code is basic usage MPU-6050 Accelerometer and Gyroscope
 * Running this code you will get angles only.
 * The Angles at X, Y and Z are displayed on LCD2004-I2C display module
 * 
 * Library and code have been taken from:
 * https://github.com/tockn/MPU6050_tockn
 * 
 * Updated by Ahmad Shamshiri on July 07, 2018 at 13:43 in Ajax, Ontario, Canada
 * for Robojax.com
 * Get this code from Robojax.com
 * Watch video instruction for this code at:ttps://youtu.be/ixe--SXemp8
 * 
 * You will need to watch 2 videos before following the instruction in this video:
 * 1-MPU6050 Introduction video and code: https://youtu.be/uhh7ik02aDc
 * 2-LCD1602 with I2C module video and code https://youtu.be/q9YC_GVHy5A
 */
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);

  // initialize the LCD, 
//  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.clear();
   lcd.setCursor (0,0); //
   lcd.print("Robojax MPU-6050"); 
   lcd.setCursor (0,1); //   
 
   lcd.print("Please Wait - 3");  
   lcd.setCursor (0,1); // 
   delay(1000);        
   lcd.print("Please Wait - 2");  
   delay(1000); 
   lcd.setCursor (0,1); //      
   lcd.print("Please Wait - 1");  
   delay(1000);       
}

void loop() {

  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  
  lcd.clear();// clearn previous values from screen
   lcdDisplay(
            mpu6050.getAngleX(), // send angle X
            mpu6050.getAngleY(), // send angle Y
            mpu6050.getAngleZ()  // send angle Z
            );                       
   delay(100);

}// loop end

/*
 * Written by Ahmad Shamshiri for Robojax.com
 * lcdDisplay(float x, float y, float z)
 * displays value and title on LCD2004-I2C display
 * How to use:
 * just pass the three values and it will display it
 * lcdDisplay(mpu6050.getAngleX() , mpu6050.getAngleY() , mpu6050.getAngleZ() )
 */
void lcdDisplay(float x, float y, float z)
{
   // Robojax.com MPU6050 Demo with LCD2004-I2C Display
   lcd.setCursor (0,0); //
   lcd.print("Robojax MPU-6050");  
    
   lcd.setCursor (0,1); //character zero, line 1
   lcd.print("Angle X:");
   lcd.setCursor (9,1); //
   lcd.print(x);   
   
   lcd.setCursor (0,2); //character zero, line 2
   lcd.print("Angle Y:");
   lcd.setCursor (9,2); //
   lcd.print(y);

   lcd.setCursor (0,3); //character zero, line 3
   lcd.print("Angle Z:");
   lcd.setCursor (9,3); //
   lcd.print(z);   
 
}
