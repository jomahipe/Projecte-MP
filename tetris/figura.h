#ifndef FIGURA_H
#define FIGURA_H
//codi aqui
#include "joc.h"

typedef enum
{
NO_FIGURA = 0,
FIGURA_O,
FIGURA_I,
FIGURA_T,
FIGURA_L,
FIGURA_J,
FIGURA_Z,
FIGURA_S
} TipusFigura;

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

const int DIM_MAT = 4;

class Figura
{
public:
	Figura() { m_girFigura = 0;}
	bool gira(DireccioGir dir);
	void inicialitza(TipusFigura tipus, int fila, int columna);
	void mouX(int dirX) { m_fila += dirX; }
	void baixa();	
	// getters:
	TipusFigura getTipusFigura() const { return m_tipusFigura; }	
	ColorFigura getColorFigura() const { return m_color; }
	int getColumna() const { return m_columna; }
	int getFila() const { return m_fila; }
	int getGir() const { return m_girFigura; }
	
	// setters:
	void setGir(int gir);

	//matriu
	void inicialitzaMatriu();
	void getMatriu(ColorFigura matriu[DIM_MAT][DIM_MAT], int& alcada, int& amplada);
private:
	TipusFigura m_tipusFigura;
	int m_fila;
	int m_columna;
	int m_girFigura; 

	//atributs de la matriu de la figura
	ColorFigura m_matriu[DIM_MAT][DIM_MAT];
	ColorFigura m_color;
	int m_alcada;
	int m_amplada;



}

#endif
