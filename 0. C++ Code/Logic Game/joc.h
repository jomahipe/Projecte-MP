#ifndef JOC_H
#define JOC_H
#include "Figura.h"
#include "Tauler.h"
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
	Tauler m_tauler;
Figura m_figura;

};

#endif
