//inisialisasi pin yang dipakai menuju ic l293d
#define motor1 2
#define motor2 3
#define motor3 4
#define motor4 5
//inisialisasi pin yang dipakai untuk output LED
#define ledstop 6
#define ledrun 7

//inisialisasi sensor ultrasonik
int echoPin = 8;
int trigPin = 9;

void setup() {
  //Serial yang dipakai untuk print pada serial monitor
  Serial.begin(115200);
  //Mode yang digunakan saat Arduino nano Aktif
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(ledstop, OUTPUT);
  pinMode(ledrun, OUTPUT);
  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  
}

float ultrasonik(){  //membuat fungsi ultrasonik untuk mendapatkan jarak dari sensor ultrasonik menggunakan rumus
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int durasiPantulan = pulseIn(echoPin, HIGH);
  return durasiPantulan * 0.034 / 2; //membuat nilai dari fungsi ultrasonik menjadi hasil perhitungan durasi*0,034/2
}


void loop() {
  //tipe data 32 bit
  float jarak = ultrasonik();
  //jika jarak lebih dari sama dengan 36 Cm maka gate IC BC547 akan aktif
  if(jarak>=36){
  digitalWrite(ledrun, HIGH);  
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, HIGH);
  
  Serial.println(jarak);
  }
  //jika jarak kurang dari sama dengan 35 Cm maka gate IC BC547 akan nonaktif
  if(jarak<=35){  
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);  
  Serial.println(jarak);
  }

  //jika jarak lebih dari sama dengan 36 Cm maka led hijau akan menyala
  if((jarak>=36) && (jarak !=0)){
  digitalWrite(ledrun, HIGH); 
  }
  else{
  digitalWrite(ledrun, LOW);  
  }
  //jika jarak kurang dari sama dengan 35 dan jarak lebih dari sama dengan 1 maka led merah menyala
  if((jarak<=35) && (jarak >= 1 )){
  digitalWrite(ledstop, HIGH);    
  //dibuat range lebih dari sama dengan 1
  }
  //jika tidak led merah akan mati
  else{ //jika tidak led merah akan mati
  digitalWrite(ledstop, LOW);  
  
  }
}
