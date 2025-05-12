#include <stdio.h>
int price(int const idade) {
    if (idade < 0 || idade > 100) {
        printf("%i é invalido.\n", idade);
        return 0;
    }
    if (idade <= 12) {
        printf("Que tem %i, logo paga 10\n", idade);
        return 10; // Menor de 12-
    } else if (idade >= 60) {
        printf("Que tem %i, logo paga 15\n", idade);
        return 15; // Idoso de 60+
    } else {
        printf("Que tem %i, logo paga 30\n", idade);
        return 30; // Todos 13-59
    }
} // Referencia para alterar o valor do original

/* Limites:
    10 reais: 0-12
    30 reais: 13-59
    15 reais: 60-100
    Invalidos fora dos 3 escopos anteriores: 0 reais
*/

int contagem(int const quantidade) {
    if(quantidade > 5 || quantidade < 1)
        return 0;
    else
        return quantidade;
}

/* Limites:
    0- pessoas: retorna 0
    1-5 pessoas: retorna o mesmo numero
    6+ pessoas: retorna 0
*/