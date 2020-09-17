
#include "covid.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define NUM_DIAS	30
#define NUM_ESTADOS	27

using namespace std;

int indexadorEstado, indexadorDia;

void Estadual::gerarNumeroObitos ()
{
	int indexadorEstado;
	srand(time(NULL));
	for (indexadorEstado=0; indexadorEstado < NUM_DIAS; indexadorEstado++)
		obitos.push_back(rand() % 100 + 1);
		totalObitos += obitos.at(indexadorEstado-1);
}

// public methods

Estadual::Estadual()
{}

Estadual::Estadual( string nome)
{
	nomeEstado = nome;
	gerarNumeroObitos();
}


//FUNÇAO QUE CALCULA A MEDIA MOVEL ENTRE OS DIAS PEDIDOS
int Estadual::calcularMediaMovel (double diaInicio, double diaFinal)
{
	int indexadorDia, soma, media, mediaMovel;

	soma = 0;

	for (indexadorDia = diaInicio; indexadorDia < diaFinal+1; indexadorDia++)
		soma+= obitos.at(indexadorDia-1);

	return mediaMovel = (soma / (diaFinal - diaInicio + 1));
}


//FUNÇAO QUE EXIBE STRING CARACTERIZANDO A EVOLUÇAO DOS OBITOS
string Estadual::getEvolucao ()
{
	setEvolucao();
	return evolucao;
}

//FUNÇAO QUE DEFINE STRING CARACTERIZANDO A EVOLUÇAO DOS OBITOS
void Estadual::setEvolucao ()
{
	int mediaMovelMenos1 = calcularMediaMovel(obitos.size()-8, obitos.size()-1);

	int mediaMovel = calcularMediaMovel(obitos.size()-7, obitos.size());

	float comparador = (mediaMovel / mediaMovelMenos1);

	evolucaoPorcentagem = comparador;

	if (comparador > 1.015 )
	{
		evolucao = "ALTA";
		idEvolucao = 'A';
	}

	else if (comparador < 0.085)
	{
		evolucao = "QUEDA";
		idEvolucao = 'Q';
	}

	else
		evolucao = "ESTÁVEL";
		idEvolucao = 'E';
}

double Estadual::getMediaMovel ( double diaInicio, double diaFinal )
{
	int mediaDisplay = calcularMediaMovel ( diaInicio, diaFinal);
	
	return mediaDisplay;
}

//------------------------------------------------------//
//--------=-------NACIONAL------------------------------//


Nacional::Nacional()
{

	string evolucao = "0";
	
	double obitosAcumulados = 0;
	float evolucaoPorcentagemNacional = 0;

	int indexadorEstado, indexadorDia;
	double somaDia;
	vector <string> Estados_Brasil = 	
	{
		"Acre",
		"Alagoas",
		"Amapa",
		"Amazonas",
		"Bahia",
		"Ceara",
		"Distrito Federal",
		"Espirito Santo",
		"Goias",
		"Maranhao",
		"Mato Grosso",
		"Mato Grosso do Sul",
		"Minas Gerais",
		"Para",
		"Paraiba",
		"Parana",
		"Pernambuco",
		"Piaui",
		"Rio de Janeiro",
		"Rio Grande do Norte",
		"Rio Grande do Sul",
		"Rondonia",
		"Roraima",
		"Santa Catarina",
		"Sao Paulo",
		"Sergipe",
		"Tocantins"	
	};

	for (indexadorEstado = 0 ; indexadorEstado < NUM_ESTADOS ; indexadorEstado++)
	{
		setEstado(Estados_Brasil.at(indexadorEstado));
	}

	for(indexadorDia=0; indexadorDia < NUM_DIAS; indexadorDia++)
	{
		somaDia = 0;

		for(indexadorEstado=0; indexadorEstado < NUM_ESTADOS; indexadorEstado++)
			somaDia += estadosBrasil.at(indexadorEstado).obitos.at(indexadorDia);

		obitosNacionais.push_back(somaDia);
	}

}

void Nacional::setEstado(string nome)
{
	Estadual estado( nome );
	estadosBrasil.push_back( estado );
}

void Nacional::getDadosAcumulados()
{
	for(indexadorDia=0 ; indexadorDia < NUM_DIAS; indexadorDia++) //Insere em cada dia do vetor Obitos NAcionais os obitos de todos os estados
	{
		for (indexadorEstado = 0; indexadorEstado < estadosBrasil.size() ; indexadorEstado ++)
		{
			//cout << obitosNacionais.at(indexadorDia);
			obitosNacionais.at(indexadorDia) += estadosBrasil.at(indexadorEstado).obitos.at(indexadorDia);
		}
	}

	
	obitosAcumulados = 0;

	for(indexadorDia=0; indexadorDia < obitosNacionais.size(); indexadorDia++)		
		obitosAcumulados += obitosNacionais.at(indexadorDia);
}

void Nacional::getEvolucaoCovid()
{
	setEvolucaoNacional();
}

void Nacional::setEvolucaoNacional ()
{
	int baseComparacao = calcularMediaMovelNacional(21, 28);

	int mediaAtual = calcularMediaMovelNacional(22, 29);

	float comparador = (mediaAtual / baseComparacao)*100 - 100;

	evolucaoPorcentagemNacional = comparador;

	if (comparador > 15.0 )
		evolucao = "ALTA";

	else if (comparador < -15.0)
		evolucao = "QUEDA";

	else
		evolucao = "ESTÁVEL";
}

int Nacional::calcularMediaMovelNacional (double diaInicio, double diaFinal)
{
	int indexadorEstado, soma, media, mediaMovel;

	soma = 0;

	for (indexadorEstado = 0; indexadorEstado < estadosBrasil.size(); indexadorEstado++) //Para cada Estado...
	{
		for(indexadorDia = diaInicio; indexadorDia < diaFinal; indexadorDia++)
		soma+= obitosNacionais.at(indexadorEstado); //somar todos os obitos entre diaInicio e diaFinal
	}

	return mediaMovel = (soma / (diaFinal - diaInicio + 1));
}


double Nacional::getMediaMovelNacional ( double diaInicio, double diaFinal )
{
	double mediaDisplay = calcularMediaMovelNacional ( diaInicio, diaFinal);
	
	//printf("A média móvel para o Brasil dos últimos %d dias é %d.\n", (diaFinal + diaInicio + 1), mediaDisplay);

	return mediaDisplay;
}

void Nacional::setPiorEstado()
{
	for (indexadorEstado = 0; indexadorEstado < estadosBrasil.size(); indexadorEstado++)
	{
		estadosBrasil.at(indexadorEstado).setEvolucao();

		if (estadosBrasil.at(indexadorEstado).evolucao > piorEstado.evolucao)
			piorEstado = estadosBrasil.at(indexadorEstado);
	}
}

void Nacional::setMelhorEstado()
{
	for (indexadorEstado = 0 ; indexadorEstado < estadosBrasil.size(); indexadorEstado++)
	{
		estadosBrasil.at(indexadorEstado).setEvolucao();

		if (estadosBrasil.at(indexadorEstado).evolucao < melhorEstado.evolucao)
			melhorEstado = estadosBrasil.at(indexadorEstado);
	}
}
