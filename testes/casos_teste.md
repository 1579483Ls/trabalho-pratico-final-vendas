# Casos de Teste - Sistema de Vendas

## 📋 Visão Geral
Documento consolidado com todos os casos de teste do sistema de vendas, organizados por módulo e tipo de teste.

## 🏷️ Convenções
- **ID**: Identificador único do caso de teste
- **Módulo**: Produtos (P), Vendedores (V), Compradores (C), Vendas (VE), Auxiliares (A), Integração (I)
- **Tipo**: Funcional (F), Integração (I), Extremo (E)
- **Prioridade**: Alta, Média, Baixa

---

## 📦 Módulo de Produtos (Lucas)



---

## 👥 Módulo de Vendedores (Daniel)



---



---

## 💰 Módulo de Vendas (Gustavo)


### VE-F-001: Cadastrar Venda Simples
**Prioridade**: Alta  
**Pré-condições**: Comprador, vendedor e produto existem  
**Dados de Entrada**:
- CPF: "123.456.789-00"
- Vendedor: 1
- Produto: 1, Quantidade: 2

**Resultado Esperado**: 
- Venda cadastrada
- Estoque atualizado
- Comissão calculada

### VE-F-002: Venda Múltiplos Itens
**Prioridade**: Alta  
**Dados de Entrada**: 2 produtos diferentes  
**Resultado Esperado**: Ambos produtos na venda

### VE-F-003: Comprador Inexistente
**Prioridade**: Alta  
**Dados de Entrada**: CPF inexistente  
**Resultado Esperado**: "Comprador não encontrado!"

### VE-F-004: Vendedor Inexistente
**Prioridade**: Alta  
**Dados de Entrada**: Número vendedor inexistente  
**Resultado Esperado**: "Vendedor não encontrado!"

### VE-F-005: Produto Inexistente
**Prioridade**: Alta  
**Dados de Entrada**: Código produto inexistente  
**Resultado Esperado**: "Produto não encontrado!"

### VE-F-006: Estoque Insuficiente
**Prioridade**: Alta  
**Pré-condições**: Produto com estoque 5  
**Dados de Entrada**: Quantidade 10  
**Resultado Esperado**: "Quantidade insuficiente em estoque!"

### VE-F-007: Consultar Vendas
**Prioridade**: Média  
**Resultado Esperado**: Lista detalhada de vendas

### VE-F-008: Excluir Venda
**Prioridade**: Alta  
**Resultado Esperado**: Venda inativa, reversões aplicadas


---

## 📄 Módulo Auxiliar (Gustavo)

### A-F-001: Calcular Frete Baixo
**Prioridade**: Alta  
**Dados de Entrada**: valor = 50.00  
**Resultado Esperado**: 30.00

### A-F-002: Calcular Frete Médio
**Prioridade**: Alta  
**Dados de Entrada**: valor = 200.00  
**Resultado Esperado**: 20.00

### A-F-003: Calcular Frete Grátis
**Prioridade**: Alta  
**Dados de Entrada**: valor = 400.00  
**Resultado Esperado**: 0.00

### A-F-004: Emitir Nota Fiscal
**Prioridade**: Alta  
**Pré-condições**: Venda registrada  
**Resultado Esperado**: Nota fiscal formatada

---

## 🔗 Testes de Integração



---

## 📊 Matriz de Rastreabilidade

| Módulo | Total Casos | Funcionais | Integração | Extremos |
|--------|-------------|------------|------------|----------|
| Produtos    |  |  |  |  |
| Vendedores  |  |  |  |  |
| Compradores |  |  |  |  |
| Vendas      |  |  |  |  |
| Auxiliares  |  |  |  |  |
| Integração  |  |  |  |  |
| **Total** | **** | **** | **** | **** |

## 📋 Template de Execução de Teste

```
=== EXECUÇÃO DE TESTE ===
ID: [ID do teste]
Data/Hora: [DD/MM/AAAA HH:MM]
Executado por: [Nome do responsável]
Ambiente: [Ambiente de teste]

DADOS DE ENTRADA:
[Dados utilizados]

PROCEDIMENTO EXECUTADO:
[Passos realizados]

RESULTADO OBTIDO:
[Resultado real]

STATUS: [ ] PASSOU [ ] FALHOU

OBSERVAÇÕES:
[Comentários adicionais]

EVIDÊNCIAS:
[Screenshots, logs, etc.]
```

## 📈 Critérios de Aceitação

### Para Aprovação do Teste
- [ ] Resultado obtido = Resultado esperado
- [ ] Sem erros inesperados
- [ ] Performance adequada
- [ ] Interface funcional

### Para Aprovação do Módulo
- [ ] 100% dos casos funcionais aprovados
- [ ] 90%+ dos casos de integração aprovados
- [ ] Bugs críticos corrigidos
- [ ] Documentação completa
