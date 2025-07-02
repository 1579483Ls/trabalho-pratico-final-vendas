# Documentação das Funcionalidades - Sistema de Vendas

## 📋 Visão Geral
Sistema de vendas desenvolvido em C para gerenciar produtos, vendedores, compradores e vendas com funcionalidades de CRUD completo e emissão de nota fiscal.

---

## 🔧 Estruturas de Dados

### Produto
```c

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



---

## 👥 Módulo de Vendedores (Daniel)



---

## 🛒 Módulo de Compradores (Guilherme)



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
**Parâmetros de Entrada**: Nenhum (lê dados do usuário)
**Parâmetros de Saída**: Nenhum
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
**Parâmetros de Saída**: Nenhum
**Funcionalidades**:
- Dados completos da venda
- Detalhamento de itens
- Valores totais
**Responsabilidade**: Gustavo

### `void alterar_venda()`
**Propósito**: Modifica uma venda existente  
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Nenhum
**Status**: Não implementada (orienta exclusão/recadastro)
**Responsabilidade**: Gustavo

### `void excluir_venda()`
**Propósito**: Cancela uma venda do sistema  
**Parâmetros de Entrada**: Nenhum (solicita código ao usuário)
**Parâmetros de Saída**: Nenhum
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
**Parâmetros de Entrada**: Nenhum (solicita código da venda)
**Parâmetros de Saída**: Nenhum
**Funcionalidades**:
- Dados completos do comprador
- Detalhamento de produtos
- Cálculo de frete
- Subtotal e total geral
- Formatação adequada para impressão
**Responsabilidade**: Gustavo

---

## 🛠️ Funções Auxiliares do Sistema



---

## 📊 Constantes do Sistema
- 
- 
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
