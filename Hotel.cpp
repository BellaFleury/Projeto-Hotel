#include <stdio.h>
#include <string.h>

#define ANDARES 20
#define APTOS 14

// Estrutura do hóspede
typedef struct {
    char nome[50];
    char cpf[20];
    char telefone[20];
    char email[50];
    char endereco[100];
} Hospede;

// Matrizes do hotel
char hotel[ANDARES][APTOS];
Hospede dados[ANDARES][APTOS];

// Inicializar hotel
void inicializar() {
    for(int i=0;i<ANDARES;i++){
        for(int j=0;j<APTOS;j++){
            hotel[i][j] = '.';
        }
    }
}

// Mostrar mapa (REQ01)
void mostrarMapa() {
    printf("\nMAPA DO HOTEL\n\n");
    for(int i=0;i<ANDARES;i++) {
        printf("Andar %2d: ", ANDARES - i);
        for(int j=0;j<APTOS;j++) {
            printf("%c ", hotel[i][j]);
        }
        printf("\n");
    }
}

// Reservar (REQ02)
void reservar() {
    int andar, apto;
    printf("Andar (1-20): ");
    scanf("%d",&andar);
    printf("Apto (1-14): ");
    scanf("%d",&apto);

    andar--; apto--;

    if(hotel[andar][apto] == '.') {
        hotel[andar][apto] = 'R';
        printf("Reserva realizada!\n");
    } else {
        printf("Apartamento indisponivel!\n");
    }
}

// Cadastrar hóspede (REQ08)
Hospede cadastrar() {
    Hospede h;
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

// Check-in (REQ03 e REQ04)
void checkin() {
    int andar, apto;
    printf("Andar: ");
    scanf("%d",&andar);
    printf("Apto: ");
    scanf("%d",&apto);

    andar--; apto--;

    if(hotel[andar][apto] == '.' || hotel[andar][apto]=='R') {
        hotel[andar][apto] = 'O';
        dados[andar][apto] = cadastrar();
        printf("Check-in realizado!\n");
    } else {
        printf("Nao disponivel!\n");
    }
}

// Check-out (REQ05)
void checkout() {
    int andar, apto;
    printf("Andar: ");
    scanf("%d",&andar);
    printf("Apto: ");
    scanf("%d",&apto);

    andar--; apto--;

    if(hotel[andar][apto] == 'O') {
        hotel[andar][apto] = '.';
        printf("Check-out feito!\n");
    } else {
        printf("Apartamento nao ocupado!\n");
    }
}

// Cancelar reserva (REQ06)
void cancelar() {
    int andar, apto;
    printf("Andar: ");
    scanf("%d",&andar);
    printf("Apto: ");
    scanf("%d",&apto);

    andar--; apto--;

    if(hotel[andar][apto] == 'R') {
        hotel[andar][apto] = '.';
        printf("Reserva cancelada!\n");
    } else {
        printf("Nao ha reserva!\n");
    }
}

// Taxas (REQ07)
void taxa() {
    int ocupados=0, reservados=0;

    for(int i=0;i<ANDARES;i++){
        for(int j=0;j<APTOS;j++){
            if(hotel[i][j]=='O') ocupados++;
            if(hotel[i][j]=='R') reservados++;
        }
    }

    printf("Ocupacao: %.2f%%\n", (ocupados/280.0)*100);
    printf("Reservas: %.2f%%\n", (reservados/280.0)*100);
}

// Ver apartamento (REQ09)
void verApto() {
    int andar, apto;
    printf("Andar: ");
    scanf("%d",&andar);
    printf("Apto: ");
    scanf("%d",&apto);

    andar--; apto--;

    printf("Status: %c\n", hotel[andar][apto]);

    if(hotel[andar][apto]=='O') {
        printf("Nome: %s\n", dados[andar][apto].nome);
        printf("CPF: %s\n", dados[andar][apto].cpf);
        printf("Telefone: %s\n", dados[andar][apto].telefone);
        printf("Email: %s\n", dados[andar][apto].email);
        printf("Endereco: %s\n", dados[andar][apto].endereco);
    }
}

// Menu principal
int main() {
    int op;
    inicializar();

    do {
        printf("\n=== HOTEL ===\n");
        printf("1 - Mostrar mapa\n");
        printf("2 - Reservar\n");
        printf("3 - Check-in\n");
        printf("4 - Check-out\n");
        printf("5 - Cancelar reserva\n");
        printf("6 - Taxas\n");
        printf("7 - Ver apartamento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&op);

        switch(op) {
            case 1: mostrarMapa(); break;
            case 2: reservar(); break;
            case 3: checkin(); break;
            case 4: checkout(); break;
            case 5: cancelar(); break;
            case 6: taxa(); break;
            case 7: verApto(); break;
        }

    } while(op != 0);

    return 0;
}

