//Chamada das bibliotecas
#include "minunit-master/minunit.h"
#include "../src/funcoes.h"

/* Limites:
    10 reais: 0-12
    30 reais: 13-59
    15 reais: 60-100
    Invalidos fora dos 3 escopos anteriores: 0 reais
*/


// Teste 1: Verifica se o erro abaixo de 0 está funcionando
MU_TEST(test_undershot_max) 
{
    double preco = price(-1);
    mu_assert_double_eq(0, preco); // Espera-se 0 (falso) como retorno
}

// Teste 2: Verifica se crianças no minimo pagam 10
MU_TEST(test_menor_min) 
{
    double preco = price(0);
    mu_assert_double_eq(10, preco); // Espera-se 10 como retorno
}

// Teste 3: Verifica se crianças no maximo pagam 10
MU_TEST(test_menor_max) 
{
    double preco = price(12);
    mu_assert_double_eq(10, preco); // Espera-se 10 como retorno
}

// Teste 4: Verifica se os "grandes" no minimo pagam inteiro
MU_TEST(test_inteiro_min) 
{
    double preco = price(13);
    mu_assert_double_eq(30, preco); // Espera-se 30 como retorno
}

// Teste 5: Verifica se os "grandes" no maximo pagam inteiro
MU_TEST(test_inteiro_max) 
{
    double preco = price(59);
    mu_assert_double_eq(30, preco); // Espera-se 30 como retorno
}

// Teste 6: Verifica se Idosos no minimo pagam 15
MU_TEST(test_idoso_min) 
{
    double preco = price(60);
    mu_assert_double_eq(15, preco); // Espera-se 15 como retorno
}

// Teste 7: Verifica se Idosos no maximo pagam 15
MU_TEST(test_idoso_max) 
{
    double preco = price(100);
    mu_assert_double_eq(15, preco); // Espera-se 15 como retorno
}

// Teste 8: Verifica se o erro de 101+ está funcionando
MU_TEST(test_overshot_min) 
{
    double quant = price(101);
    mu_assert_double_eq(0, quant); // Espera-se 0 (falso) como retorno
}

// Conjunto de Testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_undershot_max);
    MU_RUN_TEST(test_menor_min);
    MU_RUN_TEST(test_menor_max);
    MU_RUN_TEST(test_inteiro_min);
    MU_RUN_TEST(test_inteiro_max);
    MU_RUN_TEST(test_idoso_min);
    MU_RUN_TEST(test_idoso_max);
    MU_RUN_TEST(test_overshot_min);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}