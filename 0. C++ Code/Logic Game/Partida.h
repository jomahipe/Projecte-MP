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
    ModePartida m_mode;
    LlistaNodes m_sequenciaFigures[MAX_FIGURES];
    LlistaNodes m_sequenciaMoviments[MAX_FIGURES];
    
    //metodes per a public
    void actualitzaNormal(double deltaTime);
    void actualitzaTest(double deltaTime);
    void inicialitzaNormal();
    void inicialitzaTest();
};

#endif 
