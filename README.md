# cajing

Caja de seguridad didactica que se abre con una clave de cuatro digitos apartir de un reto matematico para los estudiantes de sexto grado del colegio Alfredo Iriarte.

Uso
Se ingresa un numero de 4 digitos y se presiona la tecla "*", si la respuesta es correcta se desactiva el solenoide.
Si se ingreso un numero erroneo se puede oprimir la tecla "*" para volver a ingresar el numero.
Para cerrar de nuevo la caja se lleva la puerta hacia detro y se presiona "*" para accionar el solenoide y trancar la puerta.

Programación
Se abre arduino IDE y se escoje la placa, luego el puerto y se sube el archivo
Para cambiar la clave se debe cambiar los valores del arrglo de caracteres:
    char respuesta[4] = {'1','2','3','4'};respuesta[4] = {};
 Y luego volver a programar.
