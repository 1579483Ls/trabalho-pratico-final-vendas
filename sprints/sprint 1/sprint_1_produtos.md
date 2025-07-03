# Sprint 1 - Módulo de Produtos
**Duração**: 3-4 dias  
**Responsável**: Lucas Siqueira  
**Data Início**: 21/06/2025  
**Data Fim**: 23/06/2025  
**Status**: ✅ CONCLUÍDA COM SUCESSO  

## 🎯 Objetivo da Sprint
Implementar e testar completamente o módulo de gerenciamento de produtos do sistema de vendas.

## 📋 Backlog da Sprint

### User Stories Selecionadas
1. **Como** administrador, **eu quero** cadastrar produtos **para** manter o catálogo atualizado
2. **Como** usuário, **eu quero** consultar produtos **para** visualizar o catálogo disponível  
3. **Como** administrador, **eu quero** alterar dados de produtos **para** manter informações atualizadas
4. **Como** administrador, **eu quero** excluir produtos **para** remover itens descontinuados

### Tarefas Técnicas
- [x] **T001**: Documentar assinatura da função `buscar_produto_por_codigo()` ✅ COMPLETO
- [x] **T002**: Documentar assinatura da função `cadastrar_produto()` ✅ COMPLETO
- [x] **T003**: Documentar assinatura da função `consultar_produtos()` ✅ COMPLETO
- [x] **T004**: Documentar assinatura da função `alterar_produto()` ✅ COMPLETO
- [x] **T005**: Documentar assinatura da função `excluir_produto()` ✅ COMPLETO
- [x] **T006**: Implementar casos de sucesso para todas as funções ✅ IMPLEMENTADO
- [x] **T007**: Definir casos de teste para o módulo ✅ 14 CASOS DEFINIDOS
- [x] **T008**: Executar todos os casos de teste ✅ EXECUTADOS
- [x] **T009**: Implementar tratamento de exceções ✅ IMPLEMENTADO
- [x] **T010**: Re-executar testes após implementação de exceções ✅ CONCLUÍDO
- [x] **T011**: Gerar relatório de execução de testes ✅ RELATÓRIO GERADO

## 📚 Documentação de Funções

### Função: `int buscar_produto_por_codigo(int codigo)`
**Propósito**: Localizar um produto específico no array de produtos pelo seu código único
**Parâmetros de Entrada**: 
- `codigo` (int): Código único do produto a ser localizado
**Parâmetros de Saída**: 
- Retorna o índice do produto no array (0 a num_produtos-1) se encontrado
- Retorna -1 se o produto não for encontrado ou estiver inativo

### Função: `void cadastrar_produto()`
**Propósito**: Adicionar um novo produto ao sistema com validações adequadas
**Parâmetros de Entrada**: Nenhum (coleta dados via interface)
**Parâmetros de Saída**: Nenhum (modifica array global produtos[])
**Efeitos Colaterais**: 
- Incrementa num_produtos
- Atualiza proximo_codigo_produto se necessário
- Adiciona produto ao array produtos[]

### Função: `void consultar_produtos()`
**Propósito**: Exibir lista formatada de todos os produtos ativos no sistema
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Nenhum (saída via printf)
**Formato de Saída**: Tabela com colunas Código, Nome, Estoque, Preço

### Função: `void alterar_produto()`
**Propósito**: Modificar dados de um produto existente no sistema
**Parâmetros de Entrada**: Nenhum (solicita código via interface)
**Parâmetros de Saída**: Nenhum (modifica array global produtos[])
**Campos Alteráveis**: Nome, quantidade em estoque, preço de venda

### Função: `void excluir_produto()`
**Propósito**: Remover logicamente um produto do sistema
**Parâmetros de Entrada**: Nenhum (solicita código via interface)
**Parâmetros de Saída**: Nenhum (modifica campo ativo do produto)
**Tipo de Exclusão**: Lógica (ativo = 0)

## ✅ Casos de Teste

### CT001 - Cadastrar Produto com Código Automático
**Objetivo**: Verificar cadastro com geração automática de código
**Procedimento**:
1. Executar cadastrar_produto()
2. Escolher opção 1 (código automático)
3. Inserir nome: "Produto Teste 1"
4. Inserir estoque: 10
5. Inserir preço: 99.99

**Entrada**:
- Nome: "Produto Teste 1"
- Código: Automático
- Estoque: 10
- Preço: 99.99

**Saída Esperada**: 
- Produto cadastrado com sucesso
- Código gerado automaticamente
- Produto visível na consulta

### CT002 - Cadastrar Produto com Código Manual
**Objetivo**: Verificar cadastro com código manual
**Procedimento**:
1. Executar cadastrar_produto()
2. Escolher opção 2 (código manual)
3. Inserir código: 100
4. Inserir dados restantes

**Entrada**:
- Nome: "Produto Teste 2"
- Código: 100
- Estoque: 20
- Preço: 150.00

**Saída Esperada**: 
- Produto cadastrado com código 100
- proximo_codigo_produto atualizado para 101

### CT003 - Tentar Cadastrar com Código Duplicado
**Objetivo**: Verificar validação de código único
**Pré-condição**: Produto com código 1 já existe
**Procedimento**:
1. Executar cadastrar_produto()
2. Escolher código manual = 1
3. Tentar cadastrar

**Entrada**:
- Código: 1 (duplicado)

**Saída Esperada**: 
- Mensagem "Código já existe! Digite outro código."
- Solicitar novo código

### CT004 - Buscar Produto Existente
**Objetivo**: Verificar localização de produto válido
**Pré-condição**: Produto código 1 existe
**Procedimento**:
1. Chamar buscar_produto_por_codigo(1)

**Entrada**: codigo = 1
**Saída Esperada**: Retorno >= 0 (índice válido)

### CT005 - Buscar Produto Inexistente
**Objetivo**: Verificar comportamento com produto inválido
**Procedimento**:
1. Chamar buscar_produto_por_codigo(999)

**Entrada**: codigo = 999
**Saída Esperada**: Retorno = -1

### CT006 - Consultar Produtos com Lista Vazia
**Objetivo**: Verificar comportamento sem produtos
**Pré-condição**: num_produtos = 0
**Procedimento**:
1. Executar consultar_produtos()

**Saída Esperada**: "Nenhum produto cadastrado."

### CT007 - Consultar Produtos com Lista Preenchida
**Objetivo**: Verificar exibição de produtos
**Pré-condição**: Pelo menos 1 produto ativo
**Procedimento**:
1. Executar consultar_produtos()

**Saída Esperada**: 
- Cabeçalho da tabela
- Linha para cada produto ativo
- Formato: Código | Nome | Estoque | Preço

### CT008 - Alterar Nome do Produto
**Objetivo**: Verificar alteração de nome
**Pré-condição**: Produto código 1 existe
**Procedimento**:
1. Executar alterar_produto()
2. Inserir código: 1
3. Escolher opção 1 (alterar nome)
4. Inserir novo nome: "Nome Alterado"

**Entrada**: 
- Código: 1
- Opção: 1
- Novo nome: "Nome Alterado"

**Saída Esperada**: 
- "Produto alterado com sucesso!"
- Nome deve aparecer alterado na consulta

### CT009 - Alterar Estoque do Produto
**Objetivo**: Verificar alteração de estoque
**Procedimento**:
1. Executar alterar_produto()
2. Inserir código válido
3. Escolher opção 2 (alterar estoque)
4. Inserir nova quantidade: 50

**Saída Esperada**: Estoque atualizado para 50

### CT010 - Alterar Preço do Produto
**Objetivo**: Verificar alteração de preço
**Procedimento**:
1. Executar alterar_produto()
2. Inserir código válido
3. Escolher opção 3 (alterar preço)
4. Inserir novo preço: 199.99

**Saída Esperada**: Preço atualizado para 199.99

### CT011 - Tentar Alterar Produto Inexistente
**Objetivo**: Verificar tratamento de produto inválido
**Procedimento**:
1. Executar alterar_produto()
2. Inserir código: 999

**Saída Esperada**: "Produto não encontrado!"

### CT012 - Excluir Produto com Confirmação
**Objetivo**: Verificar exclusão com confirmação
**Pré-condição**: Produto código 1 existe
**Procedimento**:
1. Executar excluir_produto()
2. Inserir código: 1
3. Confirmar: s

**Saída Esperada**: 
- "Produto excluído com sucesso!"
- Produto não aparece mais na consulta

### CT013 - Excluir Produto sem Confirmação
**Objetivo**: Verificar cancelamento de exclusão
**Procedimento**:
1. Executar excluir_produto()
2. Inserir código válido
3. Confirmar: n

**Saída Esperada**: 
- "Exclusão cancelada."
- Produto continua ativo

### CT014 - Validar Limite Máximo de Produtos
**Objetivo**: Verificar comportamento no limite
**Pré-condição**: num_produtos = MAX_PRODUTOS
**Procedimento**:
1. Tentar cadastrar mais um produto

**Saída Esperada**: "Limite máximo de produtos atingido!"

## 📊 Relatório de Execução de Testes
**Data de Execução**: 21/06/2025 23/06/2025 
**Responsável**: Lucas Siqueira  
**Status Geral**: ✅ TODOS OS TESTES PASSARAM

| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| CT001 | Cadastrar Produto - Código Automático | ✅ | Passou/Falhou [PASSOU] | [21/06 - 14:57] | Geração automática funcional |
| CT002 | Cadastrar Produto - Código Manual | ✅ | Passou/Falhou [PASSOU] | [21/06 - 14:40] | Validação de código manual OK |
| CT003 | Código Duplicado | ✅ | Passou/Falhou [PASSOU] | [21/06 - 15:10] | Validação funcionando corretamente |
| CT004 | Buscar Produto Existente | ✅ | Passou/Falhou [PASSOU] | [21/06 - 15:11] | Busca retorna índice correto |
| CT005 | Buscar Produto Inexistente | ✅ | Passou/Falhou [PASSOU] | [21/06 - 15:12] | Retorna -1 como esperado |
| CT006 | Consultar Lista Vazia | ✅ | Passou/Falhou [PASSOU] | [21/06 - 15:15] | Mensagem adequada exibida |
| CT007 | Consultar Lista Preenchida | ✅ | Passou/Falhou [PASSOU] | [21/06 - 15:17] | Formato tabular correto |
| CT008 | Alterar Nome | ✅ | Passou/Falhou [PASSOU] | [22/06 - 14:17] | Alteração de nome funcional |
| CT009 | Alterar Estoque | ✅ | Passou/Falhou [PASSOU] | [22/06 - 14:22] | Atualização de estoque OK |
| CT010 | Alterar Preço | ✅ | Passou/Falhou [PASSOU] | [22/06 - 14:27] | Alteração de preço funcional |
| CT011 | Alterar Produto Inexistente | ✅ | Passou/Falhou [PASSOU] | [22/06 - 14:32] | Tratamento de erro adequado |
| CT012 | Excluir com Confirmação | ✅ | Passou/Falhou [PASSOU] | [23/07 - 11:10] | Exclusão lógica funcional |
| CT013 | Excluir sem Confirmação | ✅ | Passou/Falhou [PASSOU] | [23/07 - 11:15] | Cancelamento funcionando |
| CT014 | Limite Máximo | ✅ | Passou/Falhou [PASSOU] | [23/07 - 11:20] | Validação de limite OK |

## 📈 Métricas da Sprint
- **Total de Casos de Teste**: 14
- **Casos Executados**: 14
- **Casos que Passaram**: 14
- **Casos que Falharam**: 0
- **Taxa de Sucesso**: 100%

## 🐛 Bugs Encontrados
Nenhum bug crítico encontrado durante os testes. Todas as funcionalidades estão operando conforme especificado.

## ✅ Definition of Done
- [x] Todas as funções implementadas ✅ COMPLETO
- [x] Documentação completa ✅ COMPLETO
- [x] Casos de teste definidos ✅ 14 CASOS DEFINIDOS
- [x] Todos os testes executados ✅ 100% EXECUTADOS
- [x] Relatório de testes gerado ✅ RELATÓRIO COMPLETO
- [x] Bugs críticos corrigidos ✅ NENHUM BUG ENCONTRADO

## 📝 Retrospectiva da Sprint
**Data da Retrospectiva**: 02/07/2025

### O que funcionou bem?
- Implementação completa de todas as funções CRUD
- Casos de teste abrangentes cobrindo cenários positivos e negativos
- Validações adequadas para entrada de dados
- Exclusão lógica implementada corretamente
- Geração automática de códigos funcionando perfeitamente

### O que pode ser melhorado?
- Interface de usuário poderia ser mais intuitiva
- Implementar persistência de dados em arquivo
- Adicionar mais validações de formato (ex: preços negativos)

### Ações para próxima sprint?
- Aplicar lições aprendidas no módulo de vendedores
- Manter o mesmo padrão de documentação e testes
- Considerar implementação de logs de auditoria
