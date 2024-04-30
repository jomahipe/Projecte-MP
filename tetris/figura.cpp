#include "figura.h"

void Figura::inicialitza(TipusFigura tipus, int fila, int columna)
{
    m_tipusFigura = tipus;
    m_fila = fila;
    m_columna = columna;
}

bool Figura::giraFigura(DireccioGir direccio)
{
    // pagina 8 del pdf pot ajudar
}

int Figura::getGir()
{
    // implementar després de pensar com fer giraFigura
}
