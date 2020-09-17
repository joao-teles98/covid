
#include <iostream>

#include "covid.h"

#define OK		0;

using namespace std;

int 
main( int argc, char *argv[])
{ //INICIO MAIN

	Nacional Brasil;

	char opcao='0';

	cout << "Bem-vindo ao Painel de Análise de Casos de COVI-19\n";
	cout << "\n O que deseja fazer?\n\n";

	//while(opcao != 'q')
	//{ //INICIO LOOP DE MENU
		cout << "a: Exibir evolução em porcentagem do número de óbitos no Brasil/Estados.\n";
		cout << "b: exibir evoluçao dos estados categorizados em ALTA, ESTÁVEIS ou em BAIXA.\n";
		cout << "c: exibir evolução do Brasil categorizada em ALTA, ESTÁVEL ou em BAIXA.\n";
		cout << "d: Exibir estado com maior alta e o com maior queda\n";
		cout << "e: Exibir dados acumulados no Brasil e nos Estados individualmente.\n\n";
		cout << "q: sair do programa\n\n";
		
		cin >> opcao;

		int indexador;

		switch(opcao)
		{ //INICIO PEGADA DE OPCOES
			case 'a':
				cout << "a: Exibir dados do Brasil.\n";
				cout << "b: Exibir dados dos Estados\n";
				cin >> opcao;

				switch(opcao)
				{ // INICIO MENU A
					case 'a':
						Brasil.getEvolucaoCovid();
						cout << "Evolução em Porcentagem dos casos do Brasil: " << Brasil.evolucaoPorcentagemNacional << "%\n";
						break;
					
					case 'b':

						//for ( indexador =0 ; Brasil.estadosBrasil.size(); indexador++)
						//	Brasil.estadosBrasil.at(indexador-1).setEvolucao();

						cout << "a: Exibir dado de um Estado específico\n";
						cout << "b: Exibir dados de todos os estados\n\n";
						
						cin >> opcao;

						switch (opcao)
						{ //INICIO MENU AB
							case 'a':
							{
								string searchEstado;

								cout << "De qual Estado deseja saber os dados?: ";

								cin >> searchEstado;

								for (indexador=0 ; Brasil.estadosBrasil.at(indexador).nomeEstado == searchEstado ; indexador++)
									
								cout << "\n\n " << Brasil.estadosBrasil.at(indexador).nomeEstado << endl;
								cout << "Número total de óbitos: " << Brasil.estadosBrasil.at(indexador).totalObitos << endl;
								cout << "Média móvel dos últimos 7 dias: " << Brasil.estadosBrasil.at(indexador).getMediaMovel(24, 30) << endl;
								cout << "Evolução do Covid no Estado: " << Brasil.estadosBrasil.at(indexador).getEvolucao() << endl;
								break;
							}
							case 'b':
								for (indexador=0; indexador < Brasil.estadosBrasil.size(); indexador++)
								{
									cout << Brasil.estadosBrasil.at(indexador).nomeEstado << ": " << Brasil.estadosBrasil.at(indexador).evolucaoPorcentagem << "%\n";
								}
								break;
						} //FIM MENU AB
				} //FIM MENU A
				
				break;

			case 'b':

				for (indexador=0; indexador < Brasil.estadosBrasil.size(); indexador++)
				{
					Brasil.estadosBrasil.at(indexador).setEvolucao();
					cout << Brasil.estadosBrasil.at(indexador).idEvolucao;
				}


				cout << "ESTADOS EM ALTA:\n";

				for (indexador=0; indexador < Brasil.estadosBrasil.size(); indexador++)
				{
					if(Brasil.estadosBrasil.at(indexador).idEvolucao == 'A')
						cout << Brasil.estadosBrasil.at(indexador).nomeEstado << ";\n";
				}

				cout << "\nESTADOS EM ESTABILIDADE:\n";

				for (indexador=0; indexador < Brasil.estadosBrasil.size(); indexador++)
				{
					if(Brasil.estadosBrasil.at(indexador).idEvolucao == 'E')
						cout << Brasil.estadosBrasil.at(indexador).nomeEstado << ";\n";
				}

				cout << "\nESTADOS EM BAIXA:\n";

				for (indexador=0; indexador < Brasil.estadosBrasil.size(); indexador++)
				{
					if(Brasil.estadosBrasil.at(indexador).idEvolucao == 'B')
						cout << Brasil.estadosBrasil.at(indexador).nomeEstado << ";\n";
				}

				break;

			case 'c':
				Brasil.getEvolucaoCovid();
				cout << "Estado de evolução do Brasil: " << Brasil.evolucao << endl;

				break;

			case 'd':

				Brasil.setPiorEstado();
				Brasil.setMelhorEstado();

				cout << "Estado com maior queda: " << Brasil.melhorEstado.nomeEstado << endl;
				cout << "Estado com maior crescimento: " << Brasil.piorEstado.nomeEstado << endl;

				break;

			case 'e':
				Brasil.getDadosAcumulados();
				cout << "DADOS ACUMULADOS BRASIL: " << Brasil.obitosAcumulados;

				break;	

			case 'q':
				break;		

			cout << "\n\n";
			
		} // FIM DA PEGADA DE OPCOES

	//} //FIM LOOP MENU

		return OK;
} //FIM MAIN
