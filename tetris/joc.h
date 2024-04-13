#ifndef JOC_H
#define JOC_H
#include "figura.h"
#include "tauler.h"

typedef enum
{
GIR_HORARI = 0,
GIR_ANTI_HORARI
} DireccioGir;

Class Joc
{
public:
        //interfície pública obligatòria 
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	//funcions nostres a partir d'aquí
	void incrementaPuntuacio();
	void incrementaNivell();
private:
	Tauler m_tauler;
	Figura m_figura;
	//coses nostres aquí
	int m_puntuacio;
	int m_nivell;
}


#endif
