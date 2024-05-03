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

class Figura
{
public:
	Figura() { m_girFigura = 0;}
	bool giraFigura(DireccioGir direccio);
	void inicialitza(TipusFigura tipus, int fila, int columna);
	void mouX(int dirX);
	void mouY(int dirY); //pot ser 1 o -1
	// getters:
	int getMatriuFigura();
	TipusFigura getTipusFigura() const { return m_tipusFigura; }	
	ColorFigura getColorFigura() const { return m_colorFigura; }
	int getColumna() const { return m_columna; }
	int getFila() const { return m_fila; }
	int getGir() const { return m_girFigura; }
	// setters:
	void setGir(int gir);
private:
	TipusFigura m_tipusFigura;
	ColorFigura m_colorFigura;
	int m_fila;
	int m_columna;
	int m_girFigura; 
}

#endif
