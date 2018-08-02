int pulsador1 = 52; // primer pulsador
int LED = 13;

void setup () { 
  pinMode (LED, OUTPUT); //configurado como salida
  analogWrite(LED, 0);
  pinMode (pulsador1,INPUT); //configurado de entrada
}

void loop () {
  if (digitalRead(pulsador1) == HIGH){ //si el pulsador1 está en alto
    analogWrite (LED, 250); //encender el LED
    Serial.print("Recibe");
  }else{
    analogWrite(LED, 0); //apagar el LED
  }
  delay(100);
}
