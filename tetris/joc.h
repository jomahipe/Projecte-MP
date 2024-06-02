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
{
public:
	//constructor
	Joc();
    //interfície pública obligatòria 
	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();	
private:
	Tauler m_tauler;
	Figura m_figura;

}

#endif
