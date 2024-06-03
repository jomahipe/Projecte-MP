#include "joc.h"
using namespace std;

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		// valors de figura que trobarem al fitxer
			int filaFig, columnaFig, girFig, tipusFig;

		// la primera fila és el tipus de la figura, posició al tauler i orientació
		fitxer >> tipusFig >> filaFig >> columnaFig >> girFig;
		m_figura.inicialitza(TipusFigura(tipusFig), filaFig, columnaFig);
		m_figura.inicialitzaMatriu();
		m_figura.setGir(girFig);
		// la resta és el propi tauler
		ColorFigura taulerFitxer[MAX_FILES][MAX_COL];
		for (int f = 0; f < MAX_FILES; f++)
		{
			for (int c = 0; c < MAX_COLUMNES; c++)
				fitxer >> taulerFitxer[f][c];
		}
		m_tauler.inicialitza(taulerFitxer);
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
		int tipusFig, filaFig, columnaFig, girFig;

		tipusFig = int(m_figura.getTipusFigura());
		filaFig = m_figura.getFila();
		columnaFig = m_figura.getColumna();
		girFig = m_figura.getGir();
		
		fitxer << tipusFig << filaFig << columnaFig << girFig;
	
	// escrivim tauler
		if (m_figura.getTipusFigura() != NO_FIGURA)
			m_tauler.escriuFigura(m_figura);
		for (int f = 0; f < MAX_FILES; f++)
		{
			for (int c = 0; c < MAX_COLUMNES; c++)
				fitxer << m_tauler.getValor(f, c);
			fitxer << endl;
		}

	fitxer.close();
	}
}


bool Joc::giraFigura(DireccioGir direccio)
{
	m_figura.gira(direccio); //fem gir
	DireccioGir direccioContraria;
	if (direccio == GIR_HORARI)
		direccioContraria = GIR_ANTI_HORARI;
	else 
		direccioContraria = GIR_HORARI;
	bool girValid = (tauler.colisioFigura(m_figura) == NO_COLISSION) ;
	if (!girValid)
		m_figura.gira(direccioContraria); //desfem gir
	return girValid;
}


bool Joc::mouFigura(int dirX)
{
	m_figura.moure(dirX);
	bool movValid = !tauler.colisioFigura(m_figura);
	if (!movValid)
		m_figura.moure(-dirX);
	return movValid;
}

int Joc::baixaFigura()
{
	int nFiles = 0;
	m_figura.baixa();
	if (m_tauler.colisioFigura(m_figura) == NO_COLLISION)
	{
		// ara toca comprovar totes les files que ocupi la figura
		for (int f = m_figura.getFilaInicial(); f < f + 3; f++)
		{	
			if (m_tauler.filaCompleta(f))
			{
				m_tauler.eliminaFila(f);
				nFiles++;
			}	
			
		}

	}
	else
	{
		m_figura.puja();
	}
	
	return nFiles;
}

