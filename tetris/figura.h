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

Class Figura
{
public:

private:
  TipusFigura m_tipusFigura;
  ColorFigura m_colorFigura;
}

#endif
