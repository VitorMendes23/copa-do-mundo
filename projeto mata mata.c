/********************************************************************************************************
				Trabalho prático 1 - Mata-mata
				
Trabalho desenvolvido e apresentado ao Centro Federal de Educação Tecnológica de Minas Gerais(CEFET-MG)
Aluno: Vitor Mendes de Oliveira Abreu
Matrícula: 20213008630 
Aluno: André Andrade Frontino Nogueira
Matrícula: 20213002725
Diciplina: Laboratório de Programação de Computadores 1, turma04A
*********************************************************************************************************/
/* O intuito deste trabalho é simular uma competição esportiva no modelo "mata-mata" como acontece em 
diversos esportes. Neste trabalho temos 16 equipes com nomes de A à P, onde o usúario interage diretamente
com o programa e insere os resultados de todos os jogos de todos os confrontos de cada fase, o programa 
processa os dados no final de todas as fases e no fim da última fase aponta qual foi a equipe campeã. Foi 
utilizado vetores na composição do programa, é um conteúdo que ainda não foi visto na matéria até o momento
mas facilitou o desenvolvimento do código */

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	char nomeEquipes[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'}; //Criando um vetor com o nome de todas as equipes

	int resultequipesOitavas[16]; 		 //Nestes 4 vetores serão armazenados os das obtidos pelas equipes em cada fase
	int resultequipesQuartas[8];
	int resultequipesSemis[4];
	int resultequipesFinais[2];
	
	char equipesVencOitvas[8] = { '\0' };		//Nestes 3 vetores serão armazenados os nomes das equipes que venceram a fase anterior
	char equipesVencQuartas[4] = { '\0'};		
	char equipesVencSemis[2] = { '\0'};			//Não é necessário armazenar os dados aa equipe vencedora aqui, já que ela foi a campeã e não é necessário exibir sua pontuação
	
	
	char nomeVencQuartas[4] = { '\0' };			//Nestes 3 vetores serão armazenados os nomes das equipes que venceram a fase atual e vão seguir para a próxima fase
	char nomeVencSemis[2] = { '\0' };
	char nomeVencFinal = '\0';					//Nessa variável ficará o nome da gramde campeã
	
	int m = 0, z = 0, y = 0;		//Aqui é declarado as variáveis que serão usadas de indices para as equipes que venceram a fase
	int i, l, n, p, q, r, s, t;		//Aqui é declarado as variáveis que serão usadas nos laços de repetição "for"
	
	for(i = 0 ; i <= 15;i++){
		printf("\n Digite o resultado do jogo de duas equipes das oitavas de final \n");								//Recolhimento dos dados dos confrontos entre as equipes das oitavas de final
		scanf("%d", &resultequipesOitavas[i]);
		
		printf("\n A equipe %c fez %d pontos, agora digite a próxima: \n", nomeEquipes[i], resultequipesOitavas[i]);	//Aqui acontecem os jogos de 1 à 8
		i++;
		scanf("%d", &resultequipesOitavas[i]);	
		printf("\n equipe %c fez %d pontos \n", nomeEquipes[i], resultequipesOitavas[i]);	
	}
	
	for( l = 0; l < 16; l++){																							//Processamento dos dados das equipes que obteveram mais pontos em cada confronto
		if(resultequipesOitavas[l] < resultequipesOitavas[l + 1]){														
			equipesVencOitvas[m] = nomeEquipes[l + 1];
			printf("\n A equipe \" %c \" avançou de fase\n", equipesVencOitvas[m]);
		}else {
			equipesVencOitvas[m] = nomeEquipes[l];
			printf("\n A equipe \" %c \" avancou de fase\n", equipesVencOitvas[m]);
		}
		m++;
		l++;
	}

	//dados das oitavas em cima
	
	
	for(n = 0; n < 8; n++){
	    printf("\n Digite o resultado do jogo de duas equipes das quartas de final \n");								//Recolhimento dos dados dos confrontos entre as equipes das quartas de final
	    scanf("%d", &resultequipesQuartas[n]);
	    
	    printf("\n A equipe %c fez %d pontos, agora digite a próxima: \n", equipesVencOitvas[n], resultequipesQuartas[n]); //Aqui acontecem os jogos de 9 à 12
	    n++;
	    scanf("%d", &resultequipesQuartas[n]);
	    printf("\n A equipe %c fez %d pontos\n", equipesVencOitvas[n], resultequipesQuartas[n]);
	}
	for(p = 0; p < 8; p++){																								//Processamento dos dados das equipes que obteveram mais pontos em cada confronto
		if(resultequipesQuartas[p] < resultequipesQuartas[p+1]){
			nomeVencQuartas[z] =  equipesVencOitvas[p+1];	
			printf("\n A equipe \" %c \" avançou de fase\n", nomeVencQuartas[z]);	
		} else{
			nomeVencQuartas[z] =  equipesVencOitvas[p];
			printf("\n A equipe \" %c \" avançou de fase\n", nomeVencQuartas[z]);
		}
		z++;
		p++;
	}
	
	//dados das quartas
	
	for(q = 0; q < 4; q++){																								//Recolhimento dos dados dos confrontos entre as equipes das semis finais
		printf("\n Digite o resultado do jogo de duas equipes das semi final \n");
	    scanf("%d", &resultequipesSemis[q]);
	    
	    printf("\n A equipe %c fez %d pontos, agora digite a próxima: \n", nomeVencQuartas[q], resultequipesSemis[q]);	//Aqui acontecem os jogos 13 e 14
	    q++;
	    scanf("%d", &resultequipesSemis[q]);
	    printf("\n A equipe %c fez %d pontos\n", nomeVencQuartas[q], resultequipesSemis[q]);
	}
	for(r = 0; r < 4; r++){																								//Processamento dos dados das equipes que obteveram mais pontos em cada confronto
		if(resultequipesSemis[r] < resultequipesSemis[r+1]){
			nomeVencSemis[y] =  nomeVencQuartas[r+1];	
			printf("\n A equipe \" %c \" esta na final\n", nomeVencSemis[y]);	
		} else{
			nomeVencSemis[y] =  nomeVencQuartas[r];
			printf("\n A equipe \" %c \" esta na final\n", nomeVencSemis[y]);
		}
		y++;
		r++;
	}
	//dados das semis
	
	
		for(s = 0; s < 2; s++){																						//Recolhimento dos dados do confronto entre as equipes da final
		printf("\n Digite os pontos obtidos da primeira equipe na Grande Final \n");
	    scanf("%d", &resultequipesFinais[s]);
	    
	    printf("\n A equipe %c fez %d pontos, agora digite os pontos obtidos da segunda equipe na Grande Final: \n", nomeVencSemis[s], resultequipesFinais[s]); 	//Aqui acontece o jogo 15
	    s++;
	    scanf("%d", &resultequipesFinais[s]);
	    printf("\n A equipe %c fez %d pontos\n", nomeVencSemis[s], resultequipesFinais[s]);
	}
	for(t = 0; t < 2; t++){																							//Processamento dos dados da equipe que obteve mais pontos no confronto final
		if(resultequipesFinais[t] < resultequipesFinais[t+1]){
			nomeVencFinal =  nomeVencSemis[t+1];	
			printf("\n A GRANDE VENCEDORA FOI A EQUIPE \" %c \" \n", nomeVencFinal);	
		} else{
			nomeVencFinal =  nomeVencSemis[t];
			printf("\n A GRANDE VENCEDORA FOI A EQUIPE \" %c \" \n", nomeVencFinal);								//Resultado final
		}
		t++;
	}
	
	return 0;
}
