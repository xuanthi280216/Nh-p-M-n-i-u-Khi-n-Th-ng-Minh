#include <AFMotor.h>
 
#include <Servo.h> 
 
int i, j;
 
Servo servo1;

Servo servo2;
 
void setup() {  
 
    Serial.begin(9600);           // mở cổng monitor 9600 bps  
    
    Serial.println("Test servo!");     
    
    servo1.attach(9);     // Khai báo chân servo

    servo2.attach(10);    // Khai báo chân servo
 
}
 
void loop() {
    
    for (i=255; i!=0; i--) {
        servo1.write(i-255); 
        delay(1);  
    }  
    for (i=0; i<255; i++) {   // chạy từ 0 đến 255 giá trị     
        servo1.write(i);    
        delay(1); // đợi 3 mili dây
    }     

    for (j=0; j<255; j++) {   // chạy từ 0 đến 255 giá trị     
 
        servo2.write(j);    
        
        delay(0.1); // đợi 3 mili dây
    }    
 
    for (j=255; j!=0; j--) {
        servo2.write(j-255); 
        delay(0.1);  
    }  
}
