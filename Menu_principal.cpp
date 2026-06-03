//Menu principal

#include <stdio.h>

void inicializar() {
    for(int i=0;i<ANDARES;i++){
        for(int j=0;j<APTOS;j++){
            hotel[i][j] = '.';
        }
    }
}

int main() {
    int opcao;
    inicializar();

    do {
        printf("\n=== BEM VINDO AO HOTEL ???? ===\n");
        printf("1 - Mostrar mapa\n");
        printf("2 - Reservar\n");
        printf("3 - Check-in\n");
        printf("4 - Check-out\n");
        printf("5 - Cancelar reserva\n");
        printf("6 - Taxas\n");
        printf("7 - Ver apartamento\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d",&opcao);

        switch(opcao) {
            case 1: mostrarMapa(); break;
            case 2: reservar(); break;
            case 3: checkin(); break;
            case 4: checkout(); break;
            case 5: cancelar(); break;
            case 6: taxa(); break;
            case 7: verApto(); break;
        }

    } while(opcao != 0);

    return 0;
}

