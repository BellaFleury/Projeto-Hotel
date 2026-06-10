#include <stdio.h>
#include <string.h>

#define ANDARES 20
#define APTOS 14

typedef struct {
    char nome[50];
    char cpf[20];
    char telefone[20];
    char email[50];
    char endereco[100];
} Hospede;

char hotel[ANDARES][APTOS];
Hospede dados[ANDARES][APTOS];

void inicializar() {
    for(int i = 0; i < ANDARES; i++) {
        for(int j = 0; j < APTOS; j++) {
            hotel[i][j] = '.';

            strcpy(dados[i][j].nome, "");
            strcpy(dados[i][j].cpf, "");
            strcpy(dados[i][j].telefone, "");
            strcpy(dados[i][j].email, "");
            strcpy(dados[i][j].endereco, "");
        }
    }
}

int valido(int andar, int apto) {
    return andar >= 0 && andar < ANDARES &&
           apto >= 0 && apto < APTOS;
}

Hospede cadastrar() {
    Hospede h;

    printf("\n--- DADOS DO HOSPEDE ---\n");

    printf("Nome: ");
    scanf(" %[^\n]", h.nome);

    printf("CPF: ");
    scanf("%s", h.cpf);

    printf("Telefone: ");
    scanf("%s", h.telefone);

    printf("Email: ");
    scanf("%s", h.email);

    printf("Endereco: ");
    scanf(" %[^\n]", h.endereco);

    return h;
}

void mostrarMapa() {
    printf("\n      ");

    for(int j = 1; j <= APTOS; j++) {
        printf("%2d ", j);
    }

    printf("\n");

    for(int i = ANDARES - 1; i >= 0; i--) {
        printf("Andar %2d ", i + 1);

        for(int j = 0; j < APTOS; j++) {
            printf(" %c ", hotel[i][j]);
        }

        printf("\n");
    }

    printf("\nR = Reservado\n");
    printf("O = Ocupado\n");
    printf(". = Livre\n");
}

void reservar() {
    int andar, apto;

    printf("Andar: ");
    scanf("%d", &andar);

    printf("Apartamento: ");
    scanf("%d", &apto);

    andar--;
    apto--;

    if(!valido(andar, apto)) {
        printf("Apartamento invalido!\n");
        return;
    }

    if(hotel[andar][apto] == '.') {
        hotel[andar][apto] = 'R';
        printf("Reserva realizada com sucesso!\n");
    }
    else {
        printf("Apartamento indisponivel!\n");
    }
}

void checkin() {
    int andar, apto;

    printf("Andar: ");
    scanf("%d", &andar);

    printf("Apartamento: ");
    scanf("%d", &apto);

    andar--;
    apto--;

    if(!valido(andar, apto)) {
        printf("Apartamento invalido!\n");
        return;
    }

    if(hotel[andar][apto] == '.' || hotel[andar][apto] == 'R') {

        dados[andar][apto] = cadastrar();

        hotel[andar][apto] = 'O';

        printf("Check-in realizado com sucesso!\n");
    }
    else {
        printf("Apartamento ja ocupado!\n");
    }
}

void checkout() {
    int andar, apto;

    printf("Andar: ");
    scanf("%d", &andar);

    printf("Apartamento: ");
    scanf("%d", &apto);

    andar--;
    apto--;

    if(!valido(andar, apto)) {
        printf("Apartamento invalido!\n");
        return;
    }

    if(hotel[andar][apto] == 'O') {

        hotel[andar][apto] = '.';

        strcpy(dados[andar][apto].nome, "");
        strcpy(dados[andar][apto].cpf, "");
        strcpy(dados[andar][apto].telefone, "");
        strcpy(dados[andar][apto].email, "");
        strcpy(dados[andar][apto].endereco, "");

        printf("Check-out realizado!\n");
    }
    else {
        printf("Apartamento nao ocupado!\n");
    }
}

void cancelar() {
    int andar, apto;

    printf("Andar: ");
    scanf("%d", &andar);

    printf("Apartamento: ");
    scanf("%d", &apto);

    andar--;
    apto--;

    if(!valido(andar, apto)) {
        printf("Apartamento invalido!\n");
        return;
    }

    if(hotel[andar][apto] == 'R') {
        hotel[andar][apto] = '.';
        printf("Reserva cancelada!\n");
    }
    else {
        printf("Nao existe reserva nesse apartamento!\n");
    }
}

void taxa() {
    int ocupados = 0;
    int reservados = 0;

    for(int i = 0; i < ANDARES; i++) {
        for(int j = 0; j < APTOS; j++) {

            if(hotel[i][j] == 'O')
                ocupados++;

            if(hotel[i][j] == 'R')
                reservados++;
        }
    }

    printf("\nTaxa de ocupacao: %.2f%%\n",
           (ocupados * 100.0) / (ANDARES * APTOS));

    printf("Taxa de reservas: %.2f%%\n",
           (reservados * 100.0) / (ANDARES * APTOS));
}

void verApto() {
    int andar, apto;

    printf("Andar: ");
    scanf("%d", &andar);

    printf("Apartamento: ");
    scanf("%d", &apto);

    andar--;
    apto--;

    if(!valido(andar, apto)) {
        printf("Apartamento invalido!\n");
        return;
    }

    printf("Status: %c\n", hotel[andar][apto]);

    if(hotel[andar][apto] == 'O') {

        printf("\n--- DADOS DO HOSPEDE ---\n");

        printf("Nome: %s\n", dados[andar][apto].nome);
        printf("CPF: %s\n", dados[andar][apto].cpf);
        printf("Telefone: %s\n", dados[andar][apto].telefone);
        printf("Email: %s\n", dados[andar][apto].email);
        printf("Endereco: %s\n", dados[andar][apto].endereco);
    }
}

int main() {

    int opcao;

    inicializar();

    do {

        printf("\n=== SISTEMA DE HOTEL ===\n");
        printf("1 - Mostrar mapa\n");
        printf("2 - Reservar apartamento\n");
        printf("3 - Check-in\n");
        printf("4 - Check-out\n");
        printf("5 - Cancelar reserva\n");
        printf("6 - Taxas de ocupacao\n");
        printf("7 - Ver apartamento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                mostrarMapa();
                break;

            case 2:
                reservar();
                break;

            case 3:
                checkin();
                break;

            case 4:
                checkout();
                break;

            case 5:
                cancelar();
                break;

            case 6:
                taxa();
                break;

            case 7:
                verApto();
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
