#include <iostream>

using namespace std;

typedef struct {
    int cod;
    char *titulo;
    char *autor;
} LIVRO;

typedef struct aux {
    LIVRO livb;
    aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* topo;
} PILHA;

void inicializaPilha(PILHA* p) {
    p->topo = NULL;
}

bool inserirLivro(PILHA *p, LIVRO novo_livro) {
    ELEMENTO *i;
    i = new ELEMENTO;
    i->livb = novo_livro;
    i->proximo = p->topo;
    p->topo = i;

    return true;
}

bool excluirLivro (PILHA *p) {
    if (p->topo == NULL) {
        return false;
    }

    ELEMENTO *i = p->topo;
    p->topo = p->topo->proximo;
    delete(i);

    return true;
}

void printLivros(PILHA *p) {
    ELEMENTO* i = p->topo;

    while (i != NULL) {
        cout << "Código do Livro = " << i->livb.cod << endl;
        cout << "Título  = " << i->livb.titulo << endl;
        cout << "Autor = " << i->livb.autor << endl;

        cout  << endl;

        i = i->proximo;
    }
}

/*
    ELEMENTO returnElemento(PILHA* p) {
        return *p->topo;
    }
*/

LIVRO returnLivro(PILHA* p) {
    return p->topo->livb;
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    PILHA p;

    inicializaPilha(&p);

    LIVRO lv;

    lv.cod = 1;
    lv.titulo = "Arsène Lupin: O Ladrão de Casaca";
    lv.autor= "Maurice Leblanc";

    inserirLivro(&p, lv);

    lv.cod = 2;
    lv.titulo = "A revolução dos bichos: Um conto de fadas";
    lv.autor= "George Orwell";

    inserirLivro(&p, lv);

    lv.cod = 3;
    lv.titulo = "Amazing Spider-Man: Renew Your Vows";
    lv.autor= "Gerry Conway";

    inserirLivro(&p, lv);

    printLivros(&p);

    cout << endl << "=========== Pilha Apois excluir o topo =========== " << endl << endl;

    excluirLivro(&p);

    printLivros(&p);

    LIVRO lvTopo = returnLivro(&p);

    cout << "=========== Livro no topo da fila: ===========" << endl << endl;
    cout << "Código do Livro = " << lvTopo.cod << endl;
    cout << "Título  = " << lvTopo.titulo << endl;
    cout << "Autor = " << lvTopo.autor << endl;

    return 0;
}
