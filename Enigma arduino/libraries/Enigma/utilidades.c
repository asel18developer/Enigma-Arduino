void keyPressed() {
  char c = (char)keyboard.getKey();
  escribe_letra(c, enigma(c));
}

/**
 * Lo que la maquina ENIGMA hara cada
 * vez que se encienda o se reinicie.
 */
void secuencia_encendido() {

  secuencia_2_leds(true, 5, 1, 100);

  secuencia_blancos(&lcd_20x4, 4, 20);
  secuencia_blancos(&lcd_16x2, 2, 16);

  secuencia_2_leds(true, 1, 1, 100);

  secuencia_2_leds(true, 5, 1, 100);
  lcd_20x4.setCursor(0, 0);
  parpadea_pantalla(&lcd_20x4, 1, 500000);
  lcd_20x4.print("Bienvenido a");

  secuencia_2_leds(true, 1, 1, 100);

  secuencia_2_leds(true, 5, 1, 100);
  lcd_20x4.setCursor(13, 2);
  parpadea_pantalla(&lcd_20x4, 1, 500000);
  lcd_20x4.print("ENIGMA");

  parpadea_pantalla(&lcd_20x4, 5, 100000);

  secuencia_2_leds(true, 1, 1, 150);

  /*
    write_special_char(smiley, &lcd_16x2, 0, 12, 0);
    write_special_char(smiley, &lcd_16x2, 1, 9, 0);

   for (int b = 6; b > 0; b--) {
     parpadea_pantalla(&lcd_16x2, 1, 50);
     lcd_16x2.scrollDisplayLeft();
     delay(200);
   }
   */

  secuencia_barras(&lcd_16x2, 2, 16);
  secuencia_barras(&lcd_20x4, 4, 20);

  secuencia_2_leds(true, 3, 1, 100);

}


void inicializa_pantallas() {
  lcd_16x2.begin(16, 2);
  lcd_20x4.begin(20, 4);
}

void inicializa_leds() {
  for (int b = 0; b <= (sizeof(pins_led_PWM) / sizeof(*pins_led_PWM)); b++) {
    pinMode(pins_led_PWM[b], OUTPUT);
  }
  secuencia_2_leds(true, 1, 1, 1);
}

void inicializa_teclado() {
  Serial.begin(9600);
}

/**
 * Hace parpadear un display.
 *
 * @param _lcd el display que va a hacer parpadear.
 * @param _times el numero de parpadeos.
 * @param _micros el numero de microsegundos entre cada parpadeo.
 */
void parpadea_pantalla(LiquidCrystal_I2C * _lcd, int _times, int _micros) {

  for (int i = 0; i < _times; i++) {
    delayMicroseconds(_micros);
    _lcd->noBacklight();
    delayMicroseconds(_micros);
    _lcd->backlight();
  }

}

/**
 * Hace parpadear ambos displays.
 *
 * @param _times el numero de parpadeos.
 * @param _micros el numero de microsegundos entre cada parpadeo.
 */
void parpadea_ambas_pantallas(int _times, int _micros) {

  for (int i = 0; i < _times; i++) {
    delayMicroseconds(_micros);
    lcd_16x2.noBacklight();
    lcd_20x4.noBacklight();

    delayMicroseconds(_micros);
    lcd_16x2.backlight();
    lcd_20x4.backlight();
  }

}

void escribe_letra(char _clara, char _cifrada) {

  if (texto_en_claro.length() >= 20) {

    texto_en_claro = texto_en_claro.substring(0, 19);
    texto_cifrado = texto_cifrado.substring(0, 19);

  }

  // Mensajes escritos de derecha a izquierda.
  texto_en_claro = _clara + texto_en_claro;
  texto_cifrado = _cifrada + texto_cifrado;

  /*
   * Es necesario que el mensaje este escrito
   * en orden inverso (de derecha a izquierda)
   * y que el display este configurado para
   * escribir en este orden.
   */
  lcd_20x4.rightToLeft();

  secuencia_2_leds(true, 1, 1, 100);

  /*
   * Imprime en la pantalla el texto en claro.
   */
  lcd_20x4.setCursor(19, 1);
  // Mensaje escrito de derecha a izquierda.
  lcd_20x4.print(texto_en_claro);

  /*
   * Imprime en la pantalla el texto cifrado.
   */
  lcd_20x4.setCursor(19, 3);
  // Mensaje escrito de derecha a izquierda.
  lcd_20x4.print(texto_cifrado);

  // Deja el display en modo de escritura normal.
  lcd_20x4.leftToRight();
}

/**
*
* @param _ch la letra a pintar.
* @param _lcd la pantalla en al que se va a pintar.
* @param _charNumber un numero de caracter que se le
* asignará a _ch y que se va a pintar en
* la posición indicada.
*
*/
void write_special_char(byte _ch[], LiquidCrystal_I2C * _lcd,
                        int _row, int _col, int _charNumber) {
  _lcd->createChar(_charNumber, _ch);
  _lcd->setCursor(_col, _row);
  _lcd->write(int(_charNumber));
}

/**
 * Imprime un bloque blanco (pixels encendidos)
 * que va recorriendo todas las posiciones
 * de la pantalla.
 *
 * @param _lcd un puntero a una pantalla.
 * @param numRows el numero de filas de la pantalla.
 * @param numCols el numero de columnas de la pantalla.
 */
void secuencia_blancos(LiquidCrystal_I2C * _lcd,
                       int numRows, int numCols) {

  _lcd->clear();

  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      write_special_char(blanco, _lcd, row, col, 2);
      delayMicroseconds(1);
    }
    for (int col = 0; col < numCols; col++) {
      write_special_char(negro, _lcd, row, col, 3);
      delayMicroseconds(1);
    }
  }

}

/**
 * Imprime una 'barra vertical' que ocupa todas
 * las lineas de la pantalla, de color blanco
 * (pixels encendidos)
 *
 * @param _lcd un puntero a una pantalla.
 * @param numRows el numero de filas de la pantalla.
 * @param numCols el numero de columnas de la pantalla.
 */
void secuencia_barras(LiquidCrystal_I2C * _lcd,
                      int numRows, int numCols) {

  _lcd->clear();


  for (int col = 0; col < numCols; col++) {
    for (int row = 0; row < numRows; row++) {
      write_special_char(blanco, _lcd, row, col, 2);
    }
    delayMicroseconds(1);
  }
  for (int col = 0; col < numCols; col++) {
    for (int row = 0; row < numRows; row++) {
      write_special_char(negro, _lcd, row, col, 3);
    }
    delayMicroseconds(1);
  }

}

/**
 * Enciende uno a uno los LEDs conectados a los
 * pines listados en la constante pins_led_PWM
 * y en ese mismo orden.
 */
void secuencia_1_leds(bool _do) {
  secuencia_2_leds(_do, 1, 1, 100);
}

/**
 * Enciende uno a uno los LEDs conectados a los
 * pines listados en la constante pins_led_PWM
 * y en ese mismo orden.
 *
 * Los LEDs recorren cada  uno de los posibles
 * estados analogicos dentro del intervalo marcado
 * por las constantes MIN_BRIGHT y MAX_BRIGHT.
 *
 * @param _iter el numero de veces que se hara
 * la secuencia.
 * @param _pause el numero de microsegundos entre
 * cada iteracion.
 * @param _between el numero de microsegundos entre
 * cada uno de los estados analogicos.
 */
void secuencia_2_leds(bool _do, int _iter, int _pause, int _between) {
  if (_do) {
    for (int by = 0; by < _iter; by++) {
      // iterate over the pins:
      for (int b = 0; b <= (sizeof(pins_led_PWM) / sizeof(*pins_led_PWM)); b++) {
        // fade the LED on thisPin from off to brightest:
        for (int brightness = MIN_BRIGHT; brightness < MAX_BRIGHT; brightness++) {
          analogWrite(pins_led_PWM[b], brightness);
          delayMicroseconds(_between);
        }
        // fade the LED on thisPin from brithstest to off:
        for (int brightness = MAX_BRIGHT; brightness >= MIN_BRIGHT; brightness--) {
          analogWrite(pins_led_PWM[b], brightness);
          delayMicroseconds(_between);
        }
        // pause between LEDs:
        delayMicroseconds(_pause);
      }
    }
  }
}

/**
 * Hace parpadear todos los LEDs.
 *
 * Los LEDs recorren cada  uno de los posibles
 * estados analogicos dentro del intervalo marcado
 * por las constantes MIN_BRIGHT y MAX_BRIGHT.
 *
 * @param _iter el numero de veces que se hara
 * la secuencia.
 * @param _pause el numero de microsegundos entre
 * cada iteracion.
 * @param _between el numero de microsegundos entre
 * cada uno de los estados analogicos.
 */
void secuencia_3_leds(bool _do, int _iter, int _pause, int _between) {
  if (_do) {
    for (int by = 0; by < _iter; by++) {
      for (int brightness = MIN_BRIGHT; brightness < MAX_BRIGHT; brightness++) {
        for (int b = 0; b <= (sizeof(pins_led_PWM) / sizeof(*pins_led_PWM)); b++) {
          analogWrite(pins_led_PWM[b], brightness);
        }
        delayMicroseconds(_between);
      }
      for (int brightness = MAX_BRIGHT; brightness >= MIN_BRIGHT; brightness--) {
        for (int b = 0; b <= (sizeof(pins_led_PWM) / sizeof(*pins_led_PWM)); b++) {
          analogWrite(pins_led_PWM[b], brightness);
        }
        delayMicroseconds(_between);
      }
      delayMicroseconds(_pause);
    }
  }
}

/**
 * Hace parpadear cinco veces todos los LEDs.
 */
void secuencia_4_leds(boolean _do) {
  secuencia_3_leds(_do, 5, 1, 150);
}

void hola_mundo(LiquidCrystal_I2C * _lcd) {

  _lcd->setCursor(3, 0);
  _lcd->print("Hola");

  _lcd->setCursor(6, 1);
  _lcd->print("mundo.");

  write_special_char(smiley, _lcd, 1, 15, 0);
  write_special_char(smiley, _lcd, 1, 13, 0);

  secuencia_2_leds(true, 1, 1, 50);

}
