//Prueba y transmision de texto con el modulo RF para Arduino http://zygzax.com
//TRANSMISOR
#include <VirtualWire.h>
const int buttonPin = 5;
const char *mensaje;
int buttonState = 0;



void setup()
{
vw_set_ptt_inverted(true); // Requerido por el modulo RF
vw_setup(2000); // Velocidad de conexion bps
vw_set_tx_pin(3); // Pin en el que conectamos la patilla data del transmisor

//BOTON
pinMode(buttonPin, INPUT);
 
}
 
void loop()
{

buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    mensaje = "1";
  }
  else {
    // turn LED off:
    mensaje = "0";
  }

//Mensaje a enviar:
vw_send((uint8_t *)mensaje, strlen(mensaje));
vw_wait_tx(); // Esperamos a que termine de enviar el mensaje
delay(500); // Esperamos para enviar el siguiente mensaje
}
