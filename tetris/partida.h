#ifndef PARTIDA_H
#define PARTIDA_H
#include "joc.h"

class Partida
{
public:
	Partida();
	void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
	void actualitza(int mode, double deltaTime);
	void menu();
private:
	Joc m_joc;
	int m_puntuacio;
	int m_nivell;
};


#endif