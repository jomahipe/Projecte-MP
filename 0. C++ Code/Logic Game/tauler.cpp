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



#include <array>

enum class CollisionType { 
    NO_COLLISION, 
    OUT_OF_BOUNDS, 
    OVERLAP 
};

CollisionType Tauler::colisio(Figura fig) {
    int novaFila = fig.getFila();
    int novaColumna = fig.getColumna();
    const int figHeight = fig.getAlcada();
    const int figWidth = fig.getAmplada();
    
    // Create a fixed-size array to store the figure's data
    int figMatrix[figHeight][figWidth];

    // Initialize the matrix to 0
    for (int i = 0; i < figHeight; ++i) {
        for (int j = 0; j < figWidth; ++j) {
            figMatrix[i][j] = 0;
        }
    }

    // Get the figure's matrix
    fig.getMatriu(figMatrix);

    // Iterate through each cell of the figure's matrix
    for (int i = 0; i < figHeight; ++i) {
        for (int j = 0; j < figWidth; ++j) {
            // Check if each part of the matrix is empty or not (i.e., if it has a color or not)
            if (figMatrix[i][j] != NO_COLOR) { // Has color
                int filaTauler = novaFila + i;
                int columnaTauler = novaColumna + j;

                if (filaTauler < 0 || filaTauler >= MAX_ROW || columnaTauler < 0 || columnaTauler >= MAX_COL) {
                    // We're out of bounds
                    return CollisionType::OUT_OF_BOUNDS;
                }

                if (m_tauler[filaTauler][columnaTauler] != NO_COLOR) {
                    // Another figure already exists at this position
                    return CollisionType::OVERLAP;
                }
            }
        }
    }

    // If no collision detected, return NO_COLLISION
    return CollisionType::NO_COLLISION;
}


void Tauler::escriuFigura(Figura fig)
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
