#ifndef CONSTANTES_H
#define CONSTANTES_H

#define MIN_BRIGHT 0
#define MAX_BRIGHT 255

#define DIRECCION_PANTALLA_PEQUEnA 0x25
#define DIRECCION_PANTALLA_GRANDE 0x27

#define LCD_EN 2
#define LCD_RW 1
#define LCD_RS 0
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
#define LCD_BL 3

#define NUM_LETRAS 26

#define PIN_VERDE_1 2
#define PIN_VERDE_2 3
#define PIN_VERDE_3 4

#define PIN_AMARILLO_1 6
#define PIN_AMARILLO_2 7
#define PIN_AMARILLO_3 8
#define PIN_AMARILLO_4 9

#define PIN_ROJO_1 11
#define PIN_ROJO_2 12
#define PIN_ROJO_3 13

const static int pins_led_PWM[] = {
  PIN_VERDE_1, PIN_VERDE_2, PIN_VERDE_3,
  PIN_AMARILLO_1, PIN_AMARILLO_2, PIN_AMARILLO_3, PIN_AMARILLO_4,
  PIN_ROJO_1, PIN_ROJO_2, PIN_ROJO_3
};

const static String TEXTO_CLARO = "Texto en claro:";
const static String TEXTO_CIFRADO = "Texto cifrado:";

#endif /* CONSTANTS_H */
