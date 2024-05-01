#include "tauler.h"


Tauler::Tauler(ColorFigura taulerInput)
{
    for (int f = 0; f < MAX_FILES; f++)
    {
        for (int c = 0; c < MAX_COLUMNES; c++)
            m_tauler[f][c] = taulerInput[f][c];
    }
}

void Tauler::eliminaFila()
{

}