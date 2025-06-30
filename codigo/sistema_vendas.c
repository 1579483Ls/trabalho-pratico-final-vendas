/*
===============================================================================
                        SISTEMA DE VENDAS - TRABALHO PRATICO 2025/1
===============================================================================
Equipe:
- Lucas Siqueira  : Modulo de Produtos (CRUD Produtos + Estruturas)
- Daniel          : Modulo de Vendedores (CRUD Vendedores + Comissoes)
- Guilherme       : Modulo de Compradores (CRUD Compradores + Enderecos)

Metodologia: Scrum com 4 sprints de 3-4 dias cada
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_PRODUTOS 100
#define MAX_VENDEDORES 50
#define MAX_COMPRADORES 100
#define MAX_VENDAS 200
#define MAX_ITENS_VENDA 20
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
    char rua[MAX_STRING];   
    char bairro[MAX_STRING];   
    char cidade[MAX_STRING];    
    char estado[3];            
    char cep[10];             
} Endereco;

typedef struct {
    char nome[MAX_STRING];      
    char cpf[15];             
    char email[MAX_STRING];  
    Endereco endereco;          
    int ativo;              
} Comprador;

typedef struct {
    char nome_produto[MAX_STRING]; 
    int codigo_produto;            
    int quantidade;              
    float preco_unitario;         
    float preco_total;           
} ItemVenda;

typedef struct {
    int codigo_venda;            
    int codigo_comprador;        
    int numero_vendedor;         
    ItemVenda itens[MAX_ITENS_VENDA];  
    int num_itens;              
    float valor_total;         
    int ativo;                  
} Venda;


Produto produtos[MAX_PRODUTOS];           
Vendedor vendedores[MAX_VENDEDORES];     
Comprador compradores[MAX_COMPRADORES];   
Venda vendas[MAX_VENDAS];                 

int num_produtos = 0;        
int num_vendedores = 0;   
int num_compradores = 0;   
int num_vendas = 0;          

int proximo_codigo_produto = 1;  
int proximo_numero_vendedor = 1;  
int proximo_codigo_venda = 1;     


void menu_principal();
void menu_produtos();
void menu_vendedores();
void menu_compradores();
void menu_vendas();          

void cadastrar_produto();
void consultar_produtos();
void alterar_produto();
void excluir_produto();
int buscar_produto_por_codigo(int codigo);

void cadastrar_vendedor();
void consultar_vendedores();
void alterar_vendedor();
void excluir_vendedor();
int buscar_vendedor_por_numero(int numero);

void cadastrar_comprador();
void consultar_compradores();
void alterar_comprador();
void excluir_comprador();
int buscar_comprador_por_cpf(char *cpf);

void cadastrar_venda();                       
void consultar_vendas();

void cadastrar_venda();                       
void consultar_vendas();                      
void alterar_venda();                         
void excluir_venda();                         
int buscar_venda_por_codigo(int codigo);

void limpar_buffer();
void pausar();
float calcular_frete(float valor_venda);
void emitir_nota_fiscal();

void salvar_produtos();
void carregar_produtos();
void salvar_vendedores();
void carregar_vendedores();
void salvar_compradores();
void carregar_compradores();
void salvar_todos_dados();
void carregar_todos_dados();

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

float calcular_frete(float valor_venda) {
    if (valor_venda <= 100.0) {
        return 30.0;
    } else if (valor_venda <= 300.0) {
        return 20.0;
    } else {
        return 0.0;
    }
}

int buscar_produto_por_codigo(int codigo) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo && produtos[i].ativo) {
            return i;
        }
    }
    return -1;
}

void cadastrar_produto() {
    if (num_produtos >= MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido!\n");
        pausar();
        return;
    }

    Produto novo_produto;
    int opcao_codigo;

    printf("\n=== CADASTRAR PRODUTO ===\n");
    
    printf("Nome do produto: ");
    fgets(novo_produto.nome, MAX_STRING, stdin);
    novo_produto.nome[strcspn(novo_produto.nome, "\n")] = 0;

    printf("Codigo do produto:\n");
    printf("1 - Gerar automaticamente (%d)\n", proximo_codigo_produto);
    printf("2 - Inserir manualmente\n");
    printf("Escolha: ");
    scanf("%d", &opcao_codigo);
    limpar_buffer();

    if (opcao_codigo == 1) {
        novo_produto.codigo = proximo_codigo_produto++;
    } else {
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

void consultar_produtos() {
    printf("\n=== CONSULTAR PRODUTOS ===\n");
    
    if (num_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    printf("%-6s %-30s %-10s %-12s\n", "Codigo", "Nome", "Estoque", "Preco");
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
    
    char confirmacao;
    scanf("%c", &confirmacao);
    limpar_buffer();

    if (tolower(confirmacao) == 's') {
        produtos[indice].ativo = 0;
        printf("Produto excluido com sucesso!\n");
        salvar_produtos();
    } else {
        printf("Exclusao cancelada.\n");
    }
    pausar();
}

int buscar_vendedor_por_numero(int numero) {
    for (int i = 0; i < num_vendedores; i++) {
        if (vendedores[i].numero == numero && vendedores[i].ativo) {
            return i;
        }
    }
    return -1;
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

    printf("Vendedor cadastrado com sucesso! Numero: %d\n", novo_vendedor.numero);
    salvar_vendedores();
    pausar();
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
            printf("Opcao invalida!\n");
            pausar();
            return;
    }

    printf("Vendedor alterado com sucesso!\n");
    salvar_vendedores();
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
        printf("Vendedor excluido com sucesso!\n");
        salvar_vendedores();
    } else {
        printf("Exclusao cancelada.\n");
    }
    pausar();
}

int buscar_comprador_por_cpf(char *cpf) {
    for (int i = 0; i < num_compradores; i++) {
        if (strcmp(compradores[i].cpf, cpf) == 0 && compradores[i].ativo) {
            return i;
        }
    }
    return -1;
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

void menu_produtos() {
    int opcao;
    
    do {
        system("cls");
        printf("=== MENU PRODUTOS ===\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar produtos\n");
        printf("3 - Alterar produto\n");
        printf("4 - Excluir produto\n");
        printf("0 - Voltar ao menu principal\n");
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
                printf("Opcao invalida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

void menu_vendedores() {
    int opcao;
    
    do {
        system("cls");
        printf("=== MENU VENDEDORES ===\n");
        printf("1 - Cadastrar vendedor\n");
        printf("2 - Consultar vendedores\n");
        printf("3 - Alterar vendedor\n");
        printf("4 - Excluir vendedor\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_vendedor(); break;
            case 2: consultar_vendedores(); break;
            case 3: alterar_vendedor(); break;
            case 4: excluir_vendedor(); break;
            case 0: break;
            default: 
                printf("Opcao invalida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);
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

void menu_principal() {
    int opcao;
    
    do {
        system("cls");
        printf("========================================\n");
        printf("       SISTEMA DE VENDAS v1.0          \n");
        printf("========================================\n");
        printf("1 - Gerenciar Produtos\n");
        printf("2 - Gerenciar Vendedores\n");
        printf("3 - Gerenciar Compradores\n");
        printf("0 - SAIR\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: menu_produtos(); break;
            case 2: menu_vendedores(); break;
            case 3: menu_compradores(); break;
            case 0: 
                printf("Encerrando sistema...\n");
                break;
            default: 
                printf("Opcao invalida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

void cadastrar_venda() {
    // Verificar se há espaço disponível no array
    if (num_vendas >= MAX_VENDAS) {
        printf("Limite máximo de vendas atingido!\n");
        pausar();
        return;
    }

    Venda nova_venda;
    char cpf[15];
    int numero_vendedor;
    int indice_comprador, indice_vendedor;

    printf("\n=== CADASTRAR VENDA ===\n");
    
    nova_venda.codigo_venda = proximo_codigo_venda++;

    // Buscar comprador
    printf("CPF do comprador: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    indice_comprador = buscar_comprador_por_cpf(cpf);
    if (indice_comprador == -1) {
        printf("Comprador não encontrado!\n");
        pausar();
        return;
    }
    nova_venda.codigo_comprador = indice_comprador;

    // Buscar vendedor
    printf("Número do vendedor: ");
    scanf("%d", &numero_vendedor);
    limpar_buffer();

    indice_vendedor = buscar_vendedor_por_numero(numero_vendedor);
    if (indice_vendedor == -1) {
        printf("Vendedor não encontrado!\n");
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
            printf("Limite máximo de itens por venda atingido!\n");
            break;
        }

        ItemVenda item;
        int codigo_produto, indice_produto;

        printf("\n--- ITEM %d ---\n", nova_venda.num_itens + 1);
        printf("Código do produto: ");
        scanf("%d", &codigo_produto);
        limpar_buffer();

        indice_produto = buscar_produto_por_codigo(codigo_produto);
        if (indice_produto == -1) {
            printf("Produto não encontrado!\n");
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
            scanf("%c", &continuar);
            limpar_buffer();
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
    printf("Código da venda: %d\n", nova_venda.codigo_venda);
    printf("Valor total: R$ %.2f\n", nova_venda.valor_total);
    printf("Comissão do vendedor: R$ %.2f\n", comissao);
    pausar();
}

int buscar_venda_por_codigo(int codigo) {
    for (int i = 0; i < num_vendas; i++) {
        if (vendas[i].codigo_venda == codigo && vendas[i].ativo) {
            return i;  
        }
    }
    return -1;  
}


int main() {
    printf("Inicializando Sistema de Vendas...\n");
    carregar_todos_dados();
    
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
    
    strcpy(vendedores[0].nome, "João Silva");
    vendedores[0].numero = 1;
    vendedores[0].salario_fixo = 2000.00;
    vendedores[0].comissoes = 0.0;
    vendedores[0].ativo = 1;
    
    num_vendedores = 1;
    proximo_numero_vendedor = 2;
    
    strcpy(compradores[0].nome, "Maria Santos");
    strcpy(compradores[0].cpf, "123.456.789-00");
    strcpy(compradores[0].email, "maria@email.com");
    strcpy(compradores[0].endereco.rua, "Rua das Flores, 123");
    strcpy(compradores[0].endereco.bairro, "Centro");
    strcpy(compradores[0].endereco.cidade, "São Paulo");
    strcpy(compradores[0].endereco.estado, "SP");
    strcpy(compradores[0].endereco.cep, "01234-567");
    compradores[0].ativo = 1;
    
    num_compradores = 1;
    
    printf("Sistema inicializado com dados de exemplo.\n");
    printf("Equipe: Lucas, Daniel, Guilherme\n");
    printf("Pressione Enter para continuar...");
    getchar();
    menu_principal();
    salvar_todos_dados();
    return 0;
}

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

void salvar_todos_dados() {
    salvar_produtos();
    salvar_vendedores();
    salvar_compradores();
}

void carregar_todos_dados() {
    carregar_produtos();
    carregar_vendedores();
    carregar_compradores();
}