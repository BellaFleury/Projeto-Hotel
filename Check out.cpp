void checkout(Hospede hotel[ANDARES][QUARTOS]) {
    int andar, quarto;

    printf("\n---- CHECK-OUT ----\n");
    printf("Digite o andar e o quarto: ");
    scanf("%d %d", &andar, &quarto);

    andar--;
    quarto--;

    if(strlen(hotel[andar][quarto].cpf) == 0) {
        printf("Apartamento ja esta livre!\n");
        return;
    }

    strcpy(hotel[andar][quarto].nome, "");
    strcpy(hotel[andar][quarto].cpf, "");
    strcpy(hotel[andar][quarto].telefone, "");
    strcpy(hotel[andar][quarto].email, "");
    strcpy(hotel[andar][quarto].endereco, "");

    printf("Checkout realizado com sucesso!\n");
    printf("Apartamento liberado!\n");
}
