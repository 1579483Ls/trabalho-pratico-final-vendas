#include "munit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simulação das estruturas do sistema_vendas.c
typedef struct {
    char rua[100];
    char bairro[100];
    char cidade[100];
    char estado[3];
    char cep[10];
} Endereco;

typedef struct {
    char nome[100];
    char cpf[15];
    char email[100];
    Endereco endereco;
    int ativo;
} Comprador;

// Simular array global de compradores
static Comprador compradores_teste[100];
static int num_compradores_teste = 0;

// Função simulada de busca por CPF
int buscar_comprador_por_cpf_teste(char* cpf) {
    for (int i = 0; i < num_compradores_teste; i++) {
        if (strcmp(compradores_teste[i].cpf, cpf) == 0 && compradores_teste[i].ativo) {
            return i;
        }
    }
    return -1;
}

// Função simulada de cadastro de comprador
int cadastrar_comprador_teste(char* nome, char* cpf, char* email, 
                             char* rua, char* bairro, char* cidade, 
                             char* estado, char* cep) {
    if (num_compradores_teste >= 100) return 0; // Array cheio
    if (strlen(nome) == 0) return 0; // Nome vazio
    if (strlen(cpf) == 0) return 0; // CPF vazio
    if (strlen(email) == 0) return 0; // Email vazio
    if (strlen(rua) == 0) return 0; // Endereço incompleto
    if (strlen(bairro) == 0) return 0;
    if (strlen(cidade) == 0) return 0;
    if (strlen(estado) == 0) return 0;
    if (strlen(cep) == 0) return 0;
    
    // Verificar CPF duplicado
    if (buscar_comprador_por_cpf_teste(cpf) >= 0) {
        return -1; // CPF duplicado
    }
    
    strcpy(compradores_teste[num_compradores_teste].nome, nome);
    strcpy(compradores_teste[num_compradores_teste].cpf, cpf);
    strcpy(compradores_teste[num_compradores_teste].email, email);
    strcpy(compradores_teste[num_compradores_teste].endereco.rua, rua);
    strcpy(compradores_teste[num_compradores_teste].endereco.bairro, bairro);
    strcpy(compradores_teste[num_compradores_teste].endereco.cidade, cidade);
    strcpy(compradores_teste[num_compradores_teste].endereco.estado, estado);
    strcpy(compradores_teste[num_compradores_teste].endereco.cep, cep);
    compradores_teste[num_compradores_teste].ativo = 1;
    num_compradores_teste++;
    
    return 1; // Sucesso
}

// Setup: executado antes de cada teste
static void* comprador_setup(const MunitParameter params[], void* user_data) {
    // Limpar array de compradores
    num_compradores_teste = 0;
    memset(compradores_teste, 0, sizeof(compradores_teste));
    return NULL;
}

// Teardown: executado após cada teste
static void comprador_teardown(void* fixture) {
    // Cleanup se necessário
}

// ===== TESTES =====

// C-F-001: Cadastrar Comprador Completo
static MunitResult test_cadastrar_comprador_completo(const MunitParameter params[], void* data) {
    int resultado = cadastrar_comprador_teste(
        "Maria da Silva Santos",
        "111.222.333-44",
        "maria@email.com",
        "Rua das Flores, 123",
        "Centro",
        "São Paulo",
        "SP",
        "01234-567"
    );
    
    munit_assert_int(resultado, ==, 1);
    munit_assert_int(num_compradores_teste, ==, 1);
    munit_assert_string_equal(compradores_teste[0].nome, "Maria da Silva Santos");
    munit_assert_string_equal(compradores_teste[0].cpf, "111.222.333-44");
    munit_assert_string_equal(compradores_teste[0].email, "maria@email.com");
    munit_assert_string_equal(compradores_teste[0].endereco.rua, "Rua das Flores, 123");
    munit_assert_string_equal(compradores_teste[0].endereco.bairro, "Centro");
    munit_assert_string_equal(compradores_teste[0].endereco.cidade, "São Paulo");
    munit_assert_string_equal(compradores_teste[0].endereco.estado, "SP");
    munit_assert_string_equal(compradores_teste[0].endereco.cep, "01234-567");
    munit_assert_int(compradores_teste[0].ativo, ==, 1);
    
    return MUNIT_OK;
}

// C-F-002: Validar CPF Duplicado
static MunitResult test_validar_cpf_duplicado(const MunitParameter params[], void* data) {
    // Primeiro cadastro
    cadastrar_comprador_teste(
        "Primeiro Comprador", "123.456.789-00", "primeiro@email.com",
        "Rua A", "Bairro A", "Cidade A", "SP", "12345-678"
    );
    
    // Tentar cadastrar com CPF duplicado
    int resultado = cadastrar_comprador_teste(
        "Segundo Comprador", "123.456.789-00", "segundo@email.com",
        "Rua B", "Bairro B", "Cidade B", "RJ", "87654-321"
    );
    
    munit_assert_int(resultado, ==, -1); // Erro de duplicação
    munit_assert_int(num_compradores_teste, ==, 1); // Apenas o primeiro foi cadastrado
    
    return MUNIT_OK;
}

// C-F-003: Validar Dados Obrigatórios - Nome Vazio
static MunitResult test_validar_nome_vazio(const MunitParameter params[], void* data) {
    int resultado = cadastrar_comprador_teste(
        "", "123.456.789-00", "email@teste.com",
        "Rua Teste", "Bairro", "Cidade", "SP", "12345-678"
    );
    
    munit_assert_int(resultado, ==, 0); // Erro de validação
    munit_assert_int(num_compradores_teste, ==, 0);
    
    return MUNIT_OK;
}

// C-F-004: Validar Dados Obrigatórios - Email Vazio
static MunitResult test_validar_email_vazio(const MunitParameter params[], void* data) {
    int resultado = cadastrar_comprador_teste(
        "Nome Teste", "123.456.789-00", "",
        "Rua Teste", "Bairro", "Cidade", "SP", "12345-678"
    );
    
    munit_assert_int(resultado, ==, 0); // Erro de validação
    munit_assert_int(num_compradores_teste, ==, 0);
    
    return MUNIT_OK;
}

// C-F-005: Validar Endereço Completo - Rua Vazia
static MunitResult test_validar_endereco_rua_vazia(const MunitParameter params[], void* data) {
    int resultado = cadastrar_comprador_teste(
        "Nome Teste", "123.456.789-00", "email@teste.com",
        "", "Bairro", "Cidade", "SP", "12345-678"
    );
    
    munit_assert_int(resultado, ==, 0); // Erro de validação
    munit_assert_int(num_compradores_teste, ==, 0);
    
    return MUNIT_OK;
}

// C-F-006: Buscar por CPF Existente
static MunitResult test_buscar_cpf_existente(const MunitParameter params[], void* data) {
    // Cadastrar comprador
    cadastrar_comprador_teste(
        "Comprador Teste", "123.456.789-00", "teste@email.com",
        "Rua Teste", "Bairro Teste", "Cidade Teste", "SP", "12345-678"
    );
    
    // Buscar o comprador
    int indice = buscar_comprador_por_cpf_teste("123.456.789-00");
    
    munit_assert_int(indice, >=, 0);
    munit_assert_string_equal(compradores_teste[indice].cpf, "123.456.789-00");
    munit_assert_string_equal(compradores_teste[indice].nome, "Comprador Teste");
    
    return MUNIT_OK;
}

// C-F-007: Buscar CPF Inexistente
static MunitResult test_buscar_cpf_inexistente(const MunitParameter params[], void* data) {
    int indice = buscar_comprador_por_cpf_teste("999.999.999-99");
    
    munit_assert_int(indice, ==, -1);
    
    return MUNIT_OK;
}

// C-F-008: CPF Vazio
static MunitResult test_cpf_vazio(const MunitParameter params[], void* data) {
    int resultado = cadastrar_comprador_teste(
        "Nome Teste", "", "email@teste.com",
        "Rua Teste", "Bairro", "Cidade", "SP", "12345-678"
    );
    
    munit_assert_int(resultado, ==, 0);
    munit_assert_int(num_compradores_teste, ==, 0);
    
    return MUNIT_OK;
}

// C-F-009: Múltiplos Cadastros
static MunitResult test_multiplos_cadastros(const MunitParameter params[], void* data) {
    int resultado1 = cadastrar_comprador_teste(
        "Comprador 1", "111.111.111-11", "comp1@email.com",
        "Rua 1", "Bairro 1", "Cidade 1", "SP", "11111-111"
    );
    
    int resultado2 = cadastrar_comprador_teste(
        "Comprador 2", "222.222.222-22", "comp2@email.com",
        "Rua 2", "Bairro 2", "Cidade 2", "RJ", "22222-222"
    );
    
    int resultado3 = cadastrar_comprador_teste(
        "Comprador 3", "333.333.333-33", "comp3@email.com",
        "Rua 3", "Bairro 3", "Cidade 3", "MG", "33333-333"
    );
    
    munit_assert_int(resultado1, ==, 1);
    munit_assert_int(resultado2, ==, 1);
    munit_assert_int(resultado3, ==, 1);
    munit_assert_int(num_compradores_teste, ==, 3);
    
    // Verificar se todos podem ser encontrados
    int indice1 = buscar_comprador_por_cpf_teste("111.111.111-11");
    int indice2 = buscar_comprador_por_cpf_teste("222.222.222-22");
    int indice3 = buscar_comprador_por_cpf_teste("333.333.333-33");
    
    munit_assert_int(indice1, >=, 0);
    munit_assert_int(indice2, >=, 0);
    munit_assert_int(indice3, >=, 0);
    
    return MUNIT_OK;
}

// C-F-010: Limite Máximo
static MunitResult test_limite_maximo(const MunitParameter params[], void* data) {
    // Simular array cheio
    num_compradores_teste = 100;
    
    int resultado = cadastrar_comprador_teste(
        "Comprador Teste", "123.456.789-00", "teste@email.com",
        "Rua Teste", "Bairro", "Cidade", "SP", "12345-678"
    );
    
    munit_assert_int(resultado, ==, 0);
    
    return MUNIT_OK;
}

// ===== CONFIGURAÇÃO DOS TESTES =====

static MunitTest comprador_tests[] = {
    { 
        "/cadastrar_completo", 
        test_cadastrar_comprador_completo, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/cpf_duplicado", 
        test_validar_cpf_duplicado, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/nome_vazio", 
        test_validar_nome_vazio, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/email_vazio", 
        test_validar_email_vazio, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/endereco_rua_vazia", 
        test_validar_endereco_rua_vazia, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_cpf_existente", 
        test_buscar_cpf_existente, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/buscar_cpf_inexistente", 
        test_buscar_cpf_inexistente, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/cpf_vazio", 
        test_cpf_vazio, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/multiplos_cadastros", 
        test_multiplos_cadastros, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { 
        "/limite_maximo", 
        test_limite_maximo, 
        comprador_setup, 
        comprador_teardown, 
        MUNIT_TEST_OPTION_NONE, 
        NULL 
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite comprador_suite = {
    "/compradores",
    comprador_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

// Para compilação standalone
#ifdef COMPILE_STANDALONE
int main(int argc, char* argv[]) {
    return munit_suite_main(&comprador_suite, NULL, argc, argv);
}
#endif
