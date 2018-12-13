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
#define PIN 4
#define pot1 A0
#define pot2 A1


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(13, 22, 6,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

  int x=1;
  int newNums = 0;
  int kindaNums =0;
 

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);//bluebutton
  pinMode(4,INPUT);//redbutton
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  
  matrix.begin();
  matrix.setBrightness(5);
  matrix.fillScreen(0);
  matrix.show(); // This sends the updated pixel colors to the hardware.

}

void loop() {
  int data = analogRead(pot1);
  int data2 = analogRead(pot2);
  float color2 = RED;
  float color = CYAN;
  newNums = map(data, 0, 1023, 0, 7);//is only going up to 12 ////make 13 and 12 do the same
  kindaNums = map(data2, 0, 1023, 0, 7);
    if(data == LOW){ // sends 0 
      newNums = 0;
      color=MAGENTA;
    }else if(newNums == 1){
      color= RED;
    }else if(newNums == 2){
      color= BLUE;
    }else if(newNums == 3){
      color= YELLOW;
    }else if(newNums == 4){
      color= GREEN;
    }else if(newNums == 5){
      color= MAGENTA;
    }else if(newNums == 6){
      color= CYAN;
    }else if(newNums == 7){
      color= WHITE;
    }else{
      color= RED;
    }

    if(data2 == LOW){ // sends 0 
      kindaNums = 0;
      color2=YELLOW;
    }else if(kindaNums == 1){
      color2= RED;
    }else if(kindaNums == 2){
      color2= BLUE;
    }else if(kindaNums == 3){
      color2= YELLOW;
    }else if(kindaNums == 4){
      color2= GREEN;
    }else if(kindaNums == 5){
      color2= MAGENTA;
    }else if(kindaNums == 6){
      color2= GREEN;
    }else if(kindaNums == 7){
      color2= WHITE;
    }else{
      color2= CYAN;
    }
        
    
    

  
  int bluebutton = digitalRead(3);
  int redbutton = digitalRead(4);
 if(bluebutton == HIGH ){
   for(int i=1; i<28; i++){
        matrix.fillScreen(0);
        matrix.drawCircle(0, 0, i, color);
        matrix.drawCircle(0, 0, i+1, color);
        matrix.drawCircle(0,0, i+2, color);
         matrix.drawCircle(0,0, i+3, color);
          matrix.drawCircle(0,0, i+4, color);
           matrix.drawCircle(0,0, i+5, color);
            matrix.drawCircle(0,0, i+6, color); // from top left

        matrix.show();
        delay(5);
      }
    Serial.println("blue pressed");
    //x++;    
  }else{
     Serial.println("not");
  }

  //_________
   if(redbutton == HIGH ){
   for(int i=1; i<30; i++){
    matrix.fillScreen(0);
        matrix.drawCircle(13, 22, i, color2); // from bottom right
        matrix.drawCircle(13, 25, i+1, color2);
        matrix.drawCircle(13,25, i+2, color2);
         matrix.drawCircle(13,25, i+3, color2);
          matrix.drawCircle(13,25, i+4, color2);
           matrix.drawCircle(13,25, i+5, color2);
            matrix.drawCircle(13,25, i+6, color2);
        matrix.show();
        delay(5);
      }
    Serial.println("red pressed");
   // x++;    
  }else{
     Serial.println("not");
  }
  //___________
  
  delay(50);
   //matrix.drawLine(0,0,x,x,YELLOW);
//matrix.drawPixel(0,0, RED); 
  
matrix.show();
}

//void drawLine(uint16_t x0, uint16_t y0, uint16_t x5, uint16_t y5, uint16_t color);
