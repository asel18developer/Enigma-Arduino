#include "rotores.h"

bool avanza(struct rodillo * _rod) {
  _rod->cursor++;
  _rod->cursor %= NUM_LETRAS;
  return (_rod->avances[_rod->cursor]);
}

int * copiaArrayInt(const int * _array) {
  int copia[NUM_LETRAS];
  for (int i = 0; i < NUM_LETRAS; i++) {
    copia[i] = _array[i];
  }
  return copia;
}

bool * copiaArrayBool(const bool * _array) {
  bool copia[NUM_LETRAS];
  for (int i = 0; i < NUM_LETRAS; i++) {
    copia[i] = _array[i];
  }
  return copia;
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

int cifra(struct rodillo * _rod, int _original) {
  int pos = (_original + _rod->cursor) % NUM_LETRAS;
  return _rod->letras[pos];
}

int descifra(struct rodillo * _rod, int _original) {
  return (_original + _rod->cursor) % NUM_LETRAS;
}
