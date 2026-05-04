#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo as variaveis globais
#define MAX_STRING 50
#define MAX_EMPRESTIMOS 10
#define MAX_LIVROS 5

// Definindo os structs
typedef struct {
    char nome[MAX_STRING];
    char autor[MAX_STRING];
    int edicao;
    int emprestado; // 1 sim, 0 nao
} Livros;

typedef struct {
    int indiceLivro;
    char nomeUsuario[MAX_STRING];
} Emprestimo;

// Definindo as funcoes
void limparBuffer() {
    int c;
    while (( c = getchar()) != '\n' && c != EOF);
}


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
        printf("\n--- MENU DA BIBLIOTECA ---\n");
        printf("1 - Adicionar livro a biblioteca\n");
        printf("2 - Listar livros da biblioteca\n");
        printf("3 - Fazer emprestimo de um livro\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - Sair\n");
        printf("--------------------------\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: // Adicionar um livro
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

                    quantiaDeLivros++;

                } else {
                    printf("Voce ja adicionou o max de livros que pode!! \n");
                }
                break;
            case 2: // Listar livros
                printf("\n--- LISTA DE LIVROS ---\n");
                for (int i = 0; i < quantiaDeLivros; i++) {
                    printf("Livro %d:\n", i + 1);
                    printf("  Titulo: %s\n", biblioteca[i].nome);
                    printf("  Autor:  %s\n", biblioteca[i].autor);
                    printf("  Edicao:%d\n", biblioteca[i].edicao);
                    printf("-----------------------\n");
                }
                break;
            case 3: // Emprestar livro
                if (quantiaDeEmprestimos >= MAX_EMPRESTIMOS) {
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

                        if (indice >=0 && indice <= quantiaDeLivros) {
                            emprestimos[indice].indiceLivro = indice;
                            printf("Qual seu nome?");
                            scanf("%s", emprestimos[indice].nomeUsuario);
                            limparBuffer();

                            biblioteca[indice].emprestado = 1;

                            quantiaDeEmprestimos++;

                            printf("Emprestimo concluido!\n");
                        } else {
                            printf("Numero inexistente ou livro indisponivel \n ");
                        }
                    }
                }
                break;
            case 4:
                printf("\n--- LISTA DE LIVROS EMPRESTADOS---\n");
                for (int i = 0; i < quantiaDeEmprestimos; i++) {
                    if (biblioteca[i].emprestado) {
                        printf("%d - %s\n", i + 1, biblioteca[i].nome);
                        printf("Emprestado para: %s\n", emprestimos[i].nomeUsuario);
                    }
                }
                break;
            case 0:
                break;
            default:
                    printf("Voce selecionou uma opcao invalida! Tente novamente.");
                }
        } while (opcao != 0);

    free(biblioteca);
    free(emprestimos);

    printf("Memoria liberada com sucesso!\n");
}