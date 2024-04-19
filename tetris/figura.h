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
	//Constructors, (canviar?)
	Figura(TipusFigura tipus, ColorFigura color, DireccioGir direccio) { m_tipusFigura = tipus; m_colorFigura = color; m_girActual = direccio; }
	Figura() { m_tipusFigura = NO_FIGURA; m_colorFigura = NO_COLOR; m_girActual = NOGIR; }
	
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	void baixaFigura();

	TipusFigura getTipusFigura() { return m_tipusFigura; }

private:
  	TipusFigura m_tipusFigura;
  	ColorFigura m_colorFigura;
	DireccioGir m_girActual;
}

#endif
