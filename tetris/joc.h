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
	//funcions nostres a partir d'aquí: qualsevol funció més que veiem útil o bona addició al programa (funcionalitats extra pugen nota)
	//això ho implementem després de tenir el joc bàsic programat
	void incrementaPuntuacio();
	void incrementaNivell();
private:
	Tauler m_tauler;
	Figura m_figura;
	//coses nostres aquí
	int puntuacio;
	int nivell;
	
}


#endif
