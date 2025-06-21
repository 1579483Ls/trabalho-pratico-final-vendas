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

```

### Endereco
```c

```

### Comprador
```c

```

### ItemVenda
```c

```

### Venda
```c

```

---

## 📦 Módulo de Produtos (Lucas)

### `void cadastrar_produto()`
**Propósito**: Adiciona um novo produto ao sistema  

**Parâmetros de Entrada**: Nome do produto, código automatico ou manual do produto, quantidade em estoque, preço de venda.

**Parâmetros de Saída**: (Código já existe! Digite outro código) caso já exista o código e (Produto cadastrado com sucesso!) caso tudo esteja ok.

**Funcionalidades**:
- Geração automática ou manual de código
- Validação de duplicidade
- Validação de dados obrigatórios

**Responsabilidade**: Lucas

---

### `void consultar_produtos()`
**Propósito**: Exibe lista de produtos ativos 

**Parâmetros de Entrada**: Código de produto.

**Parâmetros de Saída**: (Código, Nome, Estoque, Preço) se o produto estiver ativo e (Nenhum produto cadastrado) caso o código de produto não seja ativo.

**Funcionalidades**:
- Formato tabular
- Apenas produtos ativos
- Tratamento de lista vazia

**Responsabilidade**: Lucas

## 👥 Módulo de Vendedores (Daniel)



---

## 🛒 Módulo de Compradores (Guilherme)



---

## 💰 Módulo de Vendas (Gustavo)



---

## 📄 Módulo de Funcionalidades Auxiliares (Gustavo)



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

---

## 📊 Constantes do Sistema
- `MAX_PRODUTOS`: 100
- `MAX_STRING`: 100
- 
- 
- 
- 

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
