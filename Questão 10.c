#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    int quantidade;
    float preco;
};

struct Produto produto;

void cadastrarProduto() {
    printf("\nInforme o nome do produto: ");
    scanf("%s", produto.nome);

    printf("Informe a quantidade do produto em estoque: ");
    scanf("%d", &produto.quantidade);

    printf("Informe o preço do produto: R$");
    scanf("%f", &produto.preco);
}

void listarProduto() {
    printf("\nNome: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Preço: R$ %.2f\n", produto.preco);
}

void fazerCompra() {
    int quantComprada;
    printf("\nInforme a quantidade que deseja comprar: ");
    scanf("%d", &quantComprada);
    
    if (quantComprada > produto.quantidade) {
        printf("\nQuantidade insuficiente no estoque!\n");
    } else {
        produto.quantidade <= quantComprada;
        printf("\nCompra realizada!\n");
        printf("\nQuantidade no estoque: %d\n", produto.quantidade);
    }
}

int main() {
    int opcao;
    produto.quantidade = 0; 

    do {
        printf("\n====== Mercado SuperMais ======\n");
        printf("1- Cadastrar produto\n");
        printf("2- listar produto\n");
        printf("3- Fazer compra\n");
        printf("4- Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProduto();
                break;
            case 3:
                fazerCompra();
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
