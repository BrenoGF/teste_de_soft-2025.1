#include <stdio.h>
#include "./funcoes.h"

int main()
{
    int idade[5], quantidade = 0, total = 0;

    while(!quantidade) {
        printf("Insira a quantidade de ingressos: ");
        scanf("%i", &quantidade);
        quantidade = contagem(quantidade);
        if (!quantidade) {
            printf("Erro! Quantidade invalidada: Insira de 1 a 5 pessoa(s)\n");
        }
    }

    printf("Aviso: idosos acima de 100 anos não podem entrar.\nInsira a(s) idade(s):\n");
    for (int i = 0; i < quantidade; ++i) {
        printf("Pessoa %i: ", i+1);
        scanf("%i", &idade[i]);
    }

    for(int i = 0; i < quantidade; ++i) {
        total += price(idade[i]);
    }

    printf("Custo total: %i", total);
    int i = 0;
    scanf("%i", &i);
}
