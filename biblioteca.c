#include <stdio.h>
#include "biblioteca.h"
#include <stdlib.h>

/**
 * Limpa residuo do scanf
 */
void limparBuffer() {
    int c;
    while (( c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Lista as opcoes do usuario
 */
void printMenu() {

    printf("\n--- MENU DA BIBLIOTECA ---\n");
    printf("1 - Adicionar livro a biblioteca\n");
    printf("2 - Listar livros da biblioteca\n");
    printf("3 - Fazer emprestimo de um livro\n");
    printf("4 - Listar emprestimos\n");
    printf("0 - Sair\n");
    printf("--------------------------\n");
    printf("Escolha uma opcao: ");
}

/**
 * @brief Registra novo livro na biblioteca com nome, autor e edicao
 * @param biblioteca  Array (ponteiro constante, somente para leitura)
 * @param quantiaDeLivros O numero de livros ja registrados (passagem por valor)
 */
void adicionarLivro(Livros *biblioteca, int quantiaDeLivros) {
    if (quantiaDeLivros < 5) {
        printf("Digite o nome do livro: ");
        scanf(" %[^\n]s", biblioteca[quantiaDeLivros].nome);
        limparBuffer();
        printf("Digite o nome do autor: ");
        scanf(" %[^\n]s", biblioteca[quantiaDeLivros].autor);
        limparBuffer();
        printf("Digite a edicao: ");
        scanf("%d", &biblioteca[quantiaDeLivros].edicao);
        limparBuffer();

    } else {
        printf("Voce ja adicionou o max de livros que pode!! \n");
    }
}

/**
 * @brief Lista livros ja registrados na biblioteca com nome, autor e edicao
 * @param emprestadoOuNao Numero que especifica se e para listar os livros disponiveis ou os emprestados
 */
void listarLivros(int emprestadoOuNao,Livros *biblioteca, int quantiaDeLivros, int quantiaDeEmprestimos, Emprestimo *emprestimos ) {
    if (emprestadoOuNao == 0) {
        printf("\n--- LISTA DE LIVROS ---\n");
        for (int i = 0; i < quantiaDeLivros; i++) {
            printf("Livro %d:\n", i + 1);
            printf("  Titulo: %s\n", biblioteca[i].nome);
            printf("  Autor:  %s\n", biblioteca[i].autor);
            printf("  Edicao:%d\n", biblioteca[i].edicao);
            printf("-----------------------\n");
        }
    } else if (emprestadoOuNao == 1) {
        printf("\n--- LISTA DE LIVROS EMPRESTADOS---\n");
        for (int i = 0; i < quantiaDeEmprestimos; i++) {
            if (biblioteca[i].emprestado) {
                printf("%d - %s\n", i + 1, biblioteca[i].nome);
                printf("Emprestado para: %s\n", emprestimos[i].nomeUsuario);
            }
        }}
}

/**
 * @brief Registra um novo emprestimo com um livro disponivel da biblioteca
 * @param quantiaDeEmprestimos Ponteiro usado para comparacao e indice das arrays (passagem por referencia)
 * @param quantiaDeLivros Usado somente para comparacao
 * @param biblioteca Array (ponteiro constante, utilizado para editar disponibilidade do livro)
 * @param emprestimos Array (ponteiro constante,uso para registrar o nome do usuario e indice do livro registrado)
 */
void registrarEmprestimo(int *quantiaDeEmprestimos, int quantiaDeLivros, Livros *biblioteca, Emprestimo *emprestimos) {

    if (*quantiaDeEmprestimos >= MAX_EMPRESTIMOS) {
        printf("O max de emprestimos ja foram feitos! \n");
    } else {
        int disponiveis = 0;
        printf("\n--- LISTA DE LIVROS DISPONIVEIS---\n");
        for (int i = 0; i < quantiaDeLivros; i++) { // verificar quais livros nao estao emprestados
            if (!( biblioteca[i].emprestado)) {
                printf("%d - %s\n", i + 1, biblioteca[i].nome);
                disponiveis++;
            }
        }
        if (disponiveis == 0) {
            printf("Nenhum livro emprestado no momento");
        }else{
            int numLivro;
            printf("Qual o num do livro que voce gostaria de emprestar?)\n");
            scanf("%d", &numLivro);
            limparBuffer();

            int indice = numLivro - 1;

            if (indice >=0 && indice <= quantiaDeLivros) { //registrar emprestimo
                emprestimos[*quantiaDeEmprestimos].indiceLivro = indice;
                printf("Qual seu nome?");
                scanf("%s", emprestimos[*quantiaDeEmprestimos].nomeUsuario);
                limparBuffer();

                biblioteca[indice].emprestado = 1;

                (*quantiaDeEmprestimos)++;

                printf("Emprestimo concluido!\n");
            } else {
                printf("Numero inexistente ou livro indisponivel \n ");
            }
        }
    }
}

void liberarMemoria( Livros *biblioteca, Emprestimo *emprestimos) {
    free(biblioteca);
    free(emprestimos);

    printf("Memoria liberada com sucesso!\n");
}