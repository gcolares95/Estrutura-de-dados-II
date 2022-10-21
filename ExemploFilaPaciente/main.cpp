// Exemplo: Fila - Pacientes

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

 // STRUCT PACIENTE
 typedef struct {
    int cod_pac;
    char *nome;
    char *cpf;
    int idade;
 } PACIENTE;

 // STRUCT AUX
 typedef struct aux {
    PACIENTE pac; // criando variavel "pac" do tipo PACIENTE
    aux* proximo;
 } ELEMENTO;

 // STRUCT FILA
 typedef struct {
    ELEMENTO* inicio;
    ELEMENTO* fim;
 } FILA;

 // Funcao para inicializar Fila
 void inicializaFila (FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
 }

 // Funcao para inserir Paciente (push)
 bool inserirPaciente (FILA* f, PACIENTE novo_paciente) {
    ELEMENTO *i;

    i = new ELEMENTO; // alocando memoria
    i->pac = novo_paciente;
    i->proximo = NULL;

    // Se for o primeiro elemento da fila
    if (f->inicio == NULL) {
        f->inicio = i;
    } else {
        f->fim->proximo = i; // se não for o primeiro elemento da fila
    }
    f->fim= i;

    return true;
 }

 // Funcção para excluir o primeiro paciente
 bool excluirPaciente (FILA *f) {
     if (f->inicio == NULL) return false; // fila vazia

     ELEMENTO *i = f->inicio;
     f->inicio = f->inicio->proximo;

     delete(f);

     cout << "------------ Após excluir o primeiro elemento da fila ------------" << endl;
     return true;
 }

// Função para imprimir todos os pacientes da fila
 void mostrarFila (FILA* f) {
    ELEMENTO* i = f->inicio;

    while (i != NULL) {

        cout << "Código do paciente: " << i->pac.cod_pac << endl;
        cout << "Nome do paciente: " << i->pac.nome << endl;
        cout << "Cpf do paciente: " << i->pac.cpf << endl;
        cout << "Idade do paciente: " << i->pac.idade << endl;
         cout << "---------------------" << endl;
        cout << endl;

        i = i->proximo;
    }
}

int quantidadePacientes(FILA *f) {
    ELEMENTO* i = f->inicio;

    int qtdPacientes = 0;

    while (i != NULL) {
        qtdPacientes++;

        i = i->proximo;
    }

    return qtdPacientes;
}

// Funçao para retornar o primeiro paciente da fila
ELEMENTO returnElemento (FILA* f) {
    return *f->inicio;
}

PACIENTE returnPaciente (FILA* f) {
    return f->inicio->pac;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    FILA f;
    inicializaFila(&f);

    PACIENTE p;

    p.cod_pac = 1;
    p.nome = "Guilherme Colares de Araujo";
    p.cpf = "039.998.102-03";
    p.idade = 19;
    inserirPaciente(&f, p);

    p.cod_pac = 2;
    p.nome = "Ana Karolina de Souza";
    p.cpf = "323.243.434-33";
    p.idade = 22;
    inserirPaciente(&f, p);

    p.cod_pac = 3;
    p.nome = "Samuel Davi Souza";
    p.cpf = "543.111.231-54";
    p.idade = 20;
    inserirPaciente(&f, p);

    mostrarFila(&f);

    ELEMENTO e = returnElemento(&f);
    cout << "Elemento first " << e.pac.cod_pac << endl;

    PACIENTE p1 = returnPaciente(&f);
    cout << "Paciente first " << p1.cod_pac << endl;

    cout << endl;

    excluirPaciente(&f);

    cout << endl;

    mostrarFila(&f);

    int qtdPacientes = quantidadePacientes(&f);

    cout << "Existem " << qtdPacientes << " de Pacientes em espera." << endl;

    return 0;
}
