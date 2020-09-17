#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estadual
{
	public:
		Estadual Estadual (string);

		double getMediaMovel (int,int);
		string getEvolucao ();	

	private:
		string evolucao;
		float evolucaoPorcentagem;
		char idEvolucao;
		vector <int> obitos;
		string nomeEstado;
		double totalObitos;

		int calcularMediaMovel (int , int);
		
		void gerarNumeroObitos ();
		void setEvolucao();
};


class Nacional 
{

	public:
		Nacional Nacional ();
		
		void getDadosAcumulados ();
		void getEvolucaoCovid ();

	private:
		vector <Estadual> estadosBrasil;
		string evolucao;
		float evolucaoPorcentagemNacional;
		double obitosAcumulados;

		vector <double> obitosNacionais;

		void setPiorEstado();
		void setMelhorEstado();

		Estadual piorEstado;
		Estadual melhorEstado;

		void setEvolucaoNacional ();

		void calcularMediaMovelNacional ();
		void getMediaMovelNacional ();


		void setEstado (string);
};
