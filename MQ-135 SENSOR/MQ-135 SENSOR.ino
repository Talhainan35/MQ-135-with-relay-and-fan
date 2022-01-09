const int AOUTpin=A3;  // Analog çıkış pini
const int DOUTpin=7;  //  Dijital çıkış pini
int role = 2;
int esik;  // Eşik değeri
int ppm;  // Ölçülen ppm değeri
void setup() {
  Serial.begin(9600);  // Seri port başlat
  pinMode(DOUTpin, INPUT);
  pinMode(role, OUTPUT);
}
void loop()
{
  ppm= analogRead(AOUTpin);  // ppm değerini Analog pinden oku
  esik= digitalRead(DOUTpin);  // eşik değerinin aşılıp aşılmadığını oku
  Serial.print(" Hava kirliliği: ");  
  Serial.print(ppm);  //Hava kirliliği miktarını yaz
  Serial.print("ppm.");
  // Eşik değerinin aşılıp aşılmadığını kontrol et ve seri porta yaz

 if (ppm < 640)
  {
    Serial.println("Kirlilik eşik değerinin altında");
  }
  else
  {
    Serial.println("Kirlilik eşik değerinin üstünde");
  }
  delay(500);  // Yarım saniye bekle


  if (ppm > 670)
  {
   digitalWrite(role, HIGH);
  }
  else
  {
    digitalWrite(role, LOW);
  }
 
}
