#ifndef JOC_H
#define JOC_H
#include "figura.h"
#include "tauler.h"

typedef enum
{
GIR_HORARI = 0,
GIR_ANTI_HORARI
} DireccioGir;

class Joc
{
public:
        //interfície pública obligatòria 
	void inicialitza(const string& nomFitxer); //ifstream requerit
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	void baixaFigura();
	void escriuTauler(const string& nomFitxer);
	//funcions nostres a partir d'aquí
	void incrementaPuntuacio();
	void incrementaNivell();
	void eliminaFila(); //nota: el tipus de retorn de les nostres funcions pot canviar si decidim que hi ha una alternativa millor
private:
	Tauler m_tauler;
	Figura m_figura;
	//coses nostres aquí
	int m_puntuacio;
	int m_nivell;
}


#endif
