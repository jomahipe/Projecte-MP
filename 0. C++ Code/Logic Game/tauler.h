#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
//codi aqui

const int MAX_FILA = 21;
const int MAX_COL = 11; 


class Tauler
{
public:
	Tauler();
	void inicialitza(ColorFigura tauler[MAX_FILA][MAX_COL]); // constructor que inicialitza el tauler amb el que rep com a paràmetre
	bool filaCompleta(int fila);
	bool filaBuida(int fila);
	void eliminaFila(int fila);
	bool colisio(Figura fig);
	bool posicioValida(Figura fig);
	void escriuFigura(Figura fig);
	//getters
	int getValor(int fila, int col) { return int(m_tauler[fila][col]); }
private:
	ColorFigura m_tauler[MAX_FILA][MAX_COL];

};
#endif
