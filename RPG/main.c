#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
	char nome[20];
	int dano, defesa;
} Item;
typedef struct
{
	int rodada, id;
	char nomep[50];
} Passiva;
typedef struct
{
	int For, Des, Int, Car, Con, pv, pe, pvmax, pemax, ca, classe;
	char nome[50]; 
	Item arma, armadura;
	Passiva passiva[10];
	
} Personagem;


//Prototipos
Personagem criar_personagem(char nome[], int classe);
void atacar(Personagem *atacante, Personagem *alvo);
void usar_habilidade(Personagem *usuario, Personagem *alvo, char habilidade[]);
void combate(Personagem *p1, Personagem *p2);
int rolar_dados(int lados);
void Alocar_Passiva(int id, int turno, Personagem *alvo);
void rodadas(Personagem *p1, Personagem *p2);
//Criando o personagem
Personagem criar_personagem(char nome[], int classe)
{
	Personagem p; Item arma, armadura;
	strcpy(p.nome, nome);
	p.classe = classe;
	switch (p.classe)
	{
		case 1:
		{
			p.For = 8;
	        p.Des = 5;
	        p.Int = 3;
	        p.Car = 4;
	        p.Con = 8;
	        p.pv = 10 + p.Con;
	        p.pe = 10 + p.Int;
	        p.ca = 0;
	        strcpy(p.arma.nome, "Espada Longa");
	        p.arma.dano = 8;
	        p.armadura.defesa = 16;
	        break;
		}
		
		case 2:
		{
			p.For = 6;
	        p.Des = 4;
	        p.Int = 5;
	        p.Car = 6;
	        p.Con = 7;
	        p.pv = 10 + p.Con;
	        p.pe = 10 + p.Int;
	        p.ca = 0;
	        strcpy(p.arma.nome, "Martelo de Guerra");
	        p.arma.dano = 8;
	        strcpy(p.armadura.nome, "Armadura Completa");
	        p.armadura.defesa = 18;
	        break;
		}
			case 3:
		{
			p.For = 3;
	        p.Des = 4;
	        p.Int = 9;
	        p.Car = 5;
	        p.Con = 4;
	        p.pv = 10 + p.Con;
	        p.pe = 10 + p.Int;
	        p.ca = 0;
	        strcpy(p.arma.nome, "Cajado Arcano");
	        p.arma.dano = 6;
	        strcpy(p.armadura.nome, "Roupas Mágicas");
	        p.armadura.defesa = 12;
	        break;
		}
			case 4:
		{
			p.For = 5;
	        p.Des = 8;
	        p.Int = 4;
	        p.Car = 4;
	        p.Con = 6;
	        p.pv = 10 + p.Con;
	        p.pe = 10 + p.Int;
	        p.ca = 0;
	        
	        strcpy(p.arma.nome, "Arco Longo");
	        p.arma.dano = 8;
	        strcpy(p.armadura.nome, "Couro Reforçado");
	        p.armadura.defesa = 14;
	        break;
		}
			case 5:
		{
			p.For = 4;
	        p.Des = 4;
	        p.Int = 7;
	        p.Car = 6;
	        p.Con = 5;
	        p.pv = 10 + p.Con;
	        p.pe = 10 + p.Int;
	        p.ca = 0;
	        strcpy(p.arma.nome, "Maça Leve");
	        strcpy(p.armadura.nome, "Vestes Sagradas");
	        p.arma.dano = 6;
	        p.armadura.defesa = 13;
	        break;
		}
	}
	return p;
}
int rolar_dados(int lados)
{
	srand(time(NULL));
	return (rand() % lados) +1;
}
void atacar(Personagem *atacante, Personagem *alvo)
{
	int ataque = rolar_dados(20) + atacante->Des;
	if(ataque >= alvo->arma.defesa)
	{
		int dano = rolar_dados(atacante->arma.dano) + atacante->For;
	}
}
void usar_habilidade(Personagem *usuario, Personagem *alvo, char habilidade[])
{
	int dano;
	if(strcmp(habilidade, "Golpe Poderoso") == 0)
	{
		if(usuario->pe >= 2)
		{
			printf("%s usou Golpe Poderoso em %s");
			dano = usuario->arma.dano + usuario->For*2;
		}
		else
		{
			printf("Sem energia suficiente");
		}
		
		if(usuario->Des + rolar_dados(20) >= alvo->armadura.defesa)
		{
			alvo->pv -= dano;
			
		}
	}
	 if (strcmp(habilidade, "Cura Divina") == 0) 
	 {
        if (usuario->pe >= 3) 
		{
            int cura = rolar_dados(8) + usuario->Int;
            usuario->pe -= 3;
            alvo->pv += cura;
            if(alvo->pv> alvo->pvmax)
            {
            	alvo->pv = alvo->pvmax;
			}
            	printf("%s usou Cura Divina e curou %d PV de %s. %s agora tem %d PV.\n", usuario->nome, cura, alvo->nome, alvo->nome, alvo->pv);
        }
		else 
		{
            printf("%s não tem PE suficiente para usar Cura Divina!\n", usuario->nome);
        }
    
	} 
	else 
	{
        printf("Habilidade desconhecida!\n");
    }
//    //efeito 1-> Fúria do Guerreiro
  	if (strcmp(habilidade, "Fúria do Guerreiro") == 0) 
	{
		int id = 1;
        if (usuario->pe >= 3) 
		{
			usuario->pe -= 3;
			Alocar_Passiva(id, /*turnos*/3, usuario);
			
		}
		
	}
}

// Função para realizar o combate
void combate(Personagem *p1, Personagem *p2) {
    printf("Combate iniciado entre %s e %s!\n", p1->nome, p2->nome);

    while (p1->pv > 0 && p2->pv > 0) {
        // Turno do personagem 1
        atacar(p1, p2);
        if (p2->pv <= 0) {
            printf("%s foi derrotado!\n", p2->nome);
            break;
        }

        // Turno do personagem 2
        atacar(p2, p1);
        if (p1->pv <= 0) {
            printf("%s foi derrotado!\n", p1->nome);
            break;
        }
    }
}
void Alocar_Passiva(int id, int turno, Personagem *alvo)
{	int i;
	for(i=0;i<10;i++)
	{
		if(alvo->passiva[i].rodada == 0)
		{
			alvo->passiva[i].id = id; 
			alvo->passiva[i].rodada = turno;
			break;
		}
	}
/*	for(i=0;i<10;i++)
	{
		if(alvo->passiva[i].rodada > 0)
		{
			alvo->passiva[i].rodada -= 1;
		}
		else
		{
			if()
			{
				
			}
		}
		
	}*/	
}
void rodadas(Personagem *p1, Personagem *p2)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(p1->passiva[i].rodada > 0)
		{
			p1->passiva[i].rodada--;
			if(p1->passiva[i].rodada == 0)
			{
				if (p1->passiva[i].id == 1) //Furia do Guerreiro +3 for
				{
					p1->For -= 3;  
				}
			}
		}
		
		if(p2->passiva[i].rodada > 0)
		{
			p2->passiva[i].rodada--;
			if(p2->passiva[i].rodada == 0)
			{
				if (p2->passiva[i].id == 1) //Furia do Guerreiro +3 for
				{
					p2->For -= 3;  
				}
			}
		}
		
	}
}
void main ()
{
	
}
