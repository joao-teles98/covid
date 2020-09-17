#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estadual
{
	public:
		Estadual();
		Estadual (string);

		double getMediaMovel (double,double);
		string getEvolucao();
		string evolucao;	
		string nomeEstado;

		vector <int> obitos;
		float evolucaoPorcentagem;
		char idEvolucao;
	
		double totalObitos;

		void setEvolucao();

	private:
		int calcularMediaMovel (double , double);
		
		void gerarNumeroObitos ();
		
};


class Nacional 
{

	public:
		Nacional ();
		
		void getDadosAcumulados ();
		void getEvolucaoCovid ();
		void setPiorEstado();
		void setMelhorEstado();

		string evolucao;
		Estadual piorEstado;
		Estadual melhorEstado;

		double obitosAcumulados;
		float evolucaoPorcentagemNacional;
		vector <Estadual> estadosBrasil;
		vector <double> obitosNacionais;

	private:

		void setEvolucaoNacional ();

		int calcularMediaMovelNacional (double, double);
		double getMediaMovelNacional (double, double);
		void setEstado (string);
};
