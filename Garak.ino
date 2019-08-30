#include <LiquidCrystal.h>

#define btn1  A8  // 버튼1의아두이노핀번호정의
#define btn2  A9  // 버튼2의아두이노핀번호정의
#define btn3  A10 // 버튼3의아두이노핀번호정의
#define btn4  A11 // 버튼4의아두이노핀번호정의
#define btn5  A12 // 버튼5의아두이노핀번호정의
#define btn6  A13 // 버튼6의아두이노핀번호정의
#define btn7  A14 // 버튼7의아두이노핀번호정의
#define btn8  A15 // 버튼8의아두이노핀번호정의
#define btn9 A5   // 버튼9의아두이노핀번호정의
#define btn10 A4  // 버튼10의아두이노핀번호정의
//3:midi rx, 4:midi reset  아두이노핀3번4번은이미사용중
#define btn11 A3  // 버튼11의아두이노핀번호정의
#define btn12 A2  // 버튼12의아두이노핀번호정의

int max1 =0, max2 =0, max3 =0, max4 =0, max5 =0, max6=0, max7=0, max8=0,max9=0, max10=0;

const int rs = 12, en = 11, d4 = 32, d5 = 33, d6 = 34, d7 = 35;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte note = 0;
byte resetMIDI = 4; 
byte ledPin = 13; 
boolean bs1 = false;  // 버튼의 눌림 안눌림
boolean bs2 = false;  
boolean bs3 = false;
boolean bs4 = false;
boolean bs5 = false;
boolean bs6 = false;
boolean bs7 = false;
boolean bs8 = false;
boolean bs9 = false;
boolean bs10 = false;
boolean bs11 = false;
boolean bs12 = false;

boolean br1;  //버튼 값 임시저장용
boolean br2;  
boolean br3;
boolean br4;
boolean br5;
boolean br6;
boolean br7;
boolean br8;
boolean br9;
boolean br10;
boolean br11;
boolean br12;

int bn1 = 60; //버튼1의note(음계) "도"  
int bn2 = 62; //버튼2의note(음계) "레"
int bn3 = 64; //버튼3의note(음계) "미"
int bn4 = 65; //버튼4의note(음계) "파"
int bn5 = 67; //버튼5의note(음계) "솔"
int bn6 = 69; //버튼6의note(음계) "라"
int bn7 = 71; //버튼7의note(음계) "시"
int bn8 = 72; //버튼8의note(음계) "도"
int bn9 = 74; //버튼8의note(음계) "레"
int bn10 = 76; //버튼8의note(음계) "미"
byte byteData;

void setup() {  
  Serial.begin(9600);                                 
  Serial2.begin(31250);

  pinMode(resetMIDI, OUTPUT);
  digitalWrite(resetMIDI, LOW);
  delay(100);
  digitalWrite(resetMIDI, HIGH);
  delay(100);
  pinMode( btn1, INPUT);     
  digitalWrite( btn1, HIGH);  
  pinMode( btn2, INPUT);      
  digitalWrite( btn2, HIGH);
  pinMode( btn3, INPUT);
  digitalWrite( btn3, HIGH);
  pinMode( btn4, INPUT);
  digitalWrite( btn4, HIGH);
  pinMode( btn5, INPUT);
  digitalWrite( btn5, HIGH);
  pinMode( btn6, INPUT);
  digitalWrite( btn6, HIGH);
  pinMode( btn7, INPUT);
  digitalWrite( btn7, HIGH);
  pinMode( btn8, INPUT);
  digitalWrite( btn8, HIGH);
  pinMode( btn9, INPUT);
  digitalWrite( btn9, HIGH);
  pinMode( btn10, INPUT);
  digitalWrite( btn10, HIGH);
  pinMode( btn11, INPUT);
  digitalWrite( btn11, HIGH);  
  pinMode( btn12, INPUT);
  digitalWrite( btn12, HIGH);  
}

void loop() {
  int printMax[10] = {0};
  br1 = digitalRead(btn1);
  br2 = digitalRead(btn2);
  br3 = digitalRead(btn3);
  br4 = digitalRead(btn4);
  br5 = digitalRead(btn5);
  br6 = digitalRead(btn6);
  br7 = digitalRead(btn7);
  br8 = digitalRead(btn8);
  br9 = digitalRead(btn9);
  br10 = digitalRead(btn10);
  br11 = digitalRead(btn11);
  br12 = digitalRead(btn12);   
   
  int Reading1 = analogRead(btn1);
  Reading1 = map(Reading1, 235, 1000, 0, 1023);
  int Reading2= analogRead(btn2);
  Reading2 = map(Reading2, 235, 1000, 0, 1023);
  int Reading3 = analogRead(btn3);
  Reading3 = map(Reading3, 235, 1000, 0, 1023);
  int Reading4 = analogRead(btn4);
  Reading4 = map(Reading4, 235, 1000, 0, 1023);
  int Reading5 = analogRead(btn5);
  Reading5 = map(Reading5, 235, 1000, 0, 1023);
  int Reading6 = analogRead(btn6);
  Reading6 = map(Reading6, 235, 1000, 0, 1023);
  int Reading7 = analogRead(btn7);
  Reading7 = map(Reading7, 235, 1000, 0, 1023);
  int Reading8 = analogRead(btn8);
  Reading8 = map(Reading8, 235, 1000, 0, 1023);
  int Reading9 = analogRead(btn9);
  Reading9 = map(Reading9, 235, 1000, 0, 1023);
  int Reading10 = analogRead(btn10);
  Reading10 = map(Reading10, 226, 1000, 0, 1023);
  int Reading11 = analogRead(btn11);
  Reading11 = map(Reading11, 226, 1000, 0, 1023);
  int Reading12 = analogRead(btn12);
  Reading12 = map(Reading12, 226, 1000, 0, 1023);

  //값보정
  if (Reading1 < 5)
    Reading1 = 0;
  if (Reading2 < 5)
    Reading2 = 0;
  if (Reading3 < 5)
    Reading3 = 0;
  if (Reading4 < 5)
    Reading4 = 0;
  if (Reading5 < 5)
    Reading5 = 0;
  if (Reading6 < 5)
    Reading6 = 0;
  if (Reading7 < 5)
    Reading7 = 0;
  if (Reading8 < 5)
    Reading8 = 0;  
  if (Reading9 < 5)
    Reading9 = 0;  
  if (Reading10 < 5)
    Reading10 = 0;  

  //도
  if( !bs1 && !br1){
    // noteOff(0, bn1, 100);
  }
  else if( !bs1 && br1){
    noteOn(0, bn1, 100);
    bs1 = true;
  }
  else if( bs1 && br1){
    // noteOn(0, bn1, 100);
    if(Reading1 > max1){
    max1 = Reading1;
    }
  }
  else{ 
    noteOff(0, bn1, 100);
    bs1 =  false;
    if(max1 > 0){
      printMax[0] = max1;
    }
    max1 = 0;
  }

  //레
  if( !bs2 && !br2){
    // noteOff(0, bn2, 100);
  }
  else if( !bs2 && br2){
    noteOn(0, bn2, 100);
    bs2 = true;
  }
  else if( bs2 && br2){
    // noteOn(0, bn1, 100);
    if(Reading2 > max2){
      max2 = Reading2;
    }
  }
  else{ 
    noteOff(0, bn2, 100);
    bs2 =  false;
    if(max2 > 0){
      printMax[1] = max2;
    }  
    max2 = 0;
  }

  //미
  if( !bs3 && !br3){
    // noteOff(0, bn3, 100);
  }
  else if( !bs3 && br3){
    noteOn(0, bn3, 100);
    bs3 = true;
  }
  else if( bs3 && br3){
    // noteOn(0, bn3, 100);
    if(Reading3 > max3){
      max3 = Reading3;
    }
  }
  else{ 
    noteOff(0, bn3, 100);
    bs3 =  false;
    if(max3 > 0){
      printMax[2] = max3;
    }  
    max3 = 0;
  }

  //파
  if( !bs4 &&!br4){
    // noteOff(0, bn4, 100);
  }
  else if( !bs4 && br4){
    noteOn(0, bn4, 100);
    bs4 = true;
  }
  else if( bs4 && br4){
    // noteOn(0, bn4, 100);
    if(Reading4 > max4){
      max4 = Reading4;
    }
  }
  else{ 
    noteOff(0, bn4, 100);
    bs4 =  false;
    if(max4 > 0){
      printMax[3] = max4;
    }  
    max4 = 0;
  }
  
  //솔
  if( !bs5 && !br5){
    // noteOff(0, bn5, 100);
  }
  else if( !bs5 && br5){
    noteOn(0, bn5, 100);
    bs5 = true;
  }
  else if( bs5 && br5){
    // noteOn(0, bn5, 100);
    if(Reading5 > max5){
      max5 = Reading5;
    }
  }
  else{ 
    noteOff(0, bn5, 100);
    bs5 =  false;
    if(max5 > 0){
      printMax[4] = max5;
    }  
    max5 = 0;
  }
  
  //라
  if( !bs6 && !br6){
    // noteOff(0, bn6, 100);
  }
  else if( !bs6 && br6){
    noteOn(0, bn6, 100);
    bs6 = true;
  }
  else if( bs6 && br6){
    // noteOn(0, bn1, 100);
    if(Reading6 > max6){
      max6 = Reading6;
    }
  }
  else{ 
    noteOff(0, bn6, 100);
    bs6 =  false;
    if(max6 > 0){
      printMax[5] = max6;
    }  
    max6 = 0;
  }
  
  //시
  if( !bs7 && !br7){
    // noteOff(0, bn7, 100);
  }
  else if( !bs7 && br7){
    noteOn(0, bn7, 100);
    bs7 = true;
  }
  else if( bs7 && br7){
    // noteOn(0, bn7, 100);
    if(Reading7 > max7){
      max7 = Reading7;
    }
  }
  else{ 
    noteOff(0, bn7, 100);
    bs7 =  false;
    if(max7 > 0){
      printMax[6] = max7;
    }  
    max7 = 0;
  }
  
  //도
  if( !bs8 && !br8){
    // noteOff(0, bn8, 100);
  }
  else if( !bs8 && br8){
    noteOn(0, bn8, 100);
    bs8 = true;
  }
  else if( bs8 && br8){
    // noteOn(0, bn8, 100);
    if(Reading8 > max8){
      max8 = Reading8;
    }
  }
  else{ 
    noteOff(0, bn8, 100);
    bs8 =  false;
    if(max8 > 0){
      printMax[7] = max8;
    }  
    max8 = 0;
  }
  
  //레
  if( !bs9 && !br9){
    // noteOff(0, bn8, 100);
  }
  else if( !bs9 && br9){
    noteOn(0, bn9, 100);
    bs9 = true;
  }
  else if( bs9 && br9){
    // noteOn(0, bn8, 100);
    if(Reading9 > max9){
      max9 = Reading9;
    }
  }
  else{ 
    noteOff(0, bn9, 100);
    bs9 =  false;
    if(max9 > 0){
      printMax[8] = max9;
    }  
    max9 = 0;
  }
  
  //미
  if( !bs10 && !br10){
    // noteOff(0, bn8, 100);
  }
  else if( !bs10 && br10){
    noteOn(0, bn10, 100);
    bs10 = true;
  }
  else if( bs10 && br10){
    // noteOn(0, bn8, 100);
    if(Reading10 > max10){
      max10 = Reading10;
    }
  }
  else{ 
    noteOff(0, bn10, 100);
    bs10 =  false;
    if(max10 > 0){
      printMax[9] = max10;
    }  
    max10 = 0;
  }

  if(printMax[0] || printMax[1] || printMax[2] || printMax[3] || printMax[4] || printMax[5] || printMax[6] || printMax[7] || printMax[8] || printMax[9]){
    for(int i =0; i < 9; i++){
      Serial.print(printMax[i]);
      Serial.print(",");
    }
    Serial.println(printMax[9]);
  } 

  //*************** MIDI LOOPBACK ******************//
  if(Serial.available() > 0)
  {
    byteData =  Serial.read();
    Serial2.write( byteData);
  }  
}

//노트온미디메세지를송출. 버튼이눌린상태와같습니다.
void noteOn(byte channel, byte note, byte attack_velocity) {
talkMIDI( (0x90 | channel), note, attack_velocity);
}
//노트오프미디메세지를송출. 버튼이눌리지않은상태와같습니다.
void noteOff(byte channel, byte note,byte release_velocity) {
talkMIDI( (0x80 | channel), note, release_velocity);
}

void talkMIDI(byte cmd, byte data1, byte data2) {
digitalWrite(ledPin, HIGH);
Serial2.write(cmd );
Serial2.write(data1 );
if( (cmd & 0xF0) <= 0xB0)
Serial2.write(data2 );
digitalWrite(ledPin, LOW);
}
