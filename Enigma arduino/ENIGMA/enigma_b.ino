/*!
 *      MÁQUINA ENIGMA
 * Implementada con Arduino
 *
 * NAHÚM Cueto López y JESÚS García Potes
 * Junio de 2015
 *
 * "Seguridad Informática"
 * Grado en Ingeniería Informática
 * Universidad de León
 */

//////////////////////////////////////////////////////
/////////////////     INCLUDES    ////////////////////
//////////////////////////////////////////////////////
#include <KeyboardController.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <LiquidCrystal.h>

//////////////////////////////////////////////////////////
///////////////////       DEFINES      ///////////////////
//////////////////////////////////////////////////////////

#define MIN_BRIGHT 0
#define MAX_BRIGHT 255

#define DIRECCION_PANTALLA_PEQUEnA 0x25
#define DIRECCION_PANTALLA_GRANDE 0x27

#define pin_led_verde_1 2
#define pin_led_verde_2 3
#define pin_led_verde_3 5

#define pin_led_amarillo_1 6
#define pin_led_amarillo_2 7
#define pin_led_amarillo_3 8
#define pin_led_amarillo_4 9

#define pin_led_rojo_1 11
#define pin_led_rojo_2 12
#define pin_led_rojo_3 13

#define LCD_EN 2
#define LCD_RW 1
#define LCD_RS 0
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
#define LCD_BL 3

static const int NUM_LETRAS = 26;

/*
 *  ------------------------- LETRAS -------------------------
 */

const static int A = 0;
const static int B = 1;
const static int C = 2;
const static int D = 3;
const static int E = 4;
const static int F = 5;
const static int G = 6;
const static int H = 7;
const static int I = 8;
const static int J = 9;
const static int K = 10;
const static int L = 11;
const static int M = 12;
const static int N = 13;
const static int O = 14;
const static int P = 15;
const static int Q = 16;
const static int R = 17;
const static int S = 18;
const static int T = 19;
const static int U = 20;
const static int V = 21;
const static int W = 22;
const static int X = 23;
const static int Y = 24;
const static int Z = 25;

const static String TEXTO_CLARO = "Texto en claro:";
const static String TEXTO_CIFRADO = "Texto cifrado:";

//////////////////////////////////////////////////////////
///////////////////     CONSTANTES     ///////////////////
//////////////////////////////////////////////////////////

typedef struct rodillo {
  int cursor;
  int * letras;
  bool * avances;
  String nombre;
} rodillo;

/*
 *  ------------------------- ROTORES -------------------------
 */

int rotor_I[] = { E, K, M, F, L, G, D, Q, V, Z, N, T, O, W, Y, H,
                  X, U, S, P, A, I, B, R, C, J
                };
String nombre_rotor_I = " 1";
bool avance_rotor_I[] = {/* A */false, /* B */false, /* C */false,
                                /* D */false, /* E */false, /* F */false,
                                /* G */false, /* H */false, /* I */false,
                                /* J */false, /* K */false, /* L */false,
                                /* M */false, /* N */false, /* O */false,
                                /* P */false, /* Q */true, /* R */false,
                                /* S */false, /* T */false, /* U */false,
                                /* V */false, /* W */false, /* X */false,
                                /* Y */false, /* Z */false
                        };
int rotor_II[] = { A, J, D, K, S, I, R, U, X, B, L, H, W, T, M, C,
                   Q, G, Z, N, P, Y, F, V, O, E
                 };
String nombre_rotor_II = " 2";
bool avance_rotor_II[] = {/* A */false, /* B */false, /* C */false,
                                 /* D */false, /* E */true, /* F */false,
                                 /* G */false, /* H */false, /* I */false,
                                 /* J */false, /* K */false, /* L */false,
                                 /* M */false, /* N */false, /* O */false,
                                 /* P */false, /* Q */false, /* R */false,
                                 /* S */false, /* T */false, /* U */false,
                                 /* V */false, /* W */false, /* X */false,
                                 /* Y */false, /* Z */false
                         };
int rotor_III[] = { B, D, F, H, J, L, C, P, R, T, X, V, Z, N, Y, E,
                    I, W, G, A, K, M, U, S, Q, O
                  };
String nombre_rotor_III = " 3";
bool avance_rotor_III[] = {/* A */false, /* B */false, /* C */
                                  false,
                                  /* D */false, /* E */false, /* F */false,
                                  /* G */false, /* H */false, /* I */false,
                                  /* J */false, /* K */false, /* L */false,
                                  /* M */false, /* N */false, /* O */false,
                                  /* P */false, /* Q */false, /* R */false,
                                  /* S */false, /* T */false, /* U */false,
                                  /* V */true, /* W */false, /* X */false,
                                  /* Y */false, /* Z */false
                          };
int rotor_IV[] = { E, S, O, V, P, Z, J, A, Y, Q, U, I, R, H, X, L,
                   N, F, T, G, K, D, C, M, W, B
                 };
String nombre_rotor_IV = " 4";
bool avance_rotor_IV[] = {/* A */false, /* B */false, /* C */false,
                                 /* D */false, /* E */false, /* F */false,
                                 /* G */false, /* H */false, /* I */false,
                                 /* J */true, /* K */false, /* L */false,
                                 /* M */true, /* N */false, /* O */false,
                                 /* P */false, /* Q */false, /* R */false,
                                 /* S */false, /* T */false, /* U */false,
                                 /* V */false, /* W */false, /* X */false,
                                 /* Y */false, /* Z */false
                         };
int rotor_V[] = { V, Z, B, R, G, I, T, Y, U, P, S, D, N, H, L, X,
                  A, W, M, J, Q, O, F, E, C, K
                };
String nombre_rotor_V = " 5";
bool avance_rotor_V[] = {/* A */false, /* B */false, /* C */false,
                                /* D */false, /* E */false, /* F */false,
                                /* G */false, /* H */false, /* I */false,
                                /* J */false, /* K */false, /* L */false,
                                /* M */false, /* N */false, /* O */false,
                                /* P */false, /* Q */false, /* R */false,
                                /* S */false, /* T */false, /* U */false,
                                /* V */false, /* W */false, /* X */false,
                                /* Y */false, /* Z */true
                        };
int rotor_VI[] = { J, P, G, V, O, U, M, F, Y, Q, B, E, N, H, Z, R,
                   D, K, A, S, X, L, I, C, T, W
                 };
String nombre_rotor_VI = " 6";
bool avance_rotor_VI[] = {/* A */false, /* B */false, /* C */false,
                                 /* D */false, /* E */false, /* F */false,
                                 /* G */false, /* H */false, /* I */false,
                                 /* J */false, /* K */false, /* L */false,
                                 /* M */true, /* N */false, /* O */false,
                                 /* P */false, /* Q */false, /* R */false,
                                 /* S */false, /* T */false, /* U */false,
                                 /* V */false, /* W */false, /* X */false,
                                 /* Y */false, /* Z */true
                         };
int rotor_VII[] = { N, Z, J, H, G, R, C, X, M, Y, S, W, B, O, U, F,
                    A, I, V, L, P, E, K, Q, D, T
                  };
String nombre_rotor_VII = " 7";
bool avance_rotor_VII[] = {/* A */false, /* B */false, /* C */
                                  false,
                                  /* D */false, /* E */false, /* F */false,
                                  /* G */false, /* H */false, /* I */false,
                                  /* J */false, /* K */false, /* L */false,
                                  /* M */true, /* N */false, /* O */false,
                                  /* P */false, /* Q */false, /* R */false,
                                  /* S */false, /* T */false, /* U */false,
                                  /* V */false, /* W */false, /* X */false,
                                  /* Y */false, /* Z */true
                          };
int rotor_VIII[] = { F, K, Q, H, T, L, X, O, C, B, J, S, P, D, Z,
                     R, A, M, E, W, N, I, U, Y, G, V
                   };
String nombre_rotor_VIII = " 8";
bool avance_rotor_VIII[] = {/* A */false, /* B */false, /* C */
                                   false,
                                   /* D */false, /* E */false, /* F */false,
                                   /* G */false, /* H */false, /* I */false,
                                   /* J */false, /* K */false, /* L */false,
                                   /* M */true, /* N */false, /* O */false,
                                   /* P */false, /* Q */false, /* R */false,
                                   /* S */false, /* T */false, /* U */false,
                                   /* V */false, /* W */false, /* X */false,
                                   /* Y */false, /* Z */true
                           };
// NO AVANZA
int rotor_beta[] = { L, E, Y, J, V, C, N, I, X, W, P, B, Q, M, D,
                     R, T, A, K, Z, G, F, U, H, O, S
                   };
String nombre_rotor_beta = "bt";
bool avance_rotor_beta[] = {/* A */false, /* B */false, /* C */
                                   false,
                                   /* D */false, /* E */false, /* F */false,
                                   /* G */false, /* H */false, /* I */false,
                                   /* J */false, /* K */false, /* L */false,
                                   /* M */false, /* N */false, /* O */false,
                                   /* P */false, /* Q */false, /* R */false,
                                   /* S */false, /* T */false, /* U */false,
                                   /* V */false, /* W */false, /* X */false,
                                   /* Y */false, /* Z */false
                           };
// NO AVANZA
int rotor_gamma[] = { F, S, O, K, A, N, U, E, R, H, M, B, T, I, Y,
                      C, W, L, Q, P, Z, X, V, G, J, D
                    };
String nombre_rotor_gamma = "gm";
bool avance_rotor_gamma[] = {/* A */false, /* B */false, /* C */
                                    false,
                                    /* D */false, /* E */false, /* F */false,
                                    /* G */false, /* H */false, /* I */false,
                                    /* J */false, /* K */false, /* L */false,
                                    /* M */false, /* N */false, /* O */false,
                                    /* P */false, /* Q */false, /* R */false,
                                    /* S */false, /* T */false, /* U */false,
                                    /* V */false, /* W */false, /* X */false,
                                    /* Y */false, /* Z */false
                            };
int rotor_I_T[] = { K, P, T, Y, U, E, L, O, C, V, G, R, F, Q, D, A,
                    N, J, M, B, S, W, H, Z, X, I
                  };
bool avance_rotor_I_T[] = {/* A */false, /* B */false, /* C */
                                  false,
                                  /* D */false, /* E */true, /* F */false,
                                  /* G */false, /* H */false, /* I */false,
                                  /* J */false, /* K */true, /* L */false,
                                  /* M */false, /* N */false, /* O */false,
                                  /* P */false, /* Q */true, /* R */false,
                                  /* S */false, /* T */false, /* U */false,
                                  /* V */false, /* W */true, /* X */false,
                                  /* Y */false, /* Z */true
                          };
String nombre_rotor_I_T = "1T";
int rotor_II_T[] = { U, P, H, Z, L, W, E, Q, M, T, D, J, X, C, A,
                     K, S, O, I, G, V, B, Y, F, N, R
                   };
bool avance_rotor_II_T[] = {/* A */false, /* B */false, /* C */
                                   false,
                                   /* D */false, /* E */false, /* F */true,
                                   /* G */false, /* H */false, /* I */false,
                                   /* J */false, /* K */false, /* L */true,
                                   /* M */false, /* N */false, /* O */false,
                                   /* P */false, /* Q */false, /* R */true,
                                   /* S */false, /* T */false, /* U */false,
                                   /* V */false, /* W */true, /* X */false,
                                   /* Y */false, /* Z */true
                           };
String nombre_rotor_II_T = "2T";
//int rotor_III_T[] = { Q, U, D, L, Y, R, F, E, K, O, N, V, Z, A, X,
//                       W, H, M, G, P, J, B, S, I, C, T
//                     };// TODO seguir poniendo los nombres de los rotores.
//bool avance_rotor_III_T[] = {/* A */false, /* B */false, /* C */
//                                    false,
//                                    /* D */false, /* E */true, /* F */false,
//                                    /* G */false, /* H */false, /* I */false,
//                                    /* J */false, /* K */true, /* L */false,
//                                    /* M */false, /* N */false, /* O */false,
//                                    /* P */false, /* Q */true, /* R */false,
//                                    /* S */false, /* T */false, /* U */false,
//                                    /* V */false, /* W */true, /* X */false,
//                                    /* Y */false, /* Z */true
//                            };
//int rotor_IV_T[] = { C, I, W, T, B, K, X, N, R, E, S, P, F, L, Y,
//                      D, A, G, V, H, Q, U, O, J, Z, M
//                    };
//bool avance_rotor_IV_T[] = {/* A */false, /* B */false, /* C */
//                                   false,
//                                   /* D */false, /* E */false, /* F */true,
//                                   /* G */false, /* H */false, /* I */false,
//                                   /* J */false, /* K */false, /* L */true,
//                                   /* M */false, /* N */false, /* O */false,
//                                   /* P */false, /* Q */false, /* R */true,
//                                   /* S */false, /* T */false, /* U */false,
//                                   /* V */false, /* W */true, /* X */false,
//                                   /* Y */false, /* Z */true
//                           };
//int rotor_V_T[] = { U, A, X, G, I, S, N, J, B, V, E, R, D, Y, L, F,
//                     Z, W, T, P, C, K, O, H, M, Q
//                   };
//bool avance_rotor_V_T[] = {/* A */false, /* B */false, /* C */true,
//                                  /* D */false, /* E */false, /* F */true,
//                                  /* G */false, /* H */false, /* I */false,
//                                  /* J */false, /* K */true, /* L */false,
//                                  /* M */false, /* N */false, /* O */false,
//                                  /* P */false, /* Q */false, /* R */true,
//                                  /* S */false, /* T */false, /* U */false,
//                                  /* V */false, /* W */false, /* X */false,
//                                  /* Y */true, /* Z */false
//                          };
//int rotor_VI_T[] = { X, F, U, Z, G, A, L, V, H, C, N, Y, S, E, W,
//                      Q, T, D, M, R, B, K, P, I, O, J
//                    };
//bool avance_rotor_VI_T[] = {/* A */false, /* B */false, /* C */
//                                   false,
//                                   /* D */false, /* E */true, /* F */false,
//                                   /* G */false, /* H */false, /* I */true,
//                                   /* J */false, /* K */false, /* L */false,
//                                   /* M */true, /* N */false, /* O */false,
//                                   /* P */false, /* Q */true, /* R */false,
//                                   /* S */false, /* T */false, /* U */false,
//                                   /* V */false, /* W */false, /* X */true,
//                                   /* Y */false, /* Z */false
//                           };
//int rotor_VII_T[] = { B, J, V, F, T, X, P, L, N, A, Y, O, Z, I, K,
//                       W, G, D, Q, E, R, U, C, H, S, M
//                     };
//bool avance_rotor_VII_T[] = {/* A */false, /* B */false, /* C */
//                                    true,
//                                    /* D */false, /* E */false, /* F */true,
//                                    /* G */false, /* H */false, /* I */false,
//                                    /* J */false, /* K */true, /* L */false,
//                                    /* M */false, /* N */false, /* O */false,
//                                    /* P */false, /* Q */false, /* R */true,
//                                    /* S */false, /* T */false, /* U */false,
//                                    /* V */false, /* W */false, /* X */false,
//                                    /* Y */true, /* Z */false
//                            };
//int rotor_VIII_T[] = { Y, M, T, P, N, Z, H, W, K, O, D, A, J, X, E,
//                        L, U, Q, V, G, C, B, I, S, F, R
//                      };
//bool avance_rotor_VIII_T[] = {/* A */false, /* B */false, /* C */
//                                     false,
//                                     /* D */false, /* E */true, /* F */false,
//                                     /* G */false, /* H */false, /* I */true,
//                                     /* J */false, /* K */false, /* L */false,
//                                     /* M */true, /* N */false, /* O */false,
//                                     /* P */false, /* Q */true, /* R */false,
//                                     /* S */false, /* T */false, /* U */false,
//                                     /* V */false, /* W */false, /* X */true,
//                                     /* Y */false, /* Z */false
//                             };
//int rotor_I_G[] = { D, M, T, W, S, I, L, R, U, Y, Q, N, K, F, E, J,
//                     C, A, Z, B, P, G, X, O, H, V
//                   };
//bool avance_rotor_I_G[] = {/* A */true, /* B */true, /* C */true,
//                                  /* D */false, /* E */true, /* F */true,
//                                  /* G */true, /* H */false, /* I */true,
//                                  /* J */false, /* K */true, /* L */true,
//                                  /* M */false, /* N */false, /* O */true,
//                                  /* P */true, /* Q */true, /* R */false,
//                                  /* S */true, /* T */false, /* U */true,
//                                  /* V */true, /* W */true, /* X */false,
//                                  /* Y */false, /* Z */true
//                          };
//int rotor_II_G[] = { H, Q, Z, G, P, J, T, M, O, B, L, N, C, I, F,
//                      D, Y, A, W, V, E, U, S, R, K, X
//                    };
//bool avance_rotor_II_G[] = {/* A */true, /* B */false, /* C */true,
//                                   /* D */true, /* E */false, /* F */true,
//                                   /* G */true, /* H */true, /* I */false,
//                                   /* J */false, /* K */true, /* L */false,
//                                   /* M */true, /* N */true, /* O */false,
//                                   /* P */false, /* Q */true, /* R */false,
//                                   /* S */true, /* T */true, /* U */false,
//                                   /* V */true, /* W */false, /* X */false,
//                                   /* Y */true, /* Z */true
//                           };
//int rotor_III_G[] = { U, Q, N, T, L, S, Z, F, M, R, E, H, D, P, X,
//                       K, I, B, V, Y, G, J, C, W, O, A
//                     };
//bool avance_rotor_III_G[] = {/* A */true, /* B */false, /* C */
//                                    false,
//                                    /* D */false, /* E */true, /* F */true,
//                                    /* G */false, /* H */true, /* I */false,
//                                    /* J */false, /* K */true, /* L */false,
//                                    /* M */true, /* N */true, /* O */false,
//                                    /* P */false, /* Q */false, /* R */true,
//                                    /* S */false, /* T */false, /* U */true,
//                                    /* V */false, /* W */true, /* X */true,
//                                    /* Y */false, /* Z */false
//                            };
//
//int rotor_I_G312[] = { D, M, T, W, S, I, L, R, U, Y, Q, N, K, F, E,
//                        J, C, A, Z, B, P, G, X, O, H, V
//                      };
//bool avance_rotor_I_G312[] = {/* A */true, /* B */true, /* C */
//                                     true,
//                                     /* D */false, /* E */true, /* F */true,
//                                     /* G */true, /* H */false, /* I */true,
//                                     /* J */false, /* K */true, /* L */true,
//                                     /* M */false, /* N */false, /* O */true,
//                                     /* P */true, /* Q */true, /* R */false,
//                                     /* S */true, /* T */false, /* U */true,
//                                     /* V */true, /* W */true, /* X */false,
//                                     /* Y */false, /* Z */true
//                             };
//int rotor_II_G312[] = { H, Q, Z, G, P, J, T, M, O, B, L, N, C, I,
//                         F, D, Y, A, W, V, E, U, S, R, K, X
//                       };
//bool avance_rotor_II_G312[] = {/* A */true, /* B */false, /* C */
//                                      true,
//                                      /* D */true, /* E */false, /* F */true,
//                                      /* G */true, /* H */true, /* I */false,
//                                      /* J */false, /* K */true, /* L */false,
//                                      /* M */true, /* N */true, /* O */false,
//                                      /* P */false, /* Q */true, /* R */false,
//                                      /* S */true, /* T */true, /* U */false,
//                                      /* V */true, /* W */false, /* X */false,
//                                      /* Y */true, /* Z */true
//                              };
//int rotor_III_G312[] = { U, Q, N, T, L, S, Z, F, M, R, E, H, D, P,
//                          X, K, I, B, V, Y, G, J, C, W, O, A
//                        };
//bool avance_rotor_III_G312[] = {/* A */true, /* B */false, /* C */
//                                       false,
//                                       /* D */false, /* E */true, /* F */true,
//                                       /* G */false, /* H */true, /* I */false,
//                                       /* J */false, /* K */true, /* L */false,
//                                       /* M */true, /* N */true, /* O */false,
//                                       /* P */false, /* Q */false, /* R */true,
//                                       /* S */false, /* T */false, /* U */true,
//                                       /* V */false, /* W */true, /* X */true,
//                                       /* Y */false, /* Z */false
//                               };
//
//int rotor_I_G260[] = { R, C, S, P, B, L, K, Q, A, U, M, H, W, Y, T,
//                        I, F, Z, V, G, O, J, N, E, X, D
//                      };
//bool avance_rotor_I_G260[] = {/* A */true, /* B */true, /* C */
//                                     true,
//                                     /* D */false, /* E */true, /* F */true,
//                                     /* G */true, /* H */false, /* I */true,
//                                     /* J */false, /* K */true, /* L */true,
//                                     /* M */false, /* N */false, /* O */true,
//                                     /* P */true, /* Q */true, /* R */false,
//                                     /* S */true, /* T */false, /* U */true,
//                                     /* V */true, /* W */true, /* X */false,
//                                     /* Y */false, /* Z */true
//                             };
//int rotor_II_G260[] = { W, C, M, I, B, V, P, J, X, A, R, O, S, G,
//                         N, D, L, Z, K, E, Y, H, U, F, Q, T
//                       };
//bool avance_rotor_II_G260[] = {/* A */true, /* B */false, /* C */
//                                      true,
//                                      /* D */true, /* E */false, /* F */true,
//                                      /* G */true, /* H */true, /* I */false,
//                                      /* J */false, /* K */true, /* L */false,
//                                      /* M */true, /* N */true, /* O */false,
//                                      /* P */false, /* Q */true, /* R */false,
//                                      /* S */true, /* T */true, /* U */false,
//                                      /* V */true, /* W */false, /* X */false,
//                                      /* Y */true, /* Z */true
//                              };
//int rotor_III_G260[] = { F, V, D, H, Z, E, L, S, Q, M, A, X, O, K,
//                          Y, I, W, P, G, C, B, U, J, T, N, R
//                        };
//bool avance_rotor_III_G260[] = {/* A */true, /* B */false, /* C */
//                                       false,
//                                       /* D */false, /* E */true, /* F */true,
//                                       /* G */false, /* H */true, /* I */false,
//                                       /* J */false, /* K */true, /* L */false,
//                                       /* M */true, /* N */true, /* O */false,
//                                       /* P */false, /* Q */false, /* R */true,
//                                       /* S */false, /* T */false, /* U */true,
//                                       /* V */false, /* W */true, /* X */true,
//                                       /* Y */false, /* Z */false
//                               };
//
//int rotor_I_reichbahn[] = { J, G, D, Q, O, X, U, S, C, A, M, I, F,
//                             R, V, T, P, N, E, W, K, B, L, Z, Y, H
//                           };
//bool avance_rotor_I_reichbahn[] = {/* A */false, /* B */false, /* C */
//                                          false,
//                                          /* D */false, /* E */false, /* F */false,
//                                          /* G */false, /* H */false, /* I */false,
//                                          /* J */false, /* K */false, /* L */false,
//                                          /* M */false, /* N */true, /* O */false,
//                                          /* P */false, /* Q */false, /* R */false,
//                                          /* S */false, /* T */false, /* U */false,
//                                          /* V */false, /* W */false, /* X */false,
//                                          /* Y */false, /* Z */false
//                                  };
//int rotor_II_reichbahn[] = { N, T, Z, P, S, F, B, O, K, M, W, R, C,
//                              J, D, I, V, L, A, E, Y, U, X, H, G, Q
//                            };
//bool avance_rotor_II_reichbahn[] = {/* A */false, /* B */false, /* C */
//                                           false,
//                                           /* D */false, /* E */true, /* F */false,
//                                           /* G */false, /* H */false, /* I */false,
//                                           /* J */false, /* K */false, /* L */false,
//                                           /* M */false, /* N */false, /* O */false,
//                                           /* P */false, /* Q */false, /* R */false,
//                                           /* S */false, /* T */false, /* U */false,
//                                           /* V */false, /* W */false, /* X */false,
//                                           /* Y */false, /* Z */false
//                                   };
//int rotor_III_reichbahn[] = { J, V, I, U, B, H, T, C, D, Y, A, K,
//                               E, Q, Z, P, O, S, G, X, N, R, M, W, F, L
//                             };
//bool avance_rotor_III_reichbahn[] = {/* A */false, /* B */false, /* C */
//                                            false,
//                                            /* D */false, /* E */false, /* F */false,
//                                            /* G */false, /* H */false, /* I */false,
//                                            /* J */false, /* K */false, /* L */false,
//                                            /* M */false, /* N */false, /* O */false,
//                                            /* P */false, /* Q */false, /* R */false,
//                                            /* S */false, /* T */false, /* U */false,
//                                            /* V */false, /* W */false, /* X */false,
//                                            /* Y */true, /* Z */false
//                                    };
//
//int rotor_I_D[] = { L, P, G, S, Z, M, H, A, E, O, Q, K, V, X, R, F,
//                     Y, B, U, T, N, I, C, J, D, W
//                   };
//bool avance_rotor_I_D[] = {/* A */false, /* B */false, /* C */
//                                  false,
//                                  /* D */false, /* E */false, /* F */false,
//                                  /* G */false, /* H */false, /* I */false,
//                                  /* J */false, /* K */false, /* L */false,
//                                  /* M */false, /* N */false, /* O */false,
//                                  /* P */false, /* Q */false, /* R */false,
//                                  /* S */false, /* T */false, /* U */false,
//                                  /* V */false, /* W */false, /* X */false,
//                                  /* Y */true, /* Z */false
//                          };
//int rotor_II_D[] = { S, L, V, G, B, T, F, X, J, Q, O, H, E, W, I,
//                      R, Z, Y, A, M, K, P, C, N, D, U
//                    };
//bool avance_rotor_II_D[] = {/* A */false, /* B */false, /* C */
//                                   false,
//                                   /* D */false, /* E */true, /* F */false,
//                                   /* G */false, /* H */false, /* I */false,
//                                   /* J */false, /* K */false, /* L */false,
//                                   /* M */false, /* N */false, /* O */false,
//                                   /* P */false, /* Q */false, /* R */false,
//                                   /* S */false, /* T */false, /* U */false,
//                                   /* V */false, /* W */false, /* X */false,
//                                   /* Y */false, /* Z */false
//                           };
//int rotor_III_D[] = { C, J, G, D, P, S, H, K, T, U, R, A, W, Z, X,
//                       F, M, Y, N, Q, O, B, V, L, I, E
//                     };
//bool avance_rotor_III_D[] = {/* A */false, /* B */false, /* C */
//                                    false,
//                                    /* D */false, /* E */false, /* F */false,
//                                    /* G */false, /* H */false, /* I */false,
//                                    /* J */false, /* K */false, /* L */false,
//                                    /* M */false, /* N */true, /* O */false,
//                                    /* P */false, /* Q */false, /* R */false,
//                                    /* S */false, /* T */false, /* U */false,
//                                    /* V */false, /* W */false, /* X */false,
//                                    /* Y */false, /* Z */false
//                            };
//
//int rotor_I_K[] = { L, P, G, S, Z, M, H, A, E, O, Q, K, V, X, R, F,
//                     Y, B, U, T, N, I, C, J, D, W
//                   };
//bool avance_rotor_I_K[] = {/* A */false, /* B */false, /* C */
//                                  false,
//                                  /* D */false, /* E */false, /* F */false,
//                                  /* G */false, /* H */false, /* I */false,
//                                  /* J */false, /* K */false, /* L */false,
//                                  /* M */false, /* N */false, /* O */false,
//                                  /* P */false, /* Q */false, /* R */false,
//                                  /* S */false, /* T */false, /* U */false,
//                                  /* V */false, /* W */false, /* X */false,
//                                  /* Y */true, /* Z */false
//                          };
//int rotor_II_K[] = { S, L, V, G, B, T, F, X, J, Q, O, H, E, W, I,
//                      R, Z, Y, A, M, K, P, C, N, D, U
//                    };
//bool avance_rotor_II_K[] = {/* A */false, /* B */false, /* C */
//                                   false,
//                                   /* D */false, /* E */true, /* F */false,
//                                   /* G */false, /* H */false, /* I */false,
//                                   /* J */false, /* K */false, /* L */false,
//                                   /* M */false, /* N */false, /* O */false,
//                                   /* P */false, /* Q */false, /* R */false,
//                                   /* S */false, /* T */false, /* U */false,
//                                   /* V */false, /* W */false, /* X */false,
//                                   /* Y */false, /* Z */false
//                           };
//int rotor_III_K[] = { C, J, G, D, P, S, H, K, T, U, R, A, W, Z, X,
//                       F, M, Y, N, Q, O, B, V, L, I, E
//                     };
//bool avance_rotor_III_K[] = {/* A */false, /* B */false, /* C */
//                                    false,
//                                    /* D */false, /* E */false, /* F */false,
//                                    /* G */false, /* H */false, /* I */false,
//                                    /* J */false, /* K */false, /* L */false,
//                                    /* M */false, /* N */true, /* O */false,
//                                    /* P */false, /* Q */false, /* R */false,
//                                    /* S */false, /* T */false, /* U */false,
//                                    /* V */false, /* W */false, /* X */false,
//                                    /* Y */false, /* Z */false
//                            };

/*
 * ------------------------- REFLECTORES -------------------------
 */

bool avance_NO_AVANZA[] = {/* A */false, /* B */false, /* C */
                                  false,
                                  /* D */false, /* E */false, /* F */false,
                                  /* G */false, /* H */false, /* I */false,
                                  /* J */false, /* K */false, /* L */false,
                                  /* M */false, /* N */false, /* O */false,
                                  /* P */false, /* Q */false, /* R */false,
                                  /* S */false, /* T */false, /* U */false,
                                  /* V */false, /* W */false, /* X */false,
                                  /* Y */false, /* Z */false
                          };

/**
 * UKW A, M3 'Wehrmacht'
 */
int reflector_A[] = { E, J, M, Z, A, L, Y, X, V, B, W, F, C, R, Q,
                      U, O, N, T, S, P, I, K, H, G, D
                    };
String nombre_reflector_A = " A";
/**
 * UKW B, M3 and M4 'Wehrmacht'
 */
int reflector_B[] = { Y, R, U, H, Q, S, L, D, P, X, N, G, O, K, M,
                      I, E, B, F, Z, C, W, V, J, A, T
                    };
String nombre_reflector_B = " B";
/**
 * UKW C, M3 and M4 'Wehrmacht'
 */
int reflector_C[] = { F, V, P, J, I, A, O, Y, E, D, R, Z, X, W, G,
                      C, T, K, U, Q, S, B, N, M, H, L
                    };
String nombre_reflector_C = " C";
/**
 * UKW B 'thin', M4 'Shark'
 */
int reflector_Bt[] = { E, N, K, Q, A, U, Y, W, J, I, C, O, P, B, L,
                       M, D, X, Z, V, F, T, H, R, G, S
                     };
String nombre_reflector_Bt = "Bt";
/**
 * UKW C 'thin', M4 'Shark'
 */
int reflector_Ct[] = { R, D, O, B, J, N, T, K, V, E, H, M, L, F, C,
                       W, Z, A, X, G, Y, I, P, S, U, Q
                     };
String nombre_reflector_Ct = "Ct";
/**
 * UKW (T), Enigma T 'Tirpitz'
 */
int reflector_T[] = { G, E, K, P, B, T, A, U, M, O, C, N, I, L, J,
                      D, X, Z, Y, F, H, W, V, Q, S, R
                    };
String nombre_reflector_T = " T";
/**
 * UKW (G), Enigma G 'Defense'
 */
int reflector_G[] = { R, U, L, Q, M, Z, J, S, Y, G, O, C, E, T, K,
                      W, D, A, H, N, B, X, P, V, I, F
                    };
String nombre_reflector_G = " G";
/**
 * UKW (G), Enigma G312 'Defense'
 */
int reflector_G3[] = { R, U, L, Q, M, Z, J, S, Y, G, O, C, E, T, K,
                       W, D, A, H, N, B, X, P, V, I, F
                     };
String nombre_reflector_G3 = "G3";
/**
 * UKW (G), Enigma G260 'Defense'
 */
int reflector_G2[] = { I, M, E, T, C, G, F, R, A, Y, S, Q, B, Z, X,
                       W, L, H, K, D, V, U, P, O, J, N
                     };
String nombre_reflector_G2 = "G2";
/**
 * UKW, Enigma 'Reichsbahn'
 */
int reflector_RB[] = { Q, Y, H, O, G, N, E, C, V, P, U, Z, T, F, D,
                       J, A, X, W, M, K, I, S, R, B, L
                     };
String nombre_reflector_RB = "RB";
/**
 * UKW (D), Enigma D
 */
int reflector_D[] = { I, M, E, T, C, G, F, R, A, Y, S, Q, B, Z, X,
                      W, L, H, K, D, V, U, P, O, J, N
                    };
String nombre_reflector_D = " D";
/**
 * UKW, Enigma Swiss-K
 */
int reflector_SK[] = { I, M, E, T, C, G, F, R, A, Y, S, Q, B, Z, X,
                       W, L, H, K, D, V, U, P, O, J, N
                     };
String nombre_reflector_SK = "SK";

/*
 * ------------------------- RODRILLOS DE ENTRADA -------------------------
 */

char ALFABETO[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                    'X', 'Y', 'Z'
                  };
/**
 * ETW, Enigma I 'Wehrmacht'
 */
int rueda_de_entrada_EI[] = { A, B, C, D, E, F, G, H, I, J, K, L,
                              M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
                            };
String nombre_rueda_de_entrada_EI = "EI";
/**
 * ETW, M4 'Shark'
 */
int rueda_de_entrada_M4[] = { A, B, C, D, E, F, G, H, I, J, K, L,
                              M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
                            };
String nombre_rueda_de_entrada_M4 = "M4";
/**
 * ETW (T), Enigma T 'Tirpitz'
 */
int rueda_de_entrada_Tz[] = { K, Z, R, O, U, Q, H, Y, A, I, G, B,
                              L, W, V, S, T, D, X, F, P, N, M, C, J, E
                            };
String nombre_rueda_de_entrada_Tz = "Tz";
/**
 * ETW (G), Enigma G 'Defense'
 */
int rueda_de_entrada_GD[] = { Q, W, E, R, T, Z, U, I, O, A, S, D,
                              F, G, H, J, K, P, Y, X, C, V, B, N, M, L
                            };
String nombre_rueda_de_entrada_GD = "GD";
/**
 * ETW (G), Enigma G312 'Defense'
 */
int rueda_de_entrada_G3[] = { Q, W, E, R, T, Z, U, I, O, A, S, D,
                              F, G, H, J, K, P, Y, X, C, V, B, N, M, L
                            };
String nombre_rueda_de_entrada_G3 = "G3";
/**
 * ETW (G), Enigma G260 'Defense'
 */
int rueda_de_entrada_G2[] = { Q, W, E, R, T, Z, U, I, O, A, S, D,
                              F, G, H, J, K, P, Y, X, C, V, B, N, M, L
                            };
String nombre_rueda_de_entrada_G2 = "G2";
/**
 * ETW, Enigma 'Reichsbahn'
 */
int rueda_de_entrada_RB[] = { Q, W, E, R, T, Z, U, I, O, A, S, D,
                              F, G, H, J, K, P, Y, X, C, V, B, N, M, L
                            };
String nombre_rueda_de_entrada_RB = "RB";
/**
 * ETW (D), Enigma D, Version 1
 */
int rueda_de_entrada_D1[] = { J, W, U, L, C, M, N, O, H, P, Q, Z,
                              Y, X, I, R, A, D, K, E, G, V, B, T, S, F
                            };
String nombre_rueda_de_entrada_D1 = "D1";
/**
 * ETW (D), Enigma D, Version 2
 */
int rueda_de_entrada_D2[] = { Q, W, E, R, T, Z, U, I, O, A, S, D,
                              F, G, H, J, K, P, Y, X, C, V, B, N, M, L
                            };
String nombre_rueda_de_entrada_D2 = "D2";
/**
 * ETW, Enigma Swiss-K
 */
int rueda_de_entrada_SK[] = { Q, W, E, R, T, Z, U, I, O, A, S, D,
                              F, G, H, J, K, P, Y, X, C, V, B, N, M, L
                            };
String nombre_rueda_de_entrada_SK = "SK";



//////////////////////////////////////////////////////
////////////     VARIABLES GLOBALES    ///////////////
//////////////////////////////////////////////////////

/*
 * LETRAS ESPECIALES
 */

byte smiley[8] = { B00000, B10001, B00000, B00000, B10001, B01110, B00000, };

byte blanco[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, };

byte negro[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, };

/*
 * PANTALLAS.
 *
 * (dir, en,rw,rs,d4,d5,d6,d7,bl, blpol)
 */
LiquidCrystal_I2C lcd_16x2(DIRECCION_PANTALLA_PEQUEnA,
                           LCD_EN, LCD_RW, LCD_RS, LCD_D4,
                           LCD_D5, LCD_D6,
                           LCD_D7, LCD_BL, POSITIVE);
LiquidCrystal_I2C lcd_20x4(DIRECCION_PANTALLA_GRANDE,
                           LCD_EN, LCD_RW, LCD_RS, LCD_D4,
                           LCD_D5, LCD_D6,
                           LCD_D7, LCD_BL, POSITIVE);

String texto_en_claro = "";
String texto_cifrado = "";

/*
 * ROTORES
 */

rodillo  rueda_entrada;
rodillo  rotor_1;
rodillo  rotor_2;
rodillo  rotor_3;
rodillo  reflector;

/*
 * TECLADO
 */

// Initialize USB Controller
USBHost usb;

// Attach Keyboard controller to USB
KeyboardController keyboard(usb);

//////////////////////////////////////////////////////////
//////////////////////     TESTS     /////////////////////
//////////////////////////////////////////////////////////

void hola_mundo(LiquidCrystal_I2C * _lcd) {

  _lcd->setCursor(3, 0);
  _lcd->print("Hola");

  _lcd->setCursor(6, 1);
  _lcd->print("mundo.");

  write_special_char(smiley, _lcd, 1, 15, 0);
  write_special_char(smiley, _lcd, 1, 13, 0);

}



//////////////////////////////////////////////////////////
//////////////     UTILIDADES PANTALLAS     //////////////
//////////////////////////////////////////////////////////

/**
 * Imprime un bloque blanco (pixels encendidos)
 * que va recorriendo todas las posiciones
 * de la pantalla.
 *
 * @param _lcd un puntero a una pantalla.
 * @param numRows el numero de filas de la pantalla.
 * @param numCols el numero de columnas de la pantalla.
 */
void secuencia_blancos(LiquidCrystal_I2C * _lcd, int numRows, int numCols) {

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
void secuencia_barras(LiquidCrystal_I2C * _lcd, int numRows, int numCols) {

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
 *
 * @param _ch la letra a pintar.
 * @param _lcd la pantalla en al que se va a pintar.
 * @param _charNumber un numero de caracter que se le
 * asignará a _ch y que se va a pintar en
 * la posición indicada.
 *
 */
void write_special_char(byte _ch[], LiquidCrystal_I2C * _lcd, int _row,
                        int _col, int _charNumber) {
  _lcd->createChar(_charNumber, _ch);
  _lcd->setCursor(_col, _row);
  _lcd->write(int(_charNumber));
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

void pinta_rotores() {

  lcd_16x2.clear();

  lcd_16x2.setCursor(0, 0);

  lcd_16x2.print(" ");
  lcd_16x2.print(rotor_3.nombre);
  lcd_16x2.print("  ");
  lcd_16x2.print(rotor_2.nombre);
  lcd_16x2.print("  ");
  lcd_16x2.print(rotor_1.nombre);
  lcd_16x2.print("  ");
  lcd_16x2.print(rueda_entrada.nombre);

  lcd_16x2.setCursor(0, 1);

  lcd_16x2.print("  ");
  lcd_16x2.print(ALFABETO[rotor_3.cursor]);
  lcd_16x2.print("   ");
  lcd_16x2.print(ALFABETO[rotor_2.cursor]);
  lcd_16x2.print("   ");
  lcd_16x2.print(ALFABETO[rotor_1.cursor]);
  lcd_16x2.print("   ");
  lcd_16x2.print(ALFABETO[rueda_entrada.cursor]);
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

//////////////////////////////////////////////////////////
////////////////////     SECUENCIAS     //////////////////
//////////////////////////////////////////////////////////

void enciende_leds(byte potencia) {
  analogWrite(pin_led_verde_1, potencia);
  analogWrite(pin_led_verde_2, potencia);
  analogWrite(pin_led_verde_3, potencia);

  analogWrite(pin_led_amarillo_1, potencia);
  analogWrite(pin_led_amarillo_2, potencia);
  analogWrite(pin_led_amarillo_3, potencia);
  analogWrite(pin_led_amarillo_4, potencia);

  analogWrite(pin_led_rojo_1, potencia);
  analogWrite(pin_led_rojo_2, potencia);
  analogWrite(pin_led_rojo_3, potencia);
}

void secuencia_leds_paralelos(int _espaciado) {

  for (byte b = MIN_BRIGHT; b < MAX_BRIGHT; b++) {
    enciende_leds(b);
    delayMicroseconds(_espaciado);
  }

  for (byte b = MAX_BRIGHT; b > MIN_BRIGHT; b--) {
    enciende_leds(b);
    delayMicroseconds(_espaciado);
  }

  enciende_leds(0);

}

/**
 * Lo que la maquina ENIGMA hara cada
 * vez que se encienda o se reinicie.
 */
void secuencia_encendido() {

  secuencia_blancos(&lcd_20x4, 4, 20);
  secuencia_blancos(&lcd_16x2, 2, 16);

  lcd_20x4.setCursor(0, 0);
  parpadea_pantalla(&lcd_20x4, 1, 500000);
  lcd_20x4.print("Bienvenido a");

  lcd_20x4.setCursor(13, 2);
  parpadea_pantalla(&lcd_20x4, 1, 500000);
  lcd_20x4.print("ENIGMA");

  parpadea_pantalla(&lcd_20x4, 5, 100000);

  /*
   write_special_char(smiley, &lcd_16x2, 0, 12, 0);
   write_special_char(smiley, &lcd_16x2, 1, 9, 0);

   for (int b = 6; b > 0; b--) {
   parpadea_pantalla(&lcd_16x2, 1, 50);
   lcd_16x2.scrollDisplayLeft();
   delay(200);
   }
   */

  secuencia_leds_paralelos(500);

  secuencia_barras(&lcd_16x2, 2, 16);
  secuencia_barras(&lcd_20x4, 4, 20);

}

void arranca_enigma() {

  configuracion_punto();

  /*
   * Imprime en la pantalla la cabecera del texto en claro.
   */
  lcd_20x4.setCursor(0, 0);
  lcd_20x4.print(TEXTO_CLARO);

  /*
   * Imprime en la pantalla la cabecera del texto cifrado.
   */
  lcd_20x4.setCursor(0, 2);
  lcd_20x4.print(TEXTO_CIFRADO);

  pinta_rotores();
}

//////////////////////////////////////////////////////////
////////////////     INICIALIZACIONES     ////////////////
//////////////////////////////////////////////////////////

void inicializa_leds() {
  pinMode(pin_led_verde_1, OUTPUT);
  pinMode(pin_led_verde_2, OUTPUT);
  pinMode(pin_led_verde_3, OUTPUT);

  pinMode(pin_led_amarillo_1, OUTPUT);
  pinMode(pin_led_amarillo_2, OUTPUT);
  pinMode(pin_led_amarillo_3, OUTPUT);
  pinMode(pin_led_amarillo_4, OUTPUT);

  pinMode(pin_led_rojo_1, OUTPUT);
  pinMode(pin_led_rojo_2, OUTPUT);
  pinMode(pin_led_rojo_3, OUTPUT);
}

void inicializa_pantallas() {
  Serial.println("Inicializando pantallas...");
  lcd_16x2.begin(16, 2);
  lcd_16x2.clear();
  lcd_20x4.begin(20, 4);
  lcd_20x4.clear();
  Serial.println("+++ Pantallas inicializadas con exito.");
}

void inicializa_teclado() {
  Serial.println("Inicializando teclado.");
  Serial.begin(9600);
  Serial.println("+++ Teclado inicializado con exito.");
}

void configuracion_punto() {
  rueda_entrada.cursor = 0;
  rueda_entrada.letras = rueda_de_entrada_EI;
  rueda_entrada.avances = avance_NO_AVANZA;
  rueda_entrada.nombre = nombre_rueda_de_entrada_EI;

  rotor_1.cursor = 0;
  rotor_1.letras = rotor_I;
  rotor_1.avances = avance_rotor_I;
  rotor_1.nombre = nombre_rotor_I;

  rotor_2.cursor = 0;
  rotor_2.letras = rotor_II;
  rotor_2.avances = avance_rotor_II;
  rotor_2.nombre = nombre_rotor_II;

  rotor_3.cursor = 0;
  rotor_3.letras = rotor_III;
  rotor_3.avances = avance_rotor_III;
  rotor_3.nombre = nombre_rotor_III;

  reflector.cursor = 0;
  reflector.letras = reflector_A;
  reflector.avances = avance_NO_AVANZA;
  reflector.nombre = nombre_reflector_A;
}

void configuracion_1() {
  rueda_entrada.cursor = 23;
  rueda_entrada.letras = rueda_de_entrada_D1;
  rueda_entrada.avances = avance_NO_AVANZA;
  rueda_entrada.nombre = nombre_rueda_de_entrada_D1;

  rotor_1.cursor = 4;
  rotor_1.letras = rotor_II;
  rotor_1.avances = avance_rotor_II;
  rotor_1.nombre = nombre_rotor_II;

  rotor_2.cursor = 6;
  rotor_2.letras = rotor_gamma;
  rotor_2.avances = avance_rotor_gamma;
  rotor_2.nombre = nombre_rotor_gamma;

  rotor_3.cursor = 22;
  rotor_3.letras = rotor_I;
  rotor_3.avances = avance_rotor_I;
  rotor_3.nombre = nombre_rotor_I;

  reflector.cursor = 0;
  reflector.letras = reflector_RB;
  reflector.avances = avance_NO_AVANZA;
  reflector.nombre = nombre_reflector_RB;
}

void configuracion_2() {
  rueda_entrada.cursor = 11;
  rueda_entrada.letras = rueda_de_entrada_SK;
  rueda_entrada.avances = avance_NO_AVANZA;
  rueda_entrada.nombre = nombre_rueda_de_entrada_SK;

  rotor_1.cursor = 6;
  rotor_1.letras = rotor_beta;
  rotor_1.avances = avance_rotor_beta;
  rotor_1.nombre = nombre_rotor_beta;

  rotor_2.cursor = 10;
  rotor_2.letras = rotor_I_T;
  rotor_2.avances = avance_rotor_I_T;
  rotor_2.nombre = nombre_rotor_I_T;

  rotor_3.cursor = 12;
  rotor_3.letras = rotor_I;
  rotor_3.avances = avance_rotor_I;
  rotor_3.nombre = nombre_rotor_I;

  reflector.cursor = 0;
  reflector.letras = reflector_T;
  reflector.avances = avance_NO_AVANZA;
  reflector.nombre = nombre_reflector_T;
}
void configuracion_3() {
  rueda_entrada.cursor = 15;
  rueda_entrada.letras = rueda_de_entrada_Tz;
  rueda_entrada.avances = avance_NO_AVANZA;
  rueda_entrada.nombre = nombre_rueda_de_entrada_Tz;

  rotor_1.cursor = 16;
  rotor_1.letras = rotor_VI;
  rotor_1.avances = avance_rotor_VI;
  rotor_1.nombre = nombre_rotor_VI;

  rotor_2.cursor = 11;
  rotor_2.letras = rotor_I_T;
  rotor_2.avances = avance_rotor_I;
  rotor_2.nombre = nombre_rotor_I;

  rotor_3.cursor = 21;
  rotor_3.letras = rotor_II_T;
  rotor_3.avances = avance_rotor_II_T;
  rotor_3.nombre = nombre_rotor_I_T;

  reflector.cursor = 0;
  reflector.letras = reflector_B;
  reflector.avances = avance_NO_AVANZA;
  reflector.nombre = nombre_reflector_B;
}

void configuracion_4() {
  rueda_entrada.cursor = 10;
  rueda_entrada.letras = rueda_de_entrada_M4;
  rueda_entrada.avances = avance_NO_AVANZA;
  rueda_entrada.nombre = nombre_rueda_de_entrada_M4;

  rotor_1.cursor = 12;
  rotor_1.letras = rotor_VIII;
  rotor_1.avances = avance_rotor_VIII;
  rotor_1.nombre = nombre_rotor_VIII;

  rotor_2.cursor = 10;
  rotor_2.letras = rotor_II;
  rotor_2.avances = avance_rotor_II;
  rotor_2.nombre = nombre_rotor_II;

  rotor_3.cursor = 4;
  rotor_3.letras = rotor_VII;
  rotor_3.avances = avance_rotor_VII;
  rotor_3.nombre = nombre_rotor_VII;

  reflector.cursor = 0;
  reflector.letras = reflector_SK;
  reflector.avances = avance_NO_AVANZA;
  reflector.nombre = nombre_reflector_SK;
}

//////////////////////////////////////////////////////////
/////////////////////      ROTORES     ///////////////////
//////////////////////////////////////////////////////////

bool avanza(struct rodillo *  _rod) {
  _rod->cursor++;
  _rod->cursor %= NUM_LETRAS;
  if (_rod->avances[_rod->cursor]) {
    Serial.print(_rod->nombre);
    Serial.println(" avanza.");
    return true;
  } else {
    Serial.print(_rod->nombre);
    Serial.println(" no avanza.");
    return false;
  }
}

/**
 * @return la posicion de una letra en el abecedario,
 * empezando en 0, o -1 si no es una letra del abecedario.
 */
int posLetra(char _letra) {
  switch (_letra) {
    case 'A':
    case 'a':
      return A;

    case 'B':
    case 'b':
      return B;

    case 'C':
    case 'c':
      return C;

    case 'D':
    case 'd':
      return D;

    case 'E':
    case 'e':
      return E;

    case 'F':
    case 'f':
      return F;

    case 'G':
    case 'g':
      return G;

    case 'H':
    case 'h':
      return H;

    case 'I':
    case 'i':
      return I;

    case 'J':
    case 'j':
      return J;

    case 'K':
    case 'k':
      return K;

    case 'L':
    case 'l':
      return L;

    case 'M':
    case 'm':
      return M;

    case 'N':
    case 'n':
      return N;

    case 'O':
    case 'o':
      return O;

    case 'P':
    case 'p':
      return P;

    case 'Q':
    case 'q':
      return Q;

    case 'R':
    case 'r':
      return R;

    case 'S':
    case 's':
      return S;

    case 'T':
    case 't':
      return T;

    case 'U':
    case 'u':
      return U;

    case 'V':
    case 'v':
      return V;

    case 'W':
    case 'w':
      return W;

    case 'X':
    case 'x':
      return X;

    case 'Y':
    case 'y':
      return Y;

    case 'Z':
    case 'z':
      return Z;

    default:
      return -1;
  }
}

/*Denominamos cifrar al camino desde la entrada de la letra (derecha-izquierda)*/
/*hasta el reflecto*/
int cifra(struct rodillo  _rod, int _original) {
  int pos = (_original + _rod.cursor);
  pos %= NUM_LETRAS;
  return _rod.letras[pos];
}


/*Denominamos descifrar al camino desde el reflector hasta la salida (izquierda-derecha)*/
int descifra(struct rodillo  _rod, int _original) {
  int pos = buscar(_rod, _original);
  pos -= _rod.cursor;
  if (pos < 0) {
    return NUM_LETRAS + pos;
  } else {
    return pos % NUM_LETRAS;
  }
}

int buscar(struct rodillo _rod, int _valor) {
  for (int b = 0; b < NUM_LETRAS; b++) {
    if (_rod.letras[b] == _valor) {
      return b;
    }
  }
  return -1;
}

/**
 * Hace las operaciones necesarias para cifrar una letra
 * segun la configuracion actual de ENIGMA.
 *
 * @param letra la letra que se a va cifrar.
 */
char enigma(char _letra) {
  Serial.print("enigma(");
  Serial.print(_letra);
  Serial.println(")");

  int pos = posLetra(_letra);

  Serial.print("\t :::: posicion: ");
  Serial.println(pos);

  avanza(&rueda_entrada);

  if (avanza(&rotor_1)) {
    Serial.println("\t :::: rotor_1 -- vuelta completa --");
    if (avanza(&rotor_2)) {
      Serial.println("\t :::: rotor_1 -- vuelta completa --");
      avanza(&rotor_3);
    }
  }

  Serial.print("\t :::: [");
  Serial.print(ALFABETO[reflector.cursor]);
  Serial.print(" : ");
  Serial.print(reflector.cursor);
  Serial.print("] [");
  Serial.print(ALFABETO[rotor_3.cursor]);
  Serial.print(" : ");
  Serial.print(rotor_3.cursor);
  Serial.print("] [");
  Serial.print(ALFABETO[rotor_2.cursor]);
  Serial.print(" : ");
  Serial.print(rotor_2.cursor);
  Serial.print("] [");
  Serial.print(ALFABETO[rotor_1.cursor]);
  Serial.print(" : ");
  Serial.print(rotor_1.cursor);
  Serial.print("] [");
  Serial.print(ALFABETO[rueda_entrada.cursor]);
  Serial.print(" : ");
  Serial.print(rueda_entrada.cursor);
  Serial.print("] <-- ");
  Serial.println(ALFABETO[pos]);
  pos = cifra(rueda_entrada, pos);
  Serial.print("\t :::: [] [] [] [] <-- ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" <-- []");

  pos = cifra(rotor_1, pos);
  Serial.print("\t :::: [] [] [] <-- ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" <-- [] []");
  pos = cifra(rotor_2, pos);
  Serial.print("\t :::: [] [] <-- ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" <-- [] [] []");
  pos = cifra(rotor_3, pos);
  Serial.print("\t :::: [] <-- ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" <-- [] [] [] []");

  pos = cifra(reflector, pos);
  Serial.print("\t :::: [] --> ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" --> [] [] [] []");

  pos = descifra(rotor_3, pos);
  Serial.print("\t :::: [] [] --> ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" --> [] [] []");
  pos = descifra(rotor_2, pos);
  Serial.print("\t :::: [] [] [] --> ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" --> [] []");
  pos = descifra(rotor_1, pos);
  Serial.print("\t :::: [] [] [] [] --> ");
  Serial.print(ALFABETO[pos]);
  Serial.println(" --> []");

  pos = descifra(rueda_entrada, pos);
  Serial.print("\t :::: [] [] [] [] [] --> ");
  Serial.println(ALFABETO[pos]);

  char result = ALFABETO[pos];

  Serial.print("\t :::: return: ");
  Serial.println(result);

  secuencia_leds_paralelos(500);

  return result;
}

//////////////////////////////////////////////////////////
/////////////////////     PROGRAMA     ///////////////////
//////////////////////////////////////////////////////////

void setup() {

  inicializa_teclado();
  inicializa_pantallas();
  secuencia_encendido();
  arranca_enigma();
}

void loop() {

  usb.Task();

  //hola_mundo(&lcd_16x2);

}

/*Para que solo lea de teclado, las teclas que nos interesan*/
void keyPressed() {
  char c = (char)keyboard.getKey();

  switch (c) {
    case 'A':
    case 'a':
    case 'B':
    case 'b':
    case 'C':
    case 'c':
    case 'D':
    case 'd':
    case 'E':
    case 'e':
    case 'F':
    case 'f':
    case 'G':
    case 'g':
    case 'H':
    case 'h':
    case 'I':
    case 'i':
    case 'J':
    case 'j':
    case 'K':
    case 'k':
    case 'L':
    case 'l':
    case 'M':
    case 'm':
    case 'N':
    case 'n':
    case 'O':
    case 'o':
    case 'P':
    case 'p':
    case 'Q':
    case 'q':
    case 'R':
    case 'r':
    case 'S':
    case 's':
    case 'T':
    case 't':
    case 'U':
    case 'u':
    case 'V':
    case 'v':
    case 'W':
    case 'w':
    case 'X':
    case 'x':
    case 'Y':
    case 'y':
    case 'Z':
    case 'z':
      escribe_letra(c, enigma(c));
      break;
    //      case '0':
    //      configuracion_0();
    //      break;
    case '1':
      configuracion_1();
      break;
    case '2':
      configuracion_2();
      break;
    case '3':
      configuracion_3();
      break;
    case '4':
      configuracion_4();
      break;
    //      case '5':
    //      configuracion_5();
    //      break;
    //      case '6':
    //      configuracion_6();
    //      break;
    //      case '7':
    //      configuracion_7();
    //      break;
    //      case '8':
    //      configuracion_8();
    //      break;
    //      case '9':
    //      configuracion_9();
    //      break;
    case '.':
      configuracion_punto();
      break;
    default:
      escribe_letra(' ', ' ');
      break;
  }

  pinta_rotores();
}
