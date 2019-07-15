#include <SoftwareSerial.h>
SoftwareSerial ESP(2, 3); // Pin 2 (RX) y Pin 3 (TX)
String W = " ";
char w = ' ';
int boton=5;
void setup()
{
  pinMode(boton,INPUT);
Serial.begin(9600);
ESP.begin(9600);
}
void loop()
{
if (ESP.available()) // Lo que entra por WIFI a Serial
{
w = ESP.read() ;
Serial.print(w);
W = W + w; // Se va acumulando un String con lo que entra
}

int estado = digitalRead(boton);
// Condicional para saber estado del pulsador




if (Serial.available()) // Lo que entra por Serial a WIFI
{
char s = Serial.read();
ESP.print(s);
}
if ( estado == 0 ) // Comprobar si la cadena "enter" está incluida en el String
{
ESP.println("AT+CIPSEND=0,21");

if (ESP.find(">")) // Si se recibe la petición del mensaje (“>”)
{
Serial.println("Enviando al Navegador...");
ESP.println("Boton no presionado\n"); // String a enviar al navegador


} //del if
}
else
{
  if ( estado == 1 ) // Comprobar si la cadena "enter" está incluida en el String
{
ESP.println("AT+CIPSEND=0,18");

if (ESP.find(">")) // Si se recibe la petición del mensaje (“>”)
{
Serial.println("Enviando al Navegador...");
ESP.println("Boton presionado\n"); // String a enviar al navegador

}
}
}
}//de loop
