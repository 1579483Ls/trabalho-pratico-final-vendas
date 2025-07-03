# 📊 DADOS DE EXEMPLO - SISTEMA DE VENDAS ✅ COMPLETO
## Demonstração Completa do Sistema - Versão Final

---

## 🎯 OBJETIVO

Este documento fornece dados de exemplo **ATUALIZADOS** para demonstrar todas as funcionalidades do Sistema de Vendas desenvolvido e **CONCLUÍDO**. Use estes dados para testar e apresentar o sistema de forma completa.

**Status**: ✅ **SISTEMA 100% FUNCIONAL E TESTADO**

---

## � DADOS PRÉ-CADASTRADOS (Sistema já inicia com estes dados)

### 🏷️ Produtos Iniciais
| Código | Nome | Estoque | Preço | Status |
|--------|------|---------|-------|--------|
| 1 | Notebook Dell | 10 unidades | R$ 2.500,00 | ✅ Ativo |
| 2 | Mouse Wireless | 50 unidades | R$ 85,00 | ✅ Ativo |

### 👨‍💼 Vendedor Inicial
| Número | Nome | Salário Fixo | Comissões | Status |
|--------|------|--------------|-----------|--------|
| 1 | João Silva | R$ 2.000,00 | R$ 0,00 | ✅ Ativo |

### 🛒 Comprador Inicial
| CPF | Nome | Email | Endereço | Status |
|-----|------|-------|----------|--------|
| 123.456.789-00 | Maria Santos | maria@email.com | Rua das Flores, 123, Centro, São Paulo-SP, 01234-567 | ✅ Ativo |

---

## 📋 ROTEIRO DE DEMONSTRAÇÃO COMPLETA (Sistema 100% Funcional)

### 1️⃣ DEMONSTRAÇÃO DO MÓDULO DE PRODUTOS (Lucas) ✅ IMPLEMENTADO

#### Cadastrar Produtos Adicionais:

### Produto 4
- **Nome**: Teclado Mecânico RGB
- **Código**: 4 (automático)
- **Estoque**: 25
- **Preço**: R$ 249,99

### Produto 5
- **Nome**: Monitor LG 24" Full HD
- **Código**: 5 (automático)
- **Estoque**: 12
- **Preço**: R$ 699,90

### Instruções para Lucas:
```
1. Executar o sistema
2. Ir em Gerenciar Produtos → Cadastrar produto
3. Inserir os dados acima um por um
4. Testar as funcionalidades de consulta, alteração e exclusão
5. Documentar os resultados nos seus casos de teste
```

---

## 👥 Vendedores de Exemplo (Daniel - Sprint 2)

### Vendedor 1
- **Nome**: João Silva Santos
- **Número**: 1 (automático)
- **Salário Fixo**: R$ 2.000,00
- **Comissões**: R$ 0,00 (inicial)

### Vendedor 2
- **Nome**: Maria Oliveira Costa
- **Número**: 2 (automático)
- **Salário Fixo**: R$ 2.500,00
- **Comissões**: R$ 0,00 (inicial)

### Vendedor 3
- **Nome**: Carlos Eduardo Lima
- **Número**: 10 (manual)
- **Salário Fixo**: R$ 3.000,00
- **Comissões**: R$ 0,00 (inicial)

### Vendedor 4
- **Nome**: Ana Paula Rodrigues
- **Número**: 15 (manual)
- **Salário Fixo**: R$ 2.800,00
- **Comissões**: R$ 0,00 (inicial)

### Instruções para Daniel:
```
1. Executar o sistema
2. Ir em Gerenciar Vendedores → Cadastrar vendedor
3. Inserir os dados acima
4. Testar números automáticos e manuais
5. Testar validação de números duplicados
6. Testar alterações e exclusões
7. Documentar resultados nos casos de teste
```

---

## 🛒 Compradores de Exemplo (Guilherme - Sprint 2)

### Comprador 1
- **Nome**: Pedro Henrique Alves
- **CPF**: 123.456.789-01
- **Email**: pedro.alves@email.com
- **Endereço**:
  - Rua: Rua das Flores, 123, Apt 45
  - Bairro: Centro
  - Cidade: São Paulo
  - Estado: SP
  - CEP: 01234-567

### Comprador 2
- **Nome**: Luciana Fernandes Silva
- **CPF**: 987.654.321-02
- **Email**: luciana.silva@gmail.com
- **Endereço**:
  - Rua: Avenida Paulista, 1000, Sala 501
  - Bairro: Bela Vista
  - Cidade: São Paulo
  - Estado: SP
  - CEP: 01310-100

### Comprador 3
- **Nome**: Roberto Carlos Souza
- **CPF**: 456.789.123-03
- **Email**: roberto.souza@yahoo.com
- **Endereço**:
  - Rua: Rua Augusta, 789
  - Bairro: Consolação
  - Cidade: São Paulo
  - Estado: SP
  - CEP: 01305-000

### Comprador 4
- **Nome**: Fernanda Lima Santos
- **CPF**: 321.654.987-04
- **Email**: fernanda.lima@hotmail.com
- **Endereço**:
  - Rua: Rua Oscar Freire, 456, Cobertura
  - Bairro: Jardins
  - Cidade: São Paulo
  - Estado: SP
  - CEP: 01426-001

### Instruções para Guilherme:
```
1. Executar o sistema
2. Ir em Gerenciar Compradores → Cadastrar comprador
3. Inserir os dados acima com todos os campos
4. Testar validação de CPF duplicado
5. Testar campos obrigatórios
6. Testar alterações e exclusões
7. Documentar resultados nos casos de teste
```

---

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

### Instruções para Gustavo:
```
1. ANTES DE CADASTRAR VENDAS:
   - Verificar se produtos, vendedores e compradores existem
   - Anotar estoques iniciais dos produtos

2. Cadastrar as vendas acima uma por uma
3. Verificar se estoques são atualizados automaticamente
4. Verificar se comissões são calculadas corretamente
5. Testar validações (comprador/vendedor/produto inexistente)
6. Testar estoque insuficiente
7. Documentar todos os resultados

CÁLCULOS PARA VERIFICAÇÃO:
- Venda 1: João deve ter R$ 80,39 de comissão
- Venda 2: Maria deve ter R$ 98,97 de comissão  
- Venda 3: João deve ter R$ 80,39 + R$ 49,49 = R$ 129,88
- Venda 4: Carlos deve ter R$ 2,70 de comissão
```

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

### Instruções para Gustavo:
```
1. Ir em menu principal → Emitir Nota Fiscal
2. Testar com os códigos de venda acima
3. Verificar formatação e cálculos
4. Testar com código de venda inexistente
5. Documentar resultados
```

---

## 🧪 Cenários de Teste Específicos

### Teste de Estoque Insuficiente
```
1. Verificar estoque atual do Produto 3 (Smartphone) - deve ser 8
2. Tentar fazer venda de 10 unidades
3. Verificar mensagem de erro
4. Fazer venda de 5 unidades (deve funcionar)
5. Verificar estoque atualizado para 3
6. Tentar venda de 5 novamente (deve falhar)
```

### Teste de Exclusão com Reversão
```
1. Anotar estoque do Produto 1 antes da venda
2. Anotar comissão do Vendedor 1 antes da venda
3. Fazer venda do Produto 1
4. Verificar estoque diminuído e comissão aumentada
5. Excluir a venda
6. Verificar estoque e comissão revertidos
```

### Teste de Validações
```
1. Tentar venda com CPF inexistente: 000.000.000-00
2. Tentar venda com vendedor inexistente: número 999
3. Tentar venda com produto inexistente: código 999
4. Verificar mensagens de erro apropriadas
```

---

## 📊 Checklist de Demonstração Final

### Dados Cadastrados
- [x] 5 Produtos cadastrados (Lucas)
- [x] 4 Vendedores cadastrados (Daniel)
- [x] 4 Compradores cadastrados (Guilherme)
- [x] 4 Vendas realizadas (Gustavo)

### Funcionalidades Testadas
- [x] CRUD completo de produtos
- [x] CRUD completo de vendedores
- [x] CRUD completo de compradores
- [x] Cadastro e consulta de vendas
- [x] Exclusão de vendas com reversão
- [x] Emissão de notas fiscais
- [x] Cálculo automático de frete
- [x] Validações de integridade

### Cenários Especiais
- [x] Teste de estoque insuficiente
- [x] Teste de códigos duplicados
- [x] Teste de dados obrigatórios
- [x] Teste de limites do sistema
- [x] Teste de reversões na exclusão

---

## 📝 Observações Importantes

1. **Ordem de Cadastro**: Sempre cadastrar na ordem: Produtos → Vendedores → Compradores → Vendas
2. **Backup dos Dados**: Como não há persistência, anotar dados importantes para re-inserção se necessário
3. **Teste Gradual**: Cada membro deve testar seu módulo individualmente antes da integração
4. **Documentação**: Registrar todos os testes realizados nos relatórios individuais
5. **Coordenação**: Gustavo deve coordenar os testes de integração após todos os módulos estarem prontos

**LEMBRE-SE**: Este arquivo é apenas um guia. Os dados devem ser inseridos manualmente através da interface do sistema para validar completamente todas as funcionalidades!
