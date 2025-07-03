# Documentação das Funcionalidades - Sistema de Vendas

## 📋 Visão Geral
Sistema de vendas desenvolvido em C para gerenciar produtos, vendedores, compradores e vendas com funcionalidades de CRUD completo e emissão de nota fiscal.

---

## 🔧 Estruturas de Dados

### Produto
```c
typedef struct {
    char nome[MAX_STRING];        // Nome do produto
    int codigo;                   // Código único do produto
    int quantidade_estoque;       // Quantidade disponível
    float preco_venda;           // Preço unitário de venda
    int ativo;                   // Status (1=ativo, 0=removido)
} Produto;
```

### Vendedor
```c
typedef struct {
    char nome[MAX_STRING];        // Nome do vendedor
    int numero;                   // Número único do vendedor
    float salario_fixo;          // Salário base
    float comissoes;             // Comissões acumuladas
    int ativo;                   // Status (1=ativo, 0=removido)
} Vendedor;
```

### Endereco
```c
typedef struct {
    char rua[MAX_STRING];        // Endereço completo
    char bairro[MAX_STRING];     // Bairro
    char cidade[MAX_STRING];     // Cidade
    char estado[3];              // Estado (sigla)
    char cep[10];                // CEP
} Endereco;
```

### Comprador
```c
typedef struct {
    char nome[MAX_STRING];        // Nome do comprador
    char cpf[15];                // CPF único
    char email[MAX_STRING];      // Email
    Endereco endereco;           // Endereço de entrega
    int ativo;                   // Status (1=ativo, 0=removido)
} Comprador;
```

### ItemVenda
```c
typedef struct {
    char nome_produto[MAX_STRING]; // Nome do produto
    int codigo_produto;           // Código do produto
    int quantidade;               // Quantidade vendida
    float preco_unitario;         // Preço unitário na venda
    float preco_total;            // Total do item
} ItemVenda;
```

### Venda
```c
typedef struct {
    int codigo_venda;             // Código único da venda
    int codigo_comprador;         // Índice do comprador
    int numero_vendedor;          // Número do vendedor
    ItemVenda itens[MAX_ITENS_VENDA]; // Itens da venda
    int num_itens;                // Quantidade de itens
    float valor_total;            // Valor total da venda
    int ativo;                    // Status (1=ativo, 0=removido)
} Venda;
```

---

## 📦 Módulo de Produtos (Lucas)

### `int buscar_produto_por_codigo(int codigo)`
**Propósito**: Localiza um produto pelo código  
**Parâmetros de Entrada**: 
- `codigo`: Código do produto a ser buscado
**Parâmetros de Saída**: 
- Retorna o índice do produto no array ou -1 se não encontrado
**Responsabilidade**: Lucas

### `void cadastrar_produto()`
**Propósito**: Adiciona um novo produto ao sistema  
**Parâmetros de Entrada**: 
- Nome do produto
- Código do produto (geração automática ou manual)
- Quantidade em estoque
- Preço de venda
**Parâmetros de Saída**: Nenhum
**Funcionalidades**:
- Geração automática ou manual de código
- Validação de duplicidade
- Validação de dados obrigatórios
**Responsabilidade**: Lucas

### `void consultar_produtos()`
**Propósito**: Exibe lista de produtos ativos  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Lista formatada dos produtos ordenada por código
**Funcionalidades**:
- Formato tabular com cabeçalho (Código, Nome, Estoque, Preço)
- Ordenação crescente por código
- Apenas produtos ativos
- Tratamento de lista vazia
**Responsabilidade**: Lucas

### `void alterar_produto()`
**Propósito**: Modifica dados de um produto existente  
**Parâmetros de Entrada**: 
- Código do produto a ser alterado
- Novos dados (nome, quantidade, preço conforme seleção do usuário)
**Parâmetros de Saída**: Mensagem de confirmação da alteração
**Funcionalidades**:
- Busca por código
- Alteração seletiva de campos
- Validação de existência
**Responsabilidade**: Lucas

### `void excluir_produto()`
**Propósito**: Remove um produto do sistema (exclusão lógica)  
**Parâmetros de Entrada**: 
- Código do produto a ser excluído
- Confirmação da exclusão (S/N)
**Parâmetros de Saída**: Mensagem de confirmação da exclusão
**Funcionalidades**:
- Busca por código
- Confirmação de exclusão
- Exclusão lógica (ativo = 0)
**Responsabilidade**: Lucas

---

## 👥 Módulo de Vendedores (Daniel)

### `int buscar_vendedor_por_numero(int numero)`
**Propósito**: Localiza um vendedor pelo número  
**Parâmetros de Entrada**: 
- `numero`: Número do vendedor a ser buscado
**Parâmetros de Saída**: 
- Retorna o índice do vendedor no array ou -1 se não encontrado
**Responsabilidade**: Daniel

### `void cadastrar_vendedor()`
**Propósito**: Adiciona um novo vendedor ao sistema  
**Parâmetros de Entrada**: 
- Nome do vendedor
- Número do vendedor (geração automática ou manual)
- Salário fixo
**Parâmetros de Saída**: Nenhum
**Funcionalidades**:
- Geração automática ou manual de número
- Validação de duplicidade
- Inicialização de comissões em 0
**Responsabilidade**: Daniel

### `void consultar_vendedores()`
**Propósito**: Exibe lista de vendedores ativos  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Lista formatada dos vendedores ordenada por número
**Funcionalidades**:
- Formato tabular com cabeçalho (Número, Nome, Salário Fixo, Comissões)
- Ordenação crescente por número
- Apenas vendedores ativos
- Valores monetários formatados
**Responsabilidade**: Daniel

### `void alterar_vendedor()`
**Propósito**: Modifica dados de um vendedor existente  
**Parâmetros de Entrada**: 
- Número do vendedor a ser alterado
- Novos dados (nome e/ou salário conforme seleção do usuário)
**Parâmetros de Saída**: Mensagem de confirmação da alteração
**Funcionalidades**:
- Busca por número
- Alteração de nome e salário
- Comissões não podem ser alteradas manualmente
**Responsabilidade**: Daniel

### `void excluir_vendedor()`
**Propósito**: Remove um vendedor do sistema (exclusão lógica)  
**Parâmetros de Entrada**: 
- Número do vendedor a ser excluído
- Confirmação da exclusão (S/N)
**Parâmetros de Saída**: Mensagem de confirmação da exclusão
**Funcionalidades**:
- Busca por número
- Confirmação de exclusão
- Exclusão lógica (ativo = 0)
**Responsabilidade**: Daniel

---

## 🛒 Módulo de Compradores (Guilherme)

### `int buscar_comprador_por_cpf(char *cpf)`
**Propósito**: Localiza um comprador pelo CPF  
**Parâmetros de Entrada**: 
- `cpf`: CPF do comprador a ser buscado
**Parâmetros de Saída**: 
- Retorna o índice do comprador no array ou -1 se não encontrado
**Responsabilidade**: Guilherme

### `void cadastrar_comprador()`
**Propósito**: Adiciona um novo comprador ao sistema  
**Parâmetros de Entrada**: 
- Nome do comprador
- CPF (único no sistema)
- Email
- Endereço completo (rua, bairro, cidade, estado, CEP)
**Parâmetros de Saída**: Nenhum
**Funcionalidades**:
- Validação de CPF único
- Coleta de dados pessoais completos
- Endereço de entrega obrigatório
**Responsabilidade**: Guilherme

### `void consultar_compradores()`
**Propósito**: Exibe lista de compradores ativos  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Lista formatada dos compradores ordenada por nome
**Funcionalidades**:
- Dados pessoais completos (nome, CPF, email)
- Endereço completo formatado (rua, bairro, cidade, estado, CEP)
- Ordenação alfabética por nome
- Apenas compradores ativos
- Separação visual entre registros
**Responsabilidade**: Guilherme

### `void alterar_comprador()`
**Propósito**: Modifica dados de um comprador existente  
**Parâmetros de Entrada**: 
- CPF do comprador a ser alterado
- Novos dados (nome, email e/ou endereço conforme seleção do usuário)
**Parâmetros de Saída**: Mensagem de confirmação da alteração
**Funcionalidades**:
- Busca por CPF
- Alteração de nome, email e endereço
- CPF não pode ser alterado
**Responsabilidade**: Guilherme

### `void excluir_comprador()`
**Propósito**: Remove um comprador do sistema (exclusão lógica)  
**Parâmetros de Entrada**: 
- CPF do comprador a ser excluído
- Confirmação da exclusão (S/N)
**Parâmetros de Saída**: Mensagem de confirmação da exclusão
**Funcionalidades**:
- Busca por CPF
- Confirmação de exclusão
- Exclusão lógica (ativo = 0)
**Responsabilidade**: Guilherme

---

## 💰 Módulo de Vendas (Gustavo)

### `int buscar_venda_por_codigo(int codigo)`
**Propósito**: Localiza uma venda pelo código  
**Parâmetros de Entrada**: 
- `codigo`: Código da venda a ser buscada
**Parâmetros de Saída**: 
- Retorna o índice da venda no array ou -1 se não encontrada
**Responsabilidade**: Gustavo

### `void cadastrar_venda()`
**Propósito**: Registra uma nova venda no sistema  
**Parâmetros de Entrada**: 
- CPF do comprador
- Número do vendedor
- Múltiplos itens da venda (código do produto, quantidade)
**Parâmetros de Saída**: Código da venda gerado automaticamente
**Funcionalidades**:
- Validação de comprador e vendedor
- Múltiplos itens por venda
- Controle de estoque automático
- Cálculo de comissão (3%)
- Geração automática de código
**Responsabilidade**: Gustavo

### `void consultar_vendas()`
**Propósito**: Exibe histórico de vendas ativas  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Lista detalhada das vendas ordenada por código
**Funcionalidades**:
- Dados da venda (código, comprador, vendedor, valor total)
- Detalhamento completo de cada item (nome, quantidade, preço unitário, total)
- Ordenação crescente por código de venda
- Apenas vendas ativas
- Separação visual entre registros
- Busca automática dos nomes de comprador e vendedor
**Responsabilidade**: Gustavo

### `void alterar_venda()`
**Propósito**: Modifica uma venda existente  
**Parâmetros de Entrada**: 
- Código da venda a ser alterada
- Opção de alteração (1-Alterar quantidade, 2-Adicionar item, 3-Remover item)
- Dados específicos conforme a opção escolhida
**Parâmetros de Saída**: Mensagem de confirmação da alteração
**Funcionalidades**:
- Alterar quantidade de item existente
- Adicionar novo item à venda
- Remover item da venda
- Recálculo automático de totais
- Atualização de estoque e comissões
**Responsabilidade**: Gustavo

### `void excluir_venda()`
**Propósito**: Cancela uma venda do sistema  
**Parâmetros de Entrada**: 
- Código da venda a ser excluída
- Confirmação da exclusão (S/N)
**Parâmetros de Saída**: Mensagem de confirmação da exclusão
**Funcionalidades**:
- Reversão de estoque
- Reversão de comissão
- Confirmação de exclusão
- Exclusão lógica (ativo = 0)
**Responsabilidade**: Gustavo

---

## 📄 Módulo de Funcionalidades Auxiliares (Gustavo)

### `float calcular_frete(float valor_venda)`
**Propósito**: Calcula o valor do frete baseado no valor da venda  
**Parâmetros de Entrada**: 
- `valor_venda`: Valor total da venda
**Parâmetros de Saída**: 
- Retorna o valor do frete calculado
**Regras**:
- Até R$ 100,00: R$ 30,00
- R$ 100,01 a R$ 300,00: R$ 20,00
- Acima de R$ 300,00: Grátis (R$ 0,00)
**Responsabilidade**: Gustavo

### `void emitir_nota_fiscal()`
**Propósito**: Gera e exibe nota fiscal de uma venda  
**Parâmetros de Entrada**: 
- Código da venda para emissão da nota fiscal
**Parâmetros de Saída**: Nota fiscal formatada para impressão
**Funcionalidades**:
- Dados completos do comprador
- Detalhamento de produtos
- Cálculo de frete
- Subtotal e total geral
- Formatação adequada para impressão
**Responsabilidade**: Gustavo

---

## 🛠️ Funções Auxiliares do Sistema

### `void limpar_buffer()`
**Propósito**: Remove caracteres residuais do buffer de entrada  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Nenhum

### `void pausar()`
**Propósito**: Pausa a execução aguardando entrada do usuário  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Nenhum

### `int ler_opcao_valida(int min, int max)`
**Propósito**: Valida entrada de números inteiros para menus  
**Parâmetros de Entrada**: 
- `min`: Valor mínimo aceito
- `max`: Valor máximo aceito
**Parâmetros de Saída**: 
- Retorna número inteiro válido dentro do intervalo

### `void salvar_produtos()`
**Propósito**: Salva dados dos produtos em arquivo  
**Parâmetros de Entrada**: Nenhum (usa array global produtos[])
**Parâmetros de Saída**: Arquivo produtos.txt atualizado

### `void salvar_vendedores()`
**Propósito**: Salva dados dos vendedores em arquivo  
**Parâmetros de Entrada**: Nenhum (usa array global vendedores[])
**Parâmetros de Saída**: Arquivo vendedores.txt atualizado

### `void salvar_compradores()`
**Propósito**: Salva dados dos compradores em arquivo  
**Parâmetros de Entrada**: Nenhum (usa array global compradores[])
**Parâmetros de Saída**: Arquivo compradores.txt atualizado

### `void salvar_vendas()`
**Propósito**: Salva dados das vendas em arquivo  
**Parâmetros de Entrada**: Nenhum (usa array global vendas[])
**Parâmetros de Saída**: Arquivo vendas.txt atualizado

### `void salvar_todos_dados()`
**Propósito**: Salva todos os dados do sistema em arquivos  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Todos os arquivos de dados atualizados

### `void carregar_produtos()`
**Propósito**: Carrega dados dos produtos do arquivo  
**Parâmetros de Entrada**: Arquivo produtos.txt
**Parâmetros de Saída**: Array global produtos[] preenchido

### `void carregar_vendedores()`
**Propósito**: Carrega dados dos vendedores do arquivo  
**Parâmetros de Entrada**: Arquivo vendedores.txt
**Parâmetros de Saída**: Array global vendedores[] preenchido

### `void carregar_compradores()`
**Propósito**: Carrega dados dos compradores do arquivo  
**Parâmetros de Entrada**: Arquivo compradores.txt
**Parâmetros de Saída**: Array global compradores[] preenchido

### `void carregar_vendas()`
**Propósito**: Carrega dados das vendas do arquivo  
**Parâmetros de Entrada**: Arquivo vendas.txt
**Parâmetros de Saída**: Array global vendas[] preenchido

### `void carregar_todos_dados()`
**Propósito**: Carrega todos os dados do sistema dos arquivos  
**Parâmetros de Entrada**: Todos os arquivos de dados
**Parâmetros de Saída**: Todos os arrays globais preenchidos

### `int encontrar_menor_codigo_disponivel()`
**Propósito**: Encontra o menor código de produto disponível  
**Parâmetros de Entrada**: Nenhum (usa array global produtos[])
**Parâmetros de Saída**: 
- Retorna o menor código disponível para novo produto

### `int encontrar_menor_numero_vendedor_disponivel()`
**Propósito**: Encontra o menor número de vendedor disponível  
**Parâmetros de Entrada**: Nenhum (usa array global vendedores[])
**Parâmetros de Saída**: 
- Retorna o menor número disponível para novo vendedor

### `int encontrar_menor_codigo_venda_disponivel()`
**Propósito**: Encontra o menor código de venda disponível  
**Parâmetros de Entrada**: Nenhum (usa array global vendas[])
**Parâmetros de Saída**: 
- Retorna o menor código disponível para nova venda

---

## 📱 Funções de Interface e Navegação

### `void menu_principal()`
**Propósito**: Exibe e controla o menu principal do sistema  
**Parâmetros de Entrada**: Escolha do usuário (1-6)
**Parâmetros de Saída**: Navegação para submenus correspondentes

### `void menu_produtos()`
**Propósito**: Exibe e controla o submenu de produtos  
**Parâmetros de Entrada**: Escolha do usuário (1-5)
**Parâmetros de Saída**: Execução da função correspondente
**Responsabilidade**: Lucas

### `void menu_vendedores()`
**Propósito**: Exibe e controla o submenu de vendedores  
**Parâmetros de Entrada**: Escolha do usuário (1-5)
**Parâmetros de Saída**: Execução da função correspondente
**Responsabilidade**: Daniel

### `void menu_compradores()`
**Propósito**: Exibe e controla o submenu de compradores  
**Parâmetros de Entrada**: Escolha do usuário (1-5)
**Parâmetros de Saída**: Execução da função correspondente
**Responsabilidade**: Guilherme

### `void menu_vendas()`
**Propósito**: Exibe e controla o submenu de vendas  
**Parâmetros de Entrada**: Escolha do usuário (1-5)
**Parâmetros de Saída**: Execução da função correspondente
**Responsabilidade**: Gustavo

### `int main()`
**Propósito**: Função principal do programa - ponto de entrada  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: 
- Retorna 0 em caso de execução bem-sucedida
**Funcionalidades**:
- Configuração de localização (setlocale)
- Carregamento de dados dos arquivos
- Inicialização do menu principal
- Salvamento automático ao sair

---

## 📊 Constantes do Sistema
- `MAX_PRODUTOS`: 100
- `MAX_VENDEDORES`: 50
- `MAX_COMPRADORES`: 100
- `MAX_VENDAS`: 200
- `MAX_ITENS_VENDA`: 20
- `MAX_STRING`: 100

---

## 🔄 Fluxos Principais

### Fluxo de Venda
1. Validar comprador (CPF)
2. Validar vendedor (número)
3. Adicionar itens (verificar estoque)
4. Calcular totais
5. Atualizar estoque
6. Calcular e atribuir comissão
7. Registrar venda

### Fluxo de Nota Fiscal
1. Localizar venda
2. Recuperar dados do comprador
3. Calcular frete
4. Formatar e exibir nota fiscal

---

## 🎯 Regras de Negócio
- Códigos e números são únicos por tipo
- Exclusões são lógicas (ativo = 0)
- Estoque é atualizado automaticamente nas vendas
- Comissão de vendedor é 3% do valor da venda
- Frete é calculado automaticamente
- CPF é único no sistema
