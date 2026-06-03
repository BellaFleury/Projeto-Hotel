#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cpf[20];
    char telefone[20];
    char email[50];
    char endereco[100];
} Hospede;

int main() {
    int linhas, colunas;
    long long cpf, tel;

    char nome[100];
    char endereco[200];
    char email[100];

    printf("----Dados do check-in----\n");
    printf("Digite sua reserva (andar e quarto): ");
    scanf("%d %d", &linhas, &colunas);
    printf("CPF: ");
    scanf("%lld", &cpf);
    printf("Nome: ");
    scanf(" %[^\n]", nome);
    printf("Seu endereco completo:");
    scanf(" %[^\n]", endereco);
    printf("Telefone para contato:");
    scanf("%lld", &tel);
    printf("Email:");
    scanf("%s", email);
    
    
    
    
    
    
    

    return 0;
}
