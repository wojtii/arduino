#include <LedControl.h>
#include<binary.h>
//snail algorithm
//                       DIN, CLC, CS, no of matrices
LedControl lc = LedControl(4,3,2,1);
int delay_val = 50;
void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,4);
  lc.clearDisplay(0);
}

void loop() {
  delay_val = 50;
  for(int counter=0; counter<4;counter++){
    delay_val -=5;
    for(int i=counter; i<8-counter; i++){
        lc.setLed(0,i,counter,true);
        delay(delay_val);
    }
    for(int i=counter; i<8-counter; i++){
        lc.setLed(0,7-counter,i,true);
        delay(delay_val);
    }
    for(int i=8-counter; i>=counter; i--){
      lc.setLed(0,i,7-counter,true);
      delay(delay_val);
    }
    for(int i=8-counter; i>=counter; i--){
      lc.setLed(0,counter,i,true);
      delay(delay_val);
      }
  }
  delay_val = 50;
  int x_down = 3, y_down = 4;
  int x_left = 4, y_left = 4;
  int x_up = 4, y_up = 3;
  int x_right = 2, y_right =3;
  
  for(int c = 1; c<8; c+=2){
    delay_val +=10;
    for(int i =0; i<c; i++){
      lc.setLed(0, x_down+i, y_down, false);
      delay(delay_val); 
    }

    for(int i=0; i<c; i++){
      lc.setLed(0, x_left, y_left-i, false);
      delay(delay_val);
    }
    x_down--;
    y_down++;
    x_left++;
    y_left++;
    
    for(int i=0; i<c+1; i++){
      lc.setLed(0, x_up-i, y_up, false);
      delay(delay_val);
    }
    for(int i=0; i<c+1; i++){
      lc.setLed(0, x_right,y_right+i, false);
      delay(delay_val);
    }
    x_up++;
    y_up--;
    x_right--;
    y_right--;
    
  }
}
