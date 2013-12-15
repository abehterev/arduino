#define led1 13
#define led2 10
#define led3 9
#define led4 7

#define l_a 12
#define l_b 8
#define l_c 5
#define l_d 3
#define l_e 2
#define l_f 11
#define l_g 6
#define l_h 4

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(l_a, OUTPUT);
  pinMode(l_b, OUTPUT);
  pinMode(l_c, OUTPUT);
  pinMode(l_d, OUTPUT);
  pinMode(l_e, OUTPUT);
  pinMode(l_f, OUTPUT);
  pinMode(l_g, OUTPUT);
  pinMode(l_h, OUTPUT);
  
  Lcd_Off();
}

void Lcd_Off(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  Seg_Off();  
}

void Seg_Off(){
  static const byte SEG[8] = {l_a,l_b,l_c,l_d,l_e,l_f,l_g,l_h};
  for (int index = 0; index < 8; index++){
    digitalWrite(SEG[index], HIGH);
  }
}

void Seg_Test(){
  static const byte SEG[8] = {l_a,l_b,l_c,l_d,l_e,l_f,l_g,l_h};

  Seg_Off();
  
  for (int index = 0; index < 8; index++){
    digitalWrite(SEG[index], LOW);
  } 
}

void PrepareSegDigit(int D){
 static const byte Dig[10][8] = {
    {l_a,l_b,l_c,l_d,l_e,l_f,0,0},   // 0
    {l_b,l_c,0,0,0,0,0,0},           // 1
    {l_a,l_b,l_g,l_e,l_d,0,0,0},     // 2
    {l_a,l_b,l_g,l_c,l_d,0,0,0},     // 3
    {l_f,l_g,l_b,l_c,0,0,0,0},       // 4
    {l_a,l_f,l_g,l_c,l_d,0,0,0},     // 5
    {l_a,l_f,l_e,l_d,l_c,l_g,0,0},   // 6
    {l_a,l_b,l_c,0,0,0,0,0},         // 7
    {l_a,l_b,l_c,l_d,l_e,l_f,l_g,0}, // 8
    {l_a,l_b,l_c,l_d,l_f,l_g,0,0},   // 9
  };

 for (int index = 0; index < 8; index++){
   if (Dig[D][index]!=0){
     digitalWrite(Dig[D][index], LOW);
   }
 }
  
}

void Lcd_Test(){
  static const byte L[4] = {led1,led2,led3,led4};

  for (int index = 0; index < 4; index++){
    //Seg_Test();
    PrepareSegDigit(index+6);
    digitalWrite(L[index], HIGH);
    delay(2);
    digitalWrite(L[index], LOW);
    //delay(100);
    Seg_Off();
  }  
}

// the loop routine runs over and over again forever:
void loop() {
  Lcd_Test();
}
