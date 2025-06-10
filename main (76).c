#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    float preco;
} Pizza;

typedef struct {
    char nome[50];
    char telefone[50];
} Cliente;

Pizza pizzas[5];
Cliente clientes[5];
int numPizzas = 0;
int numClientes = 0;

void cadastrarPizza();
void cadastrarCliente();
void listarPizzas();
void listarClientes();
void venderPizza();

int main() {
    int opcao;
    do {
        printf("\n====== Nostra Pizza ======\n");
        printf("Escolha uma das opções:\n");
        printf("1- Cadastrar Pizza\n");
        printf("2- Cadastrar Cliente\n");
        printf("3- Listar Pizzas\n");
        printf("4- Listar Clientes\n");
        printf("5- Vender Pizza\n");
        printf("0- Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            
            case 1:
            cadastrarPizza();
            break;
            
            case 2:
            cadastrarCliente();
            break;
            
            case 3:
            listarPizzas();
            break;
            
            case 4:
            listarClientes();
            break;
            
            case 5:
            venderPizza();
            break;
            
            case 0:
            printf("Obrigado!\n");
            break;
            
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}

void cadastrarPizza() {
    system ("clear");
    if (numPizzas < 5) {
        printf("====== Cadastrar Pizza ======\n");
        printf("Nome: ");
        scanf(" %[^\n]", pizzas[numPizzas].nome);
        printf("Preço: ");
        scanf("%f", &pizzas[numPizzas].preco);
        
        numPizzas++;
        
        printf("Pizza cadastrada!\n");
        
    }
    
    else {
        printf("Limite de pizzas atingido!\n");
    }
}

void cadastrarCliente() {
    system ("clear");
    if (numClientes < 5) {
        printf("====== Cadastrar Cliente ======\n");
        printf("Nome: ");
        scanf(" %[^\n]", clientes[numClientes].nome);
        printf("Telefone: ");
        scanf(" %[^\n]", clientes[numClientes].telefone);
        numClientes++;
        printf("Cliente cadastrado!\n");
    } else {
        printf("Limite de clientes atingido!\n");
    }
}

void listarPizzas() {
    printf("====== Pizzas Cadastradas ======\n");
    for (int i = 0; i < numPizzas; i++) {
        printf("%d - %s (R$ %.2f)\n", i + 1, pizzas[i].nome, pizzas[i].preco);
    }
}

void listarClientes() {
    printf("====== Clientes Cadastrados ======\n");
    for (int i = 0; i < numClientes; i++) {
        printf("%d - %s (%s)\n", i + 1, clientes[i].nome, clientes[i].telefone);
    }
}

void venderPizza() {
    int clienteI, pizzaI, quantidade;
    float total = 0;
    printf("====== Vender Pizza ======\n");
    printf("Selecione o cliente:\n");
    
    listarClientes();
    
    scanf("%d", &clienteI);
    clienteI--;
    
    if (clienteI >= 0 && clienteI < numClientes) {
        printf("Selecione a pizza:\n");
        
        listarPizzas();
        
        scanf("%d", &pizzaI);
        pizzaI--;
        
        if (pizzaI >= 0 && pizzaI < numPizzas) {
            printf("Quantidade: ");
            scanf("%d", &quantidade);
            
            total = pizzas[pizzaI].preco * quantidade;
            
            printf("Venda realizada com sucesso!\n");
            printf("Cliente: %s\n", clientes[clienteI].nome);
            printf("Pizza: %s\n", pizzas[pizzaI].nome);
            printf("Quantidade: %d\n", quantidade);
            printf("Total: R$ %.2f\n", total);
            
        } else {
            printf("Pizza inválida!\n");
        }
        
    } else {
        printf("Cliente inválido!\n");
    }
}