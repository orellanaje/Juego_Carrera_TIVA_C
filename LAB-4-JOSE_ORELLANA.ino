bool Inicio = false;
byte J1 = 0x01;
byte J2 = 0x01;

void setup() {

Serial.begin(9600);
 // COnfig OUPUTS e INPUTS 
  pinMode(PF_0, INPUT_PULLUP);
  pinMode(PF_4, INPUT_PULLUP);
  pinMode(PA_3, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  
  pinMode(PD_0, OUTPUT);
  pinMode(PD_1, OUTPUT);
  pinMode(PD_2, OUTPUT);
  pinMode(PD_3, OUTPUT);
  pinMode(PE_1, OUTPUT);
  pinMode(PE_2, OUTPUT);
  pinMode(PE_3, OUTPUT);
  pinMode(PA_7, OUTPUT);

  pinMode(PB_5, OUTPUT);
  pinMode(PB_0, OUTPUT);
  pinMode(PB_1, OUTPUT);
  pinMode(PE_4, OUTPUT);
  pinMode(PE_5, OUTPUT);
  pinMode(PB_4, OUTPUT);
  pinMode(PA_5, OUTPUT);
  pinMode(PA_6, OUTPUT);

}
//--------------------------------------------------------------------------------
void Semaforo(){
  Inicio = false;
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  Inicio = true;
}

//-----------------------------------------------------------------------------------
void loop() {
  if(digitalRead(PA_3) == LOW)
  {
    Semaforo();
    J1 = 0x01;
    J2 = 0x01;
  }
 
  if (Inicio == true){

      if (J1 == 0x00)
      {
          J1 = 0x01;
      }
      if (J2 == 0x00)
      {
          J2 = 0x01;
      }
      
      if (digitalRead(PF_4) == LOW)
      {
      J1 = J1 << 1;
      }
      if (digitalRead(PF_0) == LOW)
      {
      J2 = J2 << 1;
      }

      if (J1 == 0x80)
      {
        Inicio = false;
        digitalWrite(RED_LED, 153);
        digitalWrite(BLUE_LED, 196);
      }
      if (J2 == 0x80)
      {
        Inicio = false;
        digitalWrite(BLUE_LED, 255);
      }
     
      Player_1(J1);
      Player_2(J2);

  delay(200);
  }
}

//-----------------------------------------------------

void Player_1(byte player1){
  digitalWrite(PD_0, bitRead(player1,0));
  digitalWrite(PD_1, bitRead(player1,1));
  digitalWrite(PD_2, bitRead(player1,2));
  digitalWrite(PD_3, bitRead(player1,3));
  digitalWrite(PE_1, bitRead(player1,4));
  digitalWrite(PE_2, bitRead(player1,5));
  digitalWrite(PE_3, bitRead(player1,6));
  digitalWrite(PA_7, bitRead(player1,7));
}

void Player_2(byte player2){
  digitalWrite(PB_5, bitRead(player2,0));
  digitalWrite(PB_0, bitRead(player2,1));
  digitalWrite(PB_1, bitRead(player2,2));
  digitalWrite(PE_4, bitRead(player2,3));
  digitalWrite(PE_5, bitRead(player2,4));
  digitalWrite(PB_4, bitRead(player2,5));
  digitalWrite(PA_5, bitRead(player2,6));
  digitalWrite(PA_6, bitRead(player2,7));
}
