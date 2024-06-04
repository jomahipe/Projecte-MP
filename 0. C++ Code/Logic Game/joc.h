#ifndef JOC_H
#define JOC_H
#include "figura.h"
#include "tauler.h"
#include <fstream>
#include <string>
using namespace std;


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
	ColorFigura m_tauler;
	TipusFigura m_figura;

};

#endif
