# Módulo de Produtos - Lucas Siqueira

## 🎯 Responsabilidades
- Gerenciamento completo de produtos
- Funções de CRUD para produtos
- Validações de negócio

## 📋 Tarefas da Sprint 1

### 1. Documentação das Funções
- [ ] `buscar_produto_por_codigo()`
- [ ] `cadastrar_produto()`
- [ ] `consultar_produtos()`
- [ ] `alterar_produto()`
- [ ] `excluir_produto()`

### 2. Implementação
- [ ] Casos de sucesso
- [ ] Tratamento de erros
- [ ] Validações

### 3. Testes
- [ ] Definir casos de teste
- [ ] Executar testes
- [ ] Documentar resultados

## 📚 Funções a Implementar

### `int buscar_produto_por_codigo(int codigo)`
**Status**:  
**Descrição**: Busca produto pelo código  
**Entrada**: Código do produto  
**Saída**: Índice no array ou -1  

### `void cadastrar_produto()`
**Status**:  
**Descrição**: Cadastra novo produto  
**Validações necessárias**:
- Nome não pode ser vazio
- Código único
- Quantidade >= 0
- Preço > 0

### `void consultar_produtos()`
**Status**:   
**Descrição**: Lista produtos ativos  
**Formato**: Tabular com código, nome, estoque, preço

### `void alterar_produto()`
**Status**:  
**Descrição**: Altera dados do produto  
**Permite alterar**: Nome, estoque, preço  
**Não permite**: Código

### `void excluir_produto()`
**Status**:   
**Descrição**: Remove produto (exclusão lógica)  
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

## 📝 Notas de Implementação
<!-- Adicionar observações durante o desenvolvimento -->

## 🐛 Bugs Encontrados
<!-- Documentar problemas encontrados -->

## ✨ Melhorias Sugeridas
<!-- Sugestões para versões futuras -->
