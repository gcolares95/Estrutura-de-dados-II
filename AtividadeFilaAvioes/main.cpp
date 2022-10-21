/*
    Atividade 05/10/2022/ - Fila

    a) Listar o número de aviões aguardando na fila de decolagem;
    b) Autorizar a decolagem do primeiro avião da fila;
    c) Adicionar um avião à fila de espera;
    d) Listar todos os aviões na fila de espera;
    e) Listar as características do primeiro avião da fila.
    Considere que os aviões possuem um nome e um número inteiro como
    identificador. Adicione outras características conforme achar necessário.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct {
    int id;
    char *modelo;
    char *cor;
    char *tipo;
} AVIAO;

typedef struct aux {
    AVIAO av;
    aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* inicio;
    ELEMENTO* fim;
} FILA;

void inicializaFila (FILA *f)  {
        f->inicio = NULL;
        f->fim = NULL;
}

bool addAviao (FILA *f, AVIAO novo_aviao) {
    ELEMENTO *i;

    i = new ELEMENTO;
    i ->av = novo_aviao;
    i->proximo = NULL;

    if (f->inicio == NULL) {
      f->inicio = i;
    }  else  {
        f->fim->proximo = i;
    }
    f->fim = i;

    return true;
}

bool liberarAviao(FILA* f) {
    if (f->inicio == NULL) {
        return false;
    }

    ELEMENTO *i = f->inicio;
    f->inicio = f->inicio->proximo;

   delete(f);

    return true;
}

void avioesEmEspera(FILA  *f) {
    ELEMENTO* i = f->inicio;
    cout << "========= AVIÕES EM ESPERA ========= " << endl;
    while (i != NULL) {
        cout << "Id = " << i->av.id << endl;
        cout << "Modelo = " << i->av.modelo << endl;
        cout << "Cor  = " << i->av.cor << endl;
        cout << "Tipo = " <<  i->av.tipo<< endl;
        cout  << endl;

        i = i->proximo;
    }
}

int qtdAvioes(FILA  *f) {
    ELEMENTO* i = f->inicio;

    int qtd = 0;

    while (i != NULL) {
        qtd++;

        i = i->proximo;
    }

    return qtd;
}

AVIAO returnAviao (FILA *f) {
    return f->inicio->av;
}

int main()
{
    setlocale(LC_ALL,  "portuguese");

    FILA f;

    inicializaFila(&f);

    AVIAO av;

    av.id = 1;
    av.modelo = "Boeing 717";
    av.cor = "Branco";
    av.tipo = "Monomotor";

    addAviao(&f, av);

    av.id = 2;
    av.modelo = "Airbus A330-800neo";
    av.cor = "Vermelho";
    av.tipo = "Bimotor";

    addAviao(&f, av);

    av.id = 3;
    av.modelo = "ATR 72-200";
    av.cor = "Azul";
    av.tipo = "Trimotor";

    addAviao(&f, av);

    cout << endl;
    avioesEmEspera(&f);

    liberarAviao(&f);

    avioesEmEspera(&f);

    int qtdAvioesFila = qtdAvioes(&f);
    cout << "Existem " << qtdAvioesFila << " Aviões Aguardando na fila de decolagem." << endl;

    cout << endl;

    AVIAO av1 = returnAviao(&f);
    cout  << "Primeiro Avião na fila: " << endl;
    cout  << "Id = " << av1.id << endl;
    cout  << "Modelo = " << av1.modelo << endl;
    cout  << "Cor  = " << av1.cor << endl;
    cout  << "Tipo = " <<  av1.tipo<< endl;
    cout  << endl;
}
