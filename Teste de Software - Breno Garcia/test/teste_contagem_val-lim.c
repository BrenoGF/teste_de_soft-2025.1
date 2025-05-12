//Chamada das bibliotecas
#include "./minunit-master/minunit.h"
#include "../src/funcoes.h"

/* Limites:
    0- pessoas: retorna 0
    1-5 pessoas: retorna o mesmo numero
    6+ pessoas: retorna 0
*/

// Teste 1: Verifica se o erro abaixo de 1 está funcionando
MU_TEST(test_undershot_max) {
    double quant = contagem(0);
    mu_assert_double_eq(0, quant); // Espera-se 0 (falso) como retorno
}

// Teste 2: Verifica se o retorno ocorre no minimo "correto"
MU_TEST(test_calculo_normal_min) {
    double quant = contagem(1);
    mu_assert_double_eq(1, quant); // O esperado é 1
}

// Teste 3: Verifica se o retorno ocorre no maximo "correto"
MU_TEST(test_calculo_normal_max) {
    double quant = contagem(5);
    mu_assert_double_eq(5, quant); // O esperado é 5
}

// Teste 4: Verifica se o erro acima de 5 está funcionando
MU_TEST(test_overshot_min) {
    double quant = contagem(6);
    mu_assert_double_eq(0, quant); // Espera-se 0 (falso) como retorno
}

// Conjunto de Testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_undershot_max);
    MU_RUN_TEST(test_calculo_normal_min);
    MU_RUN_TEST(test_calculo_normal_max);
    MU_RUN_TEST(test_overshot_min);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}