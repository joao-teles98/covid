
#include "covid.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define NUM_DIAS	30
#define NUM_ESTADOS	26

using namespace std;

int indexador, indexador2;

void Estadual::gerarNumeroObitos ()
{
	int indexador;
	srand(time(NULL));
	for (indexador=0; indexador < NUM_DIAS; indexador++)
		obitos.push_back(rand() % 100 + 1);
		totalObitos += obitos.at(indexador);
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
	int indexador, soma, media, mediaMovel;

	soma = 0;

	for (indexador = diaInicio; indexador < diaFinal; indexador++)
		soma+= obitos.at(indexador-1);

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
	int indexador;
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

	for (indexador = 0 ; indexador < NUM_DIAS ; indexador++)
		obitosNacionais.push_back()

	for (indexador = 0 ; indexador < NUM_ESTADOS ; indexador++)
	{
		setEstado(Estados_Brasil.at(indexador));
	}


}

void Nacional::setEstado(string nome,)
{
	Estadual estado( nome );
	estadosBrasil.push_back( estado );
}

void Nacional::getDadosAcumulados()
{
	for(indexador=0 ; indexador < estadosBrasil.size() ; indexador++)
	{
		for(index2 = 0 ; index2 < estadosBrasil.at(indexador).obitos.size(); index2++)
			obitosAcumulados += estadosBrasil.at(indexador).obitos.at(index2);

	}

	for(index2=0 ; index2 < estadosBrasil.obitos.size(); index2++)
	{
		for (indexador = 0; indexador < estadosBrasil.size() ; indexador ++)
			obitosNacionais.at(index2) += estadosBrasil.at(indexador).obitos.at(index2)
	}
}

void Nacional::getEvolucaoCovid()
{
	setEvolucaoNacional();
}

int Nacional::calcularMediaMovelNacional (int diaInicio, int diaFinal)
{
	int indexador, soma, media, mediaMovel;

	soma = 0;

	for (indexador = diaInicio; indexador < diaFinal; indexador++)
		soma+= obitosNacionais.at(indexador-1);

	return mediaMovel = (soma / (diaFinal - diaInicio + 1));
}


void Nacional::getMediaMovelNacional ( int diaInicio, int diaFinal )
{
	int mediaDisplay = calcularMediaMovelNacional ( diaInicio, diaFinal);
	
	printf("A média móvel para o Brasil dos últimos %d dias é %d.\n", (diaFinal + diaInicio + 1), mediaDisplay);

}
void Nacional::setEvolucaoNacional ()
{
	int baseComparacao = calcularMediaMovelNacional(obitosNacionais.size()-8, obitosNacionais.size()-1, obitosNacionais);

	int mediaAtual = calcularMediaMovelNacional(obitosNacionais.size()-7, obitosNacionais.size(), obitosNacionais);

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
	for (indexador = 0; indexador < estadosBrasil.size(); indexador++)
	{
		estadosBrasil.at(indexador).setEvolucao();

		if (estadosBrasil.at(indexador).evolucao > piorEstado.evolucao)
			piorEstado = estadosBrasil.at(indexador);
	}
}

void Nacional::setMelhorEstado()
{
	for (indexador = 0 ; indexador < estadosBrasil.size(); indexador++)
	{
		estadosBrasil.at(indexador).setEvolucao();

		if (estadosBrasil.at(indexador).evolucao < melhorEstado.evolucao)
			melhorEstado = estadosBrasil.at(indexador);
	}
}

