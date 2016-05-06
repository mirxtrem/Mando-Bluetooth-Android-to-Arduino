/* desarrollado por Gustavo Arango de mirxtrem.apps
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

Este codigo es para el proyecto Puente Levadizo mando por Bluetooth. 
Se pueden enviar ordenes a través de una app para android. 

El proyecto te ayuda a girar un motor dc en ambos sentidos por medio de un puente H conectados al microcontrolador Arduino.
El codigo esta alojado en GitHUB y se puede descargar fácilmente. Puedes subir una versión modificada y mejoirada contactandome. El codigo esta hecho por mirxtrem.apps. 
La licencia es de codigo abierto pero no olvides los creditos. El codigo esta hecho para Arduino UNO pero debería trabajar con otros tipos de Arduino.

YouTube:https://www.youtube.com/channel/UC6g5yVnUWAj_0c7RYRzHDng
correo: mirxtrem.apps@gmail.com
Facebook:https://www.facebook.com/mirxtrem.apps/
Repositorio: https://github.com/mirxtrem/Mando-Bluetooth-Android-to-Arduino.git
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/

   // Primero creamos las variables del programa

int microSup = 6;
int microInf = 7;
int subir = 13;
int bajar = 12;
int btonUp = 8;
int btonDown = 9;
int ledVerde = 10;
int ledRojo = 11;
int estadoMicroU = 0;
int estadoMicroD = 1;
int estadoUp = 0;
int estadoDown = 0;

void setup() {
  // Declaramos cuales son las salidas y las entradas y sus estados

pinMode(btonUp, INPUT);
pinMode(btonDown, INPUT);
pinMode(microSup, INPUT);
pinMode(microInf, INPUT);
pinMode(subir, OUTPUT);
pinMode(bajar, OUTPUT);
pinMode(ledVerde, OUTPUT);
pinMode(ledRojo, OUTPUT);
digitalWrite(subir, LOW);
digitalWrite(bajar, LOW);
digitalWrite(ledVerde, HIGH);
digitalWrite(ledRojo, LOW);

}

void loop() {
  // Acción A: La rampa sube a la señal de subir

estadoUp=digitalRead(btonUp);

  if(estadoUp == HIGH){
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, HIGH);
  delay(2000);
  digitalWrite(subir, HIGH);
  }
  
  // Acción B: El motor se detiene para que la rampa deje de subir
  
estadoMicroU=digitalRead(microSup);
  
  if(estadoMicroU == HIGH) {
  
    digitalWrite(subir, LOW);

  // Acción C: La rampa baja a la señal de bajar
  
  }
estadoDown=digitalRead(btonDown);

  if(estadoDown == HIGH){
  digitalWrite(bajar, HIGH);
  }
  
  // Acción D: La rampa baja y el semaforo cambia
  
estadoMicroD=digitalRead(microInf);
  
  if(estadoMicroD == HIGH) {
  
    digitalWrite(bajar, LOW);
    delay(2000);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
  }




}
