int U_min = 50;
int U_max = 255;
int U_inc = 1;
int cad = 50; // ms

int i_0;

void setup() {
  pinMode(25, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(U_inc >= 0){i_0 = U_min;} else {i_0 = U_max;}
  for(int i = i_0; U_min <= i && i <= U_max; i = i + U_inc){
    dacWrite(25, i);
    Serial.print(float(i)/255*3.3);
    Serial.println(" V");
    delay(cad);
  }
  U_inc = -U_inc;
}
