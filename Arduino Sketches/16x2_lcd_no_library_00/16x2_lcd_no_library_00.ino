#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define RS 12
#define E 11


void LCD_Write(byte cmd,int cmddta){
  digitalWrite(RS,cmddta); //Change RS for command/data
  digitalWrite(D4,(cmd & 0b00010000)>>4);
  digitalWrite(D5,(cmd & 0b00100000)>>5);
  digitalWrite(D6,(cmd & 0b01000000)>>6);
  digitalWrite(D7,(cmd & 0b10000000)>>7);
  delay(0.5);
  digitalWrite(E,HIGH);
  delay(0.5);
  digitalWrite(E,LOW);
  delay(0.5);
  digitalWrite(D4,(cmd & 0b00000001)>>0);
  digitalWrite(D5,(cmd & 0b00000010)>>1);
  digitalWrite(D6,(cmd & 0b00000100)>>2);
  digitalWrite(D7,(cmd & 0b00001000)>>3);
  delay(0.5);
  digitalWrite(E,HIGH);
  delay(0.5);
  digitalWrite(E,LOW);
  delay(0.5);
}


void LCD_Char(char character){
  LCD_Write(character,1);
}

void LCD_String(String str){
 char *cstr = new char[str.length()];
 strcpy(cstr, str.c_str());
 while(*cstr) LCD_Char (*cstr++);
}

void LCD_Int(unsigned long n){
 int nDigits = floor(log10(abs(n)))+1 ;
  char c[10];
  sprintf(c, "%d", n);
  for (int i=0;c[i] > 0;i++) LCD_Char(c[i]);
}



void LCD_Clear(){
  LCD_Write(0x01,0);
}

void LCD_Init(){
  LCD_Write(0x33,0);
  delay(0.5);
  LCD_Write(0x32,0);
  delay(0.5);
  LCD_Write(0x28,0);
  delay(0.5);
  LCD_Write(0x0C,0);
  delay(0.5);
  LCD_Write(0x06,0);
  delay(0.5);
  LCD_Write(0x01,0);
  delay(0.5);
}

void LCD_SetCursor(int row, int col){
   if (col == 0)LCD_Write((row | 0x80),0);
   if (col == 1)LCD_Write((row | 0x80)+ 0x40,0);
   if (col == 2)LCD_Write((row | 0x80)+ 0x10,0);
   if (col == 3)LCD_Write((row | 0x80)+ 0x50,0);
   delay(0.5);

}



void setup() {
  Serial.begin(9600);
for(int i = 2;i < 13; i++){ //Set pin 2 ,3 ,4, 5 to output mode
  pinMode(i,OUTPUT);
}
delay(50);
LCD_Init();
}

void loop() {
  LCD_SetCursor(0,0);
  LCD_String("Hello World!");
  LCD_SetCursor(1,1);
  LCD_Int(millis());
 }
