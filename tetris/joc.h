#ifndef JOC_H
#define JOC_H
#include "figura.h"
#include "tauler.h"
#include <ifstream>

typedef enum
{
GIR_HORARI = 0,
GIR_ANTI_HORARI
} DireccioGir;

class Joc

public:
	//constructor
	Joc() { m_puntuacio = 0; m_nivell = 0; }
    //interfície pública obligatòria 
	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	void baixaFigura();
	//funcions nostres a partir d'aquí
	void incrementaPuntuacio() { m_puntuacio++; }
	void incrementaNivell() { m_nivell++; }
	void eliminaFila(); //el tipus de retorn de les funcions pot canviar si decidim que hi ha una alternativa millor
	bool colisioFigura(int filaDesti, int colDesti);
private:
	Tauler m_tauler;
	Figura m_figura;
	//coses nostres aquí
	int m_puntuacio;
	int m_nivell;

