#ifndef TAULER_H
#define TAULER_H
#include "figura.h"
//codi aqui

const int MAX_FILES;
const int MAX_COLUMNES;

class Tauler
{
public:
	Tauler() { m_tauler[N_FILES][N_COLUMNES] = {{NO_COLOR}}; }
	Tauler(ColorFigura taulerInput); // constructor que inicialitza el tauler que rep com a paràmetre
	bool filaCompleta();
	void eliminaFila();
	bool colisioFigura(Figura f);
	//getters
	ColorFigura getValor(int fila, int col) { return int(m_tauler[fila][col]); }
private:
  	ColorFigura m_tauler[N_FILES][N_COLUMNES];
  
}

#endif
