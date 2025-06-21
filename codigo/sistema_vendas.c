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
        printf("=== MENU PRODUTOS ===\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar produtos\n");
        printf("3 - Alterar produto\n");
        printf("4 - Excluir produto\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_produto(); break;
            case 2: 
                printf("Consulta em desenvolvimento!\n");
                pausar();
                break;
            case 3: 
                printf("Alteração em desenvolvimento!\n");
                pausar();
                break;
            case 4: 
                printf("Exclusão em desenvolvimento!\n");
                pausar();
                break;
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

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Módulo de Produtos - Lucas Siqueira\n");
    getchar();
    menu_produtos();
    return 0;
}
