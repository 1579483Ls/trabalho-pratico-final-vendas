/*
===============================================================================
                        SISTEMA DE VENDAS - TRABALHO PRATICO 2025/1
===============================================================================
Equipe:
- Lucas Siqueira  : Modulo de Produtos (CRUD Produtos + Estruturas)
- Daniel          : Modulo de Vendedores (CRUD Vendedores + Comissoes)
- Guilherme       : Modulo de Compradores (CRUD Compradores + Enderecos)
- Gustavo         : Modulo de Vendas (CRUD Vendas + Integracao + Relatorios)

Metodologia: Scrum com 4 sprints de 3-4 dias cada
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// ============================================================================
//                           CONFIGURACOES GLOBAIS
// ============================================================================
// Definicoes de limites do sistema (compartilhado por toda a equipe)
#define MAX_PRODUTOS 100
#define MAX_VENDEDORES 50
#define MAX_COMPRADORES 100
#define MAX_VENDAS 200
#define MAX_ITENS_VENDA 20
#define MAX_STRING 100

// ============================================================================
//                            ESTRUTURAS DE DADOS
// ============================================================================

// ----------------------------------------------------------------------------
// RESPONSÁVEL: LUCAS SIQUEIRA - Estrutura de Produtos
// ----------------------------------------------------------------------------
// Estrutura para representar um produto no sistema
typedef struct {
    char nome[MAX_STRING];        // Nome do produto
    int codigo;                   // Codigo unico identificador
    int quantidade_estoque;       // Quantidade disponivel em estoque
    float preco_venda;           // Preco unitario de venda
    int ativo;                   // Flag: 1 = ativo, 0 = removido logicamente
} Produto;

// ----------------------------------------------------------------------------
// RESPONSÁVEL: DANIEL - Estrutura de Vendedores
// ----------------------------------------------------------------------------
// Estrutura para representar um vendedor no sistema
typedef struct {
    char nome[MAX_STRING];       // Nome completo do vendedor
    int numero;                  // Numero unico identificador
    float salario_fixo;         // Salario base mensal
    float comissoes;            // Total de comissoes acumuladas (3% por venda)
    int ativo;                  // Flag: 1 = ativo, 0 = removido logicamente
} Vendedor;

// ----------------------------------------------------------------------------
// RESPONSÁVEL: GUILHERME - Estruturas de Compradores e Endereços
// ----------------------------------------------------------------------------
// Estrutura para representar endereço de entrega
typedef struct {
    char rua[MAX_STRING];       // Logradouro completo
    char bairro[MAX_STRING];    // Bairro/distrito
    char cidade[MAX_STRING];    // Cidade
    char estado[3];             // Sigla do estado (2 caracteres + \0)
    char cep[10];              // CEP no formato XXXXX-XXX
} Endereco;

// Estrutura para representar um comprador no sistema
typedef struct {
    char nome[MAX_STRING];      // Nome completo do comprador
    char cpf[15];              // CPF no formato XXX.XXX.XXX-XX
    char email[MAX_STRING];     // E-mail para contato
    Endereco endereco;          // Endereco de entrega completo
    int ativo;                 // Flag: 1 = ativo, 0 = removido logicamente
} Comprador;

// ----------------------------------------------------------------------------
// RESPONSÁVEL: GUSTAVO - Estruturas de Vendas e Itens
// ----------------------------------------------------------------------------
// Estrutura para representar um item individual dentro de uma venda
typedef struct {
    char nome_produto[MAX_STRING];  // Nome do produto (cache para performance)
    int codigo_produto;            // Referencia ao codigo do produto
    int quantidade;               // Quantidade vendida
    float preco_unitario;         // Preco unitario no momento da venda
    float preco_total;           // Subtotal do item (quantidade * preco_unitario)
} ItemVenda;

// Estrutura principal para representar uma venda completa
typedef struct {
    int codigo_venda;            // Codigo unico da venda
    int codigo_comprador;        // Indice do comprador no array
    int numero_vendedor;         // Numero do vendedor responsavel
    ItemVenda itens[MAX_ITENS_VENDA];  // Array de itens vendidos
    int num_itens;              // Quantidade de itens na venda
    float valor_total;          // Valor total da venda (soma de todos os itens)
    int ativo;                  // Flag: 1 = ativo, 0 = removido logicamente
} Venda;

// ============================================================================
//                       VARIÁVEIS GLOBAIS DO SISTEMA
// ============================================================================

// ----------------------------------------------------------------------------
// Arrays principais para armazenamento de dados (compartilhado por toda equipe)
// ----------------------------------------------------------------------------
Produto produtos[MAX_PRODUTOS];           // LUCAS: Array de produtos
Vendedor vendedores[MAX_VENDEDORES];       // DANIEL: Array de vendedores
Comprador compradores[MAX_COMPRADORES];   // GUILHERME: Array de compradores
Venda vendas[MAX_VENDAS];                 // GUSTAVO: Array de vendas

// ----------------------------------------------------------------------------
// Contadores de registros ativos no sistema
// ----------------------------------------------------------------------------
int num_produtos = 0;        // LUCAS: Contador de produtos cadastrados
int num_vendedores = 0;      // DANIEL: Contador de vendedores cadastrados
int num_compradores = 0;     // GUILHERME: Contador de compradores cadastrados
int num_vendas = 0;          // GUSTAVO: Contador de vendas realizadas

// ----------------------------------------------------------------------------
// Geradores de códigos automáticos (para garantir unicidade)
// ----------------------------------------------------------------------------
int proximo_codigo_produto = 1;   // LUCAS: Proximo codigo de produto disponivel
int proximo_numero_vendedor = 1;  // DANIEL: Proximo numero de vendedor disponivel
int proximo_codigo_venda = 1;     // GUSTAVO: Proximo codigo de venda disponivel

// ============================================================================
//                       PROTÓTIPOS DAS FUNÇÕES
// ============================================================================

// ----------------------------------------------------------------------------
// FUNÇÕES DE MENU (Integração - GUSTAVO + toda equipe)
// ----------------------------------------------------------------------------
void menu_principal();        // Menu principal do sistema
void menu_produtos();         // LUCAS: Menu especifico de produtos
void menu_vendedores();       // DANIEL: Menu especifico de vendedores
void menu_compradores();      // GUILHERME: Menu especifico de compradores
void menu_vendas();          // GUSTAVO: Menu especifico de vendas

// ----------------------------------------------------------------------------
// MÓDULO DE PRODUTOS - RESPONSÁVEL: LUCAS SIQUEIRA
// ----------------------------------------------------------------------------
void cadastrar_produto();                    // Cadastra novo produto
void consultar_produtos();                   // Lista todos os produtos
void alterar_produto();                      // Modifica dados de produto existente
void excluir_produto();                      // Remove produto (exclusao logica)
int buscar_produto_por_codigo(int codigo);   // Busca produto pelo codigo unico

// ----------------------------------------------------------------------------
// MÓDULO DE VENDEDORES - RESPONSÁVEL: DANIEL
// ----------------------------------------------------------------------------
void cadastrar_vendedor();                     // Cadastra novo vendedor
void consultar_vendedores();                   // Lista todos os vendedores
void alterar_vendedor();                       // Modifica dados de vendedor existente
void excluir_vendedor();                       // Remove vendedor (exclusao logica)
int buscar_vendedor_por_numero(int numero);    // Busca vendedor pelo numero unico

// ----------------------------------------------------------------------------
// MÓDULO DE COMPRADORES - RESPONSÁVEL: GUILHERME
// ----------------------------------------------------------------------------
void cadastrar_comprador();                   // Cadastra novo comprador
void consultar_compradores();                 // Lista todos os compradores
void alterar_comprador();                     // Modifica dados de comprador existente
void excluir_comprador();                     // Remove comprador (exclusao logica)
int buscar_comprador_por_cpf(char *cpf);      // Busca comprador pelo CPF unico

// ----------------------------------------------------------------------------
// MÓDULO DE VENDAS E INTEGRAÇÃO - RESPONSÁVEL: GUSTAVO
// ----------------------------------------------------------------------------
void cadastrar_venda();                       // Registra nova venda (integra todos modulos)
void consultar_vendas();                      // Lista todas as vendas realizadas
void alterar_venda();                         // Modifica dados de venda existente
void excluir_venda();                         // Remove venda (exclusao logica)
int buscar_venda_por_codigo(int codigo);      // Busca venda pelo codigo unico

// ----------------------------------------------------------------------------
// FUNCOES AUXILIARES E UTILITARIAS - RESPONSAVEL: GUSTAVO (com apoio da equipe)
// ----------------------------------------------------------------------------
void limpar_buffer();                         // Limpa buffer de entrada do teclado
void pausar();                               // Pausa execucao aguardando tecla
float calcular_frete(float valor_venda);     // Calcula frete baseado no valor da venda
int ler_opcao_valida(int min, int max);      // Valida entrada de números inteiros para menus
char ler_confirmacao();                      // Valida entrada de confirmações s/n
void emitir_nota_fiscal();                   // Gera nota fiscal completa da venda

// ----------------------------------------------------------------------------
// FUNCOES DE ARQUIVOS - GUSTAVO
// ----------------------------------------------------------------------------
void salvar_produtos();                      // Salva produtos em arquivo produtos.txt
void carregar_produtos();                    // Carrega produtos do arquivo produtos.txt
void salvar_vendedores();                    // Salva vendedores em arquivo vendedores.txt
void carregar_vendedores();                  // Carrega vendedores do arquivo vendedores.txt
void salvar_compradores();                   // Salva compradores em arquivo compradores.txt
void carregar_compradores();                 // Carrega compradores do arquivo compradores.txt
void salvar_vendas();                        // Salva vendas em arquivo vendas.txt
void carregar_vendas();                      // Carrega vendas do arquivo vendas.txt
void salvar_todos_dados();                   // Salva todos os dados em arquivos
void carregar_todos_dados();                 // Carrega todos os dados dos arquivos
// ============================================================================
//                      IMPLEMENTAÇÃO DAS FUNÇÕES
// ============================================================================

// ----------------------------------------------------------------------------
// FUNÇÕES AUXILIARES - RESPONSÁVEL: GUSTAVO
// ----------------------------------------------------------------------------

// Limpa buffer de entrada do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pausa a execução aguardando tecla Enter
void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

// Calcula o valor do frete baseado no valor da venda
float calcular_frete(float valor_venda) {
    if (valor_venda <= 100.0) {
        return 30.0;    // Frete alto para vendas pequenas
    } else if (valor_venda <= 300.0) {
        return 20.0;    // Frete médio para vendas medianas
    } else {
        return 0.0;     // Frete gratis para incentivar vendas grandes
    }
}

// Função para validação robusta de entrada de números inteiros (menus e opções)
int ler_opcao_valida(int min, int max) {
    int opcao;
    char buffer[100];
    char *endptr;
    
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remove a quebra de linha se presente
            buffer[strcspn(buffer, "\n")] = 0;
            
            // Converte para inteiro usando strtol para validação robusta
            opcao = (int)strtol(buffer, &endptr, 10);
            
            // Verifica se a conversão foi bem-sucedida e está no intervalo válido
            if (*endptr == '\0' && opcao >= min && opcao <= max) {
                return opcao;
            }
        }
        
        printf("Opcao invalida! Digite um numero entre %d e %d: ", min, max);
    }
}

// Função para validação robusta de confirmações s/n
char ler_confirmacao() {
    char confirmacao[10];
    
    while (1) {
        fgets(confirmacao, sizeof(confirmacao), stdin);
        
        if (tolower(confirmacao[0]) == 's' || tolower(confirmacao[0]) == 'n') {
            return tolower(confirmacao[0]);
        }
        
        printf("Digite apenas 's' para sim ou 'n' para nao: ");
    }
}

// ============================================================================
//                    MÓDULO DE PRODUTOS - LUCAS SIQUEIRA
// ============================================================================

// Encontra o menor código de produto disponível (reutiliza códigos de produtos excluídos)
int encontrar_menor_codigo_disponivel() {
    for (int codigo = 1; codigo < proximo_codigo_produto; codigo++) {
        int codigo_existe = 0;
        for (int i = 0; i < num_produtos; i++) {
            if (produtos[i].codigo == codigo && produtos[i].ativo) {
                codigo_existe = 1;
                break;
            }
        }
        if (!codigo_existe) {
            return codigo; // Encontrou um código disponível
        }
    }
    return proximo_codigo_produto; // Se não há códigos reutilizáveis, usa o próximo sequencial
}

// Busca produto pelo código e retorna seu índice
int buscar_produto_por_codigo(int codigo) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo && produtos[i].ativo) {
            return i;  // Produto encontrado e ativo
        }
    }
    return -1;  // Produto nao encontrado ou inativo
}

// Cadastra um novo produto no sistema
void cadastrar_produto() {
    // Verificar se ha espaco disponivel no array
    if (num_produtos >= MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido!\n");
        pausar();
        return;
    }

    Produto novo_produto;
    int opcao_codigo;
    int menor_codigo_disponivel = encontrar_menor_codigo_disponivel();

    printf("\n=== CADASTRAR PRODUTO ===\n");
    
    printf("Nome do produto: ");
    fgets(novo_produto.nome, MAX_STRING, stdin);
    novo_produto.nome[strcspn(novo_produto.nome, "\n")] = 0; // Remove \n

    printf("Codigo do produto:\n");
    printf("1 - Gerar automaticamente (%d)\n", menor_codigo_disponivel);
    printf("2 - Inserir manualmente\n");
    printf("Escolha: ");
    opcao_codigo = ler_opcao_valida(1, 2);

    if (opcao_codigo == 1) {
        novo_produto.codigo = menor_codigo_disponivel;
        // Atualizar proximo_codigo_produto se necessario
        if (menor_codigo_disponivel >= proximo_codigo_produto) {
            proximo_codigo_produto = menor_codigo_disponivel + 1;
        }
    } else if (opcao_codigo == 2) {
        do {
            printf("Digite o codigo: ");
            scanf("%d", &novo_produto.codigo);
            limpar_buffer();
            
            if (buscar_produto_por_codigo(novo_produto.codigo) != -1) {
                printf("Codigo ja existe! Digite outro codigo.\n");
            }
        } while (buscar_produto_por_codigo(novo_produto.codigo) != -1);
        
        if (novo_produto.codigo >= proximo_codigo_produto) {
            proximo_codigo_produto = novo_produto.codigo + 1;
        }
    } else {
        printf("Opcao invalida! Cadastro cancelado.\n");
        pausar();
        return;
    }

    printf("Quantidade em estoque: ");
    scanf("%d", &novo_produto.quantidade_estoque);
    
    printf("Preco de venda: R$ ");
    scanf("%f", &novo_produto.preco_venda);
    limpar_buffer();

    novo_produto.ativo = 1;
    produtos[num_produtos] = novo_produto;
    num_produtos++;

    printf("Produto cadastrado com sucesso! Codigo: %d\n", novo_produto.codigo);
    salvar_produtos();
    pausar();
}

// Lista todos os produtos ativos cadastrados
void consultar_produtos() {
    printf("\n=== CONSULTAR PRODUTOS ===\n");
    
    if (num_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    // Criar array de indices dos produtos ativos ordenados por codigo
    int indices_ordenados[MAX_PRODUTOS];
    int count = 0;
    
    // Coletar indices dos produtos ativos
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].ativo) {
            indices_ordenados[count] = i;
            count++;
        }
    }
    
    // Ordenar indices por codigo (bubble sort simples)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (produtos[indices_ordenados[j]].codigo > produtos[indices_ordenados[j + 1]].codigo) {
                int temp = indices_ordenados[j];
                indices_ordenados[j] = indices_ordenados[j + 1];
                indices_ordenados[j + 1] = temp;
            }
        }
    }

    printf("%-6s %-30s %-10s %-12s\n", "Codigo", "Nome", "Estoque", "Preco");
    printf("--------------------------------------------------------\n");
    
    // Exibir produtos ordenados por codigo
    for (int i = 0; i < count; i++) {
        int idx = indices_ordenados[i];
        printf("%-6d %-30s %-10d R$ %-9.2f\n", 
               produtos[idx].codigo, 
               produtos[idx].nome, 
               produtos[idx].quantidade_estoque, 
               produtos[idx].preco_venda);
    }
    pausar();
}

// Altera dados de um produto existente
void alterar_produto() {
    int codigo, indice;
    
    printf("\n=== ALTERAR PRODUTO ===\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    limpar_buffer();

    indice = buscar_produto_por_codigo(codigo);
    if (indice == -1) {
        printf("Produto nao encontrado!\n");
        pausar();
        return;
    }

    printf("Produto encontrado: %s\n", produtos[indice].nome);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar quantidade em estoque\n");
    printf("3 - Alterar preco de venda\n");
    printf("Escolha: ");
    
    int opcao = ler_opcao_valida(1, 3);

    switch (opcao) {
        case 1:
            printf("Novo nome: ");
            fgets(produtos[indice].nome, MAX_STRING, stdin);
            produtos[indice].nome[strcspn(produtos[indice].nome, "\n")] = 0;
            break;
        case 2:
            printf("Nova quantidade: ");
            scanf("%d", &produtos[indice].quantidade_estoque);
            limpar_buffer();
            break;
        case 3:
            printf("Novo preco: R$ ");
            scanf("%f", &produtos[indice].preco_venda);
            limpar_buffer();
            break;
        default:
            printf("Opcao invalida!\n");
            pausar();
            return;
    }

    printf("Produto alterado com sucesso!\n");
    salvar_produtos();
    pausar();
}

// Remove produto do sistema (exclusão lógica)
void excluir_produto() {
    int codigo, indice;
    
    printf("\n=== EXCLUIR PRODUTO ===\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    limpar_buffer();

    indice = buscar_produto_por_codigo(codigo);
    if (indice == -1) {
        printf("Produto nao encontrado!\n");
        pausar();
        return;
    }

    printf("Produto: %s\n", produtos[indice].nome);
    printf("Confirma exclusao? (s/n): ");
    
    char confirmacao = ler_confirmacao();
    
    if (confirmacao == 's') {
        produtos[indice].ativo = 0;
        printf("Produto excluido com sucesso!\n");
        salvar_produtos();
    } else {
        printf("Exclusao cancelada.\n");
    }
    pausar();
}

// ============================================================================
//                   MÓDULO DE VENDEDORES - DANIEL
// ============================================================================

// Encontra o menor número de vendedor disponível (reutiliza números de vendedores excluídos)
int encontrar_menor_numero_vendedor_disponivel() {
    for (int numero = 1; numero < proximo_numero_vendedor; numero++) {
        int numero_existe = 0;
        for (int i = 0; i < num_vendedores; i++) {
            if (vendedores[i].numero == numero && vendedores[i].ativo) {
                numero_existe = 1;
                break;
            }
        }
        if (!numero_existe) {
            return numero; // Encontrou um número disponível
        }
    }
    return proximo_numero_vendedor; // Se não há números reutilizáveis, usa o próximo sequencial
}

// Busca vendedor pelo número e retorna seu índice
int buscar_vendedor_por_numero(int numero) {
    for (int i = 0; i < num_vendedores; i++) {
        if (vendedores[i].numero == numero && vendedores[i].ativo) {
            return i;  // Vendedor encontrado e ativo
        }
    }
    return -1;  // Vendedor não encontrado ou inativo
}

// Cadastra um novo vendedor no sistema
void cadastrar_vendedor() {
    // Verificar se há espaço disponível no array
    if (num_vendedores >= MAX_VENDEDORES) {
        printf("Limite maximo de vendedores atingido!\n");
        pausar();
        return;
    }

    Vendedor novo_vendedor;
    int opcao_numero;
    int menor_numero_disponivel = encontrar_menor_numero_vendedor_disponivel();

    printf("\n=== CADASTRAR VENDEDOR ===\n");
    
    printf("Nome do vendedor: ");
    fgets(novo_vendedor.nome, MAX_STRING, stdin);
    novo_vendedor.nome[strcspn(novo_vendedor.nome, "\n")] = 0;

    printf("Numero do vendedor:\n");
    printf("1 - Gerar automaticamente (%d)\n", menor_numero_disponivel);
    printf("2 - Inserir manualmente\n");
    printf("Escolha: ");
    opcao_numero = ler_opcao_valida(1, 2);

    if (opcao_numero == 1) {
        novo_vendedor.numero = menor_numero_disponivel;
        // Atualizar proximo_numero_vendedor se necessario
        if (menor_numero_disponivel >= proximo_numero_vendedor) {
            proximo_numero_vendedor = menor_numero_disponivel + 1;
        }
    } else if (opcao_numero == 2) {
        do {
            printf("Digite o numero: ");
            scanf("%d", &novo_vendedor.numero);
            limpar_buffer();
            
            if (buscar_vendedor_por_numero(novo_vendedor.numero) != -1) {
                printf("Numero ja existe! Digite outro numero.\n");
            }
        } while (buscar_vendedor_por_numero(novo_vendedor.numero) != -1);
        
        if (novo_vendedor.numero >= proximo_numero_vendedor) {
            proximo_numero_vendedor = novo_vendedor.numero + 1;
        }
    } else {
        printf("Opcao invalida! Cadastro cancelado.\n");
        pausar();
        return;
    }

    printf("Salario fixo: R$ ");
    scanf("%f", &novo_vendedor.salario_fixo);
    limpar_buffer();

    novo_vendedor.comissoes = 0.0;
    novo_vendedor.ativo = 1;
    vendedores[num_vendedores] = novo_vendedor;
    num_vendedores++;

    printf("Vendedor cadastrado com sucesso! Numero: %d\n", novo_vendedor.numero);
    salvar_vendedores();
    pausar();
}

// Lista todos os vendedores ativos cadastrados
void consultar_vendedores() {
    printf("\n=== CONSULTAR VENDEDORES ===\n");
    
    if (num_vendedores == 0) {
        printf("Nenhum vendedor cadastrado.\n");
        pausar();
        return;
    }

    // Criar array de indices dos vendedores ativos ordenados por numero
    int indices_ordenados[MAX_VENDEDORES];
    int count = 0;
    
    // Coletar indices dos vendedores ativos
    for (int i = 0; i < num_vendedores; i++) {
        if (vendedores[i].ativo) {
            indices_ordenados[count] = i;
            count++;
        }
    }
    
    // Ordenar indices por numero (bubble sort simples)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (vendedores[indices_ordenados[j]].numero > vendedores[indices_ordenados[j + 1]].numero) {
                int temp = indices_ordenados[j];
                indices_ordenados[j] = indices_ordenados[j + 1];
                indices_ordenados[j + 1] = temp;
            }
        }
    }

    printf("%-6s %-30s %-15s %-15s\n", "Numero", "Nome", "Salario Fixo", "Comissoes");
    printf("--------------------------------------------------------------------\n");
    
    // Exibir vendedores ordenados por numero
    for (int i = 0; i < count; i++) {
        int idx = indices_ordenados[i];
        printf("%-6d %-30s R$ %-12.2f R$ %-12.2f\n", 
               vendedores[idx].numero, 
               vendedores[idx].nome, 
               vendedores[idx].salario_fixo, 
               vendedores[idx].comissoes);
    }
    pausar();
}

// Altera dados de um vendedor existente
void alterar_vendedor() {
    int numero, indice;
    
    printf("\n=== ALTERAR VENDEDOR ===\n");
    printf("Digite o numero do vendedor: ");
    scanf("%d", &numero);
    limpar_buffer();

    indice = buscar_vendedor_por_numero(numero);
    if (indice == -1) {
        printf("Vendedor nao encontrado!\n");
        pausar();
        return;
    }

    printf("Vendedor encontrado: %s\n", vendedores[indice].nome);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar salario fixo\n");
    printf("Escolha: ");
    
    int opcao = ler_opcao_valida(1, 2);

    switch (opcao) {
        case 1:
            printf("Novo nome: ");
            fgets(vendedores[indice].nome, MAX_STRING, stdin);
            vendedores[indice].nome[strcspn(vendedores[indice].nome, "\n")] = 0;
            break;
        case 2:
            printf("Novo salario: R$ ");
            scanf("%f", &vendedores[indice].salario_fixo);
            limpar_buffer();
            break;
        default:
            printf("Opcao invalida!\n");
            pausar();
            return;
    }

    printf("Vendedor alterado com sucesso!\n");
    salvar_vendedores();
    pausar();
}

// Remove vendedor do sistema (exclusão lógica)
void excluir_vendedor() {
    int numero, indice;
    
    printf("\n=== EXCLUIR VENDEDOR ===\n");
    printf("Digite o numero do vendedor: ");
    scanf("%d", &numero);
    limpar_buffer();

    indice = buscar_vendedor_por_numero(numero);
    if (indice == -1) {
        printf("Vendedor nao encontrado!\n");
        pausar();
        return;
    }

    printf("Vendedor: %s\n", vendedores[indice].nome);
    printf("Confirma exclusao? (s/n): ");
    
    char confirmacao = ler_confirmacao();

    if (confirmacao == 's') {
        vendedores[indice].ativo = 0;
        printf("Vendedor excluido com sucesso!\n");
        salvar_vendedores();
    } else {
        printf("Exclusao cancelada.\n");
    }
    pausar();
}

// ============================================================================
//                   MÓDULO DE COMPRADORES - GUILHERME
// ============================================================================

// Busca comprador pelo CPF e retorna seu índice
int buscar_comprador_por_cpf(char *cpf) {
    for (int i = 0; i < num_compradores; i++) {
        if (strcmp(compradores[i].cpf, cpf) == 0 && compradores[i].ativo) {
            return i;  // Comprador encontrado e ativo
        }
    }
    return -1;  // Comprador não encontrado ou inativo
}

// Cadastra um novo comprador no sistema
void cadastrar_comprador() {
    // Verificar se há espaço disponível no array
    if (num_compradores >= MAX_COMPRADORES) {
        printf("Limite maximo de compradores atingido!\n");
        pausar();
        return;
    }

    Comprador novo_comprador;

    printf("\n=== CADASTRAR COMPRADOR ===\n");
    
    printf("Nome: ");
    fgets(novo_comprador.nome, MAX_STRING, stdin);
    novo_comprador.nome[strcspn(novo_comprador.nome, "\n")] = 0;

    do {
        printf("CPF: ");
        fgets(novo_comprador.cpf, 15, stdin);
        novo_comprador.cpf[strcspn(novo_comprador.cpf, "\n")] = 0;
        
        if (buscar_comprador_por_cpf(novo_comprador.cpf) != -1) {
            printf("CPF ja cadastrado! Digite outro CPF.\n");
        }
    } while (buscar_comprador_por_cpf(novo_comprador.cpf) != -1);

    printf("E-mail: ");
    fgets(novo_comprador.email, MAX_STRING, stdin);
    novo_comprador.email[strcspn(novo_comprador.email, "\n")] = 0;

    printf("\n--- ENDERECO DE ENTREGA ---\n");
    printf("Rua: ");
    fgets(novo_comprador.endereco.rua, MAX_STRING, stdin);
    novo_comprador.endereco.rua[strcspn(novo_comprador.endereco.rua, "\n")] = 0;

    printf("Bairro: ");
    fgets(novo_comprador.endereco.bairro, MAX_STRING, stdin);
    novo_comprador.endereco.bairro[strcspn(novo_comprador.endereco.bairro, "\n")] = 0;

    printf("Cidade: ");
    fgets(novo_comprador.endereco.cidade, MAX_STRING, stdin);
    novo_comprador.endereco.cidade[strcspn(novo_comprador.endereco.cidade, "\n")] = 0;

    printf("Estado (sigla): ");
    fgets(novo_comprador.endereco.estado, 3, stdin);
    novo_comprador.endereco.estado[strcspn(novo_comprador.endereco.estado, "\n")] = 0;
    limpar_buffer(); // Limpar buffer após ler estado

    printf("CEP: ");
    fgets(novo_comprador.endereco.cep, 10, stdin);
    novo_comprador.endereco.cep[strcspn(novo_comprador.endereco.cep, "\n")] = 0;

    novo_comprador.ativo = 1;
    compradores[num_compradores] = novo_comprador;
    num_compradores++;

    printf("Comprador cadastrado com sucesso!\n");
    salvar_compradores();
    pausar();
}

// Lista todos os compradores ativos cadastrados
void consultar_compradores() {
    printf("\n=== CONSULTAR COMPRADORES ===\n");
    
    if (num_compradores == 0) {
        printf("Nenhum comprador cadastrado.\n");
        pausar();
        return;
    }

    // Criar array de indices dos compradores ativos ordenados por nome
    int indices_ordenados[MAX_COMPRADORES];
    int count = 0;
    
    // Coletar indices dos compradores ativos
    for (int i = 0; i < num_compradores; i++) {
        if (compradores[i].ativo) {
            indices_ordenados[count] = i;
            count++;
        }
    }
    
    // Ordenar indices por nome (bubble sort simples)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(compradores[indices_ordenados[j]].nome, compradores[indices_ordenados[j + 1]].nome) > 0) {
                int temp = indices_ordenados[j];
                indices_ordenados[j] = indices_ordenados[j + 1];
                indices_ordenados[j + 1] = temp;
            }
        }
    }

    // Exibir compradores ordenados por nome
    for (int i = 0; i < count; i++) {
        int idx = indices_ordenados[i];
        printf("\nNome: %s\n", compradores[idx].nome);
        printf("CPF: %s\n", compradores[idx].cpf);
        printf("E-mail: %s\n", compradores[idx].email);
        printf("Endereco: %s, %s, %s - %s, CEP: %s\n",
               compradores[idx].endereco.rua,
               compradores[idx].endereco.bairro,
               compradores[idx].endereco.cidade,
               compradores[idx].endereco.estado,
               compradores[idx].endereco.cep);
        printf("----------------------------------------\n");
    }
    pausar();
}

// Altera dados de um comprador existente
void alterar_comprador() {
    char cpf[15];
    int indice;
    
    printf("\n=== ALTERAR COMPRADOR ===\n");
    printf("Digite o CPF do comprador: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    indice = buscar_comprador_por_cpf(cpf);
    if (indice == -1) {
        printf("Comprador nao encontrado!\n");
        pausar();
        return;
    }

    printf("Comprador encontrado: %s\n", compradores[indice].nome);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar e-mail\n");
    printf("3 - Alterar endereco\n");
    printf("Escolha: ");
    
    int opcao = ler_opcao_valida(1, 3);

    switch (opcao) {
        case 1:
            printf("Novo nome: ");
            fgets(compradores[indice].nome, MAX_STRING, stdin);
            compradores[indice].nome[strcspn(compradores[indice].nome, "\n")] = 0;
            break;
        case 2:
            printf("Novo e-mail: ");
            fgets(compradores[indice].email, MAX_STRING, stdin);
            compradores[indice].email[strcspn(compradores[indice].email, "\n")] = 0;
            break;
        case 3:
            printf("Nova rua: ");
            fgets(compradores[indice].endereco.rua, MAX_STRING, stdin);
            compradores[indice].endereco.rua[strcspn(compradores[indice].endereco.rua, "\n")] = 0;
            
            printf("Novo bairro: ");
            fgets(compradores[indice].endereco.bairro, MAX_STRING, stdin);
            compradores[indice].endereco.bairro[strcspn(compradores[indice].endereco.bairro, "\n")] = 0;
            
            printf("Nova cidade: ");
            fgets(compradores[indice].endereco.cidade, MAX_STRING, stdin);
            compradores[indice].endereco.cidade[strcspn(compradores[indice].endereco.cidade, "\n")] = 0;
            
            printf("Novo estado: ");
            fgets(compradores[indice].endereco.estado, 3, stdin);
            compradores[indice].endereco.estado[strcspn(compradores[indice].endereco.estado, "\n")] = 0;
            limpar_buffer(); // Limpar buffer após ler estado
            
            printf("Novo CEP: ");
            fgets(compradores[indice].endereco.cep, 10, stdin);
            compradores[indice].endereco.cep[strcspn(compradores[indice].endereco.cep, "\n")] = 0;
            break;
        default:
            printf("Opcao invalida!\n");
            pausar();
            return;
    }

    printf("Comprador alterado com sucesso!\n");
    salvar_compradores();
    pausar();
}

// Remove comprador do sistema (exclusão lógica)
void excluir_comprador() {
    char cpf[15];
    int indice;
    
    printf("\n=== EXCLUIR COMPRADOR ===\n");
    printf("Digite o CPF do comprador: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    indice = buscar_comprador_por_cpf(cpf);
    if (indice == -1) {
        printf("Comprador nao encontrado!\n");
        pausar();
        return;
    }

    printf("Comprador: %s\n", compradores[indice].nome);
    printf("Confirma exclusao? (s/n): ");
    
    char confirmacao = ler_confirmacao();

    if (confirmacao == 's') {
        compradores[indice].ativo = 0;
        printf("Comprador excluido com sucesso!\n");
        salvar_compradores();
    } else {
        printf("Exclusao cancelada.\n");
    }
    pausar();
}

// ============================================================================
//              MÓDULO DE VENDAS E INTEGRAÇÃO - GUSTAVO
// ============================================================================

// Encontra o menor código de venda disponível (reutiliza códigos de vendas excluídas)
int encontrar_menor_codigo_venda_disponivel() {
    for (int codigo = 1; codigo < proximo_codigo_venda; codigo++) {
        int codigo_existe = 0;
        for (int i = 0; i < num_vendas; i++) {
            if (vendas[i].codigo_venda == codigo && vendas[i].ativo) {
                codigo_existe = 1;
                break;
            }
        }
        if (!codigo_existe) {
            return codigo; // Encontrou um código disponível
        }
    }
    return proximo_codigo_venda; // Se não há códigos reutilizáveis, usa o próximo sequencial
}

// Busca venda pelo código e retorna seu índice
int buscar_venda_por_codigo(int codigo) {
    for (int i = 0; i < num_vendas; i++) {
        if (vendas[i].codigo_venda == codigo && vendas[i].ativo) {
            return i;  // Venda encontrada e ativa
        }
    }
    return -1;  // Venda não encontrada ou inativa
}

// Registra uma nova venda no sistema
void cadastrar_venda() {
    // Verificar se há espaço disponível no array
    if (num_vendas >= MAX_VENDAS) {
        printf("Limite maximo de vendas atingido!\n");
        pausar();
        return;
    }

    Venda nova_venda;
    char cpf[15];
    int numero_vendedor;
    int indice_comprador, indice_vendedor;

    printf("\n=== CADASTRAR VENDA ===\n");
    
    int menor_codigo_disponivel = encontrar_menor_codigo_venda_disponivel();
    nova_venda.codigo_venda = menor_codigo_disponivel;
    
    // Atualizar proximo_codigo_venda se necessario
    if (menor_codigo_disponivel >= proximo_codigo_venda) {
        proximo_codigo_venda = menor_codigo_disponivel + 1;
    }

    // Buscar comprador
    printf("CPF do comprador: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    indice_comprador = buscar_comprador_por_cpf(cpf);
    if (indice_comprador == -1) {
        printf("Comprador nao encontrado!\n");
        pausar();
        return;
    }
    nova_venda.codigo_comprador = indice_comprador;

    // Buscar vendedor
    printf("Numero do vendedor: ");
    scanf("%d", &numero_vendedor);
    limpar_buffer();

    indice_vendedor = buscar_vendedor_por_numero(numero_vendedor);
    if (indice_vendedor == -1) {
        printf("Vendedor nao encontrado!\n");
        pausar();
        return;
    }
    nova_venda.numero_vendedor = numero_vendedor;

    // Cadastrar itens da venda
    nova_venda.num_itens = 0;
    nova_venda.valor_total = 0.0;
    char continuar = 's';

    do {
        if (nova_venda.num_itens >= MAX_ITENS_VENDA) {
            printf("Limite maximo de itens por venda atingido!\n");
            break;
        }

        ItemVenda item;
        int codigo_produto, indice_produto;

        printf("\n--- ITEM %d ---\n", nova_venda.num_itens + 1);
        printf("Codigo do produto: ");
        scanf("%d", &codigo_produto);
        limpar_buffer();

        indice_produto = buscar_produto_por_codigo(codigo_produto);
        if (indice_produto == -1) {
            printf("Produto nao encontrado!\n");
            continue;
        }

        item.codigo_produto = codigo_produto;
        strcpy(item.nome_produto, produtos[indice_produto].nome);
        item.preco_unitario = produtos[indice_produto].preco_venda;

        printf("Produto: %s (Estoque: %d)\n", 
               produtos[indice_produto].nome, 
               produtos[indice_produto].quantidade_estoque);
        
        printf("Quantidade a vender: ");
        scanf("%d", &item.quantidade);
        limpar_buffer();

        if (item.quantidade > produtos[indice_produto].quantidade_estoque) {
            printf("Quantidade insuficiente em estoque!\n");
            continue;
        }

        item.preco_total = item.quantidade * item.preco_unitario;
        
        // Atualizar estoque
        produtos[indice_produto].quantidade_estoque -= item.quantidade;
        
        nova_venda.itens[nova_venda.num_itens] = item;
        nova_venda.num_itens++;
        nova_venda.valor_total += item.preco_total;

        printf("Item adicionado! Total do item: R$ %.2f\n", item.preco_total);
        
        if (nova_venda.num_itens < MAX_ITENS_VENDA) {
            printf("Adicionar mais itens? (s/n): ");
            continuar = ler_confirmacao();
        }

    } while (tolower(continuar) == 's' && nova_venda.num_itens < MAX_ITENS_VENDA);

    if (nova_venda.num_itens == 0) {
        printf("Venda cancelada - nenhum item adicionado.\n");
        pausar();
        return;
    }

    // Calcular comissão do vendedor (3%)
    float comissao = nova_venda.valor_total * 0.03;
    vendedores[indice_vendedor].comissoes += comissao;

    nova_venda.ativo = 1;
    vendas[num_vendas] = nova_venda;
    num_vendas++;

    printf("\nVenda cadastrada com sucesso!\n");
    printf("Codigo da venda: %d\n", nova_venda.codigo_venda);
    printf("Valor total: R$ %.2f\n", nova_venda.valor_total);
    printf("Comissao do vendedor: R$ %.2f\n", comissao);
    salvar_vendas();
    pausar();
}

// Lista todas as vendas ativas realizadas
void consultar_vendas() {
    printf("\n=== CONSULTAR VENDAS ===\n");
    
    if (num_vendas == 0) {
        printf("Nenhuma venda cadastrada.\n");
        pausar();
        return;
    }

    // Criar array de indices das vendas ativas ordenados por codigo
    int indices_ordenados[MAX_VENDAS];
    int count = 0;
    
    // Coletar indices das vendas ativas
    for (int i = 0; i < num_vendas; i++) {
        if (vendas[i].ativo) {
            indices_ordenados[count] = i;
            count++;
        }
    }
    
    // Ordenar indices por codigo_venda (bubble sort simples)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (vendas[indices_ordenados[j]].codigo_venda > vendas[indices_ordenados[j + 1]].codigo_venda) {
                int temp = indices_ordenados[j];
                indices_ordenados[j] = indices_ordenados[j + 1];
                indices_ordenados[j + 1] = temp;
            }
        }
    }

    // Exibir vendas ordenadas por codigo
    for (int i = 0; i < count; i++) {
        int idx = indices_ordenados[i];
        printf("\nCodigo da venda: %d\n", vendas[idx].codigo_venda);
        printf("Comprador: %s\n", compradores[vendas[idx].codigo_comprador].nome);
        printf("Vendedor: %s\n", vendedores[buscar_vendedor_por_numero(vendas[idx].numero_vendedor)].nome);
        printf("Valor total: R$ %.2f\n", vendas[idx].valor_total);
        printf("Itens:\n");
        
        for (int j = 0; j < vendas[idx].num_itens; j++) {
            printf("  - %s (Qtd: %d, Unit: R$ %.2f, Total: R$ %.2f)\n",
                   vendas[idx].itens[j].nome_produto,
                   vendas[idx].itens[j].quantidade,
                   vendas[idx].itens[j].preco_unitario,
                   vendas[idx].itens[j].preco_total);
        }
        printf("----------------------------------------\n");
    }
    pausar();
}

// Altera dados de uma venda existente
void alterar_venda() {
    int codigo, indice;
    
    printf("\n=== ALTERAR VENDA ===\n");
    printf("Digite o codigo da venda: ");
    scanf("%d", &codigo);
    limpar_buffer();

    indice = buscar_venda_por_codigo(codigo);
    if (indice == -1) {
        printf("Venda nao encontrada!\n");
        pausar();
        return;
    }

    printf("Venda encontrada - Codigo: %d\n", vendas[indice].codigo_venda);
    printf("Comprador: %s\n", compradores[vendas[indice].codigo_comprador].nome);
    printf("Valor total atual: R$ %.2f\n", vendas[indice].valor_total);
    printf("Itens atuais: %d\n", vendas[indice].num_itens);
    
    printf("\nOpcoes de alteracao:\n");
    printf("1 - Alterar quantidade de um item existente\n");
    printf("2 - Adicionar novo item a venda\n");
    printf("3 - Remover item da venda\n");
    printf("Escolha: ");
    
    int opcao = ler_opcao_valida(1, 3);
    
    switch (opcao) {
        case 1: {
            // Alterar quantidade de item existente
            if (vendas[indice].num_itens == 0) {
                printf("Esta venda nao possui itens!\n");
                break;
            }
            
            printf("\nItens da venda:\n");
            for (int i = 0; i < vendas[indice].num_itens; i++) {
                printf("%d - %s (Qtd: %d, Preco Unit: R$ %.2f)\n", 
                       i + 1, 
                       vendas[indice].itens[i].nome_produto,
                       vendas[indice].itens[i].quantidade,
                       vendas[indice].itens[i].preco_unitario);
            }
            
            printf("Digite o numero do item a alterar: ");
            int num_item;
            scanf("%d", &num_item);
            limpar_buffer();
            
            if (num_item < 1 || num_item > vendas[indice].num_itens) {
                printf("Item invalido!\n");
                break;
            }
            
            int idx_item = num_item - 1;
            int indice_produto = buscar_produto_por_codigo(vendas[indice].itens[idx_item].codigo_produto);
            
            if (indice_produto == -1) {
                printf("Produto nao encontrado no sistema!\n");
                break;
            }
            
            printf("Quantidade atual: %d\n", vendas[indice].itens[idx_item].quantidade);
            printf("Estoque disponivel: %d\n", produtos[indice_produto].quantidade_estoque + vendas[indice].itens[idx_item].quantidade);
            printf("Nova quantidade: ");
            
            int nova_quantidade;
            scanf("%d", &nova_quantidade);
            limpar_buffer();
            
            if (nova_quantidade <= 0) {
                printf("Quantidade deve ser maior que zero!\n");
                break;
            }
            
            // Verificar se ha estoque suficiente
            int estoque_disponivel = produtos[indice_produto].quantidade_estoque + vendas[indice].itens[idx_item].quantidade;
            if (nova_quantidade > estoque_disponivel) {
                printf("Quantidade insuficiente em estoque!\n");
                break;
            }
            
            // Atualizar estoque do produto
            produtos[indice_produto].quantidade_estoque += vendas[indice].itens[idx_item].quantidade; // Devolver quantidade antiga
            produtos[indice_produto].quantidade_estoque -= nova_quantidade; // Subtrair nova quantidade
            
            // Atualizar valor total da venda
            vendas[indice].valor_total -= vendas[indice].itens[idx_item].preco_total;
            vendas[indice].itens[idx_item].quantidade = nova_quantidade;
            vendas[indice].itens[idx_item].preco_total = nova_quantidade * vendas[indice].itens[idx_item].preco_unitario;
            vendas[indice].valor_total += vendas[indice].itens[idx_item].preco_total;
            
            printf("Quantidade alterada com sucesso!\n");
            printf("Novo total do item: R$ %.2f\n", vendas[indice].itens[idx_item].preco_total);
            printf("Novo valor total da venda: R$ %.2f\n", vendas[indice].valor_total);
            break;
        }
        
        case 2: {
            // Adicionar novo item
            if (vendas[indice].num_itens >= MAX_ITENS_VENDA) {
                printf("Limite maximo de itens por venda atingido!\n");
                break;
            }
            
            ItemVenda novo_item;
            int codigo_produto, indice_produto;
            
            printf("Codigo do produto a adicionar: ");
            scanf("%d", &codigo_produto);
            limpar_buffer();
            
            indice_produto = buscar_produto_por_codigo(codigo_produto);
            if (indice_produto == -1) {
                printf("Produto nao encontrado!\n");
                break;
            }
            
            // Verificar se o produto ja esta na venda
            int produto_ja_existe = 0;
            for (int i = 0; i < vendas[indice].num_itens; i++) {
                if (vendas[indice].itens[i].codigo_produto == codigo_produto) {
                    produto_ja_existe = 1;
                    break;
                }
            }
            
            if (produto_ja_existe) {
                printf("Este produto ja esta na venda! Use a opcao 1 para alterar a quantidade.\n");
                break;
            }
            
            novo_item.codigo_produto = codigo_produto;
            strcpy(novo_item.nome_produto, produtos[indice_produto].nome);
            novo_item.preco_unitario = produtos[indice_produto].preco_venda;
            
            printf("Produto: %s (Estoque: %d)\n", 
                   produtos[indice_produto].nome, 
                   produtos[indice_produto].quantidade_estoque);
            
            printf("Quantidade a adicionar: ");
            scanf("%d", &novo_item.quantidade);
            limpar_buffer();
            
            if (novo_item.quantidade > produtos[indice_produto].quantidade_estoque) {
                printf("Quantidade insuficiente em estoque!\n");
                break;
            }
            
            novo_item.preco_total = novo_item.quantidade * novo_item.preco_unitario;
            
            // Atualizar estoque
            produtos[indice_produto].quantidade_estoque -= novo_item.quantidade;
            
            // Adicionar item à venda
            vendas[indice].itens[vendas[indice].num_itens] = novo_item;
            vendas[indice].num_itens++;
            vendas[indice].valor_total += novo_item.preco_total;
            
            printf("Item adicionado com sucesso!\n");
            printf("Total do item: R$ %.2f\n", novo_item.preco_total);
            printf("Novo valor total da venda: R$ %.2f\n", vendas[indice].valor_total);
            break;
        }
        
        case 3: {
            // Remover item
            if (vendas[indice].num_itens == 0) {
                printf("Esta venda nao possui itens!\n");
                break;
            }
            
            if (vendas[indice].num_itens == 1) {
                printf("Nao e possivel remover o unico item da venda!\n");
                printf("Para excluir a venda, use a opcao 'Excluir venda' no menu.\n");
                break;
            }
            
            printf("\nItens da venda:\n");
            for (int i = 0; i < vendas[indice].num_itens; i++) {
                printf("%d - %s (Qtd: %d, Total: R$ %.2f)\n", 
                       i + 1, 
                       vendas[indice].itens[i].nome_produto,
                       vendas[indice].itens[i].quantidade,
                       vendas[indice].itens[i].preco_total);
            }
            
            printf("Digite o numero do item a remover: ");
            int num_item;
            scanf("%d", &num_item);
            limpar_buffer();
            
            if (num_item < 1 || num_item > vendas[indice].num_itens) {
                printf("Item invalido!\n");
                break;
            }
            
            int idx_item = num_item - 1;
            
            // Devolver quantidade ao estoque
            int indice_produto = buscar_produto_por_codigo(vendas[indice].itens[idx_item].codigo_produto);
            if (indice_produto != -1) {
                produtos[indice_produto].quantidade_estoque += vendas[indice].itens[idx_item].quantidade;
            }
            
            // Remover valor do total da venda
            vendas[indice].valor_total -= vendas[indice].itens[idx_item].preco_total;
            
            // Remover item do array (mover todos os itens posteriores uma posição para frente)
            for (int i = idx_item; i < vendas[indice].num_itens - 1; i++) {
                vendas[indice].itens[i] = vendas[indice].itens[i + 1];
            }
            vendas[indice].num_itens--;
            
            printf("Item removido com sucesso!\n");
            printf("Novo valor total da venda: R$ %.2f\n", vendas[indice].valor_total);
            break;
        }
    }
    
    // Recalcular comissão do vendedor
    int indice_vendedor = buscar_vendedor_por_numero(vendas[indice].numero_vendedor);
    if (indice_vendedor != -1) {
        // Remover comissão antiga e adicionar nova
        float comissao_antiga = (vendas[indice].valor_total + 
                               (vendas[indice].valor_total - vendas[indice].valor_total)) * 0.03;
        float nova_comissao = vendas[indice].valor_total * 0.03;
        vendedores[indice_vendedor].comissoes = vendedores[indice_vendedor].comissoes - comissao_antiga + nova_comissao;
    }
    
    printf("\nVenda alterada com sucesso!\n");
    salvar_vendas();
    salvar_produtos();
    salvar_vendedores();
    pausar();
}

// Remove venda do sistema (exclusão lógica)
void excluir_venda() {
    int codigo, indice;
    
    printf("\n=== EXCLUIR VENDA ===\n");
    printf("Digite o codigo da venda: ");
    scanf("%d", &codigo);
    limpar_buffer();

    indice = buscar_venda_por_codigo(codigo);
    if (indice == -1) {
        printf("Venda nao encontrada!\n");
        pausar();
        return;
    }

    printf("Venda codigo %d - Valor: R$ %.2f\n", 
           vendas[indice].codigo_venda, 
           vendas[indice].valor_total);
    printf("Confirma exclusao? (s/n): ");
    
    char confirmacao = ler_confirmacao();

    if (confirmacao == 's') {
        // Reverter estoque dos produtos
        for (int i = 0; i < vendas[indice].num_itens; i++) {
            int indice_produto = buscar_produto_por_codigo(vendas[indice].itens[i].codigo_produto);
            if (indice_produto != -1) {
                produtos[indice_produto].quantidade_estoque += vendas[indice].itens[i].quantidade;
            }
        }
        // Reverter comissao do vendedor
        int indice_vendedor = buscar_vendedor_por_numero(vendas[indice].numero_vendedor);
        if (indice_vendedor != -1) {
            float comissao = vendas[indice].valor_total * 0.03;
            vendedores[indice_vendedor].comissoes -= comissao;
        }
        vendas[indice].ativo = 0;
        printf("Venda excluida com sucesso!\n");
        salvar_vendas();
    } else {
        printf("Exclusao cancelada.\n");
    }
    pausar();
}

// Emite nota fiscal de uma venda específica
void emitir_nota_fiscal() {
    int codigo, indice;
    
    printf("\n=== EMITIR NOTA FISCAL ===\n");
    printf("Digite o codigo da venda: ");
    scanf("%d", &codigo);
    limpar_buffer();

    // Buscar venda pelo código
    indice = buscar_venda_por_codigo(codigo);
    if (indice == -1) {
        printf("Venda nao encontrada!\n");
        pausar();
        return;
    }

    // Obter referências para facilitar acesso aos dados
    Venda *venda = &vendas[indice];
    Comprador *comprador = &compradores[venda->codigo_comprador];
    float frete = calcular_frete(venda->valor_total);
    float total_com_frete = venda->valor_total + frete;

    printf("\n");
    printf("===========================================\n");
    printf("               NOTA FISCAL                 \n");
    printf("===========================================\n");
    printf("Codigo da venda: %d\n", venda->codigo_venda);
    printf("\nDADOS DO COMPRADOR:\n");
    printf("Nome: %s\n", comprador->nome);
    printf("CPF: %s\n", comprador->cpf);
    printf("E-mail: %s\n", comprador->email);
    printf("Endereco de entrega:\n");
    printf("%s, %s\n", comprador->endereco.rua, comprador->endereco.bairro);
    printf("%s - %s\n", comprador->endereco.cidade, comprador->endereco.estado);
    printf("CEP: %s\n", comprador->endereco.cep);
    
    printf("\nPRODUTOS VENDIDOS:\n");
    printf("%-30s %-6s %-10s %-12s\n", "Produto", "Qtd", "Preco Unit", "Total");
    printf("-----------------------------------------------------------\n");
    
    for (int i = 0; i < venda->num_itens; i++) {
        printf("%-30s %-6d R$ %-8.2f R$ %-9.2f\n",
               venda->itens[i].nome_produto,
               venda->itens[i].quantidade,
               venda->itens[i].preco_unitario,
               venda->itens[i].preco_total);
    }
    
    printf("-----------------------------------------------------------\n");
    printf("Subtotal: R$ %.2f\n", venda->valor_total);
    
    if (frete > 0) {
        printf("Frete: R$ %.2f\n", frete);
    } else {
        printf("Frete: GRATIS\n");
    }
    
    printf("TOTAL GERAL: R$ %.2f\n", total_com_frete);
    printf("===========================================\n");
    
    pausar();
}

// ============================================================================
//                     SISTEMA DE MENUS - INTEGRAÇÃO GUSTAVO
// ============================================================================

// Exibe menu específico de produtos
void menu_produtos() {
    int opcao;
    
    do {
        system("cls");  // Limpar tela (Windows)
        printf("=== MENU PRODUTOS ===\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar produtos\n");
        printf("3 - Alterar produto\n");
        printf("4 - Excluir produto\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        opcao = ler_opcao_valida(0, 4);

        switch (opcao) {
            case 1: cadastrar_produto(); break;   // LUCAS: Cadastro
            case 2: consultar_produtos(); break;  // LUCAS: Listagem
            case 3: alterar_produto(); break;     // LUCAS: Alteração
            case 4: excluir_produto(); break;     // LUCAS: Exclusão
            case 0: break;  // Volta ao menu principal
        }
    } while (opcao != 0);
}

// Exibe menu específico de vendedores
void menu_vendedores() {
    int opcao;
    
    do {
        system("cls");  // Limpar tela (Windows)
        printf("=== MENU VENDEDORES ===\n");
        printf("1 - Cadastrar vendedor\n");
        printf("2 - Consultar vendedores\n");
        printf("3 - Alterar vendedor\n");
        printf("4 - Excluir vendedor\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        opcao = ler_opcao_valida(0, 4);

        switch (opcao) {
            case 1: cadastrar_vendedor(); break;   // DANIEL: Cadastro
            case 2: consultar_vendedores(); break; // DANIEL: Listagem (com comissões)
            case 3: alterar_vendedor(); break;     // DANIEL: Alteração
            case 4: excluir_vendedor(); break;     // DANIEL: Exclusão
            case 0: break;  // Volta ao menu principal
        }
    } while (opcao != 0);
}

// Exibe menu específico de compradores
void menu_compradores() {
    int opcao;
    
    do {
        system("cls");
        printf("=== MENU COMPRADORES ===\n");
        printf("1 - Cadastrar comprador\n");
        printf("2 - Consultar compradores\n");
        printf("3 - Alterar comprador\n");
        printf("4 - Excluir comprador\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        opcao = ler_opcao_valida(0, 4);

        switch (opcao) {
            case 1: cadastrar_comprador(); break;   // GUILHERME: Cadastro com endereço
            case 2: consultar_compradores(); break; // GUILHERME: Listagem completa
            case 3: alterar_comprador(); break;     // GUILHERME: Alteração
            case 4: excluir_comprador(); break;     // GUILHERME: Exclusão
            case 0: break;  // Volta ao menu principal
        }
    } while (opcao != 0);
}

// Exibe menu específico de vendas
void menu_vendas() {
    int opcao;
    
    do {
        system("cls");  // Limpar tela (Windows)
        printf("=== MENU VENDAS ===\n");
        printf("1 - Cadastrar venda\n");      // GUSTAVO: Integração completa
        printf("2 - Consultar vendas\n");     // GUSTAVO: Relatórios
        printf("3 - Alterar venda\n");        // GUSTAVO: Alteração
        printf("4 - Excluir venda\n");        // GUSTAVO: Exclusão com reversão
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        opcao = ler_opcao_valida(0, 4);

        switch (opcao) {
            case 1: cadastrar_venda(); break;
            case 2: consultar_vendas(); break;
            case 3: alterar_venda(); break;
            case 4: excluir_venda(); break;
            case 0: break;
        }
    } while (opcao != 0);
}

// Exibe menu principal do sistema
void menu_principal() {
    int opcao;
    
    do {
        system("cls");
        printf("========================================\n");
        printf("       SISTEMA DE VENDAS v1.0          \n");
        printf("========================================\n");
        printf("1 - Gerenciar Produtos\n");        // LUCAS: Acessa menu_produtos()
        printf("2 - Gerenciar Vendedores\n");      // DANIEL: Acessa menu_vendedores()
        printf("3 - Gerenciar Compradores\n");     // GUILHERME: Acessa menu_compradores()
        printf("4 - Gerenciar Vendas\n");          // GUSTAVO: Acessa menu_vendas()
        printf("5 - Emitir Nota Fiscal\n");        // GUSTAVO: Relatório integrado
        printf("0 - SAIR\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        opcao = ler_opcao_valida(0, 5);

        switch (opcao) {
            case 1: menu_produtos(); break;         // LUCAS: Módulo produtos
            case 2: menu_vendedores(); break;       // DANIEL: Módulo vendedores
            case 3: menu_compradores(); break;      // GUILHERME: Módulo compradores
            case 4: menu_vendas(); break;           // GUSTAVO: Módulo vendas
            case 5: emitir_nota_fiscal(); break;    // GUSTAVO: Nota fiscal
            case 0: 
                printf("Encerrando sistema...\n");
                break;
        }
    } while (opcao != 0);
}

// ============================================================================
//                           FUNÇÃO PRINCIPAL
// ============================================================================

// Função principal do sistema de vendas
int main() {
    printf("Inicializando Sistema de Vendas...\n");
    carregar_todos_dados();
    
    // ========================================================================
    // INICIALIZAÇÃO DE DADOS DE EXEMPLO PARA DEMONSTRAÇÃO
    // ========================================================================
    
    // ------------------------------------------------------------------------
    // PRODUTOS DE EXEMPLO - RESPONSÁVEL: LUCAS SIQUEIRA
    // ------------------------------------------------------------------------
    strcpy(produtos[0].nome, "Notebook Dell");
    produtos[0].codigo = 1;
    produtos[0].quantidade_estoque = 10;
    produtos[0].preco_venda = 2500.00;
    produtos[0].ativo = 1;
    
    strcpy(produtos[1].nome, "Mouse Wireless");
    produtos[1].codigo = 2;
    produtos[1].quantidade_estoque = 50;
    produtos[1].preco_venda = 85.00;
    produtos[1].ativo = 1;
    
    num_produtos = 2;
    proximo_codigo_produto = 3;
    
    // ------------------------------------------------------------------------
    // VENDEDOR DE EXEMPLO - RESPONSÁVEL: DANIEL
    // ------------------------------------------------------------------------
    strcpy(vendedores[0].nome, "Joao Silva");
    vendedores[0].numero = 1;
    vendedores[0].salario_fixo = 2000.00;
    vendedores[0].comissoes = 0.0;  // Será atualizado conforme vendas
    vendedores[0].ativo = 1;
    
    num_vendedores = 1;
    proximo_numero_vendedor = 2;
    
    // ------------------------------------------------------------------------
    // COMPRADOR DE EXEMPLO - RESPONSÁVEL: GUILHERME
    // ------------------------------------------------------------------------
    strcpy(compradores[0].nome, "Maria Santos");
    strcpy(compradores[0].cpf, "123.456.789-00");
    strcpy(compradores[0].email, "maria@email.com");
    strcpy(compradores[0].endereco.rua, "Rua das Flores, 123");
    strcpy(compradores[0].endereco.bairro, "Centro");
    strcpy(compradores[0].endereco.cidade, "Sao Paulo");
    strcpy(compradores[0].endereco.estado, "SP");
    strcpy(compradores[0].endereco.cep, "01234-567");
    compradores[0].ativo = 1;
    
    num_compradores = 1;
    
    // ========================================================================
    // INÍCIO DO SISTEMA
    // ========================================================================
    printf("Sistema inicializado com dados de exemplo.\n");
    printf("Equipe: Lucas, Daniel, Guilherme, Gustavo\n");
    printf("Pressione Enter para continuar...");
    getchar();
    menu_principal();  // GUSTAVO: Chama menu principal integrado
    salvar_todos_dados();
    return 0;  // Encerramento do programa
}

/*
===============================================================================
                               FIM DO ARQUIVO
===============================================================================
RESUMO DA DIVISÃO DE RESPONSABILIDADES:

🔧 LUCAS SIQUEIRA - Módulo de Produtos:
   ✅ Estrutura Produto
   ✅ Funções: cadastrar_produto(), consultar_produtos(), alterar_produto(),
              excluir_produto(), buscar_produto_por_codigo()
   ✅ Menu: menu_produtos()
   ✅ Dados de exemplo: produtos iniciais

🤝 DANIEL - Módulo de Vendedores:
   ✅ Estrutura Vendedor
   ✅ Funções: cadastrar_vendedor(), consultar_vendedores(), alterar_vendedor(),
              excluir_vendedor(), buscar_vendedor_por_numero()
   ✅ Menu: menu_vendedores()
   ✅ Sistema de comissões (3% por venda)
   ✅ Dados de exemplo: vendedor inicial

🏠 GUILHERME - Módulo de Compradores:
   ✅ Estruturas: Comprador, Endereco
   ✅ Funções: cadastrar_comprador(), consultar_compradores(), alterar_comprador(),
              excluir_comprador(), buscar_comprador_por_cpf()
   ✅ Menu: menu_compradores()
   ✅ Gestão completa de endereços de entrega
   ✅ Dados de exemplo: comprador inicial

🎯 GUSTAVO - Módulo de Vendas e Integração:
   ✅ Estruturas: Venda, ItemVenda
   ✅ Funções: cadastrar_venda(), consultar_vendas(), alterar_venda(),
              excluir_venda(), buscar_venda_por_codigo(), emitir_nota_fiscal()
   ✅ Funções auxiliares: limpar_buffer(), pausar(), calcular_frete()
   ✅ Menu: menu_vendas(), menu_principal()
   ✅ Integração entre todos os módulos
   ✅ Função main() e inicialização do sistema
   ✅ Cálculo de comissões e atualizações de estoque

🏗️ TRABALHO COLABORATIVO:
   ✅ Definições globais (MAX_*, estruturas compartilhadas)
   ✅ Arrays globais e contadores
   ✅ Padronização de comentários e documentação
   ✅ Sistema de menus integrado
   ✅ Exclusão lógica em todos os módulos

===============================================================================
*/

// ============================================================================
//                    FUNCOES DE ARQUIVOS - GUSTAVO
// ============================================================================

// Salva dados dos produtos em arquivo
void salvar_produtos() {
    FILE *arquivo = fopen("produtos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo produtos.txt!\n");
        return;
    }
    for (int i = 0; i < num_produtos; i++) {
        fprintf(arquivo, "%d;%s;%d;%.2f;%d\n",
                produtos[i].codigo,
                produtos[i].nome,
                produtos[i].quantidade_estoque,
                produtos[i].preco_venda,
                produtos[i].ativo);
    }
    fclose(arquivo);
}

// Carrega dados dos produtos do arquivo
void carregar_produtos() {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) return;
    num_produtos = 0;
    char linha[300];
    while (fgets(linha, sizeof(linha), arquivo) && num_produtos < MAX_PRODUTOS) {
        char *token = strtok(linha, ";");
        if (token != NULL) produtos[num_produtos].codigo = atoi(token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(produtos[num_produtos].nome, token);
        token = strtok(NULL, ";");
        if (token != NULL) produtos[num_produtos].quantidade_estoque = atoi(token);
        token = strtok(NULL, ";");
        if (token != NULL) produtos[num_produtos].preco_venda = atof(token);
        token = strtok(NULL, ";");
        if (token != NULL) produtos[num_produtos].ativo = atoi(token);
        num_produtos++;
        if (produtos[num_produtos-1].codigo >= proximo_codigo_produto) {
            proximo_codigo_produto = produtos[num_produtos-1].codigo + 1;
        }
    }
    fclose(arquivo);
}

// Salva dados dos vendedores em arquivo
void salvar_vendedores() {
    FILE *arquivo = fopen("vendedores.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo vendedores.txt!\n");
        return;
    }
    for (int i = 0; i < num_vendedores; i++) {
        fprintf(arquivo, "%d;%s;%.2f;%.2f;%d\n",
                vendedores[i].numero,
                vendedores[i].nome,
                vendedores[i].salario_fixo,
                vendedores[i].comissoes,
                vendedores[i].ativo);
    }
    fclose(arquivo);
}

// Carrega dados dos vendedores do arquivo
void carregar_vendedores() {
    FILE *arquivo = fopen("vendedores.txt", "r");
    if (arquivo == NULL) return;
    num_vendedores = 0;
    char linha[300];
    while (fgets(linha, sizeof(linha), arquivo) && num_vendedores < MAX_VENDEDORES) {
        char *token = strtok(linha, ";");
        if (token != NULL) vendedores[num_vendedores].numero = atoi(token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(vendedores[num_vendedores].nome, token);
        token = strtok(NULL, ";");
        if (token != NULL) vendedores[num_vendedores].salario_fixo = atof(token);
        token = strtok(NULL, ";");
        if (token != NULL) vendedores[num_vendedores].comissoes = atof(token);
        token = strtok(NULL, ";");
        if (token != NULL) vendedores[num_vendedores].ativo = atoi(token);
        num_vendedores++;
        if (vendedores[num_vendedores-1].numero >= proximo_numero_vendedor) {
            proximo_numero_vendedor = vendedores[num_vendedores-1].numero + 1;
        }
    }
    fclose(arquivo);
}

// Salva dados dos compradores em arquivo
void salvar_compradores() {
    FILE *arquivo = fopen("compradores.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo compradores.txt!\n");
        return;
    }
    for (int i = 0; i < num_compradores; i++) {
        fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s;%s;%d\n",
                compradores[i].nome,
                compradores[i].cpf,
                compradores[i].email,
                compradores[i].endereco.rua,
                compradores[i].endereco.bairro,
                compradores[i].endereco.cidade,
                compradores[i].endereco.estado,
                compradores[i].endereco.cep,
                compradores[i].ativo);
    }
    fclose(arquivo);
}

// Carrega dados dos compradores do arquivo
void carregar_compradores() {
    FILE *arquivo = fopen("compradores.txt", "r");
    if (arquivo == NULL) return;
    num_compradores = 0;
    char linha[500];
    while (fgets(linha, sizeof(linha), arquivo) && num_compradores < MAX_COMPRADORES) {
        char *token = strtok(linha, ";");
        if (token != NULL) strcpy(compradores[num_compradores].nome, token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(compradores[num_compradores].cpf, token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(compradores[num_compradores].email, token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(compradores[num_compradores].endereco.rua, token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(compradores[num_compradores].endereco.bairro, token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(compradores[num_compradores].endereco.cidade, token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(compradores[num_compradores].endereco.estado, token);
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(compradores[num_compradores].endereco.cep, token);
        token = strtok(NULL, ";");
        if (token != NULL) compradores[num_compradores].ativo = atoi(token);
        num_compradores++;
    }
    fclose(arquivo);
}

// Salva dados das vendas em arquivo
void salvar_vendas() {
    FILE *arquivo = fopen("vendas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo vendas.txt!\n");
        return;
    }
    for (int i = 0; i < num_vendas; i++) {
        fprintf(arquivo, "%d;%d;%d;%d;%.2f;%d;",
                vendas[i].codigo_venda,
                vendas[i].codigo_comprador,
                vendas[i].numero_vendedor,
                vendas[i].num_itens,
                vendas[i].valor_total,
                vendas[i].ativo);
        for (int j = 0; j < vendas[i].num_itens; j++) {
            fprintf(arquivo, "%d,%s,%d,%.2f,%.2f",
                    vendas[i].itens[j].codigo_produto,
                    vendas[i].itens[j].nome_produto,
                    vendas[i].itens[j].quantidade,
                    vendas[i].itens[j].preco_unitario,
                    vendas[i].itens[j].preco_total);
            if (j < vendas[i].num_itens - 1) {
                fprintf(arquivo, "|");
            }
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

// Carrega dados das vendas do arquivo
void carregar_vendas() {
    FILE *arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL) return;
    num_vendas = 0;
    char linha[1000];
    while (fgets(linha, sizeof(linha), arquivo) && num_vendas < MAX_VENDAS) {
        char *token = strtok(linha, ";");
        if (token != NULL) vendas[num_vendas].codigo_venda = atoi(token);
        token = strtok(NULL, ";");
        if (token != NULL) vendas[num_vendas].codigo_comprador = atoi(token);
        token = strtok(NULL, ";");
        if (token != NULL) vendas[num_vendas].numero_vendedor = atoi(token);
        token = strtok(NULL, ";");
        if (token != NULL) vendas[num_vendas].num_itens = atoi(token);
        token = strtok(NULL, ";");
        if (token != NULL) vendas[num_vendas].valor_total = atof(token);
        token = strtok(NULL, ";");
        if (token != NULL) vendas[num_vendas].ativo = atoi(token);
        token = strtok(NULL, "\n");
        if (token != NULL && strlen(token) > 0) {
            char *item_token = strtok(token, "|");
            int item_index = 0;
            while (item_token != NULL && item_index < vendas[num_vendas].num_itens) {
                char *campo = strtok(item_token, ",");
                if (campo != NULL) vendas[num_vendas].itens[item_index].codigo_produto = atoi(campo);
                campo = strtok(NULL, ",");
                if (campo != NULL) strcpy(vendas[num_vendas].itens[item_index].nome_produto, campo);
                campo = strtok(NULL, ",");
                if (campo != NULL) vendas[num_vendas].itens[item_index].quantidade = atoi(campo);
                campo = strtok(NULL, ",");
                if (campo != NULL) vendas[num_vendas].itens[item_index].preco_unitario = atof(campo);
                campo = strtok(NULL, ",");
                if (campo != NULL) vendas[num_vendas].itens[item_index].preco_total = atof(campo);
                item_index++;
                item_token = strtok(NULL, "|");
            }
        }
        num_vendas++;
        if (vendas[num_vendas-1].codigo_venda >= proximo_codigo_venda) {
            proximo_codigo_venda = vendas[num_vendas-1].codigo_venda + 1;
        }
    }
    fclose(arquivo);
}

// Salva todos os dados em seus respectivos arquivos
void salvar_todos_dados() {
    salvar_produtos();
    salvar_vendedores();
    salvar_compradores();
    salvar_vendas();
}

// Carrega todos os dados dos arquivos do sistema
void carregar_todos_dados() {
    carregar_produtos();
    carregar_vendedores();
    carregar_compradores();
    carregar_vendas();
}
