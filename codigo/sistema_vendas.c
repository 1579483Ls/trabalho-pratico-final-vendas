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
#define MAX_VENDEDORES 50
#define MAX_COMPRADORES 100
#define MAX_STRING 100

typedef struct {
    char nome[MAX_STRING];
    int codigo;
    int quantidade_estoque;
    float preco_venda;
    int ativo;
} Produto;

typedef struct {
    char nome[MAX_STRING];       
    int numero;                  
    float salario_fixo;         
    float comissoes;            
    int ativo;                  
} Vendedor;

typedef struct {
    char nome[MAX_STRING];      
    char cpf[15];             
    char email[MAX_STRING];    
    Endereco endereco;         
    int ativo;              
} Comprador;

typedef struct {
    char rua[MAX_STRING];     
    char bairro[MAX_STRING];  
    char cidade[MAX_STRING];  
    char estado[3];            
    char cep[10];              
} Endereco;

Produto produtos[MAX_PRODUTOS];
Vendedor vendedores[MAX_VENDEDORES];
Comprador compradores[MAX_COMPRADORES];

int num_compradores = 0;
int num_produtos = 0;
int num_vendedores = 0;
int proximo_codigo_produto = 1;
int proximo_numero_vendedor = 1;

void cadastrar_comprador();
void consultar_compradores();
void alterar_comprador();
void excluir_comprador();
int buscar_comprador_por_cpf(char *cpf);

void menu_compradores();

void cadastrar_produto();
void consultar_produtos();
void alterar_produto();
void excluir_produto();
int buscar_produto_por_codigo(int codigo);

void cadastrar_vendedor();                     // Cadastra novo vendedor
void consultar_vendedores();                   // Lista todos os vendedores
void alterar_vendedor();                       // Modifica dados de vendedor existente
void excluir_vendedor();                       // Remove vendedor (exclusão lógica)
int buscar_vendedor_por_numero(int numero);
void menu_vendedores();

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

int buscar_vendedor_por_numero(int numero) {
    for (int i = 0; i < num_vendedores; i++) {
        if (vendedores[i].numero == numero && vendedores[i].ativo) {
            return i;  // Vendedor encontrado e ativo
        }
    }
    return -1;  // Vendedor não encontrado ou inativo
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

void cadastrar_vendedor() {
    if (num_vendedores >= MAX_VENDEDORES) {
        printf("Limite máximo de vendedores atingido!\n");
        pausar();
        return;
    }

    Vendedor novo_vendedor;
    int opcao_numero;

    printf("\n=== CADASTRAR VENDEDOR ===\n");
    
    printf("Nome do vendedor: ");
    fgets(novo_vendedor.nome, MAX_STRING, stdin);
    novo_vendedor.nome[strcspn(novo_vendedor.nome, "\n")] = 0;

    printf("Número do vendedor:\n");
    printf("1 - Gerar automaticamente (%d)\n", proximo_numero_vendedor);
    printf("2 - Inserir manualmente\n");
    printf("Escolha: ");
    scanf("%d", &opcao_numero);
    limpar_buffer();

    if (opcao_numero == 1) {
        novo_vendedor.numero = proximo_numero_vendedor++;
    } else {
        do {
            printf("Digite o número: ");
            scanf("%d", &novo_vendedor.numero);
            limpar_buffer();
            
            if (buscar_vendedor_por_numero(novo_vendedor.numero) != -1) {
                printf("Número já existe! Digite outro número.\n");
            }
        } while (buscar_vendedor_por_numero(novo_vendedor.numero) != -1);
        
        if (novo_vendedor.numero >= proximo_numero_vendedor) {
            proximo_numero_vendedor = novo_vendedor.numero + 1;
        }
    }

    printf("Salário fixo: R$ ");
    scanf("%f", &novo_vendedor.salario_fixo);
    limpar_buffer();

    novo_vendedor.comissoes = 0.0;
    novo_vendedor.ativo = 1;
    vendedores[num_vendedores] = novo_vendedor;
    num_vendedores++;

    printf("Vendedor cadastrado com sucesso! Número: %d\n", novo_vendedor.numero);
    pausar();
}

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
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_venda(); break;
            case 2: consultar_vendas(); break;
            case 3: alterar_venda(); break;
            case 4: excluir_venda(); break;
            case 0: break;
            default: 
                printf("Opção inválida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

void consultar_vendedores() {
    printf("\n=== CONSULTAR VENDEDORES ===\n");
    
    if (num_vendedores == 0) {
        printf("Nenhum vendedor cadastrado.\n");
        pausar();
        return;
    }

    printf("%-6s %-30s %-15s %-15s\n", "Número", "Nome", "Salário Fixo", "Comissões");
    printf("--------------------------------------------------------------------\n");
    
    for (int i = 0; i < num_vendedores; i++) {
        if (vendedores[i].ativo) {
            printf("%-6d %-30s R$ %-12.2f R$ %-12.2f\n", 
                   vendedores[i].numero, 
                   vendedores[i].nome, 
                   vendedores[i].salario_fixo, 
                   vendedores[i].comissoes);
        }
    }
    pausar();
}

void alterar_vendedor() {
    int numero, indice;
    
    printf("\n=== ALTERAR VENDEDOR ===\n");
    printf("Digite o número do vendedor: ");
    scanf("%d", &numero);
    limpar_buffer();

    indice = buscar_vendedor_por_numero(numero);
    if (indice == -1) {
        printf("Vendedor não encontrado!\n");
        pausar();
        return;
    }

    printf("Vendedor encontrado: %s\n", vendedores[indice].nome);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar salário fixo\n");
    printf("Escolha: ");
    
    int opcao;
    scanf("%d", &opcao);
    limpar_buffer();

    switch (opcao) {
        case 1:
            printf("Novo nome: ");
            fgets(vendedores[indice].nome, MAX_STRING, stdin);
            vendedores[indice].nome[strcspn(vendedores[indice].nome, "\n")] = 0;
            break;
        case 2:
            printf("Novo salário: R$ ");
            scanf("%f", &vendedores[indice].salario_fixo);
            limpar_buffer();
            break;
        default:
            printf("Opção inválida!\n");
            pausar();
            return;
    }

    printf("Vendedor alterado com sucesso!\n");
    pausar();
}

void excluir_vendedor() {
    int numero, indice;
    
    printf("\n=== EXCLUIR VENDEDOR ===\n");
    printf("Digite o número do vendedor: ");
    scanf("%d", &numero);
    limpar_buffer();

    indice = buscar_vendedor_por_numero(numero);
    if (indice == -1) {
        printf("Vendedor não encontrado!\n");
        pausar();
        return;
    }

    printf("Vendedor: %s\n", vendedores[indice].nome);
    printf("Confirma exclusão? (s/n): ");
    
    char confirmacao;
    scanf("%c", &confirmacao);
    limpar_buffer();

    if (tolower(confirmacao) == 's') {
        vendedores[indice].ativo = 0;
        printf("Vendedor excluído com sucesso!\n");
    } else {
        printf("Exclusão cancelada.\n");
    }
    pausar();
}

void cadastrar_comprador() {
    
    if (num_compradores >= MAX_COMPRADORES) {
        printf("Limite máximo de compradores atingido!\n");
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
            printf("CPF já cadastrado! Digite outro CPF.\n");
        }
    } while (buscar_comprador_por_cpf(novo_comprador.cpf) != -1);

    printf("E-mail: ");
    fgets(novo_comprador.email, MAX_STRING, stdin);
    novo_comprador.email[strcspn(novo_comprador.email, "\n")] = 0;

    printf("\n--- ENDEREÇO DE ENTREGA ---\n");
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

int buscar_comprador_por_cpf(char *cpf) {
    for (int i = 0; i < num_compradores; i++) {
        if (strcmp(compradores[i].cpf, cpf) == 0 && compradores[i].ativo) {
            return i;  // Comprador encontrado e ativo
        }
    }
    return -1;  // Comprador não encontrado ou inativo
}

void consultar_compradores() {
    printf("\n=== CONSULTAR COMPRADORES ===\n");
    
    if (num_compradores == 0) {
        printf("Nenhum comprador cadastrado.\n");
        pausar();
        return;
    }

    for (int i = 0; i < num_compradores; i++) {
        if (compradores[i].ativo) {
            printf("\nNome: %s\n", compradores[i].nome);
            printf("CPF: %s\n", compradores[i].cpf);
            printf("E-mail: %s\n", compradores[i].email);
            printf("Endereço: %s, %s, %s - %s, CEP: %s\n",
                   compradores[i].endereco.rua,
                   compradores[i].endereco.bairro,
                   compradores[i].endereco.cidade,
                   compradores[i].endereco.estado,
                   compradores[i].endereco.cep);
            printf("----------------------------------------\n");
        }
    }
    pausar();
}

void alterar_comprador() {
    char cpf[15];
    int indice;
    
    printf("\n=== ALTERAR COMPRADOR ===\n");
    printf("Digite o CPF do comprador: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    indice = buscar_comprador_por_cpf(cpf);
    if (indice == -1) {
        printf("Comprador não encontrado!\n");
        pausar();
        return;
    }

    printf("Comprador encontrado: %s\n", compradores[indice].nome);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar e-mail\n");
    printf("3 - Alterar endereço\n");
    printf("Escolha: ");
    
    int opcao;
    scanf("%d", &opcao);
    limpar_buffer();

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

void excluir_comprador() {
    char cpf[15];
    int indice;
    
    printf("\n=== EXCLUIR COMPRADOR ===\n");
    printf("Digite o CPF do comprador: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    indice = buscar_comprador_por_cpf(cpf);
    if (indice == -1) {
        printf("Comprador não encontrado!\n");
        pausar();
        return;
    }

    printf("Comprador: %s\n", compradores[indice].nome);
    printf("Confirma exclusão? (s/n): ");
    
    char confirmacao;
    scanf("%c", &confirmacao);
    limpar_buffer();

    if (tolower(confirmacao) == 's') {
        compradores[indice].ativo = 0;
        printf("Comprador excluido com sucesso!\n");
        salvar_compradores();
    } else {
        printf("Exclusao cancelada.\n");
    }
    pausar();
}

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
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_comprador(); break;   
            case 2: consultar_compradores(); break; 
            case 3: alterar_comprador(); break;     
            case 4: excluir_comprador(); break;    
            case 0: break;  
            default: 
                printf("Opcao invalida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    
    printf("=======================================\n");
    printf("Inicializando Sistema de Vendas...\n");
    printf("=======================================\n");
    printf("Pressione Enter para continuar...");
    getchar();
    
    menu_produtos();
    
    printf("\nObrigado por usar o sistema!\n");
    return 0;
}
