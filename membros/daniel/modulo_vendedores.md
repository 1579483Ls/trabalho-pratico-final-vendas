# Módulo de Vendedores - Daniel

## 🎯 Responsabilidades
- Gerenciamento completo de vendedores
- Funções de CRUD para vendedores
- Controle de comissões

## 📋 Tarefas da Sprint 2

### 1. Documentação das Funções
- [x] `buscar_vendedor_por_numero()`
- [x] `cadastrar_vendedor()`
- [x] `consultar_vendedores()`
- [ ] `alterar_vendedor()`
- [ ] `excluir_vendedor()`

### 2. Implementação
- [ ] Casos de sucesso
- [ ] Tratamento de erros
- [ ] Validações

### 3. Testes
- [ ] Definir casos de teste
- [ ] Executar testes
- [ ] Documentar resultados

## 📚 Funções a Implementar

### `int buscar_vendedor_por_numero(int numero)`
**Status**: ✅ Implementado 
**Descrição**: Busca vendedor pelo número  
**Entrada**: Número do vendedor  
**Saída**: Índice no array ou -1  

### `void cadastrar_vendedor()`
**Status**: ✅ Implementado 
**Descrição**: Cadastra novo vendedor  
**Validações necessárias**:
- Nome não pode ser vazio
- Número único
- Salário fixo > 0
- Comissões iniciam em 0

### `void consultar_vendedores()`
**Status**:   ✅ Implementado 
**Descrição**: Lista vendedores ativos  
**Formato**: Tabular com número, nome, salário, comissões

### `void alterar_vendedor()`
**Status**:  
**Descrição**: Altera dados do vendedor  
**Permite alterar**: Nome, salário fixo  
**Não permite**: Número, comissões

### `void excluir_vendedor()`
**Status**: 
**Descrição**: Remove vendedor (exclusão lógica)  
**Confirmação**: Sim/Não

## ✅ Casos de Teste a Implementar

### CT001 - Cadastrar Vendedor com automatico
**Entrada**:
- Nome: "João Vendedor"
- Número: Automático
- Salário: 2000.00

### CT002 - Cadastrar Vendedor com numero manual
**Entrada**:
- Nome: "Maria Carvalho"
- Número: 3
- Salário: 750.00

### CT003 - Cadastrar Vendedor com Número Duplicado
**Entrada**:
- Nome: "Ana Costa"
- Número: 1 (já existente)
- Salário: 2000.00

**Resultado Esperado**: Erro - número já existe

### CT004 - Cadastrar Vendedor com Salário Inválido
**Entrada**:
- Nome: "Pedro Santos"
- Número: Automático
- Salário: 0

**Resultado Esperado**: Erro - salário deve ser maior que 0

### CT005 - Buscar Vendedor Existente
**Entrada**: Número 1
**Resultado Esperado**: Retorna índice válido

### CT006 - Buscar Vendedor Inexistente
**Entrada**: Número 999
**Resultado Esperado**: Retorna -1

### CT007 - Consultar Vendedores
**Pré-condição**: Pelo menos 1 vendedor cadastrado
**Resultado Esperado**: Lista vendedores em formato tabular


## 📊 Relatório de Execução
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
| CT008 | [ ] | [ ] Passou / [ ] Falhou | |
| CT009 | [ ] | [ ] Passou / [ ] Falhou | |
| CT010 | [ ] | [ ] Passou / [ ] Falhou | |
| CT011 | [ ] | [ ] Passou / [ ] Falhou | |
## 📝 Regras de Negócio Específicas


## 🔄 Integração com Outros Módulos

## 📝 Notas de Implementação
<!-- Adicionar observações durante o desenvolvimento -->

## 🐛 Bugs Encontrados
<!-- Documentar problemas encontrados -->

## ✨ Melhorias Sugeridas
<!-- Sugestões para versões futuras -->
