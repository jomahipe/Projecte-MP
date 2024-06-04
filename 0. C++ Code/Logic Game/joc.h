#ifndef JOC_H
#define JOC_H
#include "figura.h"
#include "tauler.h"
#include <fstream>
#include <string>
using namespace std;

typedef enum
{
GIR_HORARI = 0,
GIR_ANTI_HORARI
} DireccioGir;
class Joc
{
public:
	
	//interfície pública obligatòria 
	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
private:
	Tauler m_tauler;
	Figura m_figura;

};

#endif