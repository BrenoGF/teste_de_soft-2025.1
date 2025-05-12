//Chamada das bibliotecas
#include "minunit-master/minunit.h"
#include "../src/funcoes.h"

/* Limites:
    10 reais: 0-12
    30 reais: 13-59
    15 reais: 60-100
    Invalidos fora dos 3 escopos anteriores: 0 reais
*/


// Teste 1: Verifica se o erro abaixo de 1 está funcionando
MU_TEST(test_undershot) 
{
    double preco = price(-5);
    mu_assert_double_eq(0, preco); // Espera-se 0 (falso) como retorno
}

// Teste 2: Verifica se crianças pagam 10
MU_TEST(test_menor) 
{
    double preco = price(7);
    mu_assert_double_eq(10, preco); // Espera-se 10 como retorno
}

// Teste 3: Verifica se os "grandes" pagam inteiro
MU_TEST(test_inteiro) 
{
    double preco = price(30);
    mu_assert_double_eq(30, preco); // Espera-se 30 como retorno
}

// Teste 4: Verifica se Idosos sub-100 pagam 15
MU_TEST(test_idoso) 
{
    double preco = price(70);
    mu_assert_double_eq(15, preco); // Espera-se 15 como retorno
}

// Teste 5: Verifica se o erro acima de 100 está funcionando
MU_TEST(test_overshot) 
{
    double quant = price(111);
    mu_assert_double_eq(0, quant); // Espera-se 0 (falso) como retorno
}

// Conjunto de Testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_undershot);
    MU_RUN_TEST(test_menor);
    MU_RUN_TEST(test_inteiro);
    MU_RUN_TEST(test_idoso);
    MU_RUN_TEST(test_overshot);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}