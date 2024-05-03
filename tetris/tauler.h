#ifndef TAULER_H
#define TAULER_H
#include "figura.h"
//codi aqui

const int MAX_FIL;
const int MAX_COL; // hem d'inicialitzar aquests valors!

class Tauler
{
public:
	Tauler();
	void inicialitza(ColorFigura tauler); // constructor que inicialitza el tauler que rep com a paràmetre
	bool filaCompleta(int fila);
	bool filaBuida(int fila);
	void eliminaFila(int fila);
	bool colisio(Figura fig);
	void escriuFigura(Figura);
	//getters
	ColorFigura getValor(int fila, int col) { return int(m_tauler[fila][col]); }
private:
  	ColorFigura m_tauler[N_FILES][N_COLUMNES];
  
}

#endif
