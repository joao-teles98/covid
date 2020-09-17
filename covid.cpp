
#include "covid.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define NUM_DIAS	30
#define NUM_ESTADOS	26

using namespace std;

int indexadorEstado, indexadorDia;

void Estadual::gerarNumeroObitos ()
{
	int indexadorEstado;
	srand(time(NULL));
	for (indexadorEstado=0; indexadorEstado < NUM_DIAS; indexadorEstado++)
		obitos.push_back(rand() % 100 + 1);
		totalObitos += obitos.at(indexadorEstado);
}

// public methods

Estadual::Estadual( string nome)
{
	nomeEstado = nome;
	gerarNumeroObitos();
}


//FUNÇAO QUE CALCULA A MEDIA MOVEL ENTRE OS DIAS PEDIDOS
int Estadual::calcularMediaMovel (int diaInicio, int diaFinal)
{
	int indexadorEstado, soma, media, mediaMovel;

	soma = 0;

	for (indexadorEstado = diaInicio; indexadorEstado < diaFinal; indexadorEstado++)
		soma+= obitos.at(indexadorEstado-1);

	return mediaMovel = (soma / (diaFinal - diaInicio + 1));
}


//FUNÇAO QUE DEFINE STRING CARACTERIZANDO A EVOLUÇAO DOS OBITOS
void Estadual::setEvolucao ()
{
	int baseComparacao = calcularMediaMovel(obitos.size()-8, obitos.size()-1);

	int mediaAtual = calcularMediaMovel(obitos.size()-7, obitos.size());

	float comparador = (mediaAtual / baseComparacao)*100 - 100;

	evolucaoPorcentagem = comparador;

	if (comparador > 15.0 )
	{
		evolucao = "ALTA";
		idEvolucao = 'A';
	}

	else if (comparador < -15.0)
	{
		evolucao = "QUEDA";
		idEvolucao = 'Q';
	}

	else
		evolucao = "ESTÁVEL";
		idEvolucao = 'E';
}

//FUNÇAO QUE EXIBE STRING CARACTERIZANDO A EVOLUÇAO DOS OBITOS
string Estadual::getEvolucao ()
{
	setEvolucao();
	return evolucao;
}

double Estadual::getMediaMovel ( int diaInicio, int diaFinal )
{
	int mediaDisplay = calcularMediaMovel ( diaInicio, diaFinal);
	
	return mediaDisplay;
}


//------------------------------------------------------//
//--------=-------NACIONAL------------------------------//


Nacional::Nacional()
{
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
	for(indexadorEstado=0 ; indexadorEstado < estadosBrasil.size() ; indexadorEstado++)
	{
		for(indexadorDia = 0 ; indexadorDia < estadosBrasil.at(indexadorEstado).obitos.size(); indexadorDia++)
			obitosAcumulados += estadosBrasil.at(indexadorEstado).obitos.at(indexadorDia);

	}

	for(indexadorDia=0 ; indexadorDia < NUM_DIAS; indexadorDia++)
	{
		for (indexadorEstado = 0; indexadorEstado < estadosBrasil.size() ; indexadorEstado ++)
			obitosNacionais.at(indexadorDia) += estadosBrasil.at(indexadorEstado).obitos.at(indexadorDia);
	}
}

void Nacional::getEvolucaoCovid()
{
	setEvolucaoNacional();
}

int Nacional::calcularMediaMovelNacional (int diaInicio, int diaFinal)
{
	int indexadorEstado, soma, media, mediaMovel;

	soma = 0;

	for (indexadorEstado = diaInicio; indexadorEstado < diaFinal; indexadorEstado++)
		soma+= obitosNacionais.at(indexadorEstado-1);

	return mediaMovel = (soma / (diaFinal - diaInicio + 1));
}


void Nacional::getMediaMovelNacional ( int diaInicio, int diaFinal )
{
	int mediaDisplay = calcularMediaMovelNacional ( diaInicio, diaFinal);
	
	printf("A média móvel para o Brasil dos últimos %d dias é %d.\n", (diaFinal + diaInicio + 1), mediaDisplay);

}
void Nacional::setEvolucaoNacional ()
{
	int baseComparacao = calcularMediaMovelNacional(sizeof(obitosNacionais)-8, sizeof(obitosNacionais)-1);

	int mediaAtual = calcularMediaMovelNacional(sizeof(obitosNacionais)-7, sizeof(obitosNacionais));

	float comparador = (mediaAtual / baseComparacao)*100 - 100;

	evolucaoPorcentagemNacional = comparador;

	if (comparador > 15.0 )
		evolucao = "ALTA";

	else if (comparador < -15.0)
		evolucao = "QUEDA";

	else
		evolucao = "ESTÁVEL";
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

