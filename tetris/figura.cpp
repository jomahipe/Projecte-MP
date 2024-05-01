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
bool Figura::mouFigura(int dirX)
{
if (dirX == 1)
{
//hem de moure la figura per la dreta
//hem de veure si primer es possible el moviment que hem passat com a parametre
return false;
}
else
{
return false;
}
{

}
}


int Figura::getGir()
{
    // implementar després de pensar com fer giraFigura
}
