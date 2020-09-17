#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estadual
{
	public:
		Estadual (string);

		double getMediaMovel (double,double);
		string getEvolucao ();
		string evolucao;	

		vector <int> obitos;

		void setEvolucao();

	private:

		float evolucaoPorcentagem;
		char idEvolucao;
		
		string nomeEstado;
		double totalObitos;

		int calcularMediaMovel (double , double);
		
		void gerarNumeroObitos ();
		
};


class Nacional 
{

	public:
		Nacional ();
		
		void getDadosAcumulados ();
		void getEvolucaoCovid ();

		string evolucao;

	private:
		vector <Estadual> estadosBrasil;
		float evolucaoPorcentagemNacional;
		double obitosAcumulados;

		vector <double> obitosNacionais;

		void setPiorEstado();
		void setMelhorEstado();

		Estadual piorEstado;
		Estadual melhorEstado;

		void setEvolucaoNacional ();

		int calcularMediaMovelNacional (double, double);
		double getMediaMovelNacional (double, double);


		void setEstado (string);
};
