/*
===============================================================================
                        SISTEMA DE VENDAS - TRABALHO PRÁTICO 2025/1
===============================================================================
Equipe:
- Lucas Siqueira  : Módulo de Produtos (CRUD Produtos + Estruturas)
- Daniel          : Módulo de Vendedores (CRUD Vendedores + Comissões)
- Guilherme       : Módulo de Compradores (CRUD Compradores + Endereços)
- Gustavo         : Módulo de Vendas (CRUD Vendas + Integração + Relatórios)

Metodologia: Scrum com 4 sprints de 3-4 dias cada
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_PRODUTOS 100
#define MAX_STRING 100

typedef struct {
    char nome[MAX_STRING];
    int codigo;
    int quantidade_estoque;
    float preco_venda;
    int ativo;
} Produto;

Produto produtos[MAX_PRODUTOS];
int num_produtos = 0;
int proximo_codigo_produto = 1;

void cadastrar_produto();
void consultar_produtos();
void alterar_produto();
void excluir_produto();
int buscar_produto_por_codigo(int codigo);
void menu_produtos();
void limpar_buffer();
void pausar();

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

int buscar_produto_por_codigo(int codigo) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo && produtos[i].ativo) {
            return i;
        }
    }
    return -1;
}

void menu_produtos() {
    int opcao;
    
    do {
        system("cls");
        printf("=======================================\n");
        printf("=== MENU PRODUTOS ===\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar produtos\n");
        printf("3 - Alterar produto\n");
        printf("4 - Excluir produto\n");
        printf("0 - Sair\n");
        printf("=======================================\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_produto(); break;
            case 2: consultar_produtos(); break;
            case 3: alterar_produto(); break;
            case 4: excluir_produto(); break;     
            case 0: break;
            default: 
                printf("Opção inválida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

void cadastrar_produto() {
    if (num_produtos >= MAX_PRODUTOS) {
        printf("Limite máximo de produtos atingido!\n");
        pausar();
        return;
    }

    Produto novo_produto;
    int opcao_codigo;

    printf("\n=== CADASTRAR PRODUTO ===\n");
    
    printf("Nome do produto: ");
    fgets(novo_produto.nome, MAX_STRING, stdin);
    novo_produto.nome[strcspn(novo_produto.nome, "\n")] = 0;

    printf("Código do produto:\n");
    printf("1 - Gerar automaticamente (%d)\n", proximo_codigo_produto);
    printf("2 - Inserir manualmente\n");
    printf("Escolha: ");
    scanf("%d", &opcao_codigo);
    limpar_buffer();

    if (opcao_codigo == 1) {
        novo_produto.codigo = proximo_codigo_produto++;
    } else {
        do {
            printf("Digite o código: ");
            scanf("%d", &novo_produto.codigo);
            limpar_buffer();
            
            if (buscar_produto_por_codigo(novo_produto.codigo) != -1) {
                printf("Código já existe! Digite outro código.\n");
            }
        } while (buscar_produto_por_codigo(novo_produto.codigo) != -1);
        
        if (novo_produto.codigo >= proximo_codigo_produto) {
            proximo_codigo_produto = novo_produto.codigo + 1;
        }
    }

    printf("Quantidade em estoque: ");
    scanf("%d", &novo_produto.quantidade_estoque);
    
    printf("Preço de venda: R$ ");
    scanf("%f", &novo_produto.preco_venda);
    limpar_buffer();

    novo_produto.ativo = 1;
    produtos[num_produtos] = novo_produto;
    num_produtos++;

    printf("Produto cadastrado com sucesso! Código: %d\n", novo_produto.codigo);
    pausar();
}

void consultar_produtos() {
    printf("\n=== CONSULTAR PRODUTOS ===\n");
    
    if (num_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    printf("%-6s %-30s %-10s %-12s\n", "Código", "Nome", "Estoque", "Preço");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].ativo) {
            printf("%-6d %-30s %-10d R$ %-9.2f\n", 
                   produtos[i].codigo, 
                   produtos[i].nome, 
                   produtos[i].quantidade_estoque, 
                   produtos[i].preco_venda);
        }
    }
    pausar();
}

void alterar_produto() {
    int codigo, indice;
    
    printf("\n=== ALTERAR PRODUTO ===\n");
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    limpar_buffer();

    indice = buscar_produto_por_codigo(codigo);
    if (indice == -1) {
        printf("Produto não encontrado!\n");
        pausar();
        return;
    }

    printf("Produto encontrado: %s\n", produtos[indice].nome);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar quantidade em estoque\n");
    printf("3 - Alterar preço de venda\n");
    printf("Escolha: ");
    
    int opcao;
    scanf("%d", &opcao);
    limpar_buffer();

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
            printf("Novo preço: R$ ");
            scanf("%f", &produtos[indice].preco_venda);
            limpar_buffer();
            break;
        default:
            printf("Opção inválida!\n");
            pausar();
            return;
    }

    printf("Produto alterado com sucesso!\n");
    pausar();
}

void excluir_produto() {
    int codigo, indice;
    
    printf("\n=== EXCLUIR PRODUTO ===\n");
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    limpar_buffer();

    indice = buscar_produto_por_codigo(codigo);
    if (indice == -1) {
        printf("Produto não encontrado!\n");
        pausar();
        return;
    }

    printf("Produto: %s\n", produtos[indice].nome);
    printf("Confirma exclusão? (s/n): ");
    
    char confirmacao;
    scanf("%c", &confirmacao);
    limpar_buffer();

    if (tolower(confirmacao) == 's') {
        produtos[indice].ativo = 0;
        printf("Produto excluído com sucesso!\n");
    } else {
        printf("Exclusão cancelada.\n");
    }
    pausar();
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    printf("=======================================\n");
    printf("  SISTEMA DE VENDAS - MÓDULO PRODUTOS\n");
    printf("  Responsável: Lucas Siqueira\n");
    printf("  Sprint 1 - Implementação CRUD\n");
    printf("=======================================\n");
    printf("Pressione Enter para continuar...");
    getchar();
    
    menu_produtos();
    
    printf("\nObrigado por usar o sistema!\n");
    return 0;
}