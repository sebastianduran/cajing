const unsigned long period = 50;
unsigned long prevMillis = 0;
int num = 0;
char cadena[4]= {' ', ' ',' ',' '};
char respuesta[4] = {'1','2','3','4'};
const int solenoidPin = 13;
bool cerrado;
byte iRow = 0, iCol = 0;
const byte countRows = 4;
const byte countCols = 4;
const byte rowsPins[countRows] = {9, 8, 7, 6};
const byte colsPins[countCols] = {5, 4, 3, 2};
char keys[countRows][countCols] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}};

bool readKeypad(){
  bool rst = false;
  for (byte c = 0; c < countCols; c++){
    pinMode(colsPins[c], OUTPUT);
    digitalWrite(colsPins[c], LOW);
    for (byte r = 0; r < countRows; r++){
      if (digitalRead(rowsPins[r]) == LOW){
        iRow = r;
        iCol = c;
        rst = true; 
      }
    }
    digitalWrite(colsPins[c], HIGH);
    pinMode(colsPins[c], INPUT);
  }
  return rst;
}
 
void setup(){
  pinMode (solenoidPin, OUTPUT);
  Serial.begin(9600);
  for (byte c = 0; c < countCols; c++){
    pinMode(colsPins[c], INPUT);
    digitalWrite(colsPins[c], HIGH);
  }
 
  for (byte r = 0; r < countRows; r++){
    pinMode(rowsPins[r], INPUT_PULLUP);
  }
}
void resetCadena(){
  cadena[0] =' ';
  cadena[1] =' ';
  cadena[2] =' ';
  cadena[3] =' ';
}
void loop(){
  while(num <4){
    if (millis() - prevMillis > period){
      prevMillis = millis();
      if(readKeypad()){
        
        cadena[num]= (char) keys[iRow][iCol];
        num ++;
        delay (300);
        Serial.println(num);
        if (keys[iRow][iCol] == '*'){
            num = 0;
            resetCadena();
        } 
      }
    }
  }
  Serial.println(cadena);
  if(cadena[0]==respuesta[0] && cadena[1]==respuesta[1] && cadena[2]==respuesta[2] && cadena[3]==respuesta[3]){
    digitalWrite(solenoidPin, HIGH); 
    cerrado = false;
    while(!cerrado){
      if(readKeypad()){
        if (keys[iRow][iCol] == '*'){
          cerrado = true;
        }
      }
    }
  }
  digitalWrite(solenoidPin, LOW); 
  resetCadena();
  num = 0;
}
