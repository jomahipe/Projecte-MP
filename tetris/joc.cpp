#include "joc.h"
using namespace std;

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		// valors de figura que trobarem al fitxer
		TipusFigura tipusFig;
		int filaFig, columnaFig, girFig;

		// la primera fila és el tipus de la figura, posició al tauler i orientació
		fitxer >> tipusFig >> filaFig >> columnaFig >> girFig;
		m_figura.inicialitza(tipusFig, filaFig, columnaFig);
		giraFigura(girFig);
		
		// la resta és el propi tauler
		ColorFigura taulerFitxer;
		for (int f = 0; f < MAX_FILES; f++)
		{
			for (int c = 0; c < MAX_COLUMNES; c++)
				fitxer >> taulerFitxer[f][c];
		}
		m_tauler.(taulerFitxer);
		fitxer.close();
	}
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
	// escrivim valors de figura
		TipusFigura tipusFig;
		int filaFig, columnaFig, girFig;

		tipusFig = m_figura.getTipusFigura();
		filaFig = m_figura.getFila();
		columnaFig = m_figura.getColumna();
		girFig = m_figura.getGir();
		
		fitxer << tipusFig << filaFig << columnaFig << girFig;
	
	// escrivim tauler
		for (int f = 0; f < MAX_FILES; f++)
		{
			for (int c = 0; c < MAX_COLUMNES; c++)
				fitxer << m_tauler.getValor(f, c);
		}

	fitxer.close();
	}
}


bool Joc::giraFigura(DireccioGir direccio)
{
	m_figura.gira(direccio); //fem gir
	bool girValid = tauler.colisioFigura(m_figura);
	if (!girValid)
		m_figura.gira(-direccio);
	return girValid;
}


bool Joc::mouFigura(int dirX)
{
	m_figura.moure(dirX);
	bool movValid = tauler.colisioFigura(m_figura);
	if (!movValid)
		m_figura.moure(-dirX);
	return movValid;
}

void Joc::baixaFigura()
{
	if (colisioFigura(m_figura))

}

