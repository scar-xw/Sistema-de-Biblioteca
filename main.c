#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

// Funcao principal
int main(void) {
    //Alocacao de memoria dinamica usando ponteiros
    Livros *biblioteca = (Livros *) calloc(MAX_LIVROS, sizeof(Livros));
    Emprestimo *emprestimos = (Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    int quantiaDeLivros = 0;
    int quantiaDeEmprestimos = 0;
    int opcao;

    // Printar menu de usuario, o que ele gostaria de fazer
    do {
        printMenu();
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                adicionarLivro(biblioteca, quantiaDeLivros);
                quantiaDeLivros++;
                break;
            case 2:
                listarLivros(0,biblioteca, quantiaDeLivros, quantiaDeEmprestimos, emprestimos);
                break;
            case 3:
                registrarEmprestimo(&quantiaDeEmprestimos, quantiaDeLivros, biblioteca,emprestimos);
                break;
            case 4:
                listarLivros(1,biblioteca, quantiaDeLivros, quantiaDeEmprestimos, emprestimos);
                break;
            case 0:
                break;
            default:
                    printf("Voce selecionou uma opcao invalida! Tente novamente.");
                }
        } while (opcao != 0);

    liberarMemoria( biblioteca, emprestimos);
}