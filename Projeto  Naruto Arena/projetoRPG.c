#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{	char name[30];
	int valor;
	char descricao[550];
	int tipo; //
	int cd;
	int turn;
	int energia[5];
	int stun;
		
} S;
typedef struct
{
char name[30];
S skill[3];
S SkillAtivo[10];
int def;
int ddef;
int vida;	
} pers; 

 void preencherfichar(pers guer[])
{
	int i, j, k;
	//zerando os status dos pers
	for(i=0;i<3;i++)
	{
		guer[i].vida = 100;
		guer[i].def = 0;
		guer[i].ddef = 0;
		//guer[i].SkillAtivo[i] = NULL;	
		for(j=0;j<3;j++)
		{
			for(k=0;k<5;k++)
			{
				guer[i].skill[j].energia[k] = 0;	
			}
		}
	}
	//UZUMAKI NARUTO
	strcpy (guer[0].name,"Uzumaki Naruto"); //0 rad 1 taijutsu 2 Blodline 3 ninjutsu 4 Genjustsu
	//skill 1
	//guer[0].vida = 100;
	strcpy(guer[0].skill[0].name,"Rasengan");
	strcpy(guer[0].skill[0].descricao,"Uzumaki Naruto acerta um inimigo, causando 45 de dano a ele e atordoando suas habilidades por 1 turno.");
	guer[0].skill[0].valor = 45;
	
	guer[0].skill[0].tipo = 11;
	
	
	guer[0].skill[0].cd = 1;
	guer[0].skill[0].energia[3] = 1;
	guer[0].skill[0].energia[0] = 1;
	
	//skill 2
	strcpy(guer[0].skill[1].name,"Clone das Sombras");
	strcpy(guer[0].skill[1].descricao,"Uzumaki Naruto ganha 15 pontos de redução de dano por 4 turnos. \nDurante esse tempo, 'Uzumaki Naruto Combo' irá causar 10 de dano adicional.\n");
	guer[0].skill[1].valor = 15;
/* 1.1 atk 1.2 piersing 1.3 aflição
2.1 def 2.2 destruct */
	guer[0].skill[1].tipo = 21;
	
	guer[0].skill[1].cd = 4;
	guer[0].skill[1].turn = 3;
	guer[0].skill[1].energia[0] = 1;
	
	strcpy(guer[0].skill[2].name,"Uzumaki Combo");
	strcpy(guer[0].skill[2].descricao, "Uzumaki Naruto causa 20 de dano a um inimigo. \nDurante 'Shadow Clones' essa habilidade irá causar 10 de dano adicional.");
	guer[0].skill[2].valor = 20;
	guer[0].skill[2].tipo = 11;
	
	
	guer[0].skill[2].cd = 0;
	guer[0].skill[2].turn = 0;
	guer[0].skill[2].energia[1] = 1;
	
	//UCHIHA SASUKE
	strcpy (guer[1].name,"Uchiha Sasuke");
	//guer[1].vida = 100;
	
	strcpy(guer[1].skill[0].name,"Shidori");
	strcpy(guer[1].skill[0].descricao, "Uchiha Sasuke causa 35 de dano a um inimigo. \nEssa habilidade causa 10 de dano adicional no inimigo afetado por 'Sharingan'.");
	guer[1].skill[0].valor = 35;
	guer[1].skill[0].tipo = 12;
	guer[1].skill[0].cd = 1;
	
	guer[1].skill[0].energia[3] = 1;
	guer[1].skill[0].energia[0] = 1;
	
	//skill 2
	strcpy(guer[1].skill[1].name,"Sharingan");
	strcpy(guer[1].skill[1].descricao, "Uchiha Sasuke marca um inimigo. Por 3 turns, \nUchiha Sasuke ganha 10 pontos de redução de dano. \nDurante esse tempo, esse inimigo irá ser incapaz de \nreduzir dano ou se tornar invulnerável.");
	guer[1].skill[1].valor = 10;
	guer[1].skill[1].tipo = 21;
	

	guer[1].skill[1].cd = 3;
	
	guer[1].skill[1].energia[0] = 1;
	//skill 3
	
	strcpy(guer[1].skill[2].name,"Lion Combo");
	strcpy(guer[1].skill[2].descricao, "Uchiha Sasuke causa 35 de dano a um inimigo. \nEssa habilidade causa 10 de dano adicional no inimigo afetado por 'Sharingan'.");
	guer[1].skill[2].valor = 35;
	guer[1].skill[2].tipo = 11;
	guer[1].skill[2].cd = 0;
	
	guer[1].skill[2].energia[1] = 1;
	guer[1].skill[2].energia[0] = 1;
	
	//HARUNO SAKURA
	
	strcpy (guer[2].name,"Sakura Haruno");
	//guer[1].vida = 100;
	
	strcpy(guer[2].skill[0].name,"KO punsh");
	strcpy(guer[2].skill[0].descricao, "Haruno Sakura acerta um inimigo causando 20 de dano a ele e \natordoando suas habilidades physical e strategic por 1 turno. \nDurante 'Inner Sakura', 'KO Punch' causa 10 de dano adicional.");
	guer[2].skill[0].valor = 20;
	//tipo 1.1 dano normal
	guer[2].skill[0].tipo = 11;
	
	guer[2].skill[0].energia[2] = 1;
	
	//skill 2
	strcpy(guer[2].skill[1].name,"Cura");
	strcpy(guer[2].skill[1].descricao, "Haruno Sakura cura 25 de vida de um aliado ou de si mesma.");
	guer[2].skill[1].valor = 25;
	guer[2].skill[1].tipo = 32;

	guer[2].skill[1].energia[3] = 1;
	
	//skill 3
	
	strcpy(guer[2].skill[2].name,"Inner Sakura");
	strcpy(guer[2].skill[2].descricao, "Por 4 turnos, Haruno Sakura ganha 10 pontos de redução de dano e irá ignorar todos os efeitos atordoantes. \nDurante esse tempo, 'KO Punch' causa 10 de dano adicional.");
	guer[2].skill[2].valor = 10;
	guer[2].skill[2].tipo = 21;
	guer[2].skill[2].cd = 4;
	
	guer[2].skill[2].energia[0] = 1;
}
void mostrarguerreiro( pers guer)
{
	if(guer.vida > 0)
	{
		printf("Nome: %s\n", guer.name);
		printf("Vida: %d\n", guer.vida);
		printf("\n");
	}
	
	
}
//retorna a quantidade de alvos vivos para calcular a quantidade de energia na roda
int alvosvivos(pers guer[])
{
	int quant = 0;
	int i;
	
	for(i=0;i<3;i++)
	{
		
		if(guer[i].vida > 0)
		{	
			//mostrarguerreiro(guer[i]);
			quant++;
		}
	}
	return quant;
}

int MenuSkills(S skill[], int energia[], S *skillT)
{
	int i, j, somaP[3] = {0,0,0}, aux, somaM = 0, s[3] = {-1,-1,-1}, id = 0, op;
	
	//guardando a quantidade necessaria de energia para cada skill em somaP
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			somaP[i] += skill[i].energia[j];
		}
		//soma total de energia na mão em somaM
	}
	for(i=1;i<5;i++)
	{
		somaM += energia[i];
	}
	
	for(i=0;i<3;i++)
	{
		aux = 1;
		
//verificando se as energia que está em mão é maior do que a energia que precisa para ativar
		for(j=1;j<5;j++)
		{
//se a energia colorida J da skill for maior do que a que está em mão J ou total da skill for maior que o tatal de energia em mão
			if((skill[i].energia[j] > energia[j]) || (somaP[i] > somaM))
			{
				//return 0;
				aux = 0;
			}
		}
		//mostrar skill
		if(aux)
		{	
			mostraskill(i, skill[i]);
			//salvando a id da skill disponivel em id
			s[id] = i;
			//andando com id
			id++;
		}	
	}
	// 9 será a opção para passar a vez sem atacar
	printf("\nDigite o numero da skill ou 9 para passar a vez: ");
	scanf("%d", &op);
	//VerificarSkill retorna se op estiver em op
	while (!VerificarSkill(s, op) && op != 9)
	{
		printf("Digite uma skill valida: ");
		scanf("%d", &op);
	}
	// Se chegou aqui então op é diferente de 9 porque se op for 9 então VerificarSkill não irá retornar
	if(VerificarSkill(s, op))
	{	//Removendo a energia da mão com base na opção que foi escolhida e verificada
		RemovendoEnergia(skill[op], energia);
		//retorná a opção para a main 
		*skillT = skill[op];
		return 1;
		
	}
	//Se chegou aqui então op é diferente de 9	
	else
	{
		printf("\nVez passada!\n\n ");
		return -1;
	}
	
	//retorná -1 porque a vez foi passada	
	//return -1;
}
int mostraskill(int i, S skill)
{
		printf("\n%d %s\n", i, skill.name);
		printf("\n%s\n", skill.descricao);	
}		

void GerarEnergia(int energia[], int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		energia[rand() % 4 +1]++;
	}
		
}

void MostrarEnergia(int energia[])
{
	printf("Taijutsu: %d\n", energia[1]);
	printf("Blodline: %d\n", energia[2]);
	printf("Ninjutsu: %d\n", energia[3]);
	printf("Genjutsu: %d\n", energia[4]);
	printf("\n");	
}
// s guarda as id's das skill que são válidas e será verificado se a opção está salva em op
int VerificarSkill(int s[], int op)
{	int i;
	for(i=0;i<3;i++)
	{
		//verificando s é uma opção válida
		
		if(op == s[i])
		{ 
			return 1;
		}	
	}
	return 0;
}

int RemovendoEnergia (S skill, int energia[])
{
	//Guardando a energia random da skill em rad
	int ran = skill.energia[0], i, e;
	//removendo as energias   da mão (1-4)
	for(i=1;i<5;i++)
	{
		energia[i] -= skill.energia[i];
	}
	//agora as enegias Radoms
	//enquanto tiver random, pedirá energia
	while(ran != 0)
	{	// 'e' guardará a opção que o usuario escolher
		printf("Escolha %d Energia aleatoria: ", ran);
		scanf("%d", &e);
		// se a energia for valida, então a energia[e] será removida
		if ((e < 5) && (e > 0) && (energia[e] > 0))
		{
				energia[e]--;
				ran--;	
		}
		else
		{
			printf("Energia invalida\n");
		}
	}
}
int AtivandoSkill(pers aliado[], pers inimigo[], S Skills[], int alvos[])
{
	int def, ddfef, i, j;
	
	//percorrendo as skills
	for(i=0;i<3;i++)
	{
		switch (Skills[i].tipo)
		{
			case 21:
				{
					aliado[alvos[i]].def = Skills[i].valor;
					break;
				}
			case 11:
				if(inimigo[alvos[i]].def< Skills[i].valor)
				{
					inimigo[alvos[i]].vida  -= Skills[i].valor - inimigo[alvos[i]].def;
					break;
				}
				
		}
		
		
	}
	// escolhendo o tipo de skll (1 dano 2 defesa 3 cura)
	
}
int ZerarAcumulador(S acumulador[], int *p)	
{
	int i;
	
	for(i=0;i<3;i++)
	{
		acumulador[i].valor = -1;
	}
	*p = 0;
	
	return 1;
}
void mostrarguerreiros(pers aliado[], pers inimigo[])
{
	int i;
	printf("Alidados\n");
	for(i=0;i<3;i++)
	{
		if(aliado[i].vida > 0)
		{
			printf("Nome: %s\n", aliado[i].name);
			printf("Vida: %d\n", aliado[i].vida);
			printf("\n");
		}	
	}
	
	printf("inimigos\n");
	for(i=0;i<3;i++)
	{
		if(inimigo[i].vida > 0)
		{
			printf("Nome: %s\n", inimigo[i].name);
			printf("Vida: %d\n", inimigo[i].vida);
			printf("\n");
		}	
		
	}
			//mostrarguerreiro(guer[i]);
}

int escolheralvo(S skill, pers aliados[], pers inimigos[])
{
	int val=0, alvo;
	while(!val)
	{
		printf("Digite o alvo: ");
		scanf("%d", &alvo);
		switch (skill.tipo %10)
		{
			case 1:
			{
				if(inimigos[alvo].vida > 0)
				{
					return alvo;
				}
				else
				{
					printf("Alvo invalido\n");
				}
				break;
			}

			case 2:
			{
				if(aliados[alvo].vida > 0)
				{
					return alvo;
				}
				else
				{
					printf("Alvo invalido\n");
				}
				break;
			}
		}
	}
}
void main ()
{	
	setlocale(LC_ALL, "Portuguese");
	int n = 3;
	pers guer[n], guer2[n];
	
	preencherfichar(guer);
	preencherfichar(guer2);
	
	int op, energia1[5] = {0,0,0,0,0}, energia2[5] = {0,0,0,0,0}, vivos[3], p, alvos[3];
	S skillT[3], i;
	
	while (alvosvivos(guer) && alvosvivos(guer2))
	{

		ZerarAcumulador(skillT, &p);
		//Jogador 1;
		system("CLS");
		printf("Jogador 1:\n");
		//retorna a quantidade de alvos vivos 
		alvosvivos(guer);
		mostrarguerreiros(guer, guer2);
		GerarEnergia(energia1, alvosvivos(guer));
		MostrarEnergia(energia1);
		if(guer[0].vida > 0)
		{
			if (MenuSkills(guer[0].skill, energia1, &skillT[0]) > -1)
			{
				alvos[0] = escolheralvo(skillT[0], guer, guer2);
			}
			else
			{
				alvos[0] = -1;
			}	
		}
		
		if(guer[1].vida > 0)
		{
			if(MenuSkills(guer[1].skill, energia1, &skillT[1]) > -1)
			{
				alvos[1] = escolheralvo(skillT[1], guer, guer2);
			}
			else
			{
				alvos[1] = -1;
			}
		
		}
		
		if(guer[2].vida > 0)
		{
			if(MenuSkills(guer[2].skill, energia1, &skillT[2]) > -1)
			{
				alvos[2] = escolheralvo(skillT[2], guer, guer2);
			}
			else
			{
				alvos[2] = -1;
			}
		}
		
		AtivandoSkill(guer, guer2, skillT, alvos);
		
		ZerarAcumulador(skillT, &p);
		//Jogador 2;
		system("CLS");
		printf("Jogador 2:\n");
		//retorna a quantidade de alvos vivos 
		alvosvivos(guer2);
		mostrarguerreiros(guer2, guer);
		GerarEnergia(energia2, alvosvivos(guer2));
		MostrarEnergia(energia2);
		//
		if(guer2[0].vida > 0)
		{
			if (MenuSkills(guer2[0].skill, energia1, &skillT[0]) > -1)
			{
				alvos[0] = escolheralvo(skillT[0], guer2, guer);
			}
			else
			{
				alvos[0] = -1;
			}	
		}
		
		if(guer2[1].vida > 0)
		{
			if(MenuSkills(guer2[1].skill, energia1, &skillT[1]) > -1)
			{
				alvos[1] = escolheralvo(skillT[1], guer2, guer);
			}
			else
			{
				alvos[1] = -1;
			}
		
		}
		
		if(guer2[2].vida > 0)
		{
			if(MenuSkills(guer[2].skill, energia2, &skillT[2]) > -1)
			{
				alvos[2] = escolheralvo(skillT[2], guer2, guer);
			}
			else
			{
				alvos[2] = -1;
			}
		}
		
		AtivandoSkill(guer2, guer, skillT, alvos);
		
		system("PAUSE");
	}	
}
