#ifndef TAULER_H
#define TAULER_H
//codi aqui

const int MAX_FILES;
const int MAX_COLUMNES;

class Tauler
{
public:
void eliminaFila();
void actualitzarTaula(); //he afegit aquesta funcio en cas si eliminem una fila
private:
 	 ColorFigura m_tauler[N_FILES][N_COLUMNES];
  
}

#endif
