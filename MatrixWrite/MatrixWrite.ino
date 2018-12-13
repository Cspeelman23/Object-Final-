#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

#define PIN 3
#define pot1 A0

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(13, 22, 6,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);


  float colors[] = {
  GREEN, MAGENTA, CYAN };
  int x = matrix.width();
  int pass = 0;
 

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);//bluebutton

  matrix.begin();
  matrix.setBrightness(7);
  matrix.setTextColor(colors[0]);
  matrix.setTextWrap(false);
 
}
int count= 0;
String temp= "";
String keep1,keep2,keep3,keep4,keep5;

void loop() {
  int bluebutton = digitalRead(3);
  int data = analogRead(pot1);
  int letters = map(data,0,1023, 0,32);//0 for when not pressed //having problems getting to 26

    if(count<5){
      Serial.println(letters);
     //Serial.println(keep1 +keep2 + keep3+ keep4 +keep5);
     Serial.println(temp);

        matrix.fillScreen(0);
        matrix.setCursor(x, 0);
        matrix.print(temp);
        if(--x < -10) {
          x = matrix.width();
          if(++pass >= 3) pass = 0;
          matrix.setTextColor(colors[pass]);
        }
          matrix.show();
          delay(100);
    }else{
      Serial.println(keep1 +keep2 + keep3+ keep4 +keep5);
        matrix.fillScreen(0);
        matrix.setCursor(x, 0);
        String printMe= keep1 +keep2 + keep3+ keep4 +keep5;
        matrix.print(printMe);
        if(--x < -26) {
          x = matrix.width();
          if(++pass >= 3) pass = 0;
          matrix.setTextColor(colors[pass]);
        }
          matrix.show();
          delay(100);
    }

  if(letters== 1){
    temp= "A";
    }else if(letters==2){
      temp= "B";
    }else if(letters==3){
      temp= "C";
    }else if(letters==4){
      temp= "D";
    }else if(letters==5){
      temp= "E";
      }else if(letters==6){
      temp= "F";
      }else if(letters==7){
      temp= "G";}
      else if(letters==8){
      temp= "H";
      }else if(letters==9){
      temp= "I";
      }else if(letters==10){
      temp= "J";
      }else if(letters==11){
      temp= "K";
      }else if(letters==12){
      temp= "L";
      }else if(letters==13){
      temp= "M";
      }else if(letters==14){
      temp= "N";
      }else if(letters==15){
      temp= "O";
      }else if(letters==16){
      temp= "P";
      }else if(letters==17){
      temp= "Q";
      }else if(letters==18){
      temp= "R";
      }else if(letters==19){
      temp= "S";
      }else if(letters==20){
      temp= "T";
      }else if(letters==21){
      temp= "U";
      }else if(letters==22){
      temp= "V";
      }else if(letters==23){
      temp= "W";
      }else if(letters==24){
      temp= "X";
      }else if(letters==25){
      temp= "Y";
      }else if(letters==26){
      temp= "Z";
    }else{
      temp=" ";
    }

 

  
 if(bluebutton == HIGH ){
    
    count ++;
     Serial.println(count);
    if(count==1){
    keep1 = temp;
    }else if(count ==2){
       keep2=temp;
      }else if(count ==3){
        keep3=temp;
      }else if(count ==4){
         keep4=temp;
      }else if(count ==5){
         keep5=temp;
      }else{// 5+ entered
      }  
    
     delay(500); 
      
  }
  




  // matrix.drawLine(0,0,x,x,YELLOW);

}

//void drawLine(uint16_t x0, uint16_t y0, uint16_t x5, uint16_t y5, uint16_t color);
