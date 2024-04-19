#include "figura.h"
#include <iostream>
#include <string>
#define files 10
#define columnes 10
/*
using namespace std;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum {
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S
} TipusFigura;

typedef enum
{
    NOGIR = 0,
    ESQUERRA = 1,
    DRETA = 2,
} Gir;
/*
class Figura
{
public:
    Figura(TipusFigura tipus, ColorFigura color)
        : tipusFigura(tipus), tipusColor(color), m_girActual(NOGIR), m_posicio_x(0), m_posicio_y(0) {}

    Figura(int posx, int posy)
        : tipusFigura(NO_FIGURA), tipusColor(NO_COLOR), m_girActual(NOGIR), m_posicio_x(posx), m_posicio_y(posy) {}
/*
    void moureLateral() { /* Implementació */ }
    void baixa() { /* Implementació */ }
    void gira() { /* Implementació */ }

    void setX(int posx) { m_posicio_x = posx; }
    void setY(int posy) { m_posicio_y = posy; }
    int getX() const { return m_posicio_x; }
    int getY() const { return m_posicio_y; }
private:
    TipusFigura tipusFigura;
    ColorFigura tipusColor;
    Gir m_girActual;
    int m_posicio_x;
    int m_posicio_y;
};
*/
/*
class Tauler
{
public:
    bool MovimentValid(int posx, int posy, int figura_dins_capsula[3][3]) {  return false; }
    void colocarFigura(int posx, int posy, int forma[3][3]) { ; }
    void elimina() { }
    void actualitzaTaula() {  }

private:
    ColorFigura m_tauler[files][columnes];
};

class Joc
{
public:
    void inicialitza(const string& nomFitxer) {  }
    bool giraFigura(Gir direccio) {  return false; }
    bool mouFigura(int dirX) { return false; }
    int baixaFigura() {  return 0; }
    void escriuTauler(const string& nomFitxer) { ; }

private:
    bool liniacompleta() { return false; }
    void eliminaLinia() { }
    void Actualitzar() { }

    int m_tauler[files][columnes];
};*/
