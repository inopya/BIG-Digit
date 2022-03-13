

#include <Adafruit_NeoPixel.h>      // Incluir biblioteca Adafruit NeoPixel


#define TIPO_LED          NEO_GRB + NEO_KHZ800      //tipo controlador de los led


const uint8_t CANTIDAD_DISPLAYS = 4;                // numero displays
const uint8_t CANTIDAD_SEGMENTOS = 7;               // numero de segmentos del display
const uint8_t LEDS_SEGMENTO = 1;                    // numero de leds por segmento

const uint8_t LONGITUD_TIRA = CANTIDAD_DISPLAYS*CANTIDAD_SEGMENTOS*LEDS_SEGMENTO;   

Adafruit_NeoPixel tiraLEDS = Adafruit_NeoPixel(LONGITUD_TIRA, PIN_TIRA_LED, TIPO_LED);



#define COLOR_ROJO  255,0,0
#define COLOR_VERDE  0, 255, 0
#define COLOR_AZUL  0,0,255
#define COLOR_AMARILLO 255, 255, 0            // amarillo
#define COLOR_ROSA  255, 0, 255               // morado / rosa
#define COLOR_NARANJA  255, 140, 0            // naranja
#define COLOR_MORADO  255, 105, 180           // rosa
#define COLOR_AMARILLO_VERDE  175, 255, 20    // amarillo verdoso
#define COLOR_CELESTE  0, 255, 255            // celeste/agua
#define COLOR_AZUL_CIELO  0, 180, 255         // azul cielo
#define COLOR_AZUL_OSCURO  0, 0, 140          // azul oscuro
#define COLOR_NAVY  0, 0, 128                 // navy
#define COLOR_BLANCO  255, 255, 255           // blanco
#define COLOR_GRIS  80, 80, 80                // gris 
#define COLOR_NEGRO  0, 0, 0                  // negro/apagado
