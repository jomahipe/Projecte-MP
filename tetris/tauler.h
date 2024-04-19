#ifndef TAULER_H
#define TAULER_H
//codi aqui

const int MAX_FILES;
const int MAX_COLUMNES;

class Tauler
{
public:
	Tauler() { m_tauler[N_FILES][N_COLUMNES] = {{NO_COLOR}}; }
	void eliminaFila();
private:
  	ColorFigura m_tauler[N_FILES][N_COLUMNES];
  
}

#endif
