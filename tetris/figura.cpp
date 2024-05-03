#include "figura.h"

void Figura::inicialitza(TipusFigura tipus, int fila, int columna)
{
    m_tipusFigura = tipus;
    m_fila = fila;
    m_columna = columna;
}

bool Figura::giraFigura(direccioGir gir)
{
	if (m_tipusFigura == NO_FIGURA || m_tipusColor == NO_COLOR)
	{
		return false;
	}
	else
	{
		int novaForma[6][6] = { 0 };//creem aquesta variable per guardar temporalment els canvis realitzades en la figura actual
		int intercanvi[6][6] = { 0 };//aquesta matriu es fara servir quan hem de realitzar columnes invertides i files invertides
		//en qualsevol cas necessitem la transposada
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				novaForma[i][j] = m_forma[i][j];
			}
		}
		if (direccio == GIR_HORARI)
		{
			for (int j = 0; i < 6; i++)
			{ //invertim columnes;
				for (int j = 0; j < 6; j++)
				{
					intercanvi[i][j] = novaForma[i][5-j];
				}
			}
		}
		else if (direccio == ANTI_HORARI)
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					intercanvi[i][j] = novaForma[5 - i][j];
				}
			}
		}
		//despres de tot hem de realitzar el intercanvi final
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				m_forma[i][j] = intercanvi[i][j];
			}
		}
		return true;
	}
	
}
void Figura::mouX(int dirX)
{
	m_columna += dirX;
}

void Figura::mouY(int dirY)
{
	m_fila += dirY;
}

void Figura::setGir(int gir)
{
	for (int i = 0; i < gir; i++)
		gira(GIR_HORARI);
}


void inicialitzaMatriu()
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


void getMatriu(ColorFigura matriu[DIM_MAT][DIM_MAT], int& alcada, int& amplada)
{
	//copiem matriu
	for (int f = 0; f < DIM_MAT; f++)
	{
		for (int c = 0; c < DIM_MAT; c++)
			matriu[f][c] = m_matriu[f][c];
	}
	alcada = m_alcada;
	amplada = m_amplada;
}
