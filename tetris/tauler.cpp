#include "tauler.h"


Tauler::Tauler(ColorFigura taulerInput)
{
    for (int f = 0; f < MAX_FILES; f++)
    {
        for (int c = 0; c < MAX_COLUMNES; c++)
            m_tauler[f][c] = taulerInput[f][c];
    }
}

bool Tauler::eliminaFila() // no acabat
{
    bool filaCompleta;
    int c = 0;
    for (int f = 0; f < MAX_FILES; f++)
    {
        filaCompleta = true;
        while (c < MAX_COLUMNES && filaCompleta)
        {
            if (m_tauler[f][c] == 0)
                filaCompleta = false;
        }
        if (filaCompleta)
        
    }
}