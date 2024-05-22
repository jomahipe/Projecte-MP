#include "tauler.h"

Tauler::Tauler()
{
    for (int f = 0; f < MAX_COL; f++)
    {
        for (int c = 0; c < MAX_COL; c++)
            tauler[f][c] = NO_COLOR;
    }
}
void Tauler::inicialitza(ColorFigura tauler)
{
    for (int f = 0; f < MAX_COL; f++)
    {
        for (int c = 0; c < MAX_COL; c++)
            m_tauler[f][c] = tauler[f][c];
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


bool Tauler::colisio(Figura fig)
	{
		int novaFila = 0;
		int novaColumna = 0;
		bool trobat=false //inicialitzem el boolean trobat a false, es a dir, diem que no hem trobat o detectat colisions
		novaFila = fig.getFila();
		novaColumna = fig.getColumna();
		//arar cal iterar per cada quadrat de la matriu on esta la figura
		//fem whiles (nomes en detectar una colisio ja es suficient
		int i = 0;
		int j = 0;
		
		while(i<DIM_MAT&&!trobat){
			while(j<DIM_MAT&&!trobat){
				//ara mirem si cada part de la matriu es buida o no, es dir , si te un color o no
				if (fig.getValors(i, j) != NO_COLOR)//tenim color passe, sino no
				{
					int filaTauler = novaFila + i;
					int columnaTauler = novaColumna + j;
					if ((filaTauler < 0 && filaTauler > MAX_COL) && (columnaTauler<0 && columnaTauler>MAX_COL))
					{
						//estem fora dels limits
						trobat = true;
					}
					if (m_tauler[novaFila][novaColumna] != NO_COLOR)
					{
						//en aquesta posicio ja existeix una altre figura
						trobat = true;
					}
				}
			}
		}
		return trobat;
		
	}

void Tauler::escriuFigura(Figura fig)
{
    // per a aquest mètode suposem que ja hem fet comprovacions
    // i que la figura no pot baixar sense tapar una figura ja fixada al tauler
    ColorFigura matriuFigura[DIM_MAT][DIM_MAT];
    fig.getMatriu(matriuFigura);
    fig.getValors(alcadaFigura, ampladaFigura);
    if (fig.getTipusFigura != FIGURA_I)
    {
		int f = 0; c = 0;
        for (int filaTauler = fig.getFilaInicial(); filaTauler < fig.getFilaFinal(); filaTauler++)
        {
            for (int colTauler = fig.getColInicial(); colTauler < fig.getColFinal(); colTauler++)
           {
			   m_tauler[filaTauler][colTauler] = matriuFigura[f][c];
			   c++; 

        }
			f++;
}
