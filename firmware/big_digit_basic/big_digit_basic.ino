
/*
#       _\|/_   A ver..., ¿que tenemos por aqui?
#       (O-O)        
# ---oOO-(_)-OOo---------------------------------
 
 
##########################################################
# ****************************************************** #
# *           DOMOTICA PARA PRINCIPIANTES              * #
# *                  BIG DIGIT 2022                    * #
# *          Autor:  Eulogio López Cayuela             * #
# *                                                    * #
# *       Versión 1.0        Fecha: 28/02/2022         * #
# ****************************************************** #
##########################################################
*/





//------------------------------------------------------
//Importamos las librerias necesarias
//------------------------------------------------------


#include  <Arduino.h>				        //compatibilidad con entorno ARDUINO en platformio


#include <Adafruit_NeoPixel.h>      // Incluir biblioteca Adafruit NeoPixel

//ficheros personales 
#include "definiciones.h"
#include "pinout.h"
#include "variables.h"
#include "led_strip.h"




/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//   Prototipado de  funciones
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/


void bigDigit_NUM( uint8_t pos ,uint8_t numero, uint8_t _red, uint8_t _green, uint8_t _blue );
void bigDigit_TXT( uint8_t pos ,uint8_t _caracter, uint8_t _red, uint8_t _green, uint8_t _blue );
void bigCifra( uint16_t cifra, uint8_t _red, uint8_t _green, uint8_t _blue );
void borrarDisplay( void );
void rotuloRotativoPuntero(uint8_t *mensaje, int8_t LM, int8_t sentido, uint8_t _r, uint8_t _g, uint8_t _b, uint16_t _pause);


float read_NTC( void ); 


void contador( void );
void mostrar_mensaje( void );
void termometro_color( void );



/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
   ****************************************************************************************************** 
                                    FUNCION DE CONFIGURACION
   ****************************************************************************************************** 
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/

void setup()
{
  
  pinMode(PIN_LED_OnBoard, OUTPUT);
  digitalWrite(PIN_LED_OnBoard, LED_ON);

  pinMode(PIN_TIRA_LED, OUTPUT);  // pin para la linea DATA de los leds
  tiraLEDS.begin();               // Initializar el objeto 'tiraLEDS'
  
  /* establecer la cantidad de brillo */
  tiraLEDS.setBrightness(25);
  tiraLEDS.clear();
  tiraLEDS.show();



  digitalWrite(PIN_LED_OnBoard, LED_OFF);     



}




/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
   ****************************************************************************************************** 
                                  BUCLE PRINCIPAL DEL PROGRAMA
   ****************************************************************************************************** 
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/

 
void loop()
{
    
contador();
mostrar_mensaje();
termometro_color();
}




/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//   FUNCIONES DE CONTROL BASICO DEL DISPLAY  (CONTROL DE LA TIRA DE LEDS)
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/

//========================================================
//    BORRAR DISPLAY
//========================================================

 
void borrarDisplay()
{
  tiraLEDS.clear();
}


//========================================================
//    CREAR DIGITOS NUMERICOS
//========================================================

void bigDigit_NUM(uint8_t pos ,uint8_t numero, uint8_t _red, uint8_t _green, uint8_t _blue)
{
  //buscalos numeros sobre una lista, ideal apra resultados de operaciones numericas
  for (int pixel=0; pixel< 7; pixel++){  // recorremos la matrid de segmentos para formar el numero
    //la matriz de segmentos indica si los led se apagan o encienden
    if (numero>11) { numero=numero%10; }  //evitar que cifras grandes desborden
    if (getBit(numeros[numero],pixel) == 1) { //encender el segmento
      tiraLEDS.setPixelColor(pixel+pos*7, tiraLEDS.Color(_red, _green, _blue)); //color unico
    }
    else { tiraLEDS.setPixelColor(pixel+pos*7, 0); }   
  }
  tiraLEDS.show(); //pasar la informaciona los led
}  



//========================================================
//    CREAR CARACTERES GENERICOS TEXTO, NUMERO Y SIMBOLOS
//========================================================

void bigDigit_TXT(uint8_t pos ,uint8_t _caracter, uint8_t _red, uint8_t _green, uint8_t _blue)
{
  for (int pixel=0; pixel< 7; pixel++){  // recorremos la matrid de segmentos para formar el numero
    //la matriz de segmentos indica si los led se apagan o encienden
    if (getBit(_caracter,pixel) == 1) { //encender el segmento
      tiraLEDS.setPixelColor(pixel+pos*7, tiraLEDS.Color(_red, _green, _blue)); //color unico
    }
    else { tiraLEDS.setPixelColor(pixel+pos*7, 0); }   
  }
  tiraLEDS.show(); //pasar la informaciona los led
} 


//========================================================
//    CREAR CIFRAS QUE OCUPAN TODO EL DISPLAY (NUMEROS O-9999)
//========================================================

void bigCifra(uint16_t cifra, uint8_t _red, uint8_t _green, uint8_t _blue)
{
  uint8_t unidades = cifra%10;
  uint8_t decenas  = (cifra/10)%10;
  uint8_t centenas = (cifra/100)%10;
  uint8_t millares = (cifra/1000)%10; 
  bigDigit_NUM(3, millares, _red, _green, _blue);
  bigDigit_NUM(2, centenas, _red, _green, _blue);
  bigDigit_NUM(1, decenas,  _red, _green, _blue);
  bigDigit_NUM(0, unidades, _red, _green, _blue);
}  

//========================================================
//    ROTULO ROTATIVO PUNTEROS
//========================================================

void rotuloRotativoPuntero(uint8_t *mensaje, int8_t LM, int8_t sentido, uint8_t _r, uint8_t _g, uint8_t _b, uint16_t _pause)
{
  borrarDisplay();

  const uint8_t DISPLAY_SIZE = 4;
  const uint8_t EXTRA_ESPACES = 0;  //Espacios añadidos tras el mensaje.
                                    //crean un retraso en la repeticion del mensaje


  int8_t pos;

  if (sentido>0)   pos = LM+ DISPLAY_SIZE + EXTRA_ESPACES; //derecha
  else pos = (-1) * DISPLAY_SIZE;
 

  while(true){
    if (sentido>0) { //derecha
      for(int8_t offset=DISPLAY_SIZE-1;offset>=0;offset--){
      if ((pos-offset)>=0 && (pos-offset)<LM) {bigDigit_TXT( offset, mensaje[pos-offset]  , _r, _g, _b ); }
      else{bigDigit_TXT( offset, CARACTER_OFF  , COLOR_NEGRO ); }
      }  
      pos--;
      if( pos <-1 ) { return; } 
    }  
    else{ //izquierda
      for(int8_t offset=0;offset<DISPLAY_SIZE;offset++){
        if ((pos-offset)>=0 && (pos-offset)<LM) {bigDigit_TXT( offset, mensaje[pos-offset]  , _r, _g, _b ); }
        else{ bigDigit_TXT( offset, CARACTER_OFF  , COLOR_NEGRO ); }
      }    
      pos++;
      if( pos >= (LM + DISPLAY_SIZE + EXTRA_ESPACES) ) { return; } 
    }
    delay(_pause);    
   
  }
}

/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//    SENSOR NTC  
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/

float read_NTC() 
{
  const int Rc = 10000;       //valor de la resistencia
  float K = 2.5;              //factor de disipacion en mW/C
  float A = 1.11492089e-3;
  float B = 2.372075385e-4;
  float C = 6.954079529e-8;
  
  float ERROR_NTC = 1.128;//1.128-1.132

  //------------------------------//
  
  float raw = analogRead(PIN_sensorNTC);

  float Vcc = 3.3; 
  float V =  raw / 1023 * Vcc;
  
  float R = (Rc * V ) / (Vcc - V);
  
 
  float logR  = log(R);
  float R_th = 1.0 / (A + B * logR + C * logR * logR * logR );
 
  float kelvin = R_th - V*V/(K * R)*1000;
  float celsius = kelvin - 273.15;

  return celsius*ERROR_NTC;

}




/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//   OTRAS FUNCIONES DEL DISPLAY
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/


//========================================================
//    TERMOMETRO COLOR SEGUN TEMPERATURA
//========================================================

void termometro_color()
{
  float temperatura = read_NTC();
  uint8_t unidades = int(temperatura)%10;
  uint8_t decenas = int(temperatura)/10; 

  if(temperatura<15){
    bigDigit_NUM(3, decenas,  COLOR_AZUL);
    bigDigit_NUM(2, unidades, COLOR_AZUL); 
    bigDigit_TXT(1 ,CARACTER_GRADO, COLOR_AZUL);       
    bigDigit_TXT(0 ,CARACTER_C, COLOR_AZUL);
  }
  else if(temperatura>24){
    bigDigit_NUM(3, decenas,  COLOR_ROJO);
    bigDigit_NUM(2, unidades, COLOR_ROJO);
    bigDigit_TXT(1 ,CARACTER_GRADO, COLOR_ROJO);        
    bigDigit_TXT(0 ,CARACTER_C, COLOR_ROJO);
  }
  else{
    bigDigit_NUM(3, decenas,  COLOR_VERDE);
    bigDigit_NUM(2, unidades, COLOR_VERDE);        
    bigDigit_TXT(1 ,CARACTER_GRADO, COLOR_VERDE);
    bigDigit_TXT(0 ,CARACTER_C, COLOR_VERDE);
  }

}

//========================================================
//    CONTADOR
//========================================================

void contador()
{

  for (uint16_t numero=0;numero<10000;numero++){
      bigCifra(numero, 255, 0, 0 );
      delay(100); 
  }
  

}


//========================================================
//    MOSTRAR MENSAJE
//========================================================

void mostrar_mensaje()
{
    
    uint8_t mensaje [] = {  
                          CARACTER_E , CARACTER_r , CARACTER_r , CARACTER_o , CARACTER_r, 
                          CARACTER_OFF, CARACTER_c, CARACTER_o, CARACTER_d, CARACTER_E,
                          CARACTER_OFF, CARACTER_4, CARACTER_0, CARACTER_4,
                         } ;

  rotuloRotativoPuntero(mensaje, sizeof(mensaje)/sizeof(mensaje[0]), 0, COLOR_VERDE, 250);


}








//*******************************************************
//                    FIN DE PROGRAMA
//*******************************************************
