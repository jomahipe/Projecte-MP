#pragma once
#idndef CONSTANTS_H
#define CONSTANTS_H
#include "figura.h"
//codi aqui

const int MAX_FIL = 21;
const int MAX_COL= 11; 
/*el type enum struct a continuacio esta duplicat(poso barres per si decas)
typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;
*/a

class Tauler
{
public:
	Tauler();
	void inicialitza(ColorFigura tauler); // constructor que inicialitza el tauler amb el que rep com a paràmetre
	bool filaCompleta(int fila);
	bool filaBuida(int fila);
	void eliminaFila(int fila);
	bool colisio(Figura fig);
	bool posicioValida(Figura fig);
	void escriuFigura(Figura);
	//getters
	int getValor(int fila, int col) { return int(m_tauler[fila][col]); }
private:
	ColorFigura m_tauler[MAX_FIL][MAX_COL];

};
