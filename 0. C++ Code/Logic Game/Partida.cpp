#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"

Partida::Partida()
{
    m_puntuacio = 0;
    m_nivell = 0;
    m_temps = 0;

}

void Partida::actualitza(double deltaTime)
{
    if (!m_jocAcabat)
    {
        if (m_mode == NORMAL)
            actualitzaNormal();
        else actualitzaTest();
    }
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    m_joc.dibuixa();
    if (m_jocAcabat)
    {
        string out = "FINAL DE LA PARTIDA";
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 1.8, out);
    }


}

void Partida::menu()
{   
    int choice;
    cout << "Benvingut al Tetris" << endl;
    cout << "Escull una opció prement la tecla corresponent i ENTER: " << endl;
    cout << "1. JUGAR (MODE NORMAL)" << endl;
    cout << "2. JUGAR (MODE TEST)" << endl;
    cout << "3. VISUALITZAR MILLORS PUNTUACIONS" << endl;
    cout << "4. SORTIR " << endl;
    cin >> choice;
    switch (choice)
    {
    case(1):

    case(2):

    case(3):

    case(4):

    }
}

void Partida::actualitzaJoc()
{

    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        m_joc.mouFigura(1);
    
    else
    {
        if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
            m_joc.mouFigura(-1);
    }
    if (Keyboard_GetKeyTrg(KEYBOARD_UP))
        m_joc.giraFigura(GIR_HORARI);

    else
    {
        if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
            m_joc.giraFigura(GIR_ANTI_HORARI);
    }
 
}