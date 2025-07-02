# Módulo de Vendas e Integração - Gustavo

## 🎯 Responsabilidades
- Gerenciamento completo de vendas
- Integração entre todos os módulos
- Funcionalidades auxiliares (nota fiscal, frete)
- Coordenação final do projeto

## 📋 Tarefas da Sprint 3

### 1. Documentação das Funções de Vendas
- [x] `buscar_venda_por_codigo()`
- [x] `cadastrar_venda()`
- [x] `consultar_vendas()`
- [x] `alterar_venda()`
- [x] `excluir_venda()`

### 2. Implementação de Vendas
- [x] Casos de sucesso
- [x] Tratamento de erros
- [x] Validações
- [x] Integração com outros módulos

### 3. Testes de Vendas
- [x] Definir casos de teste
- [x] Executar testes
- [x] Documentar resultados

## 📋 Tarefas da Sprint 4

### 1. Documentação das Funções Auxiliares
- [x] `calcular_frete()`
- [x] `emitir_nota_fiscal()`

### 2. Implementação Auxiliar
- [x] Cálculo de frete
- [x] Nota fiscal
- [x] Integração final

### 3. Testes de Integração
- [ ] Testes end-to-end
- [ ] Testes de integração
- [ ] Validação final

## 📚 Funções de Vendas a Implementar

### `int buscar_venda_por_codigo(int codigo)`
**Status**:  ✅ Implementado 
**Descrição**: Busca venda pelo código  
**Entrada**: Código da venda  
**Saída**: Índice no array ou -1  

### `void cadastrar_venda()`
**Status**:  ✅ Implementado  
**Descrição**: Registra nova venda  
**Integrações necessárias**:
- Validar comprador (CPF)
- Validar vendedor (número)
- Validar produtos (código e estoque)
- Atualizar estoque automaticamente
- Calcular comissão do vendedor

### `void consultar_vendas()`
**Status**:  ✅ Implementado  
**Descrição**: Lista vendas ativas  
**Formato**: Dados completos com itens detalhados

### `void alterar_venda()`
**Status**:   ✅ Implementado 
**Descrição**: Altera dados da venda  
**Decisão**: Orientar exclusão e recadastro

### `void excluir_venda()`
**Status**:   ✅ Implementado 
**Descrição**: Cancela venda  
**Funcionalidades**:
- Reverter estoque
- Reverter comissão
- Exclusão lógica

## 📚 Funções Auxiliares a Implementar

### `float calcular_frete(float valor_venda)`
**Status**:   ✅ Implementado 
**Descrição**: Calcula frete baseado no valor  
**Regras**:
- Até R$ 100: R$ 30
- R$ 100,01 a R$ 300: R$ 20
- Acima de R$ 300: Grátis

### `void emitir_nota_fiscal()`
**Status**:   ✅ Implementado 
**Descrição**: Gera nota fiscal  
**Integrações**:
- Dados do comprador
- Dados da venda
- Cálculo de frete
- Formatação

## ✅ Casos de Teste de Vendas

### CT001 - Cadastrar Venda com Sucesso
**Entrada**:
- CPF Comprador: "123.456.789-00"
- Número Vendedor: 1
- Produtos: Código 1, Qtd 2

**Resultado Esperado**: 
- Venda cadastrada
- Estoque atualizado
- Comissão calculada

### CT002 - Cadastrar Venda com Comprador Inexistente
**Entrada**:
- CPF: "999.999.999-99"

**Resultado Esperado**: Erro - comprador não encontrado

### CT003 - Cadastrar Venda com Vendedor Inexistente
**Entrada**:
- Número Vendedor: 999

**Resultado Esperado**: Erro - vendedor não encontrado

### CT004 - Cadastrar Venda com Produto Inexistente
**Entrada**:
- Código Produto: 999

**Resultado Esperado**: Erro - produto não encontrado

### CT005 - Cadastrar Venda com Estoque Insuficiente
**Entrada**:
- Produto com estoque 5
- Quantidade solicitada: 10

**Resultado Esperado**: Erro - estoque insuficiente

### CT006 - Verificar Atualização de Estoque
**Pré-condição**: Produto com estoque 10
**Entrada**: Venda de 3 unidades
**Resultado Esperado**: Estoque = 7

### CT007 - Verificar Cálculo de Comissão
**Entrada**: Venda de R$ 1000
**Resultado Esperado**: Comissão = R$ 30 (3%)

### CT008 - Excluir Venda
**Entrada**: 
- Código da venda válido
- Confirmação: S

**Resultado Esperado**: 
- Venda marcada como inativa
- Estoque revertido
- Comissão revertida

## ✅ Casos de Teste Auxiliares

### CT009 - Calcular Frete Valor Baixo
**Entrada**: R$ 50,00
**Resultado Esperado**: R$ 30,00

### CT010 - Calcular Frete Valor Médio
**Entrada**: R$ 200,00
**Resultado Esperado**: R$ 20,00

### CT011 - Calcular Frete Valor Alto
**Entrada**: R$ 500,00
**Resultado Esperado**: R$ 0,00

### CT012 - Emitir Nota Fiscal
**Pré-condição**: Venda cadastrada
**Entrada**: Código da venda
**Resultado Esperado**: 
- Dados do comprador
- Itens detalhados
- Frete calculado
- Total geral

## ✅ Casos de Teste de Integração

### CT013 - Fluxo Completo de Venda
**Cenário**: Cadastrar produto → vendedor → comprador → venda → nota fiscal
**Resultado Esperado**: Fluxo sem erros

### CT014 - Múltiplos Itens na Venda
**Entrada**: 3 produtos diferentes
**Resultado Esperado**: 
- Todos os estoques atualizados
- Valor total correto
- Comissão sobre total

### CT015 - Venda com Frete Grátis
**Entrada**: Venda acima de R$ 300
**Resultado Esperado**: Frete = 0 na nota fiscal

## 📊 Relatório de Execução - Vendas
<!-- A ser preenchido durante a execução dos testes -->

| Caso de Teste | Status | Resultado | Observações |
|---------------|--------|-----------|-------------|
| CT001 | [x] | [x] Passou / [ ] Falhou | |
| CT002 | [x] | [x] Passou / [ ] Falhou | |
| CT003 | [x] | [x] Passou / [ ] Falhou | |
| CT004 | [x] | [x] Passou / [ ] Falhou | |
| CT005 | [x] | [x] Passou / [ ] Falhou | |
| CT006 | [x] | [x] Passou / [ ] Falhou | |
| CT007 | [x] | [x] Passou / [ ] Falhou | |
| CT008 | [x] | [x] Passou / [ ] Falhou | |

## 📊 Relatório de Execução - Auxiliares
<!-- A ser preenchido durante a execução dos testes -->

| Caso de Teste | Status | Resultado | Observações |
|---------------|--------|-----------|-------------|
| CT009 | [x] | [x] Passou / [ ] Falhou | |
| CT010 | [x] | [x] Passou / [ ] Falhou | |
| CT011 | [x] | [ ] Passou / [x] Falhou | |
| CT012 | [x] | [] Passou / [x] Falhou | |

## 📊 Relatório de Execução - Integração
<!-- A ser preenchido durante a execução dos testes -->

| Caso de Teste | Status | Resultado | Observações |
|---------------|--------|-----------|-------------|
| CT013 | [x] | [x] Passou / [ ] Falhou | |
| CT014 | [x] | [x] Passou / [ ] Falhou | |
| CT015 | [x] | [x] Passou / [ ] Falhou | |

## 📝 Regras de Negócio Críticas
- Comissão sempre 3% do valor total da venda
- Estoque deve ser atualizado automaticamente
- Não permitir venda com estoque insuficiente
- Exclusão de venda deve reverter todas as alterações
- Códigos de venda são sequenciais e automáticos

## 🔄 Pontos de Integração
1. **Com Produtos**: Validação e atualização de estoque
2. **Com Vendedores**: Validação e cálculo de comissões
3. **Com Compradores**: Validação e dados para nota fiscal
4. **Entre Funções**: Cálculo de frete na nota fiscal

## 📝 Checklist de Integração Final

- [x] Testar fluxo completo produto→vendedor→comprador→venda
- [x] Validar cálculos automáticos
- [x] Verificar reversões na exclusão
- [x] Testar nota fiscal com todos os cenários
- [x] Validar limites máximos do sistema
- [x] Testar casos extremos

## 📝 Notas de Implementação
<!-- Adicionar observações durante o desenvolvimento -->

## 🐛 Bugs Encontrados
<!-- Documentar problemas encontrados -->

## ✨ Melhorias Sugeridas
<!-- Sugestões para versões futuras -->
