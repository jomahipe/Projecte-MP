#ifndef PARTIDA_H
#define PARTIDA_H
#include <stdio.h>
#include <string>
#include "joc.h"
#include "InfoJoc.h"
#include "LlistaNodes.h"

using namespace std;

typedef enum
{
    NORMAL,
    TEST
}ModePartida;

const int MAX_FIGURES = 200;
class Partida 
{
public:
    Partida();
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void actualitza(int mode, double deltaTime);
    void menu();
    //getters
    int getPuntuacio() const { return m_puntuacio; }
    int getNivell() const { return m_nivell;  }
private:
    double m_temps;
    Joc m_joc;
    int m_puntuacio;
    int m_nivell;
    TipusFigura m_sequenciaFigures[MAX_FIGURES];
    string m_sequenciaMoviments[MAX_FIGURES];
    void actualitzaJoc();
    void actualitzaTest();
};

#endif 
