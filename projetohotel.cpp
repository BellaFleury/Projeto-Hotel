#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Adicionado para usar o comando system()

#define ANDARES 20
#define APTOS 14

typedef struct {
    char nome[50];
    char cpf[20];
    char telefone[20];
    char email[50];
    char endereco[100];
    int reserva; 
} Hospede;

char hotel[ANDARES][APTOS];
Hospede dados[ANDARES][APTOS];

// Função para limpar o terminal de forma multiplataforma
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para pausar a tela, pedir Enter e limpar depois
void aguardarEnter() {
    printf("\nPressione Enter para sair deste menu...");
    
    // Limpa o buffer de entrada para consumir o '\n' deixado pelos scanfs anteriores
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // Aguarda o próximo Enter do usuário
    getchar(); 
    limparTela();
}

void inicializar() {
    for(int i = 0; i < ANDARES; i++) {
        for(int j = 0; j < APTOS; j++) {
            hotel[i][j] = '.';

            strcpy(dados[i][j].nome, "");
            strcpy(dados[i][j].cpf, "");
            strcpy(dados[i][j].telefone, "");
            strcpy(dados[i][j].email, "");
            strcpy(dados[i][j].endereco, "");
            dados[i][j].reserva = 0;
        }
    }
}

int valido(int andar, int apto) {
    return andar >= 0 && andar < ANDARES &&
           apto >= 0 && apto < APTOS;
}

Hospede cadastrar(int andar, int apto) {
    Hospede h;

    h.reserva = (andar * 100) + apto;

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

    printf("\n>>> Cadastro finalizado! Numero da Reserva: %03d <<<\n", h.reserva);

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

    int andar_original = andar;
    int apto_original = apto;

    andar--;
    apto--;

    if(!valido(andar, apto)) {
        printf("Apartamento invalido!\n");
        return;
    }

    if(hotel[andar][apto] == '.' || hotel[andar][apto] == 'R') {

        if(hotel[andar][apto] == 'R') {
            int num_reserva_digitado;
            printf("Este apartamento esta reservado. Digite o numero da reserva: ");
            scanf("%d", &num_reserva_digitado);

            int num_reserva_esperado = (andar_original * 100) + apto_original;

            if(num_reserva_digitado != num_reserva_esperado) {
                printf("Numero de reserva incorreto! Check-in invalido.\n");
                return;
            }
        }

        dados[andar][apto] = cadastrar(andar_original, apto_original);

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
        dados[andar][apto].reserva = 0; 

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
        printf("Codigo da Reserva: %03d\n", dados[andar][apto].reserva); 
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
    limparTela(); // Garante que o sistema comece com a tela limpa

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
                limparTela();
                mostrarMapa();
                aguardarEnter();
                break;

            case 2:
                limparTela();
                reservar();
                aguardarEnter();
                break;

            case 3:
                limparTela();
                checkin();
                aguardarEnter();
                break;

            case 4:
                limparTela();
                checkout();
                aguardarEnter();
                break;

            case 5:
                limparTela();
                cancelar();
                aguardarEnter();
                break;

            case 6:
                limparTela();
                taxa();
                aguardarEnter();
                break;

            case 7:
                limparTela();
                verApto();
                aguardarEnter();
                break;

            case 0:
                limparTela();
                printf("Encerrando sistema...\n");
                break;

            default:
                limparTela();
                printf("Opcao invalida!\n");
                aguardarEnter();
        }

    } while(opcao != 0);

    return 0;
}
