#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para atributos do personagem
typedef struct {
    int forca;
    int destreza;
    int inteligencia;
    int carisma;
    int constituicao;
} Atributos;

// Estrutura para itens
typedef struct {
    char nome[50];
    char tipo[20]; // Exemplo: "arma", "armadura", "consumivel"
    int dano;
    int defesa;
} Item;

// Estrutura para habilidades
typedef struct {
    char nome[50];
    char descricao[100];
    int custoPE;
    void (*efeito)(void *, void *); // Ponteiro para função de efeito
} Habilidade;

// Estrutura para personagens
typedef struct {
    char nome[50];
    char classe[20];
    Atributos atributos;
    int pvMax;
    int pvAtual;
    int peMax;
    int peAtual;
    int nivel;
    int experiencia;
    Habilidade *habilidades[10];
    int numHabilidades;
    Item arma;
    Item armadura;
} Personagem;

// Função para atacar
void atacar(Personagem *atacante, Personagem *alvo) {
    int dano = atacante->atributos.forca + atacante->arma.dano;
    printf("%s ataca %s causando %d de dano!\n", atacante->nome, alvo->nome, dano);
    alvo->pvAtual -= dano;
    if (alvo->pvAtual <= 0) {
        alvo->pvAtual = 0;
        printf("%s foi derrotado!\n", alvo->nome);
    }
}

// Exemplo de habilidade: Golpe Poderoso
void golpePoderoso(void *usuario, void *alvo) {
    Personagem *u = (Personagem *)usuario;
    Personagem *a = (Personagem *)alvo;
    int dano = u->atributos.forca * 2;
    printf("%s usa Golpe Poderoso em %s causando %d de dano!\n", u->nome, a->nome, dano);
    a->pvAtual -= dano;
    if (a->pvAtual <= 0) {
        a->pvAtual = 0;
        printf("%s foi derrotado!\n", a->nome);
    }
}

// Função para usar habilidade
void usarHabilidade(Personagem *usuario, Habilidade *habilidade, Personagem *alvo) {
    if (usuario->peAtual >= habilidade->custoPE) {
        usuario->peAtual -= habilidade->custoPE;
        habilidade->efeito(usuario, alvo);
    } else {
        printf("%s não tem PE suficiente para usar %s!\n", usuario->nome, habilidade->nome);
    }
}

// Função para subir de nível
void subirDeNivel(Personagem *p) {
    p->nivel++;
    p->pvMax += 5;
    p->peMax += 2;
    p->pvAtual = p->pvMax;
    p->peAtual = p->peMax;
    printf("%s subiu para o nível %d!\n", p->nome, p->nivel);
}

// Função para criar um personagem
Personagem criarPersonagem(char *nome, char *classe, Atributos atributos, int pv, int pe, Item arma, Item armadura) {
    Personagem p;
    strcpy(p.nome, nome);
    strcpy(p.classe, classe);
    p.atributos = atributos;
    p.pvMax = pv;
    p.pvAtual = pv;
    p.peMax = pe;
    p.peAtual = pe;
    p.nivel = 1;
    p.experiencia = 0;
    p.numHabilidades = 0;
    p.arma = arma;
    p.armadura = armadura;
    return p;
}

// Função principal
int main() {
    // Criando itens
    Item espada = {"Espada Longa", "arma", 8, 0};
    Item cotaMalha = {"Cota de Malha", "armadura", 0, 16};

    // Criando habilidades
    Habilidade golpePoderosoHabilidade = {"Golpe Poderoso", "Causa dano igual ao dobro da Força.", 3, golpePoderoso};

    // Criando personagens
    Atributos atributosGuerreiro = {8, 5, 3, 4, 8};
    Personagem guerreiro = criarPersonagem("Thorgar", "Guerreiro", atributosGuerreiro, 18, 13, espada, cotaMalha);
    guerreiro.habilidades[guerreiro.numHabilidades++] = &golpePoderosoHabilidade;

    Atributos atributosGoblin = {4, 6, 2, 2, 5};
    Personagem goblin = criarPersonagem("Goblin", "Inimigo", atributosGoblin, 10, 5, espada, cotaMalha);

    // Combate
    atacar(&guerreiro, &goblin);
    usarHabilidade(&guerreiro, &golpePoderosoHabilidade, &goblin);

    return 0;
}

