# Módulo de Produtos - Lucas Siqueira

## 🎯 Responsabilidades
- Gerenciamento completo de produtos
- Funções de CRUD para produtos
- Validações de negócio

## 📋 Tarefas da Sprint 1

### 1. Documentação das Funções
- [x] `buscar_produto_por_codigo()`
- [X] `cadastrar_produto()`
- [X] `consultar_produtos()`
- [x] `alterar_produto()`
- [x] `excluir_produto()`

### 2. Implementação
- [X] Casos de sucesso
- [ ] Tratamento de erros
- [ ] Validações

### 3. Testes
- [x] Definir casos de teste
- [ ] Executar testes
- [ ] Documentar resultados

## 📚 Funções a Implementar

### `int buscar_produto_por_codigo(int codigo)`
**Status**: ✅ Implementado
**Descrição**: Busca produto pelo código  
**Entrada**: Código do produto  
**Saída**: Índice no array ou -1  

### `void cadastrar_produto()`
**Status**: ✅ Implementado  
**Descrição**: Cadastra novo produto  
**Validações necessárias**:
- Nome não pode ser vazio
- Código único
- Quantidade >= 0
- Preço > 0

### `void consultar_produtos()`
**Status**: ✅ Implementado   
**Descrição**: Lista produtos ativos  
**Formato**: Tabular com código, nome, estoque, preço

### `void alterar_produto()`
**Status**: ✅ Implementado  
**Descrição**: Altera dados do produto  
**Permite alterar**: Nome, estoque, preço  
**Não permite**: Código

### `void excluir_produto()`
**Status**: ✅ Implementado   
**Descrição**: Remove produto (exclusão lógica)  
**Confirmação**: Sim/Não

## 📊 Relatório de Execução
<!-- A ser preenchido durante a execução dos testes -->

| Caso de Teste | Status | Resultado | Observações |
|---------------|--------|-----------|-------------|
| CT001 | [X] | [X] Passou / [ ] Falhou | |
| CT002 | [X] | [X] Passou / [ ] Falhou | |
| CT003 | [X] | [X] Passou / [ ] Falhou | |
| CT004 | [X] | [X] Passou / [ ] Falhou | |
| CT005 | [X] | [X] Passou / [ ] Falhou | |
| CT006 | [X] | [X] Passou / [ ] Falhou | |
| CT007 | [X] | [X] Passou / [ ] Falhou | |
| CT008 | [x] | [x] Passou / [ ] Falhou | |
| CT009 | [x] | [x] Passou / [ ] Falhou | |
| CT010 | [x] | [x] Passou / [ ] Falhou | |
| CT011 | [x] | [x] Passou / [ ] Falhou | |
| CT012 | [x] | [x] Passou / [ ] Falhou | |
| CT013 | [x] | [x] Passou / [ ] Falhou | |
| CT014 | [x] | [x] Passou / [ ] Falhou | |

## 📝 Notas de Implementação
<!-- Adicionar observações durante o desenvolvimento -->

## 🐛 Bugs Encontrados
<!-- Documentar problemas encontrados -->

## ✨ Melhorias Sugeridas
<!-- Sugestões para versões futuras -->
