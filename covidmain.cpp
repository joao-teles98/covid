#include <stdlib.h>
#include <stdio>

#include "covid.h"

int 
main( int argc, char *argv[])
{

	Nacional Brasil;

	char opcao='0';

	printf("Bem-vindo ao Painel de Análise de Casos de COVI-19\n");
	printf("\n O que deseja fazer?\n\n");

	while(opcao != 'q')
	{
		printf("a: Exibir evolução em porcentagem do número de óbitos no Brasil/Estados.\n");
		printf("b: exibir evoluçao dos estados categorizados em ALTA, ESTÁVEIS ou em BAIXA.\n");
		printf("c: exibir evolução do Brasil categorizada em ALTA, ESTÁVEL ou em BAIXA.\n");
		printf("d: Exibir estado com maior alta e o com maior queda\n");
		printf("e: Exibir dados acumulados no Brasil e nos Estados individualmente.\n\n");
		printf("q: sair do programa\n\n");
		
		getline(cin, opcao);

		int index;

		switch(opcao)
		{
			case 'a':
				printf("a: Exibir dados do Brasil.\n");
				printf("b: Exibir dados dos Estados\n");
				getline(cin, opcao);

				switch(opcao)
				{
					case 'a':
						Brasil.getEvolucaoCovid();
						printf("Evolução em Porcentagem dos casos do Brasil: %f\n", Brasil.evolucaoPorcentagemNacional);
					
					case 'b':

						for ( index =0 , Brasil.estadosBrasil.len(), index++)
							Brasil.estadosBrasil.at(index).setEvolucao();

						printf("a: Exibir dado de um Estado específico\n");
						printf("b: Exibir dados de todos os estados\n\n");
						
						getline(cin, opcao);

						switch (opcao)
						{
							case 'a':
								printf("De qual Estado deseja saber os dados?: ");

								getline(cin, searchEstado);

								for(index=0 , Brasil.estadosBrasil.at(index).nomeEstado == searchEstado , index++)
									
								printf("\n\n %s \n", Brasil.estadosBrasil.at(index).nomeEstado);
								printf("Número total de óbitos: %d\n", Brasil.estadosBrasil.at(index).totalObitos);
								printf("Média móvel dos últimos 7 dias: %d\n", Brasil.estadosBrasil.at(index).getMediaMovel(24, 30);
								printf("Evolução do Covid no Estado: %s\n", Brasil.estadosBrasil.at(index).getEvolucaoCovid());


							case 'b':
								for(index=0, index < Brasil.estadosBrasil.len(), index++)
								{
									printf("%s: %s\n",Brasil.estadosBrasil.at(index).nomeEstado, Brasil.estadosBrasil.at(index).getEvolucaoCovid());
								}
				}

			case 'b':
				printf("ESTADOS EM ALTA:\n");

				for(index=0, index < Brasil.estadosBrasil.len(), index++)
				{
					if(Brasil.estadosBrasil.at(index).idEvolucao == 'A')
						printf("%s;\n", Brasil.estadosBrasil.at(index).nomeEstado);
				}

				printf("\nESTADOS EM ESTABILIDADE:\n");

				for(index=0, index < Brasil.estadosBrasil.len(), index++)
				{
					if(Brasil.estadosBrasil.at(index).idEvolucao == 'E')
						printf("%s;\n", Brasil.estadosBrasil.at(index).nomeEstado);
				}

				printf("\nESTADOS EM BAIXA:\n");

				for(index=0, index < Brasil.estadosBrasil.len(), index++)
				{
					if(Brasil.estadosBrasil.at(index).idEvolucao == 'B')
						printf("%s;\n", Brasil.estadosBrasil.at(index).nomeEstado);
				}

			case 'c':
				Brasil.getEvolucaoCovid();
				printf("Estado de evolução do Brasil: %s", Brasil.evolucao);

			case 'd':

				Brasil.setPiorEstado();
				Brasil.setMelhorEstado();

				printf("Estado com maior queda: %s\n", Brasil.melhorEstado);
				printf("Estado com maior crescimento: %s\n", Brasil.piorEstado);

			case 'e':
				Brasil.getDadosAcumulado()
				printf("DADOS ACUMULADOS BRASIL: %d ÓBITOS\n", Brasil.obitosAcumulados);
				

			printf("\n\n");
		}

		return OK;
}
