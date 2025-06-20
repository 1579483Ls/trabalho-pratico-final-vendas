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



---

## 📄 Módulo de Funcionalidades Auxiliares (Gustavo)



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
