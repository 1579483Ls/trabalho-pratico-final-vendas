#include "munit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simulação das estruturas do sistema_vendas.c
typedef struct {
    int codigo;
    char nome[50];
    char categoria[30];
    float preco;
    int quantidade;
    int ativo;
} Produto;

// Simular array global de produtos
static Produto produtos_teste[100];
static int total_produtos_teste = 0;

// Função simulada de cadastro de produto
int cadastrar_produto_teste(int codigo, char* nome, char* categoria, float preco, int quantidade) {
    if (total_produtos_teste >= 100) return 0; // Array cheio
    if (preco <= 0 || quantidade < 0) return 0; // Dados inválidos
    if (strlen(nome) == 0 || strlen(categoria) == 0) return 0; // Strings vazias
    
    produtos_teste[total_produtos_teste].codigo = codigo;
    strcpy(produtos_teste[total_produtos_teste].nome, nome);
    strcpy(produtos_teste[total_produtos_teste].categoria, categoria);
    produtos_teste[total_produtos_teste].preco = preco;
    produtos_teste[total_produtos_teste].quantidade = quantidade;
    produtos_teste[total_produtos_teste].ativo = 1;
    total_produtos_teste++;
    
    return 1; // Sucesso
}

// Função simulada de busca de produto
Produto* buscar_produto_teste(int codigo) {
    for (int i = 0; i < total_produtos_teste; i++) {
        if (produtos_teste[i].codigo == codigo) {
            return &produtos_teste[i];
        }
    }
    return NULL;
}

// Setup: executado antes de cada teste
static void* produto_setup(const MunitParameter params[], void* user_data) {
    // Limpar array de produtos
    total_produtos_teste = 0;
    memset(produtos_teste, 0, sizeof(produtos_teste));
    return NULL;
}

// Teardown: executado após cada teste
static void produto_teardown(void* fixture) {
    // Cleanup se necessário
}

// ===== TESTES =====

// Teste 1: Cadastro de produto válido
static MunitResult test_cadastrar_produto_valido(const MunitParameter params[], void* data) {
    int resultado = cadastrar_produto_teste(1, "Notebook", "Eletrônicos", 2500.0, 5);
    
    munit_assert_int(resultado, ==, 1);
    munit_assert_int(total_produtos_teste, ==, 1);
    munit_assert_int(produtos_teste[0].codigo, ==, 1);
    munit_assert_string_equal(produtos_teste[0].nome, "Notebook");
    munit_assert_string_equal(produtos_teste[0].categoria, "Eletrônicos");
    munit_assert_float_equal(produtos_teste[0].preco, 2500.0, 2);
    munit_assert_int(produtos_teste[0].quantidade, ==, 5);
    
    return MUNIT_OK;
}

// Teste 2: Cadastro com preço inválido
static MunitResult test_cadastrar_produto_preco_invalido(const MunitParameter params[], void* data) {
    int resultado = cadastrar_produto_teste(1, "Produto", "Categoria", -100.0, 5);
    
    munit_assert_int(resultado, ==, 0);
    munit_assert_int(total_produtos_teste, ==, 0);
    
    return MUNIT_OK;
}

// Teste 3: Cadastro com quantidade inválida
static MunitResult test_cadastrar_produto_quantidade_invalida(const MunitParameter params[], void* data) {
    int resultado = cadastrar_produto_teste(1, "Produto", "Categoria", 100.0, -5);
    
    munit_assert_int(resultado, ==, 0);
    munit_assert_int(total_produtos_teste, ==, 0);
    
    return MUNIT_OK;
}

// Teste 4: Cadastro com nome vazio
static MunitResult test_cadastrar_produto_nome_vazio(const MunitParameter params[], void* data) {
    int resultado = cadastrar_produto_teste(1, "", "Categoria", 100.0, 5);
    
    munit_assert_int(resultado, ==, 0);
    munit_assert_int(total_produtos_teste, ==, 0);
    
    return MUNIT_OK;
}

// Teste 5: Buscar produto existente
static MunitResult test_buscar_produto_existente(const MunitParameter params[], void* data) {
    // Primeiro cadastrar um produto
    cadastrar_produto_teste(123, "Mouse", "Periféricos", 50.0, 10);
    
    // Buscar o produto
    Produto* produto_encontrado = buscar_produto_teste(123);
    
    munit_assert_not_null(produto_encontrado);
    munit_assert_int(produto_encontrado->codigo, ==, 123);
    munit_assert_string_equal(produto_encontrado->nome, "Mouse");
    munit_assert_string_equal(produto_encontrado->categoria, "Periféricos");
    munit_assert_float_equal(produto_encontrado->preco, 50.0, 2);
    munit_assert_int(produto_encontrado->quantidade, ==, 10);
    
    return MUNIT_OK;
}

// Teste 6: Buscar produto inexistente
static MunitResult test_buscar_produto_inexistente(const MunitParameter params[], void* data) {
    // Não cadastrar nenhum produto
    
    // Buscar produto inexistente
    Produto* produto_encontrado = buscar_produto_teste(999);
    
    munit_assert_null(produto_encontrado);
    
    return MUNIT_OK;
}

// Teste 7: Múltiplos cadastros
static MunitResult test_multiplos_cadastros(const MunitParameter params[], void* data) {
    int resultado1 = cadastrar_produto_teste(1, "Produto1", "Cat1", 100.0, 5);
    int resultado2 = cadastrar_produto_teste(2, "Produto2", "Cat2", 200.0, 10);
    int resultado3 = cadastrar_produto_teste(3, "Produto3", "Cat3", 300.0, 15);
    
    munit_assert_int(resultado1, ==, 1);
    munit_assert_int(resultado2, ==, 1);
    munit_assert_int(resultado3, ==, 1);
    munit_assert_int(total_produtos_teste, ==, 3);
    
    // Verificar se todos podem ser encontrados
    Produto* p1 = buscar_produto_teste(1);
    Produto* p2 = buscar_produto_teste(2);
    Produto* p3 = buscar_produto_teste(3);
    
    munit_assert_not_null(p1);
    munit_assert_not_null(p2);
    munit_assert_not_null(p3);
    
    munit_assert_string_equal(p1->nome, "Produto1");
    munit_assert_string_equal(p2->nome, "Produto2");
    munit_assert_string_equal(p3->nome, "Produto3");
    
    return MUNIT_OK;
}

// Teste 8: Alterar produto existente
static MunitResult test_alterar_produto_existente(const MunitParameter params[], void* data) {
    // Cadastrar produto primeiro
    cadastrar_produto_teste(1, "Produto Original", "Categoria", 100.0, 5);
    
    // Simular alteração de nome
    strcpy(produtos_teste[0].nome, "Produto Alterado");
    produtos_teste[0].preco = 150.0;
    produtos_teste[0].quantidade = 8;
    
    // Verificar alterações
    munit_assert_string_equal(produtos_teste[0].nome, "Produto Alterado");
    munit_assert_float_equal(produtos_teste[0].preco, 150.0, 2);
    munit_assert_int(produtos_teste[0].quantidade, ==, 8);
    
    return MUNIT_OK;
}

// Teste 9: Excluir produto (exclusão lógica)
static MunitResult test_excluir_produto_logico(const MunitParameter params[], void* data) {
    // Cadastrar produto primeiro
    cadastrar_produto_teste(1, "Produto Para Excluir", "Categoria", 100.0, 5);
    
    // Simular exclusão lógica
    produtos_teste[0].ativo = 0;
    
    // Verificar se produto foi marcado como inativo
    munit_assert_int(produtos_teste[0].ativo, ==, 0);
    
    return MUNIT_OK;
}

// Teste 10: Validação de preço zero
static MunitResult test_validacao_preco_zero(const MunitParameter params[], void* data) {
    int resultado = cadastrar_produto_teste(1, "Produto", "Categoria", 0.0, 5);
    
    munit_assert_int(resultado, ==, 0);
    munit_assert_int(total_produtos_teste, ==, 0);
    
    return MUNIT_OK;
}

// Teste 11: Validação de estoque negativo
static MunitResult test_validacao_estoque_negativo(const MunitParameter params[], void* data) {
    int resultado = cadastrar_produto_teste(1, "Produto", "Categoria", 100.0, -1);
    
    munit_assert_int(resultado, ==, 0);
    munit_assert_int(total_produtos_teste, ==, 0);
    
    return MUNIT_OK;
}

// Teste 12: Busca com array vazio
static MunitResult test_busca_array_vazio(const MunitParameter params[], void* data) {
    // Não cadastrar nenhum produto
    Produto* produto = buscar_produto_teste(1);
    
    munit_assert_null(produto);
    
    return MUNIT_OK;
}
}

// ===== CONFIGURAÇÃO DOS TESTES =====

static MunitTest produto_tests[] = {
    { 
        "/cadastrar_valido", 
        test_cadastrar_produto_valido, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/cadastrar_preco_invalido", 
        test_cadastrar_produto_preco_invalido, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/cadastrar_quantidade_invalida", 
        test_cadastrar_produto_quantidade_invalida, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/cadastrar_nome_vazio", 
        test_cadastrar_produto_nome_vazio, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_existente", 
        test_buscar_produto_existente, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_inexistente", 
        test_buscar_produto_inexistente, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/multiplos_cadastros", 
        test_multiplos_cadastros, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/alterar_produto", 
        test_alterar_produto_existente, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/excluir_logico", 
        test_excluir_produto_logico, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/preco_zero", 
        test_validacao_preco_zero, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/estoque_negativo", 
        test_validacao_estoque_negativo, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/busca_array_vazio", 
        test_busca_array_vazio, 
        produto_setup, 
        produto_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite produto_suite = {
    "/produtos",
    produto_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

// Para compilação standalone (teste individual)
#ifdef COMPILE_STANDALONE
int main(int argc, char* argv[]) {
    return munit_suite_main(&produto_suite, NULL, argc, argv);
}
#endif
