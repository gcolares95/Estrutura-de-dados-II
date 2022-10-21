/*
    Atividade 05/10/2022/ - Pilha

    Se tem um estacionamento que guarda até dez carros em fileira um detrás do outro.
    Existe apenas uma entrada/saída no estacionamento. Se chegar um cliente para retirar um carro que não seja o mais próximo da saída, todos os carros bloqueando seu caminho sairão do estacionamento de um em um. O carro do cliente será manobrado para fora do estacionamento, e os outros carros voltarão a ocupar a mesma sequência inicial.
    Crie um programa usando uma estrutura de tipo PILHA (como a ministrada em aula) para controlar o estacionamento. O programa deverá ter as seguinte funcionalidades:
    - Estacionar um carro (cada carro é identificado por um numero inteiro de quatro dígitos)
    - Retirar u carro do estacionamento (respeitando a regra de negocio)
    - Listar os carros que estão no estacionamento.
    - Mostrar quantos carros estão no estacionamento.
*/

#include <iostream>

using namespace std;

typedef struct {
    char  *placa;
    char *modelo;
    char *cor;
} CARRO;

typedef struct aux {
    CARRO car;
    aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* topo;
} PILHA;

void inicializaPilha(PILHA* p) {
    p->topo = NULL;
}

bool addCarro(PILHA *p, CARRO novo_carro) {
    ELEMENTO *i;
    i = new ELEMENTO;
    i->car = novo_carro;
    i->proximo = p->topo;
    p->topo = i;

    return true;
}

bool removeCarro (PILHA *p) {
    if (p->topo == NULL) {
        return false;
    }

    ELEMENTO *i = p->topo;
    p->topo = p->topo->proximo;
    delete(i);

    return true;
}

void printCarros(PILHA *p) {
    ELEMENTO* i = p->topo;

    cout << "=========== CARROS ESTACIONADOS =========== " << endl << endl;

    while (i != NULL) {
        cout << "Placa do Carro = " << i->car.placa << endl;
        cout << "Modelo = " << i->car.modelo<< endl;
        cout << "Cor = " << i->car.cor << endl;

        cout  << endl;

        i = i->proximo;
    }
}

int qtdCarrosEstacionados(PILHA *p) {
    ELEMENTO *i = p->topo;

    int qtdCarros = 0;

    while (i != NULL) {
        qtdCarros++;

        i = i->proximo;
    }

    return qtdCarros;
}

CARRO returnCarro(PILHA* p) {
    return p->topo->car;
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    PILHA p;

    inicializaPilha(&p);

    CARRO ca;

    ca.placa = "KSD234";
    ca.modelo = "CIVIC";
    ca.cor= "PRETO";

    addCarro(&p, ca);

    ca.placa = "SSF544";
    ca.modelo = "CELTA";
    ca.cor= "AZUL";

    addCarro(&p, ca);

    ca.placa = "BFH553";
    ca.modelo = "FORD KA";
    ca.cor= "BRANCO";

    addCarro(&p, ca);

    printCarros(&p);

    cout << endl << "=========== ESTACIONAMENTO APÓS RETIRAR O ÚLTIMO CARRO =========== " << endl << endl;

    removeCarro(&p);

    printCarros(&p);

    int qtdCarros = qtdCarrosEstacionados(&p);

    if (qtdCarros == 0) {
        cout << endl << "=========== ESTACIONAMENTO ESTÁ VAZIO =========== " << endl << endl;
    } else {
        cout << endl << "=========== RESTAM " << qtdCarros << " CARROS NO ESTACIONAMENTO =========== " << endl << endl;
    }



    return 0;
}
