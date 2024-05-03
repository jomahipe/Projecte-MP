#include "tauler.h"


Tauler::Tauler(ColorFigura tauler)
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
    }

}
