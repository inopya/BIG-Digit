# BIG-Digit
Display 7 segmentos para imprimir en 3D
Se incluye ejemplo para mostrar contadores, temperaturas y desplazamiento de mensajes de texto.

Digito de 7 segmntos iluminado con tira de leds direccionable, de manera que solo necesitamos ocupar una salida del microcontrolador.
Es posible concatenar varios digitos.
En el ejemplo de la carpeta firmware se incluyen rutinas que usan hasta 4 displays
Se incluye el fichero STL. 
El tamaño de display esta preparado para usar tiras de leds de 144 pixels por metro 
de manera que se minimizan las soldaduras reduciendose estas solo a las conexiones entre digitos.
Se nos genera de esta manera un display de 55mm dealto por 35 de ancho.

![](./imagenes/leds.jpg)

Si se usan multiples displays el acceso alos digitos será de derecha a izquierda, esdecir primero las unidades.
Dentro de cada displayel orden de los segmentos es el siguiente:

![](./imagenes/orden_segmentos.png)


**Modelo 3D**

![](./imagenes/digito-solido.png)   ![](./imagenes/digito-transp.jpg)

![](./imagenes/seccion.png)         ![](./imagenes/muestras_print.jpg) 



Si se imprime en la posicion que muestra la imagen se evitan los soportes 
(salvo una minima parteque corresponde a los agujeros que se usan para la union entre digitos)

![](./imagenes/3Da.jpg)  ![](./imagenes/3Db.jpg)



**Ejemplo de un reloj**

![](./imagenes/reloj.jpg) 

**Nota**

Si se usan simbolos especiales como es el caso de los dos puntos de separacion en el reloj de la imagen superior, 
estos deben crearse con pixeles del final de la tira leds, es decir tras la formacion de todos los digitos,
para poder mantener la compatibilidad con las funciones usadas en los ejemplos de la carpeta firmware
