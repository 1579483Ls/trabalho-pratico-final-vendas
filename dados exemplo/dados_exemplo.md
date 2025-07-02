# Dados de Exemplo para Demonstração - Sistema de Vendas

## 📋 Instruções de Preenchimento

Este arquivo contém dados pré-definidos para facilitar a demonstração e testes do sistema durante as sprints. 

**IMPORTANTE**: Estes dados devem ser inseridos manualmente através da interface do sistema pelos membros da equipe durante o desenvolvimento, para testar todas as funcionalidades.

---

## 📦 Produtos de Exemplo (Lucas - Sprint 1)



### Instruções para Lucas:
```

```

---

## 👥 Vendedores de Exemplo (Daniel - Sprint 2)



### Instruções para Daniel:
```

```

---

## 🛒 Compradores de Exemplo (Guilherme - Sprint 2)



## 💰 Vendas de Exemplo (Gustavo - Sprint 3)

### Venda 1
- **Comprador**: CPF 123.456.789-01 (Pedro)
- **Vendedor**: Número 1 (João)
- **Itens**:
  - Produto 1 (Notebook): Quantidade 1, Preço R$ 2.499,99
  - Produto 2 (Mouse): Quantidade 2, Preço R$ 89,90
- **Total Esperado**: R$ 2.679,79
- **Comissão Esperada**: R$ 80,39 (3%)

### Venda 2
- **Comprador**: CPF 987.654.321-02 (Luciana)
- **Vendedor**: Número 2 (Maria)
- **Itens**:
  - Produto 3 (Smartphone): Quantidade 1, Preço R$ 3.299,00
- **Total Esperado**: R$ 3.299,00
- **Comissão Esperada**: R$ 98,97 (3%)

### Venda 3
- **Comprador**: CPF 456.789.123-03 (Roberto)
- **Vendedor**: Número 1 (João)
- **Itens**:
  - Produto 4 (Teclado): Quantidade 1, Preço R$ 249,99
  - Produto 5 (Monitor): Quantidade 2, Preço R$ 699,90
- **Total Esperado**: R$ 1.649,79
- **Comissão Esperada**: R$ 49,49 (3%)

### Venda 4 (Para testar frete)
- **Comprador**: CPF 321.654.987-04 (Fernanda)
- **Vendedor**: Número 10 (Carlos)
- **Itens**:
  - Produto 2 (Mouse): Quantidade 1, Preço R$ 89,90
- **Total Esperado**: R$ 89,90
- **Comissão Esperada**: R$ 2,70 (3%)
- **Frete Esperado**: R$ 30,00 (valor baixo)


---

## 📄 Notas Fiscais para Demonstração (Gustavo - Sprint 4)

### Teste de Nota Fiscal 1 (Venda com frete normal)
- **Código da Venda**: 4 (Fernanda - Mouse)
- **Verificar**:
  - Dados completos da Fernanda
  - Produto: Mouse, Qtd 1, Unit R$ 89,90, Total R$ 89,90
  - Subtotal: R$ 89,90
  - Frete: R$ 30,00
  - Total Geral: R$ 119,90

### Teste de Nota Fiscal 2 (Venda com frete médio)
- **Código da Venda**: 3 (Roberto - Teclado + Monitor)
- **Verificar**:
  - Subtotal: R$ 1.649,79
  - Frete: R$ 20,00 (entre R$ 100-300)
  - Total Geral: R$ 1.669,79

### Teste de Nota Fiscal 3 (Venda com frete grátis)
- **Código da Venda**: 1 (Pedro - Notebook + Mouse)
- **Verificar**:
  - Subtotal: R$ 2.679,79
  - Frete: GRÁTIS (acima de R$ 300)
  - Total Geral: R$ 2.679,79

---

## 🧪 Cenários de Teste Específicos


```

### Teste de Validações
```

```

---

## 📊 Checklist de Demonstração Final



---

## 📝 Observações Importantes



**LEMBRE-SE**: Este arquivo é apenas um guia. Os dados devem ser inseridos manualmente através da interface do sistema para validar completamente todas as funcionalidades!
