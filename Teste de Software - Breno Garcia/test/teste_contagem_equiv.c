//Chamada das bibliotecas
#include "minunit-master/minunit.h"
#include "../src/funcoes.h"

/* Limites:
    0- pessoas: retorna 0
    1-5 pessoas: retorna o mesmo numero
    6+ pessoas: retorna 0
*/


// Teste 1: Verifica se o retorno ocorre normalmente
MU_TEST(test_calculo_normal) {
    double quant = contagem(3);
    mu_assert_double_eq(3, quant); // O esperado é 3
}

// Teste 2: Verifica se o erro abaixo de 1 está funcionando
MU_TEST(test_undershot) {
    double quant = contagem(-1);
    mu_assert_double_eq(0, quant); // Espera-se 0 (falso) como retorno
}

// Teste 3: Verifica se o erro acima de 5 está funcionando
MU_TEST(test_overshot) {
    double quant = contagem(7);
    mu_assert_double_eq(0, quant); // Espera-se 0 (falso) como retorno
}

// Conjunto de Testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_undershot);
    MU_RUN_TEST(test_calculo_normal);
    MU_RUN_TEST(test_overshot);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}