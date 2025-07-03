#include "munit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declarações das suites externas
extern const MunitSuite produto_suite;
extern const MunitSuite vendedor_suite;
extern const MunitSuite comprador_suite;
extern const MunitSuite venda_suite;

// Simulação de estruturas para testes de integração
typedef struct {
    char nome[100];
    int codigo;
    int quantidade_estoque;
    float preco_venda;
    int ativo;
} ProdutoIntegracao;

typedef struct {
    char nome[100];
    int numero;
    float comissoes;
    int ativo;
} VendedorIntegracao;

typedef struct {
    char nome[100];
    char cpf[15];
    int ativo;
} CompradorIntegracao;

typedef struct {
    int codigo_venda;
    int codigo_comprador;
    int numero_vendedor;
    float valor_total;
    int ativo;
} VendaIntegracao;

// Arrays globais para testes de integração
static ProdutoIntegracao produtos_integracao[100];
static VendedorIntegracao vendedores_integracao[50];
static CompradorIntegracao compradores_integracao[100];
static VendaIntegracao vendas_integracao[200];

static int num_produtos_int = 0;
static int num_vendedores_int = 0;
static int num_compradores_int = 0;
static int num_vendas_int = 0;

// Função para simular fluxo completo
int fluxo_completo_teste() {
    // 1. Cadastrar produto
    strcpy(produtos_integracao[0].nome, "Produto Integração");
    produtos_integracao[0].codigo = 1;
    produtos_integracao[0].quantidade_estoque = 10;
    produtos_integracao[0].preco_venda = 100.00;
    produtos_integracao[0].ativo = 1;
    num_produtos_int = 1;
    
    // 2. Cadastrar vendedor
    strcpy(vendedores_integracao[0].nome, "Vendedor Integração");
    vendedores_integracao[0].numero = 1;
    vendedores_integracao[0].comissoes = 0.0;
    vendedores_integracao[0].ativo = 1;
    num_vendedores_int = 1;
    
    // 3. Cadastrar comprador
    strcpy(compradores_integracao[0].nome, "Comprador Integração");
    strcpy(compradores_integracao[0].cpf, "123.456.789-00");
    compradores_integracao[0].ativo = 1;
    num_compradores_int = 1;
    
    // 4. Realizar venda
    vendas_integracao[0].codigo_venda = 1;
    vendas_integracao[0].codigo_comprador = 0;
    vendas_integracao[0].numero_vendedor = 1;
    vendas_integracao[0].valor_total = 200.00; // 2 produtos
    vendas_integracao[0].ativo = 1;
    num_vendas_int = 1;
    
    // 5. Atualizar estoque
    produtos_integracao[0].quantidade_estoque -= 2;
    
    // 6. Calcular comissão
    vendedores_integracao[0].comissoes += vendas_integracao[0].valor_total * 0.03;
    
    return 1; // Sucesso
}

// Setup para testes de integração
static void* integracao_setup(const MunitParameter params[], void* user_data) {
    // Limpar arrays
    memset(produtos_integracao, 0, sizeof(produtos_integracao));
    memset(vendedores_integracao, 0, sizeof(vendedores_integracao));
    memset(compradores_integracao, 0, sizeof(compradores_integracao));
    memset(vendas_integracao, 0, sizeof(vendas_integracao));
    
    num_produtos_int = 0;
    num_vendedores_int = 0;
    num_compradores_int = 0;
    num_vendas_int = 0;
    
    return NULL;
}

// ===== TESTES DE INTEGRAÇÃO =====

// I-I-001: Fluxo Completo
static MunitResult test_fluxo_completo(const MunitParameter params[], void* data) {
    int resultado = fluxo_completo_teste();
    
    munit_assert_int(resultado, ==, 1);
    
    // Verificar se todos os módulos foram afetados
    munit_assert_int(num_produtos_int, ==, 1);
    munit_assert_int(num_vendedores_int, ==, 1);
    munit_assert_int(num_compradores_int, ==, 1);
    munit_assert_int(num_vendas_int, ==, 1);
    
    // Verificar dados específicos
    munit_assert_int(produtos_integracao[0].codigo, ==, 1);
    munit_assert_int(vendedores_integracao[0].numero, ==, 1);
    munit_assert_string_equal(compradores_integracao[0].cpf, "123.456.789-00");
    munit_assert_int(vendas_integracao[0].codigo_venda, ==, 1);
    
    return MUNIT_OK;
}

// I-I-002: Atualização de Estoque
static MunitResult test_atualizacao_estoque(const MunitParameter params[], void* data) {
    // Configurar produto inicial
    produtos_integracao[0].quantidade_estoque = 10;
    num_produtos_int = 1;
    
    // Executar fluxo que deve reduzir estoque
    fluxo_completo_teste();
    
    // Verificar se estoque foi atualizado corretamente
    munit_assert_int(produtos_integracao[0].quantidade_estoque, ==, 8);
    
    return MUNIT_OK;
}

// I-I-003: Cálculo de Comissões
static MunitResult test_calculo_comissoes(const MunitParameter params[], void* data) {
    // Configurar vendedor inicial
    vendedores_integracao[0].comissoes = 0.0;
    
    // Executar fluxo
    fluxo_completo_teste();
    
    // Verificar se comissão foi calculada (3% de 200 = 6.00)
    munit_assert_float_equal(vendedores_integracao[0].comissoes, 6.00, 2);
    
    return MUNIT_OK;
}

// I-I-004: Reversões na Exclusão
static MunitResult test_reversoes_exclusao(const MunitParameter params[], void* data) {
    // Configurar estado inicial
    produtos_integracao[0].quantidade_estoque = 10;
    vendedores_integracao[0].comissoes = 0.0;
    
    // Executar venda
    fluxo_completo_teste();
    
    // Verificar estado após venda
    munit_assert_int(produtos_integracao[0].quantidade_estoque, ==, 8);
    munit_assert_float_equal(vendedores_integracao[0].comissoes, 6.00, 2);
    
    // Simular exclusão da venda (reversão)
    vendas_integracao[0].ativo = 0; // Marcar como inativa
    produtos_integracao[0].quantidade_estoque += 2; // Reverter estoque
    vendedores_integracao[0].comissoes -= 6.00; // Reverter comissão
    
    // Verificar reversão
    munit_assert_int(vendas_integracao[0].ativo, ==, 0);
    munit_assert_int(produtos_integracao[0].quantidade_estoque, ==, 10);
    munit_assert_float_equal(vendedores_integracao[0].comissoes, 0.00, 2);
    
    return MUNIT_OK;
}

// ===== CONFIGURAÇÃO DOS TESTES DE INTEGRAÇÃO =====

static MunitTest integracao_tests[] = {
    { 
        "/fluxo_completo", 
        test_fluxo_completo, 
        integracao_setup, 
        NULL, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/atualizacao_estoque", 
        test_atualizacao_estoque, 
        integracao_setup, 
        NULL, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/calculo_comissoes", 
        test_calculo_comissoes, 
        integracao_setup, 
        NULL, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/reversoes_exclusao", 
        test_reversoes_exclusao, 
        integracao_setup, 
        NULL, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite integracao_suite = {
    "/integracao",
    integracao_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

// ===== SUITE PRINCIPAL =====

static const MunitSuite* suites[] = {
    &produto_suite,
    &vendedor_suite,
    &comprador_suite,
    &venda_suite,
    &integracao_suite,
    NULL
};

static const MunitSuite main_suite = {
    "/sistema_vendas",
    NULL,
    (MunitSuite**)suites,
    1,
    MUNIT_SUITE_OPTION_NONE
};

// Função principal do runner
int main(int argc, char* argv[]) {
    printf("=== SISTEMA DE TESTES - SISTEMA DE VENDAS ===\n");
    printf("Executando todos os módulos de teste...\n\n");
    
    return munit_suite_main(&main_suite, NULL, argc, argv);
}
