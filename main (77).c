#include <stdio.h>
#include <stdlib.h>

struct CD {
    char banda[50];
    int genero;
    int ano;
    int disponivel;
};

struct CD CDS[100];
int totalcds = 0;

void CadastrarCd ();
void PesquisarCd ();
void ConsultarCd ();
void VenderCd ();
void FinalizarFuncao ();

int main (){
    int opcao;
    do{
        printf ("====== loja Som e Arte ======\n");
        printf ("Escolha uma opção:\n");
        printf ("1- Cadastrar CD\n");
        printf ("2- Pesquisar CD\n");
        printf ("3- Consultar CD\n");
        printf ("4- Vender CD\n");
        printf ("0- Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao){
            case 1:
                CadastrarCd ();
                FinalizarFuncao ();
                break;
                
            case 2:
                PesquisarCd();
                FinalizarFuncao ();
                break;
                
            case 3:
                ConsultarCd();
                FinalizarFuncao();
                break;
                
            case 4:
                VenderCd();
                FinalizarFuncao();
                break;
                
            case 0:
                printf ("Obrigado(a) pela preferencia!\n");
                printf ("Saindo...\n");
                break;
                
            default :
                printf ("Opção inválida! Tente novamente!\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}

void CadastrarCd (){
    printf("Digite o nome da banda: \n");
    scanf(" %[^\n]",CDS[totalcds].banda);
    printf("Digite o gênero do CD: \n");
    printf ("1- Modão, 2- Sertanejo, 3- MPB, 4- Pagode, 5- Eletronica\n");
    scanf(" %d",&CDS[totalcds].genero);
    printf("Digite o ano do CD: \n");
    scanf("%d",&CDS[totalcds].ano);
    
    CDS[totalcds].disponivel = 1;
    totalcds++;
    printf("CD cadastrado com sucesso!\n");
}

void PesquisarCd (){
  int genero;
int encontrado = 0;

    printf("Escolha o gênero:\n");
    printf("1- Modão\n");
    printf("2- Sertanejo\n");
    printf("3- MPB\n");
    printf("4- Pagode\n");
    printf("5- Eletronica\n");
    scanf("%d", &genero);
    
    for (int i = 0; i < totalcds; i++) {
        
        if (CDS[i].genero == genero) {
            printf("Nome da banda: %s\n", CDS[i].banda);
            switch (genero){
                case 1:
                printf ("Genereo: Modão\n");
                break;
                
                case 2:
                printf ("Genero: Sertanejo\n");
                break;
                
                case 3:
                printf ("Genero: MPB \n");
                break;
                
                case 4:
                printf ("Genero: Pagode\n");
                break;
                
                case 5:
                printf ("Genero: Eletronica\n");
                break;
            }
            printf("Ano: %d\n", CDS[i].ano);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Não temos CDs desse gênero\n");
    }
} 

void ConsultarCd (){
    char banda[50];
    printf("Digite o nome da banda: \n");
    scanf(" %[^\n]", banda);
    
    for (int i = 0; i < totalcds; i++) {
        
        if (CDS[i].banda[0] == banda[0]) {
            if (CDS[i].disponivel == 1) {
                printf("CD disponível!\n");
            } else {
                printf("CD não está disponível!\n");
            }
            return;
        }
    }
    printf("CD não encontrado!\n");
}

void VenderCd(){
    char banda[50];
    
    printf("Digite o nome da banda: \n");
    scanf(" %[^\n]", banda);
    
    for (int i = 0; i < totalcds; i++) {
        
        if (CDS[i].banda[0] == banda[0]) {
            if (CDS[i].disponivel == 1) {
                printf("CD encontrado! Venda realizada com sucesso!\n");
                
                for (int j = i; j < totalcds - 1; j++) { //for dentro de for usa j
                    CDS[j] = CDS[j + 1];
                }
                totalcds--;
                return;
                
            } else {
                printf("CD não está disponível!\n");
                return;
            }
        }
    }
    printf("CD não encontrado!\n");
}


void FinalizarFuncao (){
    printf ("\nEnter para Continuar....\n");
    getchar ();
    getchar ();
    system ("clear");
}