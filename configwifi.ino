#include "SoftwareSerial.h"

SoftwareSerial wifi (2, 3); // RX | TX //se nombra el módulo ESP8266 como “wifi”

char txt; // Se crea una variable tipo char donde se almacene el texto que se leerá

void setup()

{ Serial.begin(9600); //Inicia el monitor serial a 9600 baudios

wifi.begin(9600); // Se inicia el módulo wifi a una velocidad de 115200 baudios que es la lectura que soporta y está configurado el ESP8266

}

void loop()

{if (Serial.available()) //Si hay datos, envialos cuando los reciba

{txt = Serial.read(); // Se leen los datos que se enviaron

wifi.print(txt); // Imprime los datos introducidos

}

if (wifi.available()) //Igual que el serial, en este caso sería el módulo wifi que envíe datos cuando los reciba

{txt = wifi.read(); // Se leen los datos en el módulo wifi

Serial.print(txt); // Que se impriman los datos del módulo en el monitor serie

}

}
