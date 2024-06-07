Tetris::Tetris(const string& file)
{
 
    guardaPuntuacio(file);
}

int Tetris::jugar(Screen& pantalla, ModePartida mode, string& fitxerInicial)
{

    m_partida.inicialitza(mode, fitxerInicial, "", "");

    // Main game loop
    while (!m_partida.isGameOver()) {
        double deltaTime = pantalla.getDeltaTime();
        m_partida.actualitza(deltaTime);
        pantalla.update();
    }

    return m_partida.getPuntuacio();
}

void Tetris::actualitzaPuntuacio(const string& nom, int punts)
{
   
    string scoreEntry = nom + ": " + to_string(punts);
    m_puntuacions.push_front(scoreEntry);
}

void Tetris::mostraPuntuacions()
{
    
    for (const auto& puntuacio : m_puntuacions) {
        cout << puntuacio << endl;
    }
}

void Tetris::guardaPuntuacio(const string& file)
{
   
    ofstream outFile(file);
    if (outFile.is_open()) {
        for (const auto& puntuacio : m_puntuacions) {
            outFile << puntuacio << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to open file for writing: " << file << endl;
    }
}
