/* Este codigo esta hecho para el proyecto 'Puente levadizo a través de mobil android' por mirxtrem.apps
  Gustavo Arango.
  */
String stringGral, dispositivo, valorRecibido;

  //Declaramos las variables.
  int pin13 = 13;
  int pin12 = 12;
  int estado = 0;



void setup() {
  // Abre el puerto serial:
  Serial.begin(9600);
  //Declaramos las variables como Salidas, y su estado en cero.
  
  pinMode(pin13, OUTPUT);
  digitalWrite(13,LOW);
  pinMode(pin12, OUTPUT);
  digitalWrite(12, LOW);
}

// se configura las acciones segun la orden que reciba del celular a travéz comunicación Bluetooth.
void loop()
{
    if(Serial.available())
    
    {
      estado = Serial.read();   
    }
 
  //Si recibe 'U' habilita la salida 13 y deshabilita la salida 12. 
    if (estado =='U')
  {
      digitalWrite(pin13, HIGH);
      digitalWrite(pin12, LOW);
  }

//Si recibe 'D' habilita la salida 12 y deshabilita la salida 13.
    if (estado =='D')
  {
      digitalWrite(pin12, HIGH);
      digitalWrite(pin13, LOW);
  }
//Si recibe 'D' deshabilita ambas salidas.  
    if (estado =='S')
  {
      digitalWrite(pin12, LOW);
      digitalWrite(pin13, LOW);
  }  
}



