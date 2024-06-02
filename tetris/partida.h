#ifndef PARTIDA_H
#define PARTIDA_H
#include "joc.h"

class Partida
{
public:
	Partida();
	void inicialitza();
	void actualitza();

private:
	Joc m_joc;
	int m_puntuacio;
	int m_nivell;
};


#endif