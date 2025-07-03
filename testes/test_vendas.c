#include "munit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simulação das estruturas do sistema_vendas.c
typedef struct {
    char nome_produto[100];
    int codigo_produto;
    int quantidade;
    float preco_unitario;
    float preco_total;
} ItemVenda;

typedef struct {
    int codigo_venda;
    int codigo_comprador; // Índice do comprador
    int numero_vendedor;  // Número do vendedor
    ItemVenda itens[20];
    int num_itens;
    float valor_total;
    int ativo;
} Venda;

// Arrays simulados para dependências
typedef struct {
    char nome[100];
    char cpf[15];
    int ativo;
} CompradorSimples;

typedef struct {
    char nome[100];
    int numero;
    float comissoes;
    int ativo;
} VendedorSimples;

typedef struct {
    char nome[100];
    int codigo;
    int quantidade_estoque;
    float preco_venda;
    int ativo;
} ProdutoSimples;

// Arrays globais de teste
static Venda vendas_teste[200];
static int num_vendas_teste = 0;
static int proximo_codigo_venda_teste = 1;

static CompradorSimples compradores_simples[100];
static int num_compradores_simples = 0;

static VendedorSimples vendedores_simples[50];
static int num_vendedores_simples = 0;

static ProdutoSimples produtos_simples[100];
static int num_produtos_simples = 0;

// Funções auxiliares para simulação
int buscar_comprador_por_cpf_simples(char* cpf) {
    for (int i = 0; i < num_compradores_simples; i++) {
        if (strcmp(compradores_simples[i].cpf, cpf) == 0 && compradores_simples[i].ativo) {
            return i;
        }
    }
    return -1;
}

int buscar_vendedor_por_numero_simples(int numero) {
    for (int i = 0; i < num_vendedores_simples; i++) {
        if (vendedores_simples[i].numero == numero && vendedores_simples[i].ativo) {
            return i;
        }
    }
    return -1;
}

int buscar_produto_por_codigo_simples(int codigo) {
    for (int i = 0; i < num_produtos_simples; i++) {
        if (produtos_simples[i].codigo == codigo && produtos_simples[i].ativo) {
            return i;
        }
    }
    return -1;
}

// Função para buscar venda
int buscar_venda_por_codigo_teste(int codigo) {
    for (int i = 0; i < num_vendas_teste; i++) {
        if (vendas_teste[i].codigo_venda == codigo && vendas_teste[i].ativo) {
            return i;
        }
    }
    return -1;
}

// Função para cadastrar venda simples
int cadastrar_venda_teste(char* cpf_comprador, int numero_vendedor, 
                         int codigo_produto, int quantidade) {
    if (num_vendas_teste >= 200) return 0; // Array cheio
    
    // Buscar comprador
    int indice_comprador = buscar_comprador_por_cpf_simples(cpf_comprador);
    if (indice_comprador < 0) return -1; // Comprador não encontrado
    
    // Buscar vendedor
    int indice_vendedor = buscar_vendedor_por_numero_simples(numero_vendedor);
    if (indice_vendedor < 0) return -2; // Vendedor não encontrado
    
    // Buscar produto
    int indice_produto = buscar_produto_por_codigo_simples(codigo_produto);
    if (indice_produto < 0) return -3; // Produto não encontrado
    
    // Verificar estoque
    if (produtos_simples[indice_produto].quantidade_estoque < quantidade) {
        return -4; // Estoque insuficiente
    }
    
    // Criar venda
    vendas_teste[num_vendas_teste].codigo_venda = proximo_codigo_venda_teste++;
    vendas_teste[num_vendas_teste].codigo_comprador = indice_comprador;
    vendas_teste[num_vendas_teste].numero_vendedor = numero_vendedor;
    vendas_teste[num_vendas_teste].num_itens = 1;
    vendas_teste[num_vendas_teste].ativo = 1;
    
    // Adicionar item
    strcpy(vendas_teste[num_vendas_teste].itens[0].nome_produto, produtos_simples[indice_produto].nome);
    vendas_teste[num_vendas_teste].itens[0].codigo_produto = codigo_produto;
    vendas_teste[num_vendas_teste].itens[0].quantidade = quantidade;
    vendas_teste[num_vendas_teste].itens[0].preco_unitario = produtos_simples[indice_produto].preco_venda;
    vendas_teste[num_vendas_teste].itens[0].preco_total = produtos_simples[indice_produto].preco_venda * quantidade;
    vendas_teste[num_vendas_teste].valor_total = vendas_teste[num_vendas_teste].itens[0].preco_total;
    
    // Atualizar estoque
    produtos_simples[indice_produto].quantidade_estoque -= quantidade;
    
    // Calcular comissão (3%)
    vendedores_simples[indice_vendedor].comissoes += vendas_teste[num_vendas_teste].valor_total * 0.03;
    
    num_vendas_teste++;
    return 1; // Sucesso
}

// Função para calcular frete
float calcular_frete_teste(float valor_venda) {
    if (valor_venda <= 100.00) {
        return 30.00;
    } else if (valor_venda <= 300.00) {
        return 20.00;
    } else {
        return 0.00; // Grátis
    }
}

// Setup: executado antes de cada teste
static void* venda_setup(const MunitParameter params[], void* user_data) {
    // Limpar arrays
    num_vendas_teste = 0;
    proximo_codigo_venda_teste = 1;
    num_compradores_simples = 0;
    num_vendedores_simples = 0;
    num_produtos_simples = 0;
    
    memset(vendas_teste, 0, sizeof(vendas_teste));
    memset(compradores_simples, 0, sizeof(compradores_simples));
    memset(vendedores_simples, 0, sizeof(vendedores_simples));
    memset(produtos_simples, 0, sizeof(produtos_simples));
    
    // Cadastrar dados de teste
    
    // Comprador de teste
    strcpy(compradores_simples[0].nome, "Maria Santos");
    strcpy(compradores_simples[0].cpf, "123.456.789-00");
    compradores_simples[0].ativo = 1;
    num_compradores_simples = 1;
    
    // Vendedor de teste
    strcpy(vendedores_simples[0].nome, "João Silva");
    vendedores_simples[0].numero = 1;
    vendedores_simples[0].comissoes = 0.0;
    vendedores_simples[0].ativo = 1;
    num_vendedores_simples = 1;
    
    // Produto de teste
    strcpy(produtos_simples[0].nome, "Notebook Dell");
    produtos_simples[0].codigo = 1;
    produtos_simples[0].quantidade_estoque = 10;
    produtos_simples[0].preco_venda = 2500.00;
    produtos_simples[0].ativo = 1;
    num_produtos_simples = 1;
    
    return NULL;
}

// Teardown: executado após cada teste
static void venda_teardown(void* fixture) {
    // Cleanup se necessário
}

// ===== TESTES =====

// VE-F-001: Cadastrar Venda Simples
static MunitResult test_cadastrar_venda_simples(const MunitParameter params[], void* data) {
    int resultado = cadastrar_venda_teste("123.456.789-00", 1, 1, 2);
    
    munit_assert_int(resultado, ==, 1);
    munit_assert_int(num_vendas_teste, ==, 1);
    munit_assert_int(vendas_teste[0].codigo_venda, ==, 1);
    munit_assert_int(vendas_teste[0].numero_vendedor, ==, 1);
    munit_assert_int(vendas_teste[0].num_itens, ==, 1);
    munit_assert_int(vendas_teste[0].itens[0].codigo_produto, ==, 1);
    munit_assert_int(vendas_teste[0].itens[0].quantidade, ==, 2);
    munit_assert_float_equal(vendas_teste[0].valor_total, 5000.00, 2);
    
    // Verificar se estoque foi atualizado
    munit_assert_int(produtos_simples[0].quantidade_estoque, ==, 8);
    
    // Verificar se comissão foi calculada (3% de 5000 = 150)
    munit_assert_float_equal(vendedores_simples[0].comissoes, 150.00, 2);
    
    return MUNIT_OK;
}

// VE-F-002: Comprador Inexistente
static MunitResult test_comprador_inexistente(const MunitParameter params[], void* data) {
    int resultado = cadastrar_venda_teste("999.999.999-99", 1, 1, 2);
    
    munit_assert_int(resultado, ==, -1); // Comprador não encontrado
    munit_assert_int(num_vendas_teste, ==, 0);
    
    return MUNIT_OK;
}

// VE-F-003: Vendedor Inexistente
static MunitResult test_vendedor_inexistente(const MunitParameter params[], void* data) {
    int resultado = cadastrar_venda_teste("123.456.789-00", 999, 1, 2);
    
    munit_assert_int(resultado, ==, -2); // Vendedor não encontrado
    munit_assert_int(num_vendas_teste, ==, 0);
    
    return MUNIT_OK;
}

// VE-F-004: Produto Inexistente
static MunitResult test_produto_inexistente(const MunitParameter params[], void* data) {
    int resultado = cadastrar_venda_teste("123.456.789-00", 1, 999, 2);
    
    munit_assert_int(resultado, ==, -3); // Produto não encontrado
    munit_assert_int(num_vendas_teste, ==, 0);
    
    return MUNIT_OK;
}

// VE-F-005: Estoque Insuficiente
static MunitResult test_estoque_insuficiente(const MunitParameter params[], void* data) {
    int resultado = cadastrar_venda_teste("123.456.789-00", 1, 1, 15); // Estoque é 10
    
    munit_assert_int(resultado, ==, -4); // Estoque insuficiente
    munit_assert_int(num_vendas_teste, ==, 0);
    
    return MUNIT_OK;
}

// VE-F-006: Buscar Venda Existente
static MunitResult test_buscar_venda_existente(const MunitParameter params[], void* data) {
    // Primeiro cadastrar uma venda
    cadastrar_venda_teste("123.456.789-00", 1, 1, 2);
    
    // Buscar a venda
    int indice = buscar_venda_por_codigo_teste(1);
    
    munit_assert_int(indice, >=, 0);
    munit_assert_int(vendas_teste[indice].codigo_venda, ==, 1);
    
    return MUNIT_OK;
}

// VE-F-007: Buscar Venda Inexistente
static MunitResult test_buscar_venda_inexistente(const MunitParameter params[], void* data) {
    int indice = buscar_venda_por_codigo_teste(999);
    
    munit_assert_int(indice, ==, -1);
    
    return MUNIT_OK;
}

// VE-F-008: Múltiplas Vendas
static MunitResult test_multiplas_vendas(const MunitParameter params[], void* data) {
    int resultado1 = cadastrar_venda_teste("123.456.789-00", 1, 1, 1);
    int resultado2 = cadastrar_venda_teste("123.456.789-00", 1, 1, 2);
    
    munit_assert_int(resultado1, ==, 1);
    munit_assert_int(resultado2, ==, 1);
    munit_assert_int(num_vendas_teste, ==, 2);
    
    // Verificar códigos únicos
    munit_assert_int(vendas_teste[0].codigo_venda, ==, 1);
    munit_assert_int(vendas_teste[1].codigo_venda, ==, 2);
    
    // Verificar estoque (10 - 1 - 2 = 7)
    munit_assert_int(produtos_simples[0].quantidade_estoque, ==, 7);
    
    return MUNIT_OK;
}

// A-F-001: Calcular Frete Baixo
static MunitResult test_calcular_frete_baixo(const MunitParameter params[], void* data) {
    float frete = calcular_frete_teste(50.00);
    
    munit_assert_float_equal(frete, 30.00, 2);
    
    return MUNIT_OK;
}

// A-F-002: Calcular Frete Médio
static MunitResult test_calcular_frete_medio(const MunitParameter params[], void* data) {
    float frete = calcular_frete_teste(200.00);
    
    munit_assert_float_equal(frete, 20.00, 2);
    
    return MUNIT_OK;
}

// A-F-003: Calcular Frete Grátis
static MunitResult test_calcular_frete_gratis(const MunitParameter params[], void* data) {
    float frete = calcular_frete_teste(400.00);
    
    munit_assert_float_equal(frete, 0.00, 2);
    
    return MUNIT_OK;
}

// A-F-004: Frete Limite Inferior
static MunitResult test_frete_limite_inferior(const MunitParameter params[], void* data) {
    float frete1 = calcular_frete_teste(100.00); // Exatamente 100
    float frete2 = calcular_frete_teste(100.01); // Pouco acima de 100
    
    munit_assert_float_equal(frete1, 30.00, 2);
    munit_assert_float_equal(frete2, 20.00, 2);
    
    return MUNIT_OK;
}

// ===== CONFIGURAÇÃO DOS TESTES =====

static MunitTest venda_tests[] = {
    { 
        "/cadastrar_venda_simples", 
        test_cadastrar_venda_simples, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/comprador_inexistente", 
        test_comprador_inexistente, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/vendedor_inexistente", 
        test_vendedor_inexistente, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/produto_inexistente", 
        test_produto_inexistente, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/estoque_insuficiente", 
        test_estoque_insuficiente, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_venda_existente", 
        test_buscar_venda_existente, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_venda_inexistente", 
        test_buscar_venda_inexistente, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/multiplas_vendas", 
        test_multiplas_vendas, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/calcular_frete_baixo", 
        test_calcular_frete_baixo, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/calcular_frete_medio", 
        test_calcular_frete_medio, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/calcular_frete_gratis", 
        test_calcular_frete_gratis, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/frete_limite_inferior", 
        test_frete_limite_inferior, 
        venda_setup, 
        venda_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite venda_suite = {
    "/vendas",
    venda_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

// Para compilação standalone
#ifdef COMPILE_STANDALONE
int main(int argc, char* argv[]) {
    return munit_suite_main(&venda_suite, NULL, argc, argv);
}
#endif
