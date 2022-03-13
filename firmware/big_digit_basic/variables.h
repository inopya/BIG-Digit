


/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//        CONSTANTES DEL PROGRAMA
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/


/* el led interno del wemos esta conectado a una salida Pull-up (enciende con LOW) */
#define LED_ON    1    
#define LED_OFF   0



/*mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//        VARIABLES GLOBALES
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm*/


const byte numeros[12] =  {			//PROGMEM
						B01110111, //0
						B00100100, //1
						B01011101, //2
						B01101101, //3
						B00101110, //4
						B01101011, //5
						B01111011, //6
						B00100101, //7
						B01111111, //8
						B00101111, //9
						B00001000, //-       (10)                                          
						B00000000, //apagado (11)
					};

#define   CARACTER_0			      B1110111 //0
#define   CARACTER_1			      B0100100 //1
#define   CARACTER_2			      B1011101 //2
#define   CARACTER_3			      B1101101 //3
#define   CARACTER_4			      B0101110 //4
#define   CARACTER_5			      B1101011 //5
#define   CARACTER_6			      B1111011 //6
#define   CARACTER_7			      B0100101 //7
#define   CARACTER_8			      B1111111 //8
#define   CARACTER_9			      B0101111 //9

#define   CARACTER_a            B1111101 //a
#define   CARACTER_A            B0111111 //A
#define   CARACTER_b            B1111010 //b
#define   CARACTER_c            B1011000 //c
#define   CARACTER_C            B1010011 //C
#define   CARACTER_d            B1111100 //d
#define   CARACTER_D            B1110111 //D, O, 0
#define   CARACTER_e            B1011111 //e
#define   CARACTER_E            B1011011 //E
#define   CARACTER_F            B0011011 //F
#define   CARACTER_g            B1101111 //g
#define   CARACTER_G            B1111011 //G
#define   CARACTER_h            B0111010 //h
#define   CARACTER_H            B0110110 //H
#define   CARACTER_i            B0010000 //i
#define   CARACTER_I            B0010010 //I
#define   CARACTER_J            B1110100 //J
#define   CARACTER_l            B0010010 //l
#define   CARACTER_L            B1010010 //L
#define   CARACTER_n            B0111000 //n
#define   CARACTER_N            B0110111 //N
#define   CARACTER_n            B0111000 //n m
#define   CARACTER_N            B0110111 //N M					
#define   CARACTER_nn           B0111001 //ñ
#define   CARACTER_o            B1111000 //o
#define   CARACTER_O            B1110111 //O
#define   CARACTER_P            B0011111 //P
#define   CARACTER_q            B0101111 //q
#define   CARACTER_r            B0011000 //r
#define   CARACTER_R            B0010011 //R
#define   CARACTER_S            B1101011 //S
#define   CARACTER_t            B1011010 //t
#define   CARACTER_u            B1110000 //u
#define   CARACTER_U            B1110110 //U
#define   CARACTER_v            B1110000 //v
#define   CARACTER_V            B1110110 //V
#define   CARACTER_x            B0111110 //x
#define   CARACTER_X            B0111110 //x X
#define   CARACTER_y            B1101110 //y
#define   CARACTER_Z            B1011101 //Z
#define   CARACTER_GRADO        B0001111 //º 
#define   CARACTER_NEGATIVO     B0001000 //-  
#define   CARACTER_MENOS        B0001000 //-  
#define   CARACTER_BARRA        B0011100 // /                                  
#define   CARACTER_OFF          B0000000 //apagado  
#define   CARACTER_NULO         B0000000 //apagado  
