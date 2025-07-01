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
- [ ] Casos de sucesso
- [ ] Tratamento de erros
- [ ] Validações
- [ ] Integração com outros módulos

### 3. Testes de Vendas
- [ ] Definir casos de teste
- [ ] Executar testes
- [ ] Documentar resultados

## 📋 Tarefas da Sprint 4

### 1. Documentação das Funções Auxiliares
- [ ] `calcular_frete()`
- [ ] `emitir_nota_fiscal()`

### 2. Implementação Auxiliar
- [ ] Cálculo de frete
- [ ] Nota fiscal
- [ ] Integração final

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
**Status**:   
**Descrição**: Calcula frete baseado no valor  
**Regras**:
- Até R$ 100: R$ 30
- R$ 100,01 a R$ 300: R$ 20
- Acima de R$ 300: Grátis

### `void emitir_nota_fiscal()`
**Status**:   
**Descrição**: Gera nota fiscal  
**Integrações**:
- Dados do comprador
- Dados da venda
- Cálculo de frete
- Formatação

## ✅ Casos de Teste de Vendas


## ✅ Casos de Teste Auxiliares


## ✅ Casos de Teste de Integração

## 📊 Relatório de Execução - Vendas
<!-- A ser preenchido durante a execução dos testes -->

| Caso de Teste | Status | Resultado | Observações |
|---------------|--------|-----------|-------------|
| CT001 | [ ] | [ ] Passou / [ ] Falhou | |
| CT002 | [ ] | [ ] Passou / [ ] Falhou | |
| CT003 | [ ] | [ ] Passou / [ ] Falhou | |
| CT004 | [ ] | [ ] Passou / [ ] Falhou | |
| CT005 | [ ] | [ ] Passou / [ ] Falhou | |
| CT006 | [ ] | [ ] Passou / [ ] Falhou | |
| CT007 | [ ] | [ ] Passou / [ ] Falhou | |
| CT008 | [ ] | [ ] Passou / [ ] Falhou | |

## 📊 Relatório de Execução - Auxiliares
<!-- A ser preenchido durante a execução dos testes -->

| Caso de Teste | Status | Resultado | Observações |
|---------------|--------|-----------|-------------|
| CT009 | [ ] | [ ] Passou / [ ] Falhou | |
| CT010 | [ ] | [ ] Passou / [ ] Falhou | |
| CT011 | [ ] | [ ] Passou / [ ] Falhou | |
| CT012 | [ ] | [ ] Passou / [ ] Falhou | |

## 📊 Relatório de Execução - Integração
<!-- A ser preenchido durante a execução dos testes -->

| Caso de Teste | Status | Resultado | Observações |
|---------------|--------|-----------|-------------|
| CT013 | [ ] | [ ] Passou / [ ] Falhou | |
| CT014 | [ ] | [ ] Passou / [ ] Falhou | |
| CT015 | [ ] | [ ] Passou / [ ] Falhou | |

## 📝 Regras de Negócio Críticas

## 🔄 Pontos de Integração

## 📝 Checklist de Integração Final

## 📝 Notas de Implementação
<!-- Adicionar observações durante o desenvolvimento -->

## 🐛 Bugs Encontrados
<!-- Documentar problemas encontrados -->

## ✨ Melhorias Sugeridas
<!-- Sugestões para versões futuras -->
