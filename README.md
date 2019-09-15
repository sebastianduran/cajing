# cajing

Caja de seguridad didactica que se abre con una clave de cuatro digitos apartir de un reto matematico para los estudiantes de sexto grado del colegio Alfredo Iriarte.

# Uso
Se ingresa un numero de 4 digitos y se presiona la tecla *, si la respuesta es correcta se desactiva el solenoide. /n
Si se ingreso un numero erroneo se puede oprimir la tecla * para volver a ingresar el numero. /n
Para cerrar de nuevo la caja se lleva la puerta hacia detro y se presiona * para accionar el solenoide y trancar la puerta. /n 

# Programación
Se abre arduino IDE y se escoje la placa, luego el puerto y se sube el archivo.
Luego se realizan las conexiones según el esquematico presentado.
Para cambiar la clave se debe cambiar los valores del arrglo de caracteres:

    char respuesta[4] = {'1','2','3','4'};respuesta[4] = {};
    
 Y luego volver a programar.

# Materiales
Caja con tapa (1) /n
Visagras (1 o 2 según tamaño de la caja) /n
Transistor TIP120 (1) /n
Teclado 4x4 (1) /n
Arduino modelo de su preferencia (1) /n
Cableas (según las conexiones) /n
Pilas 9v (2) /n
Solenoide 12 V (1) /n
Diodo 1N4004 (1)
Resistencia 220 ohms (1)/n
Conectores, soldadura y baquelita según diseño./n
![alt text](https://github.com/sebastianduran/cajing/blob/master/caja_bb.png)
