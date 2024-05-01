#ifndef FIGURA_H
#define FIGURA_H
//codi aqui

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
	bool giraFigura(DireccioGir direccio);
	void inicialitza(TipusFigura tipus, int fila, int columna);
	void moure(int dirX);
	// getters:
	TipusFigura getTipusFigura() { return m_tipusFigura; }	
	int getColumna() { return m_columna; }
	int getFila() { return m_fila; }
	int getGir();
private:
	TipusFigura m_tipusFigura;
	ColorFigura m_colorFigura;
	int m_fila;
	int m_columna;
	int m_girFigura; // <- possiblement faci falta modificar aquest atribut 
	// corregir si no està ben implementat
	int m_forma[6][6]; // una vegada decidim que aquesta és la solució final crearem una constant
}

#endif
