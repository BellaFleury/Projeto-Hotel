#include <stdio.h>

int main() 
{
    int linhas = 21, colunas = 15;
    char matriz[21][15];
    int l, c;
    char status;

    // Preencher com '.'
    for(int i = 1; i < linhas; i++) 
    {
        for(int j = 1; j < colunas; j++) 
        {
            matriz[i][j] = '.';
        }
    }

    while(1) 
    {
        // Mostrar cabeçalho
        printf("\n    ");
        for(int j = 1; j < colunas; j++)
            printf("%2d ", j);

        printf("\n");

        // Mostrar matriz
        for(int i = linhas-1; i > 0; i--) 
        {
            printf("%2d  ", i);

            for(int j = 1; j < colunas; j++) 
            {
                printf(" %c ", matriz[i][j]);
            }

            printf("\n");
        }

        // Entrada
        printf("\nDigite o andar e quarto (-1 para sair): ");
        scanf("%d", &l);

        if(l == -1)
            break;

        scanf("%d", &c);

        if(c == -1)
            break;

        // Escolher status
        printf("Digite R para reservado ou O para ocupado: ");
        scanf(" %c", &status);

        // Validação
        if(l > 0 && l < linhas && c > 0 && c < colunas) 
        {
            if(status == 'R' || status == 'r')
            {
                matriz[l][c] = 'R';
            }
            else if(status == 'O' || status == 'o')
            {
                matriz[l][c] = 'O';
            }
            else
            {
                printf("Status     invalido!\n");
            }
        } 
        else 
        {
            printf("Coordenadas invalidas!\n");
        }
    }

    return 0;
}
