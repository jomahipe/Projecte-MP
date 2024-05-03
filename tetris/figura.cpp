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
			color = COLOR_GROC;
			break;
		case (FIGURA_J):
			m_matriu[0][0] = m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = COLOR_BLAUFOSC;
			color = COLOR_BLAUFOSC;
			break;
		case (FIGURA_L):
			m_matriu[2][0] = m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = COLOR_TARONJA;
			color = COLOR_TARONJA;
			break;
		case (FIGURA_T):
			m_matriu[0][1] = m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = COLOR_MAGENTA;
			color = COLOR_MAGENTA;
			break;
		case (FIGURA_S):
			m_matriu[0][1] = m_matriu[0][2] = m_matriu[1][0] = m_matriu[1][1] = COLOR_VERD;
			color = COLOR_VERD;
			break;
		case (FIGURA_Z):
			m_matriu[0][0] = m_matriu[0][1] = m_matriu[1][1] = m_matriu[1][2] = COLOR_VERMELL;
			color = COLOR_VERMELL;
			break;
		case (FIGURA_I):
			m_matriu[1][0] = m_matriu[1][1] = m_matriu[1][2] = m_matriu[1][3] = COLOR_BLAUCEL;
			color = COLOR_BLAUCEL;
			break;
	}

}
