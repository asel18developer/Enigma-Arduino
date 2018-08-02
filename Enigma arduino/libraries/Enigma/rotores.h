#ifndef ROTORES_H
#define ROTORES_H

/*
 *  ------------------------- LETRAS -------------------------
 */

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8
#define J 9
#define K 10
#define L 11
#define M 12
#define N 13
#define O 14
#define P 15
#define Q 16
#define R 17
#define S 18
#define T 19
#define U 20
#define V 21
#define W 22
#define X 23
#define Y 24
#define Z 25

/*
 *  ------------------------- ROTORES -------------------------
 */



const static int rotor_I[] = {E, K, M, F, L, G, D, Q, V, Z, N, T, O, W, Y, H, X, U, S, P, A, I, B, R, C, J};
static const String nombre_rotor_I = "I";
static const bool avance_rotor_I[] = {/* A */false, /* B */false, /* C */false,
                                             /* D */false, /* E */false, /* F */false,
                                             /* G */ false, /* H */false, /* I */false,
                                             /* J */false, /* K */false, /* L */false,
                                             /* M */ false, /* N */false, /* O */false,
                                             /* P */false, /* Q */true, /* R */false,
                                             /* S */false, /* T */false, /* U */false,
                                             /* V */false, /* W */false, /* X */false,
                                             /* Y */false, /* Z */false
                                     };
const static int rotor_II[] = {A, J, D, K, S, I, R, U, X, B, L, H, W, T, M, C, Q, G, Z, N, P, Y, F, V, O, E};
static const String nombre_rotor_II = "II";
static const bool avance_rotor_II[] = {/* A */false, /* B */false, /* C */false,
                                              /* D */false, /* E */true, /* F */false,
                                              /* G */ false, /* H */false, /* I */false,
                                              /* J */false, /* K */false, /* L */false,
                                              /* M */ false, /* N */false, /* O */false,
                                              /* P */false, /* Q */false, /* R */false,
                                              /* S */false, /* T */false, /* U */false,
                                              /* V */false, /* W */false, /* X */false,
                                              /* Y */false, /* Z */false
                                      };
const static int rotor_III[] = {	B, D, F, H, J, L, C, P, R, T, X, V, Z, N, Y, E, I, W, G, A, K, M, U, S, Q, O};
static const String nombre_rotor_III = "III";
static const bool avance_rotor_III[] = {/* A */false, /* B */false, /* C */false,
                                               /* D */false, /* E */false, /* F */false,
                                               /* G */ false, /* H */false, /* I */false,
                                               /* J */false, /* K */false, /* L */false,
                                               /* M */ false, /* N */false, /* O */false,
                                               /* P */false, /* Q */false, /* R */false,
                                               /* S */false, /* T */false, /* U */false,
                                               /* V */true, /* W */false, /* X */false,
                                               /* Y */false, /* Z */false
                                       };
const static int rotor_IV[] = {E, S, O, V, P, Z, J, A, Y, Q, U, I, R, H, X, L, N, F, T, G, K, D, C, M, W, B};
static const String nombre_rotor_IV = "IV";
static const bool avance_rotor_IV[] = {/* A */false, /* B */false, /* C */false,
                                              /* D */false, /* E */false, /* F */false,
                                              /* G */ false, /* H */false, /* I */false,
                                              /* J */true, /* K */false, /* L */false,
                                              /* M */ true, /* N */false, /* O */false,
                                              /* P */false, /* Q */false, /* R */false,
                                              /* S */false, /* T */false, /* U */false,
                                              /* V */false, /* W */false, /* X */false,
                                              /* Y */false, /* Z */false
                                      };
const static int rotor_V[] = {V, Z, B, R, G, I, T, Y, U, P, S, D, N, H, L, X, A, W, M, J, Q, O, F, E, C, K};
static const String nombre_rotor_V = "V";
static const bool avance_rotor_V[] = {/* A */false, /* B */false, /* C */false,
                                             /* D */false, /* E */false, /* F */false,
                                             /* G */ false, /* H */false, /* I */false,
                                             /* J */false, /* K */false, /* L */false,
                                             /* M */ false, /* N */false, /* O */false,
                                             /* P */false, /* Q */false, /* R */false,
                                             /* S */false, /* T */false, /* U */false,
                                             /* V */false, /* W */false, /* X */false,
                                             /* Y */false, /* Z */true
                                     };
const static int rotor_VI[] = {J, P, G, V, O, U, M, F, Y, Q, B, E, N, H, Z, R, D, K, A, S, X, L, I, C, T, W};
static const String nombre_rotor_VI = "VI";
static const bool avance_rotor_VI[] = {/* A */false, /* B */false, /* C */false,
                                              /* D */false, /* E */false, /* F */false,
                                              /* G */ false, /* H */false, /* I */false,
                                              /* J */false, /* K */false, /* L */false,
                                              /* M */ true, /* N */false, /* O */false,
                                              /* P */false, /* Q */false, /* R */false,
                                              /* S */false, /* T */false, /* U */false,
                                              /* V */false, /* W */false, /* X */false,
                                              /* Y */false, /* Z */true
                                      };
const static int rotor_VII[] = {N, Z, J, H, G, R, C, X, M, Y, S, W, B, O, U, F, A, I, V, L, P, E, K, Q, D, T};
static const String nombre_rotor_VII = "VII";
static const bool avance_rotor_VII[] = {/* A */false, /* B */false, /* C */false,
                                               /* D */false, /* E */false, /* F */false,
                                               /* G */ false, /* H */false, /* I */false,
                                               /* J */false, /* K */false, /* L */false,
                                               /* M */ true, /* N */false, /* O */false,
                                               /* P */false, /* Q */false, /* R */false,
                                               /* S */false, /* T */false, /* U */false,
                                               /* V */false, /* W */false, /* X */false,
                                               /* Y */false, /* Z */true
                                       };
const static int rotor_VIII[] = {F, K, Q, H, T, L, X, O, C, B, J, S, P, D, Z, R, A, M, E, W, N, I, U, Y, G, V};
static const String nombre_rotor_VIII = "VIII";
static const bool avance_rotor_VIII[] = {/* A */false, /* B */false, /* C */false,
                                                /* D */false, /* E */false, /* F */false,
                                                /* G */ false, /* H */false, /* I */false,
                                                /* J */false, /* K */false, /* L */false,
                                                /* M */ true, /* N */false, /* O */false,
                                                /* P */false, /* Q */false, /* R */false,
                                                /* S */false, /* T */false, /* U */false,
                                                /* V */false, /* W */false, /* X */false,
                                                /* Y */false, /* Z */true
                                        };
// NO AVANZA
const static int rotor_beta[] = {L, E, Y, J, V, C, N, I, X, W, P, B, Q, M, D, R, T, A, K, Z, G, F, U, H, O, S};
static const String nombre_rotor_beta = "β";
static const bool avance_rotor_beta[] = {/* A */false, /* B */false, /* C */false,
                                                /* D */false, /* E */false, /* F */false,
                                                /* G */ false, /* H */false, /* I */false,
                                                /* J */false, /* K */false, /* L */false,
                                                /* M */ false, /* N */false, /* O */false,
                                                /* P */false, /* Q */false, /* R */false,
                                                /* S */false, /* T */false, /* U */false,
                                                /* V */false, /* W */false, /* X */false,
                                                /* Y */false, /* Z */false
                                        };
// NO AVANZA
const static int rotor_gamma[] = {F, S, O, K, A, N, U, E, R, H, M, B, T, I, Y, C, W, L, Q, P, Z, X, V, G, J, D};
static const String nombre_rotor_gamma = "γ";
static const bool avance_rotor_gamma[] = {/* A */false, /* B */false, /* C */false,
                                                 /* D */false, /* E */false, /* F */false,
                                                 /* G */ false, /* H */false, /* I */false,
                                                 /* J */false, /* K */false, /* L */false,
                                                 /* M */ false, /* N */false, /* O */false,
                                                 /* P */false, /* Q */false, /* R */false,
                                                 /* S */false, /* T */false, /* U */false,
                                                 /* V */false, /* W */false, /* X */false,
                                                 /* Y */false, /* Z */false
                                         };
const static int rotor_I_T[] = {K, P, T, Y, U, E, L, O, C, V, G, R, F, Q, D, A, N, J, M, B, S, W, H, Z, X, I}; // TODO seguir poniendo los nombres de los rotores.
static const bool avance_rotor_I_T[] = {/* A */false, /* B */false, /* C */false,
                                               /* D */false, /* E */true, /* F */false,
                                               /* G */ false, /* H */false, /* I */false,
                                               /* J */false, /* K */true, /* L */false,
                                               /* M */ false, /* N */false, /* O */false,
                                               /* P */false, /* Q */true, /* R */false,
                                               /* S */false, /* T */false, /* U */false,
                                               /* V */false, /* W */true, /* X */false,
                                               /* Y */false, /* Z */true
                                       };
const static int rotor_II_T[] = {U, P, H, Z, L, W, E, Q, M, T, D, J, X, C, A, K, S, O, I, G, V, B, Y, F, N, R};
static const bool avance_rotor_II_T[] = {/* A */false, /* B */false, /* C */false,
                                                /* D */false, /* E */false, /* F */true,
                                                /* G */ false, /* H */false, /* I */false,
                                                /* J */false, /* K */false, /* L */true,
                                                /* M */ false, /* N */false, /* O */false,
                                                /* P */false, /* Q */false, /* R */true,
                                                /* S */false, /* T */false, /* U */false,
                                                /* V */false, /* W */true, /* X */false,
                                                /* Y */false, /* Z */true
                                        };
const static int rotor_III_T[] = {Q, U, D, L, Y, R, F, E, K, O, N, V, Z, A, X, W, H, M, G, P, J, B, S, I, C, T};
static const bool avance_rotor_III_T[] = {/* A */false, /* B */false, /* C */false,
                                                 /* D */false, /* E */true, /* F */false,
                                                 /* G */ false, /* H */false, /* I */false,
                                                 /* J */false, /* K */true, /* L */false,
                                                 /* M */ false, /* N */false, /* O */false,
                                                 /* P */false, /* Q */true, /* R */false,
                                                 /* S */false, /* T */false, /* U */false,
                                                 /* V */false, /* W */true, /* X */false,
                                                 /* Y */false, /* Z */true
                                         };
const static int rotor_IV_T[] = {C, I, W, T, B, K, X, N, R, E, S, P, F, L, Y, D, A, G, V, H, Q, U, O, J, Z, M};
static const bool avance_rotor_IV_T[] = {/* A */false, /* B */false, /* C */false,
                                                /* D */false, /* E */false, /* F */true,
                                                /* G */ false, /* H */false, /* I */false,
                                                /* J */false, /* K */false, /* L */true,
                                                /* M */ false, /* N */false, /* O */false,
                                                /* P */false, /* Q */false, /* R */true,
                                                /* S */false, /* T */false, /* U */false,
                                                /* V */false, /* W */true, /* X */false,
                                                /* Y */false, /* Z */true
                                        };
const static int rotor_V_T[] = {U, A, X, G, I, S, N, J, B, V, E, R, D, Y, L, F, Z, W, T, P, C, K, O, H, M, Q};
static const bool avance_rotor_V_T[] = {/* A */false, /* B */false, /* C */true,
                                               /* D */false, /* E */false, /* F */true,
                                               /* G */ false, /* H */false, /* I */false,
                                               /* J */false, /* K */true, /* L */false,
                                               /* M */ false, /* N */false, /* O */false,
                                               /* P */false, /* Q */false, /* R */true,
                                               /* S */false, /* T */false, /* U */false,
                                               /* V */false, /* W */false, /* X */false,
                                               /* Y */true, /* Z */false
                                       };
const static int rotor_VI_T[] = {X, F, U, Z, G, A, L, V, H, C, N, Y, S, E, W, Q, T, D, M, R, B, K, P, I, O, J};
static const bool avance_rotor_VI_T[] = {/* A */false, /* B */false, /* C */false,
                                                /* D */false, /* E */true, /* F */false,
                                                /* G */ false, /* H */false, /* I */true,
                                                /* J */false, /* K */false, /* L */false,
                                                /* M */ true, /* N */false, /* O */false,
                                                /* P */false, /* Q */true, /* R */false,
                                                /* S */false, /* T */false, /* U */false,
                                                /* V */false, /* W */false, /* X */true,
                                                /* Y */false, /* Z */false
                                        };
const static int rotor_VII_T[] = {B, J, V, F, T, X, P, L, N, A, Y, O, Z, I, K, W, G, D, Q, E, R, U, C, H, S, M};
static const bool avance_rotor_VII_T[] = {/* A */false, /* B */false, /* C */true,
                                                 /* D */false, /* E */false, /* F */true,
                                                 /* G */ false, /* H */false, /* I */false,
                                                 /* J */false, /* K */true, /* L */false,
                                                 /* M */ false, /* N */false, /* O */false,
                                                 /* P */false, /* Q */false, /* R */true,
                                                 /* S */false, /* T */false, /* U */false,
                                                 /* V */false, /* W */false, /* X */false,
                                                 /* Y */true, /* Z */false
                                         };
const static int rotor_VIII_T[] = {Y, M, T, P, N, Z, H, W, K, O, D, A, J, X, E, L, U, Q, V, G, C, B, I, S, F, R};
static const bool avance_rotor_VIII_T[] = {/* A */false, /* B */false, /* C */false,
                                                  /* D */false, /* E */true, /* F */false,
                                                  /* G */ false, /* H */false, /* I */true,
                                                  /* J */false, /* K */false, /* L */false,
                                                  /* M */ true, /* N */false, /* O */false,
                                                  /* P */false, /* Q */true, /* R */false,
                                                  /* S */false, /* T */false, /* U */false,
                                                  /* V */false, /* W */false, /* X */true,
                                                  /* Y */false, /* Z */false
                                          };
const static int rotor_I_G[] = {D, M, T, W, S, I, L, R, U, Y, Q, N, K, F, E, J, C, A, Z, B, P, G, X, O, H, V};
static const bool avance_rotor_I_G[] = {/* A */true, /* B */true, /* C */true,
                                               /* D */false, /* E */true, /* F */true,
                                               /* G */ true, /* H */false, /* I */true,
                                               /* J */false, /* K */true, /* L */true,
                                               /* M */ false, /* N */false, /* O */true,
                                               /* P */true, /* Q */true, /* R */false,
                                               /* S */true, /* T */false, /* U */true,
                                               /* V */true, /* W */true, /* X */false,
                                               /* Y */false, /* Z */true
                                       };
const static int rotor_II_G[] = {H, Q, Z, G, P, J, T, M, O, B, L, N, C, I, F, D, Y, A, W, V, E, U, S, R, K, X};
static const bool avance_rotor_II_G[] = {/* A */true, /* B */false, /* C */true,
                                                /* D */true, /* E */false, /* F */true,
                                                /* G */ true, /* H */true, /* I */false,
                                                /* J */false, /* K */true, /* L */false,
                                                /* M */ true, /* N */true, /* O */false,
                                                /* P */false, /* Q */true, /* R */false,
                                                /* S */true, /* T */true, /* U */false,
                                                /* V */true, /* W */false, /* X */false,
                                                /* Y */true, /* Z */true
                                        };
const static int rotor_III_G[] = {U, Q, N, T, L, S, Z, F, M, R, E, H, D, P, X, K, I, B, V, Y, G, J, C, W, O, A};
static const bool avance_rotor_III_G[] = {/* A */true, /* B */false, /* C */false,
                                                 /* D */false, /* E */true, /* F */true,
                                                 /* G */ false, /* H */true, /* I */false,
                                                 /* J */false, /* K */true, /* L */false,
                                                 /* M */ true, /* N */true, /* O */false,
                                                 /* P */false, /* Q */false, /* R */true,
                                                 /* S */false, /* T */false, /* U */true,
                                                 /* V */false, /* W */true, /* X */true,
                                                 /* Y */false, /* Z */false
                                         };

const static int rotor_I_G312[] = {D, M, T, W, S, I, L, R, U, Y, Q, N, K, F, E, J, C, A, Z, B, P, G, X, O, H, V};
static const bool avance_rotor_I_G312[] = {/* A */true, /* B */true, /* C */true,
                                                  /* D */false, /* E */true, /* F */true,
                                                  /* G */ true, /* H */false, /* I */true,
                                                  /* J */false, /* K */true, /* L */true,
                                                  /* M */ false, /* N */false, /* O */true,
                                                  /* P */true, /* Q */true, /* R */false,
                                                  /* S */true, /* T */false, /* U */true,
                                                  /* V */true, /* W */true, /* X */false,
                                                  /* Y */false, /* Z */true
                                          };
const static int rotor_II_G312[] = {H, Q, Z, G, P, J, T, M, O, B, L, N, C, I, F, D, Y, A, W, V, E, U, S, R, K, X};
static const bool avance_rotor_II_G312[] = {/* A */true, /* B */false, /* C */true,
                                                   /* D */true, /* E */false, /* F */true,
                                                   /* G */ true, /* H */true, /* I */false,
                                                   /* J */false, /* K */true, /* L */false,
                                                   /* M */ true, /* N */true, /* O */false,
                                                   /* P */false, /* Q */true, /* R */false,
                                                   /* S */true, /* T */true, /* U */false,
                                                   /* V */true, /* W */false, /* X */false,
                                                   /* Y */true, /* Z */true
                                           };
const static int rotor_III_G312[] = {U, Q, N, T, L, S, Z, F, M, R, E, H, D, P, X, K, I, B, V, Y, G, J, C, W, O, A};
static const bool avance_rotor_III_G312[] = {/* A */true, /* B */false, /* C */false,
                                                    /* D */false, /* E */true, /* F */true,
                                                    /* G */ false, /* H */true, /* I */false,
                                                    /* J */false, /* K */true, /* L */false,
                                                    /* M */ true, /* N */true, /* O */false,
                                                    /* P */false, /* Q */false, /* R */true,
                                                    /* S */false, /* T */false, /* U */true,
                                                    /* V */false, /* W */true, /* X */true,
                                                    /* Y */false, /* Z */false
                                            };

const static int rotor_I_G260[] = {R, C, S, P, B, L, K, Q, A, U, M, H, W, Y, T, I, F, Z, V, G, O, J, N, E, X, D};
static const bool avance_rotor_I_G260[] = {/* A */true, /* B */true, /* C */true,
                                                  /* D */false, /* E */true, /* F */true,
                                                  /* G */ true, /* H */false, /* I */true,
                                                  /* J */false, /* K */true, /* L */true,
                                                  /* M */ false, /* N */false, /* O */true,
                                                  /* P */true, /* Q */true, /* R */false,
                                                  /* S */true, /* T */false, /* U */true,
                                                  /* V */true, /* W */true, /* X */false,
                                                  /* Y */false, /* Z */true
                                          };
const static int rotor_II_G260[] = {W, C, M, I, B, V, P, J, X, A, R, O, S, G, N, D, L, Z, K, E, Y, H, U, F, Q, T};
static const bool avance_rotor_II_G260[] = {/* A */true, /* B */false, /* C */true,
                                                   /* D */true, /* E */false, /* F */true,
                                                   /* G */ true, /* H */true, /* I */false,
                                                   /* J */false, /* K */true, /* L */false,
                                                   /* M */ true, /* N */true, /* O */false,
                                                   /* P */false, /* Q */true, /* R */false,
                                                   /* S */true, /* T */true, /* U */false,
                                                   /* V */true, /* W */false, /* X */false,
                                                   /* Y */true, /* Z */true
                                           };
const static int rotor_III_G260[] = {F, V, D, H, Z, E, L, S, Q, M, A, X, O, K, Y, I, W, P, G, C, B, U, J, T, N, R};
static const bool avance_rotor_III_G260[] = {/* A */true, /* B */false, /* C */false,
                                                    /* D */false, /* E */true, /* F */true,
                                                    /* G */ false, /* H */true, /* I */false,
                                                    /* J */false, /* K */true, /* L */false,
                                                    /* M */ true, /* N */true, /* O */false,
                                                    /* P */false, /* Q */false, /* R */true,
                                                    /* S */false, /* T */false, /* U */true,
                                                    /* V */false, /* W */true, /* X */true,
                                                    /* Y */false, /* Z */false
                                            };

const static int rotor_I_reichbahn[] = {J, G, D, Q, O, X, U, S, C, A, M, I, F, R, V, T, P, N, E, W, K, B, L, Z, Y, H};
static const bool avance_rotor_I_reichbahn[] = {/* A */false, /* B */false, /* C */false,
                                                       /* D */false, /* E */false, /* F */false,
                                                       /* G */ false, /* H */false, /* I */false,
                                                       /* J */false, /* K */false, /* L */false,
                                                       /* M */ false, /* N */true, /* O */false,
                                                       /* P */false, /* Q */false, /* R */false,
                                                       /* S */false, /* T */false, /* U */false,
                                                       /* V */false, /* W */false, /* X */false,
                                                       /* Y */false, /* Z */false
                                               };
const static int rotor_II_reichbahn[] = {N, T, Z, P, S, F, B, O, K, M, W, R, C, J, D, I, V, L, A, E, Y, U, X, H, G, Q};
static const bool avance_rotor_II_reichbahn[] = {/* A */false, /* B */false, /* C */false,
                                                        /* D */false, /* E */true, /* F */false,
                                                        /* G */ false, /* H */false, /* I */false,
                                                        /* J */false, /* K */false, /* L */false,
                                                        /* M */ false, /* N */false, /* O */false,
                                                        /* P */false, /* Q */false, /* R */false,
                                                        /* S */false, /* T */false, /* U */false,
                                                        /* V */false, /* W */false, /* X */false,
                                                        /* Y */false, /* Z */false
                                                };
const static int rotor_III_reichbahn[] = {J, V, I, U, B, H, T, C, D, Y, A, K, E, Q, Z, P, O, S, G, X, N, R, M, W, F, L};
static const bool avance_rotor_III_reichbahn[] = {/* A */false, /* B */false, /* C */false,
                                                         /* D */false, /* E */false, /* F */false,
                                                         /* G */ false, /* H */false, /* I */false,
                                                         /* J */false, /* K */false, /* L */false,
                                                         /* M */ false, /* N */false, /* O */false,
                                                         /* P */false, /* Q */false, /* R */false,
                                                         /* S */false, /* T */false, /* U */false,
                                                         /* V */false, /* W */false, /* X */false,
                                                         /* Y */true, /* Z */false
                                                 };

const static int rotor_I_D[] = {L, P, G, S, Z, M, H, A, E, O, Q, K, V, X, R, F, Y, B, U, T, N, I, C, J, D, W};
static const bool avance_rotor_I_D[] = {/* A */false, /* B */false, /* C */false,
                                               /* D */false, /* E */false, /* F */false,
                                               /* G */ false, /* H */false, /* I */false,
                                               /* J */false, /* K */false, /* L */false,
                                               /* M */ false, /* N */false, /* O */false,
                                               /* P */false, /* Q */false, /* R */false,
                                               /* S */false, /* T */false, /* U */false,
                                               /* V */false, /* W */false, /* X */false,
                                               /* Y */true, /* Z */false
                                       };
const static int rotor_II_D[] = {S, L, V, G, B, T, F, X, J, Q, O, H, E, W, I, R, Z, Y, A, M, K, P, C, N, D, U};
static const bool avance_rotor_II_D[] = {/* A */false, /* B */false, /* C */false,
                                                /* D */false, /* E */true, /* F */false,
                                                /* G */ false, /* H */false, /* I */false,
                                                /* J */false, /* K */false, /* L */false,
                                                /* M */ false, /* N */false, /* O */false,
                                                /* P */false, /* Q */false, /* R */false,
                                                /* S */false, /* T */false, /* U */false,
                                                /* V */false, /* W */false, /* X */false,
                                                /* Y */false, /* Z */false
                                        };
const static int rotor_III_D[] = {C, J, G, D, P, S, H, K, T, U, R, A, W, Z, X, F, M, Y, N, Q, O, B, V, L, I, E};
static const bool avance_rotor_III_D[] = {/* A */false, /* B */false, /* C */false,
                                                 /* D */false, /* E */false, /* F */false,
                                                 /* G */ false, /* H */false, /* I */false,
                                                 /* J */false, /* K */false, /* L */false,
                                                 /* M */ false, /* N */true, /* O */false,
                                                 /* P */false, /* Q */false, /* R */false,
                                                 /* S */false, /* T */false, /* U */false,
                                                 /* V */false, /* W */false, /* X */false,
                                                 /* Y */false, /* Z */false
                                         };

const static int rotor_I_K[] = {L, P, G, S, Z, M, H, A, E, O, Q, K, V, X, R, F, Y, B, U, T, N, I, C, J, D, W};
static const bool avance_rotor_I_K[] = {/* A */false, /* B */false, /* C */false,
                                               /* D */false, /* E */false, /* F */false,
                                               /* G */ false, /* H */false, /* I */false,
                                               /* J */false, /* K */false, /* L */false,
                                               /* M */ false, /* N */false, /* O */false,
                                               /* P */false, /* Q */false, /* R */false,
                                               /* S */false, /* T */false, /* U */false,
                                               /* V */false, /* W */false, /* X */false,
                                               /* Y */true, /* Z */false
                                       };
const static int rotor_II_K[] = {S, L, V, G, B, T, F, X, J, Q, O, H, E, W, I, R, Z, Y, A, M, K, P, C, N, D, U};
static const bool avance_rotor_II_K[] = {/* A */false, /* B */false, /* C */false,
                                                /* D */false, /* E */true, /* F */false,
                                                /* G */ false, /* H */false, /* I */false,
                                                /* J */false, /* K */false, /* L */false,
                                                /* M */ false, /* N */false, /* O */false,
                                                /* P */false, /* Q */false, /* R */false,
                                                /* S */false, /* T */false, /* U */false,
                                                /* V */false, /* W */false, /* X */false,
                                                /* Y */false, /* Z */false
                                        };
const static int rotor_III_K[] = {C, J, G, D, P, S, H, K, T, U, R, A, W, Z, X, F, M, Y, N, Q, O, B, V, L, I, E};
static const bool avance_rotor_III_K[] = {/* A */false, /* B */false, /* C */false,
                                                 /* D */false, /* E */false, /* F */false,
                                                 /* G */ false, /* H */false, /* I */false,
                                                 /* J */false, /* K */false, /* L */false,
                                                 /* M */ false, /* N */true, /* O */false,
                                                 /* P */false, /* Q */false, /* R */false,
                                                 /* S */false, /* T */false, /* U */false,
                                                 /* V */false, /* W */false, /* X */false,
                                                 /* Y */false, /* Z */false
                                         };

/*
* ------------------------- REFLECTORES -------------------------
*/

static const bool avance_NO_AVANZA[] = {/* A */false, /* B */false, /* C */false,
                                               /* D */false, /* E */false, /* F */false,
                                               /* G */ false, /* H */false, /* I */false,
                                               /* J */false, /* K */false, /* L */false,
                                               /* M */ false, /* N */false, /* O */false,
                                               /* P */false, /* Q */false, /* R */false,
                                               /* S */false, /* T */false, /* U */false,
                                               /* V */false, /* W */false, /* X */false,
                                               /* Y */false, /* Z */false
                                       };

/**
* UKW A, M3 'Wehrmacht'
*/
static const int reflector_A[] = {E, J, M, Z, A, L, Y, X, V, B, W, F, C, R, Q, U, O, N, T, S, P, I, K, H, G, D};
/**
* UKW B, M3 and M4 'Wehrmacht'
*/
static const int reflector_B[] = {Y, R, U, H, Q, S, L, D, P, X, N, G, O, K, M, I, E, B, F, Z, C, W, V, J, A, T};
/**
* UKW C, M3 and M4 'Wehrmacht'
*/
static const int reflector_C[] = {F, V, P, J, I, A, O, Y, E, D, R, Z, X, W, G, C, T, K, U, Q, S, B, N, M, H, L};
/**
* UKW B 'thin', M4 'Shark'
*/
static const int reflector_Bt[] = {E, N, K, Q, A, U, Y, W, J, I, C, O, P, B, L, M, D, X, Z, V, F, T, H, R, G, S};
/**
* UKW C 'thin', M4 'Shark'
*/
static const int reflector_Ct[] = {R, D, O, B, J, N, T, K, V, E, H, M, L, F, C, W, Z, A, X, G, Y, I, P, S, U, Q};
/**
* UKW (T), Enigma T 'Tirpitz'
*/
static const int reflector_T[] = {G, E, K, P, B, T, A, U, M, O, C, N, I, L, J, D, X, Z, Y, F, H, W, V, Q, S, R};
/**
* UKW (G), Enigma G 'Defense'
*/
static const int reflector_G[] = {R, U, L, Q, M, Z, J, S, Y, G, O, C, E, T, K, W, D, A, H, N, B, X, P, V, I, F};
/**
* UKW (G), Enigma G312 'Defense'
*/
static const int reflector_G3[] = {R, U, L, Q, M, Z, J, S, Y, G, O, C, E, T, K, W, D, A, H, N, B, X, P, V, I, F};
/**
* UKW (G), Enigma G260 'Defense'
*/
static const int reflector_G2[] = {I, M, E, T, C, G, F, R, A, Y, S, Q, B, Z, X, W, L, H, K, D, V, U, P, O, J, N};
/**
* UKW, Enigma 'Reichsbahn'
*/
static const int reflector_RB[] = {Q, Y, H, O, G, N, E, C, V, P, U, Z, T, F, D, J, A, X, W, M, K, I, S, R, B, L};
/**
* UKW (D), Enigma D
*/
static const int reflector_D[] = {I, M, E, T, C, G, F, R, A, Y, S, Q, B, Z, X, W, L, H, K, D, V, U, P, O, J, N};
/**
* UKW, Enigma Swiss-K
*/
static const int reflector_SK[] = {I, M, E, T, C, G, F, R, A, Y, S, Q, B, Z, X, W, L, H, K, D, V, U, P, O, J, N};

/*
* ------------------------- RODRILLOS DE ENTRADA -------------------------
*/

static const char ALFABETO[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
/**
 * ETW, Enigma I 'Wehrmacht'
 */
static const int rueda_de_entrada_EI[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
/**
 * ETW, M4 'Shark'
 */
static const int rueda_de_entrada_M4[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
/**
 * ETW (T), Enigma T 'Tirpitz'
 */
static const int rueda_de_entrada_Tz[] = {K, Z, R, O, U, Q, H, Y, A, I, G, B, L, W, V, S, T, D, X, F, P, N, M, C, J, E};
/**
 * ETW (G), Enigma G 'Defense'
 */
static const int rueda_de_entrada_GD[] = {Q, W, E, R, T, Z, U, I, O, A, S, D, F, G, H, J, K, P, Y, X, C, V, B, N, M, L};
/**
 * ETW (G), Enigma G312 'Defense'
 */
static const int rueda_de_entrada_G3[] = {Q, W, E, R, T, Z, U, I, O, A, S, D, F, G, H, J, K, P, Y, X, C, V, B, N, M, L};
/**
 * ETW (G), Enigma G260 'Defense'
 */
static const int rueda_de_entrada_G2[] = {Q, W, E, R, T, Z, U, I, O, A, S, D, F, G, H, J, K, P, Y, X, C, V, B, N, M, L};
/**
 * ETW, Enigma 'Reichsbahn'
 */
static const int rueda_de_entrada_RB[] = {Q, W, E, R, T, Z, U, I, O, A, S, D, F, G, H, J, K, P, Y, X, C, V, B, N, M, L};
/**
 * ETW (D), Enigma D, Version 1
 */
static const int rueda_de_entrada_D1[] = {J, W, U, L, C, M, N, O, H, P, Q, Z, Y, X, I, R, A, D, K, E, G, V, B, T, S, F};
/**
 * ETW (D), Enigma D, Version 2
 */
static const int rueda_de_entrada_D2[] = {Q, W, E, R, T, Z, U, I, O, A, S, D, F, G, H, J, K, P, Y, X, C, V, B, N, M, L};
/**
 * ETW, Enigma Swiss-K
 */
static const int rueda_de_entrada_SK[] = {Q, W, E, R, T, Z, U, I, O, A, S, D, F, G, H, J, K, P, Y, X, C, V, B, N, M, L};


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

typedef struct rodillo {
  int cursor;
  int * letras;
  bool * avances;
  String nombre;
} rodillo;

bool avanza(struct rodillo * _rod);
int * copiaArrayInt(const int * _array);
bool * copiaArrayBool(const bool * _array);
int posLetra(char _letra);
int cifra(struct rodillo * _rod, int _original);
int descifra(struct rodillo * _rod, int _original);

#endif /* ROTORES_H */
