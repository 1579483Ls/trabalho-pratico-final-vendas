#include "munit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simulação das estruturas do sistema_vendas.c
typedef struct {
    char nome[100];
    int numero;
    float salario_fixo;
    float comissoes;
    int ativo;
} Vendedor;

// Simular array global de vendedores
static Vendedor vendedores_teste[50];
static int num_vendedores_teste = 0;
static int proximo_numero_vendedor_teste = 1;

// Função simulada de busca de vendedor
int buscar_vendedor_por_numero_teste(int numero) {
    for (int i = 0; i < num_vendedores_teste; i++) {
        if (vendedores_teste[i].numero == numero && vendedores_teste[i].ativo) {
            return i;
        }
    }
    return -1;
}

// Função simulada de cadastro de vendedor
int cadastrar_vendedor_teste(int numero, char* nome, float salario) {
    if (num_vendedores_teste >= 50) return 0; // Array cheio
    if (salario <= 0) return 0; // Salário inválido
    if (strlen(nome) == 0) return 0; // Nome vazio
    
    // Verificar duplicidade
    if (numero > 0 && buscar_vendedor_por_numero_teste(numero) >= 0) {
        return -1; // Número duplicado
    }
    
    // Usar código automático se número <= 0
    if (numero <= 0) {
        numero = proximo_numero_vendedor_teste;
        proximo_numero_vendedor_teste++;
    } else {
        // Atualizar próximo número se necessário
        if (numero >= proximo_numero_vendedor_teste) {
            proximo_numero_vendedor_teste = numero + 1;
        }
    }
    
    strcpy(vendedores_teste[num_vendedores_teste].nome, nome);
    vendedores_teste[num_vendedores_teste].numero = numero;
    vendedores_teste[num_vendedores_teste].salario_fixo = salario;
    vendedores_teste[num_vendedores_teste].comissoes = 0.0; // Inicializar em zero
    vendedores_teste[num_vendedores_teste].ativo = 1;
    num_vendedores_teste++;
    
    return 1; // Sucesso
}

// Setup: executado antes de cada teste
static void* vendedor_setup(const MunitParameter params[], void* user_data) {
    // Limpar array de vendedores
    num_vendedores_teste = 0;
    proximo_numero_vendedor_teste = 1;
    memset(vendedores_teste, 0, sizeof(vendedores_teste));
    return NULL;
}

// Teardown: executado após cada teste
static void vendedor_teardown(void* fixture) {
    // Cleanup se necessário
}

// ===== TESTES =====

// V-F-001: Cadastrar Vendedor Código Automático
static MunitResult test_cadastrar_vendedor_automatico(const MunitParameter params[], void* data) {
    int resultado = cadastrar_vendedor_teste(0, "Carlos Vendedor Silva", 2500.00);
    
    munit_assert_int(resultado, ==, 1);
    munit_assert_int(num_vendedores_teste, ==, 1);
    munit_assert_int(vendedores_teste[0].numero, ==, 1);
    munit_assert_string_equal(vendedores_teste[0].nome, "Carlos Vendedor Silva");
    munit_assert_float_equal(vendedores_teste[0].salario_fixo, 2500.00, 2);
    munit_assert_float_equal(vendedores_teste[0].comissoes, 0.0, 2);
    munit_assert_int(vendedores_teste[0].ativo, ==, 1);
    
    return MUNIT_OK;
}

// V-F-002: Cadastrar Vendedor Código Manual
static MunitResult test_cadastrar_vendedor_manual(const MunitParameter params[], void* data) {
    int resultado = cadastrar_vendedor_teste(50, "Ana Vendedora Santos", 3000.00);
    
    munit_assert_int(resultado, ==, 1);
    munit_assert_int(num_vendedores_teste, ==, 1);
    munit_assert_int(vendedores_teste[0].numero, ==, 50);
    munit_assert_string_equal(vendedores_teste[0].nome, "Ana Vendedora Santos");
    munit_assert_float_equal(vendedores_teste[0].salario_fixo, 3000.00, 2);
    munit_assert_int(proximo_numero_vendedor_teste, ==, 51);
    
    return MUNIT_OK;
}

// V-F-003: Validar Número Duplicado
static MunitResult test_validar_numero_duplicado(const MunitParameter params[], void* data) {
    // Primeiro cadastro
    cadastrar_vendedor_teste(1, "Primeiro Vendedor", 2000.00);
    
    // Tentar cadastrar com número duplicado
    int resultado = cadastrar_vendedor_teste(1, "Segundo Vendedor", 2500.00);
    
    munit_assert_int(resultado, ==, -1); // Erro de duplicação
    munit_assert_int(num_vendedores_teste, ==, 1); // Apenas o primeiro foi cadastrado
    
    return MUNIT_OK;
}

// V-F-004: Validar Salário Inválido
static MunitResult test_validar_salario_invalido(const MunitParameter params[], void* data) {
    int resultado = cadastrar_vendedor_teste(1, "Vendedor Teste", 0.0);
    
    munit_assert_int(resultado, ==, 0); // Erro de validação
    munit_assert_int(num_vendedores_teste, ==, 0);
    
    return MUNIT_OK;
}

// V-F-005: Buscar Vendedor Existente
static MunitResult test_buscar_vendedor_existente(const MunitParameter params[], void* data) {
    // Cadastrar vendedor
    cadastrar_vendedor_teste(123, "Vendedor Teste", 2500.00);
    
    // Buscar o vendedor
    int indice = buscar_vendedor_por_numero_teste(123);
    
    munit_assert_int(indice, >=, 0);
    munit_assert_int(vendedores_teste[indice].numero, ==, 123);
    munit_assert_string_equal(vendedores_teste[indice].nome, "Vendedor Teste");
    
    return MUNIT_OK;
}

// V-F-006: Buscar Vendedor Inexistente
static MunitResult test_buscar_vendedor_inexistente(const MunitParameter params[], void* data) {
    int indice = buscar_vendedor_por_numero_teste(999);
    
    munit_assert_int(indice, ==, -1);
    
    return MUNIT_OK;
}

// V-F-007: Nome Vazio
static MunitResult test_nome_vazio(const MunitParameter params[], void* data) {
    int resultado = cadastrar_vendedor_teste(1, "", 2500.00);
    
    munit_assert_int(resultado, ==, 0);
    munit_assert_int(num_vendedores_teste, ==, 0);
    
    return MUNIT_OK;
}

// V-F-008: Múltiplos Cadastros
static MunitResult test_multiplos_cadastros(const MunitParameter params[], void* data) {
    int resultado1 = cadastrar_vendedor_teste(0, "Vendedor 1", 2000.00); // Automático
    int resultado2 = cadastrar_vendedor_teste(0, "Vendedor 2", 2500.00); // Automático
    int resultado3 = cadastrar_vendedor_teste(50, "Vendedor 3", 3000.00); // Manual
    
    munit_assert_int(resultado1, ==, 1);
    munit_assert_int(resultado2, ==, 1);
    munit_assert_int(resultado3, ==, 1);
    munit_assert_int(num_vendedores_teste, ==, 3);
    
    // Verificar números atribuídos
    munit_assert_int(vendedores_teste[0].numero, ==, 1);
    munit_assert_int(vendedores_teste[1].numero, ==, 2);
    munit_assert_int(vendedores_teste[2].numero, ==, 50);
    
    // Verificar próximo número
    munit_assert_int(proximo_numero_vendedor_teste, ==, 51);
    
    return MUNIT_OK;
}

// V-F-009: Inicialização de Comissões
static MunitResult test_inicializacao_comissoes(const MunitParameter params[], void* data) {
    cadastrar_vendedor_teste(1, "Vendedor Teste", 2500.00);
    
    munit_assert_float_equal(vendedores_teste[0].comissoes, 0.0, 2);
    
    return MUNIT_OK;
}

// V-F-010: Limite Máximo
static MunitResult test_limite_maximo(const MunitParameter params[], void* data) {
    // Simular array cheio
    num_vendedores_teste = 50;
    
    int resultado = cadastrar_vendedor_teste(1, "Vendedor Teste", 2500.00);
    
    munit_assert_int(resultado, ==, 0);
    
    return MUNIT_OK;
}

// ===== CONFIGURAÇÃO DOS TESTES =====

static MunitTest vendedor_tests[] = {
    { 
        "/cadastrar_automatico", 
        test_cadastrar_vendedor_automatico, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/cadastrar_manual", 
        test_cadastrar_vendedor_manual, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/numero_duplicado", 
        test_validar_numero_duplicado, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/salario_invalido", 
        test_validar_salario_invalido, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_existente", 
        test_buscar_vendedor_existente, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_inexistente", 
        test_buscar_vendedor_inexistente, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/nome_vazio", 
        test_nome_vazio, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/multiplos_cadastros", 
        test_multiplos_cadastros, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/inicializacao_comissoes", 
        test_inicializacao_comissoes, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/limite_maximo", 
        test_limite_maximo, 
        vendedor_setup, 
        vendedor_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite vendedor_suite = {
    "/vendedores",
    vendedor_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

// Para compilação standalone
#ifdef COMPILE_STANDALONE
int main(int argc, char* argv[]) {
    return munit_suite_main(&vendedor_suite, NULL, argc, argv);
}
#endif
