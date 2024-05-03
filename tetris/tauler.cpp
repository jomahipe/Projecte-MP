#include "tauler.h"

Tauler::Tauler()
{
    for (int f = 0; f < MAX_FILES; f++)
    {
        for (int c = 0; c < MAX_COLUMNES; c++)
            tauler[f][c] = NO_COLOR;
    }
}
void Tauler::inicialitza(ColorFigura tauler)
{
    for (int f = 0; f < MAX_FILES; f++)
    {
        for (int c = 0; c < MAX_COLUMNES; c++)
            m_tauler[f][c] = tauler[f][c];
    }
}


bool Tauler::filaCompleta(int fila)
{
	int j = 0;
	bool trobat = false;
	while (j < MAX_COLUMNES && !trobat)
	{
		if (m_tauler[fila][j] == 0)
		{
			trobat = true;//hem trobat un zero
		}
	}
	return !trobat;
}

bool Tauler::filaBuida(int fila)
{
    bool buida = true;
    int i = 0;
    while (buida && i < MAX_COLUMNES)
    {
        if (m_tauler[fila][i] != 0)
            buida = false;
    }
    return buida;
}

void Tauler::eliminaFila(int fila)
{
    int f = fila;
    
    while (f > 1 && !filaBuida(f))
    {
        for (int c = 0; c < MAX_COLUMNES; c++)
            m_tauler[f][c] = m_tauler[f - 1][c];
        --f;
    }

}


bool colisioFigura(Figura fig)
{
    // obtenim la matriu de figura
    // es recorre la matriu amb el tauler. Xoca?
    // si hi ha colisio return true
    // si no, false
}

void Tauler::escriuFigura(Figura fig)
{
    // per a aquest mètode suposem que ja hem fet comprovacions
    // i que la figura no pot baixar sense tapar una figura ja fixada al tauler
    ColorFigura matriuFigura[DIM_MAT][DIM_MAT];
    int alcadaFigura, ampladaFigura;
    fig.getMatriu(matriuFigura, alcadaFigura, ampladaFigura);
    if (fig.getTipusFigura != FIGURA_I)
    {
        for (int filaTauler = fig.getFila() - (alcada / 2); filaTauler < fig.getFila() + (alcada / 2); filaTauler++)
        {
            for (int colTauler = fig.getColumna() - (amplada / 2); colTauler < fig.getColumna() - (amplada / 2); colTauler++)

        }

    }
    else

}