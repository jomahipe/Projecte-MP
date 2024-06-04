#ifndef TETRIS_H
#define TETRIS_H
#include "Partida.h"
#include <forward_list>

class Tetris()
{
public:
	Tetris(const string & file);
	int jugar(Screen & pantalla, ModePartida mode, string & fitxerInicial);
	void actualitzaPuntuacio(const string & nom, int punts);
	void mostraPuntuacions();
	void guardaPuntuacio(const string & file);
private:
	Partida m_partida;
	forward_list<string> m_puntuacions;
};

#endif