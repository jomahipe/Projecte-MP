#include "figura.h"

void Figura::inicialitza(TipusFigura tipus, int fila, int columna)
{
    m_tipusFigura = tipus;
    m_fila = fila;
    m_columna = columna;
}

void Figura::gira(DireccioGir gir) {
	

if (m_tipusFigura != NO_FIGURA || m_color != NO_COLOR) {
		ColorFigura novaMatriu[DIM_MAT][DIM_MAT] = { NO_COLOR };
		//tant com en el cas horari com anti horari em de fer la matriu transposada
		for (int i = 0; i < DIM_MAT; i++) {
			for (int j = 0; j < DIM_MAT; j++) {
				novaMatriu[j][i] = m_matriu[i][j];
			}
		}
		// Rotate the matrix based on the direction
		if (gir == GIR_HORARI) {
			
			
			for (int i = 0; i < DIM_MAT; i++) {
				for (int j = 0; j < DIM_MAT / 2; j++) {
					ColorFigura temp = novaMatriu[i][j];
					novaMatriu[i][j] = novaMatriu[i][DIM_MAT - 1 - j];
					novaMatriu[i][DIM_MAT - 1 - j] = temp;
				}
			}
		}
		else if (gir == GIR_ANTI_HORARI) {
			
			for (int i = 0; i < DIM_MAT / 2; i++) {
				for (int j = 0; j < DIM_MAT; j++) {
					ColorFigura temp = novaMatriu[i][j];
					novaMatriu[i][j] = novaMatriu[DIM_MAT- 1 - i][j];
					novaMatriu[DIM_MAT - 1 - i][j] = temp;
			
		}
			}

		// Update the original matrix with the rotated matrix
		for (int i = 0; i < DIM_MAT; i++) {
			for (int j = 0; j < DIM_MAT; j++) {
				m_matriu[i][j] = novaMatriu[i][j];
			}
		}
		
	}
		}
	int aux = m_alcada;
	m_alcada = m_amplada;
	m_amplada = aux;
}

void Figura::setGir(int gir)
{
	for (int i = 0; i < gir; i++)
		gira(GIR_HORARI);
}


void Figura::inicialitzaMatriu()
{
	switch (m_tipusFigura)
	{
		case (FIGURA_O):
			m_matriu[0][0] = m_matriu[0][1] = m_matriu[1][0] = m_matriu[1][1] = COLOR_GROC;
			m_color = COLOR_GROC;
			m_alcada = 2;
			m_amplada = 2;
			break;
		case (FIGURA_J):
			m_matriu[0][0] = m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = COLOR_BLAUFOSC;
			m_color = COLOR_BLAUFOSC;
			m_alcada = 2; 
			m_amplada = 3;
			break;
		case (FIGURA_L):
			m_matriu[2][0] = m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = COLOR_TARONJA;
			m_color = COLOR_TARONJA;
			m_alcada = 2; 
			m_amplada = 3;
			break;
		case (FIGURA_T):
			m_matriu[0][1] = m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = COLOR_MAGENTA;
			m_color = COLOR_MAGENTA;
			m_alcada = 2;
			m_amplada = 3;
			break;
		case (FIGURA_S):
			m_matriu[0][1] = m_matriu[0][2] = m_matriu[1][0] = m_matriu[1][1] = COLOR_VERD;
			m_color = COLOR_VERD;
			m_alcada = 2;
			m_amplada = 3;
			break;
		case (FIGURA_Z):
			m_matriu[0][0] = m_matriu[0][1] = m_matriu[1][1] = m_matriu[1][2] = COLOR_VERMELL;
			m_color = COLOR_VERMELL;
			m_alcada = 2;
			m_amplada = 3;
			break;
		case (FIGURA_I):
			m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = m_matriu[1][3] = COLOR_BLAUCEL;
			m_color = COLOR_BLAUCEL;
			m_alcada = 1;
			m_amplada = 4;
			break;
	}

}


void Figura::getMatriu(ColorFigura matriu[DIM_MAT][DIM_MAT])
{
	inicialitzaMatriu();
	setGir(m_girFigura);
	//copiem matriu
	for (int f = 0; f < DIM_MAT; f++)
	{
		for (int c = 0; c < DIM_MAT; c++)
			matriu[f][c] = m_matriu[f][c];
	}
		

}


int Figura::getFilaInicial() const
{
	bool trobat = false;
	int f = 0, c = 0;
	while(!trobat && f < DIM_MAT)
	{
		while (c < DIM_MAT && !trobat)
		{
			if (m_matriu[f][c] == m_color)
			{	
				trobat = true;
			}
			else c++;
		}
		if (!trobat) 
		{
			c = 0;
			f++;
		}
	}	
	if (f == 0 || (f == 1 && m_tipusFigura == FIGURA_I)) //canviar quan trobem solució
		return (m_fila - 1);
	else if (f == 1)
		return m_fila;
	else if (f == 2)
		return (m_fila + 1);
	//si f es otra cosa tenim un problema ...
}

int Figura::getColInicial() const
{
	bool trobat = false;
	int f = 0, c = 0;
	while(!trobat && f < DIM_MAT)
	{
		while (c < DIM_MAT && !trobat)
		{
			if (m_matriu[f][c] == m_color)
			{
				trobat = true;
				int col = c;
			}
			else c++;

		}
		if (!trobat)
		{
			c = 0;
			f++;
		}
	}
	if (c == 0 && m_tipusFigura != FIGURA_I)
		return (m_columna - 1);
	else if (c == 0 && m_tipusFigura == FIGURA_I)
		return (m_columna - 2);
	else 
		return m_columna;
}
