#ifndef JOC_H
#define JOC_H

Class Joc
{
public:
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	//funcions nostres a partir d'aquí
	void incrementaPuntuacio();
	void incrementaNivell();
private:
	Tauler m_tauler;
	Figura m_figura;
	//
	int puntuacio;
	int nivell;
	
}

