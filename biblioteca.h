#ifndef BIBLIOTECA_SISTEMA_BIBLIOTECA_H
#define BIBLIOTECA_SISTEMA_BIBLIOTECA_H

// ------- Variaveis constantes ---------
#define MAX_STRING 50
#define MAX_EMPRESTIMOS 10
#define MAX_LIVROS 5

// ------- Structs -----------
typedef struct {
    char nome[MAX_STRING];
    char autor[MAX_STRING];
    int edicao;
    int emprestado; // 1 Livro emprestado, 0 Livro disponivel para emprestimo
} Livros;

typedef struct {
    int indiceLivro;
    char nomeUsuario[MAX_STRING];
} Emprestimo;

// -------- Prototipo das funcoes ------------

void limparBuffer();
void printMenu();
void adicionarLivro(Livros *biblioteca, int quantiaDeLivros);
void listarLivros(int emprestadoOuNao, Livros *biblioteca, int quantiaDeLivros, int quantiaDeEmprestimos, Emprestimo *emprestimos );
void registrarEmprestimo(int *quantiaDeEmprestimos, int quantiaDeLivros, Livros *biblioteca, Emprestimo *emprestimos);
void liberarMemoria( Livros *biblioteca, Emprestimo *emprestimos);

#endif //BIBLIOTECA_SISTEMA_BIBLIOTECA_H
