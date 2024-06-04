#include "tauler.h"

Tauler::Tauler()
{
    for (int f = 0; f < MAX_COL; f++)
    {
        for (int c = 0; c < MAX_COL; c++)
            m_tauler[f][c] = NO_COLOR;
    }
}
void Tauler::inicialitza(ColorFigura tauler)
{
    for (int f = 0; f < MAX_COL; f++)
    {
        for (int c = 0; c < MAX_COL; c++)
            m_tauler[f][c] = ColorFigura(tauler[f][c]);
    }
}


bool Tauler::filaCompleta(int fila)
{
	int j = 0;
	bool completa = true;
    if (fila >= MAX_COL)
    { 
        completa = false;
        goto out;
    }
	while (j < MAX_COL && completa)
	{
		if (m_tauler[fila][j] == 0)
		{
			completa = false;
		}
	}
    out:
	return completa;
}
bool Tauler::filaBuida(int fila)
{
    bool buida = true;
    int i = 0;
    while (buida && i < MAX_COL)
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
        for (int c = 0; c < MAX_COL; c++)
            m_tauler[f][c] = m_tauler[f - 1][c];
        --f;
    }

}

bool Tauler::posicioValida(TipusFigura fig) {
	// a continuacio tenim codi no important pero el guardo per si de cas: 
    int novaFila = fig.getFila();
    int novaColumna = fig.getColumna();
    int figHeight, figWidth;
    fig.getValors(figHeight,figWidth);
	
    
    int figMatrix[DIM_MAT][DIM_MAT];
    fig.getMatriu(figMatrix);

    for (int i = 0; i < DIM_MAT; ++i) {
        for (int j = 0; j < DIM_MAT; ++j) {
            if (figMatrix[i][j] != NO_COLOR) { // Has color
                int filaTauler = novaFila + i;
                int columnaTauler = novaColumna + j;

                if (filaTauler < 0 || filaTauler >= MAX_FILA || columnaTauler < 0 || columnaTauler >= MAX_COL) {
                    return false; // Out of bounds
                }

                if (m_tauler[filaTauler][columnaTauler] != NO_COLOR) {
                    return false; // Overlap with existing figure
                }
            }
        }
    }
    return true; // Valid position
}

bool Tauler::colisio(TipusFigura fig) {
    int novaFila = fig.getFila();
    int novaColumna = fig.getColumna();
    int figHeight, figWidth;
    fig.getValors(figHeight, figWidth);

    ColorFigura figMatrix[DIM_MAT][DIM_MAT];
    fig.getMatriu(figMatrix);

    for (int i = 0; i < DIM_MAT; ++i) {
        for (int j = 0; j < DIM_MAT; ++j) {
            if (figMatrix[i][j] != NO_COLOR) { 
                int filaTauler = novaFila + i;
                int columnaTauler = novaColumna + j;

                int filaBelow = filaTauler + 1;
                if (filaBelow >= MAX_FILA || (filaBelow >= 0 && m_tauler[filaBelow][columnaTauler] != NO_COLOR)) {
                    return true; 
                }
            }
        }
    }
    return false; 
}


void Tauler::escriuFigura(TipusFigura fig)
{
    // per a aquest mètode suposem que ja hem fet comprovacions
    // i que la figura no pot baixar sense tapar una figura ja fixada al tauler
	int ff = 0, cf = 0, alc, ampl;
	ColorFigura matriuFigura[DIM_MAT][DIM_MAT];
    fig.getMatriu(matriuFigura);
	fig.getValors(alc, ampl);
	    for (int f = fig.getFilaInicial(); f < fig.getFilaInicial() + alc; f++)
    {
		for (int c = fig.getColInicial(); c < fig.getColInicial() + ampl; c++)
        {
			if (m_tauler[f][c] == NO_COLOR )
				m_tauler[f][c] = matriuFigura[ff][cf];
			cf++; 
		}
		ff++;
	}
}
