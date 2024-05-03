#ifndef TAULER_H
#define TAULER_H
#include "figura.h"
//codi aqui

const int MAX_FILES;
const int MAX_COLUMNES; // hem d'inicialitzar aquests valors!

class Tauler
{
public:
	Tauler() { m_tauler[N_FILES][N_COLUMNES] = {{NO_COLOR}}; }
	void inicialitza(ColorFigura tauler); // constructor que inicialitza el tauler que rep com a paràmetre
	bool filaCompleta(int fila);
	void eliminaFila(int fila);
	bool colisioFigura(Figura fig);
	void escriuMatriu(int matriu);
	//getters
	ColorFigura getValor(int fila, int col) { return int(m_tauler[fila][col]); }
private:
  	ColorFigura m_tauler[N_FILES][N_COLUMNES];
	bool filaBuida(int fila);
  
}

#endif
