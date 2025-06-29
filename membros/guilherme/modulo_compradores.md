# Módulo de Compradores - Guilherme

## 🎯 Responsabilidades
- Gerenciamento completo de compradores
- Funções de CRUD para compradores
- Validação de dados pessoais

## 📋 Tarefas da Sprint 2

### 1. Documentação das Funções
- [X] `buscar_comprador_por_cpf()`
- [X] `cadastrar_comprador()`
- [X] `consultar_compradores()`
- [X] `alterar_comprador()`
- [X] `excluir_comprador()`

### 2. Implementação
- [ ] Casos de sucesso
- [ ] Tratamento de erros
- [ ] Validações

### 3. Testes
- [ ] Definir casos de teste
- [ ] Executar testes
- [ ] Documentar resultados

## 📚 Funções a Implementar

### `int buscar_comprador_por_cpf(char *cpf)`
**Status**:  Implementado
**Descrição**: Busca comprador pelo CPF  
**Entrada**: CPF do comprador  
**Saída**: Índice no array ou -1  

### `void cadastrar_comprador()`
**Status**:  Implementado
**Descrição**: Cadastra novo comprador  
**Validações necessárias**:
- Nome não pode ser vazio
- CPF único e obrigatório
- Email obrigatório
- Endereço completo obrigatório

### `void consultar_compradores()`
**Status**:   Implementado
**Descrição**: Lista compradores ativos  
**Formato**: Dados pessoais + endereço completo

### `void alterar_comprador()`
**Status**:   Implementado
**Descrição**: Altera dados do comprador  
**Permite alterar**: Nome, email, endereço  
**Não permite**: CPF

### `void excluir_comprador()`
**Status**:   Implementado
**Descrição**: Remove comprador (exclusão lógica)  
**Confirmação**: Sim/Não

## ✅ Casos de Teste a Implementar


## 📊 Relatório de Execução
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
| CT009 | [ ] | [ ] Passou / [ ] Falhou | |
| CT010 | [ ] | [ ] Passou / [ ] Falhou | |
| CT011 | [ ] | [ ] Passou / [ ] Falhou | |


## 📝 Notas de Implementação
<!-- Adicionar observações durante o desenvolvimento -->

## 🐛 Bugs Encontrados
<!-- Documentar problemas encontrados -->

## ✨ Melhorias Sugeridas
<!-- Sugestões para versões futuras -->

