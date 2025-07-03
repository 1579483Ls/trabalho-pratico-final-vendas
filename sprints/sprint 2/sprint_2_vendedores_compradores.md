# Sprint 2 - Módulos de Vendedores e Compradores
**Duração**: 3-4 dias  
**Responsáveis**: Daniel (Vendedores) + Guilherme (Compradores)  
**Data Início**: 24/06/2025  
**Data Fim**: 29/06/2025  
**Status**: ✅ CONCLUÍDA COM SUCESSO  

## 🎯 Objetivo da Sprint
Implementar e testar os módulos de gerenciamento de vendedores e compradores, criando a base de pessoas do sistema.

## 📋 Backlog da Sprint

### User Stories - Vendedores (Daniel)
1. **Como** administrador, **eu quero** cadastrar vendedores **para** gerenciar a equipe de vendas
2. **Como** usuário, **eu quero** consultar vendedores **para** visualizar a equipe disponível  
3. **Como** administrador, **eu quero** alterar dados de vendedores **para** manter informações atualizadas
4. **Como** administrador, **eu quero** excluir vendedores **para** remover funcionários desligados

### User Stories - Compradores (Guilherme)
1. **Como** administrador, **eu quero** cadastrar compradores **para** manter base de clientes
2. **Como** usuário, **eu quero** consultar compradores **para** visualizar a base de clientes
3. **Como** administrador, **eu quero** alterar dados de compradores **para** manter informações atualizadas
4. **Como** administrador, **eu quero** excluir compradores **para** remover clientes inativos

### Tarefas Técnicas - Daniel (Vendedores)
- [x] **T001**: Documentar funções do módulo de vendedores ✅ COMPLETO
- [x] **T002**: Implementar casos de sucesso para vendedores ✅ IMPLEMENTADO
- [x] **T003**: Definir casos de teste para vendedores ✅ 10 CASOS DEFINIDOS
- [x] **T004**: Executar testes de vendedores ✅ EXECUTADOS
- [x] **T005**: Implementar tratamento de exceções ✅ IMPLEMENTADO
- [x] **T006**: Gerar relatório de testes de vendedores ✅ RELATÓRIO GERADO

### Tarefas Técnicas - Guilherme (Compradores)
- [x] **T007**: Documentar funções do módulo de compradores ✅ COMPLETO
- [x] **T008**: Implementar casos de sucesso para compradores ✅ IMPLEMENTADO
- [x] **T009**: Definir casos de teste para compradores ✅ 12 CASOS DEFINIDOS
- [x] **T010**: Executar testes de compradores ✅ EXECUTADOS
- [x] **T011**: Implementar tratamento de exceções ✅ IMPLEMENTADO
- [x] **T012**: Gerar relatório de testes de compradores ✅ RELATÓRIO GERADO

### Tarefas de Integração
- [x] **T013**: Testar integração entre módulos ✅ TESTADO
- [x] **T014**: Validar dados para futuras vendas ✅ VALIDADO
- [x] **T015**: Documentar pontos de integração ✅ DOCUMENTADO

## 📚 Documentação - Módulo Vendedores (Daniel)

### Função: `int buscar_vendedor_por_numero(int numero)`
**Propósito**: Localizar vendedor pelo número único
**Parâmetros de Entrada**: 
- `numero` (int): Número único do vendedor
**Parâmetros de Saída**: 
- Índice do vendedor (0 a num_vendedores-1) ou -1 se não encontrado

### Função: `void cadastrar_vendedor()`
**Propósito**: Adicionar novo vendedor ao sistema
**Parâmetros de Entrada**: Nenhum (interface)
**Parâmetros de Saída**: Nenhum
**Efeitos**: Incrementa num_vendedores, atualiza proximo_numero_vendedor

### Função: `void consultar_vendedores()`
**Propósito**: Listar vendedores ativos
**Formato**: Tabela com número, nome, salário fixo, comissões

### Função: `void alterar_vendedor()`
**Propósito**: Modificar dados do vendedor
**Campos Alteráveis**: Nome, salário fixo
**Restrições**: Número e comissões não alteráveis

### Função: `void excluir_vendedor()`
**Propósito**: Remover vendedor logicamente
**Tipo**: Exclusão lógica (ativo = 0)

## 📚 Documentação - Módulo Compradores (Guilherme)

### Função: `int buscar_comprador_por_cpf(char *cpf)`
**Propósito**: Localizar comprador pelo CPF único
**Parâmetros de Entrada**: 
- `cpf` (char*): CPF do comprador
**Parâmetros de Saída**: 
- Índice do comprador ou -1 se não encontrado

### Função: `void cadastrar_comprador()`
**Propósito**: Adicionar novo comprador
**Validações**: CPF único, dados obrigatórios, endereço completo
**Efeitos**: Incrementa num_compradores

### Função: `void consultar_compradores()`
**Propósito**: Listar compradores ativos
**Formato**: Dados pessoais + endereço completo

### Função: `void alterar_comprador()`
**Propósito**: Modificar dados do comprador
**Campos Alteráveis**: Nome, email, endereço
**Restrições**: CPF não alterável

### Função: `void excluir_comprador()`
**Propósito**: Remover comprador logicamente
**Tipo**: Exclusão lógica (ativo = 0)

## ✅ Casos de Teste - Vendedores (Daniel)

### VT001 - Cadastrar Vendedor Código Automático
**Entrada**:
- Nome: "João Vendedor"
- Número: Automático
- Salário: 2000.00

**Saída Esperada**: Vendedor cadastrado, número gerado

### VT002 - Cadastrar Vendedor Código Manual
**Entrada**:
- Nome: "Maria Vendedora"
- Número: 50
- Salário: 2500.00

**Saída Esperada**: Vendedor cadastrado com número 50

### VT003 - Número Duplicado
**Pré-condição**: Vendedor número 1 existe
**Entrada**: Número 1
**Saída Esperada**: Erro de duplicação

### VT004 - Salário Inválido
**Entrada**: Salário 0 ou negativo
**Saída Esperada**: Erro de validação

### VT005 - Buscar Vendedor Existente
**Entrada**: Número 1
**Saída Esperada**: Índice válido

### VT006 - Buscar Vendedor Inexistente
**Entrada**: Número 999
**Saída Esperada**: -1

### VT007 - Consultar Lista Vazia
**Pré-condição**: num_vendedores = 0
**Saída Esperada**: Mensagem apropriada

### VT008 - Consultar Lista Preenchida
**Pré-condição**: Vendedores cadastrados
**Saída Esperada**: Tabela formatada

### VT009 - Alterar Nome
**Entrada**: Nome "João Silva Santos"
**Saída Esperada**: Nome alterado

### VT010 - Alterar Salário
**Entrada**: Salário 3000.00
**Saída Esperada**: Salário alterado

### VT011 - Excluir com Confirmação
**Entrada**: Confirmação 's'
**Saída Esperada**: Vendedor inativo

### VT012 - Excluir sem Confirmação
**Entrada**: Confirmação 'n'
**Saída Esperada**: Operação cancelada

## ✅ Casos de Teste - Compradores (Guilherme)

### CT001 - Cadastrar Comprador Completo
**Entrada**:
- Nome: "Carlos Cliente"
- CPF: "111.222.333-44"
- Email: "carlos@email.com"
- Endereço: Completo

**Saída Esperada**: Comprador cadastrado

### CT002 - CPF Duplicado
**Pré-condição**: CPF já existe
**Entrada**: Mesmo CPF
**Saída Esperada**: Erro de duplicação

### CT003 - Dados Obrigatórios Vazios
**Entrada**: Nome ou email vazio
**Saída Esperada**: Erro de validação

### CT004 - Endereço Incompleto
**Entrada**: Campos de endereço vazios
**Saída Esperada**: Erro de validação

### CT005 - Buscar por CPF Existente
**Entrada**: CPF válido
**Saída Esperada**: Índice válido

### CT006 - Buscar por CPF Inexistente
**Entrada**: CPF inválido
**Saída Esperada**: -1

### CT007 - Consultar Lista Vazia
**Pré-condição**: Nenhum comprador
**Saída Esperada**: Mensagem apropriada

### CT008 - Consultar Lista Preenchida
**Pré-condição**: Compradores cadastrados
**Saída Esperada**: Dados completos

### CT009 - Alterar Nome
**Entrada**: Novo nome
**Saída Esperada**: Nome alterado

### CT010 - Alterar Email
**Entrada**: Novo email
**Saída Esperada**: Email alterado

### CT011 - Alterar Endereço
**Entrada**: Novo endereço completo
**Saída Esperada**: Endereço alterado

### CT012 - Excluir com Confirmação
**Entrada**: Confirmação 's'
**Saída Esperada**: Comprador inativo

## ✅ Casos de Teste - Integração

### IT001 - Dados para Vendas
**Objetivo**: Verificar se dados estão prontos para módulo de vendas
**Procedimento**:
1. Cadastrar vendedor
2. Cadastrar comprador
3. Verificar se podem ser usados em vendas

### IT002 - Validação de Referências
**Objetivo**: Verificar integridade referencial básica
**Procedimento**: Buscar vendedor e comprador por identificadores

## 📊 Relatório de Execução - Vendedores (Daniel)
**Data de Execução**: 26/06/2025  
**Responsável**: Daniel  
**Status Geral**: ✅ TODOS OS TESTES APROVADOS

| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| VT001 | Cadastrar Automático | ✅ | ✅ Passou | 24/06 17:47 | Número gerado automaticamente |
| VT002 | Cadastrar Manual | ✅ | ✅ Passou | 25/06 10:21 | Número manual aceito |
| VT003 | Número Duplicado | ✅ | ✅ Passou | 25/06 10:50 | Validação funcionando |
| VT004 | Salário Inválido | ✅ | ✅ Passou | 25/06 11:17 | Erro tratado adequadamente |
| VT005 | Buscar Existente | ✅ | ✅ Passou | 25/06 11:55 | Retorna índice correto |
| VT006 | Buscar Inexistente | ✅ | ✅ Passou | 25/06 12:21 | Retorna -1 conforme esperado |
| VT007 | Lista Vazia | ✅ | ✅ Passou | 25/06 12:02 | Mensagem adequada |
| VT008 | Lista Preenchida | ✅ | ✅ Passou | 25/06 12:05 | Formato tabular perfeito |0
| VT009 | Alterar Nome | ✅ | ✅ Passou | 25/06 12:07 | Nome alterado com sucesso |
| VT010 | Alterar Salário | ✅ | ✅ Passou | 25/06 12:09 | Salário atualizado |
| VT011 | Excluir Sim | ✅ | ✅ Passou | 25/06 12:50 | Exclusão lógica operacional |
| VT012 | Excluir Não | ✅ | ✅ Passou | 25/06 12:55 | Cancelamento funcionando |

## 📊 Relatório de Execução - Compradores (Guilherme)
**Data de Execução**: 29/06/2025  
**Responsável**: Guilherme  
**Status Geral**: ✅ TODOS OS TESTES APROVADOS

| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| CT001 | Cadastrar Completo | ✅ | ✅ Passou | 29/06 13:15 | Endereço completo funcionando |
| CT002 | CPF Duplicado | ✅ | ✅ Passou | 29/06 13:30 | Validação de CPF única |
| CT003 | Dados Vazios | ✅ | ✅ Passou | 29/06 13:45 | Campos obrigatórios validados |
| CT004 | Endereço Incompleto | ✅ | ✅ Passou | 29/06 14:00 | Validação de endereço completo |
| CT005 | Buscar Existente | ✅ | ✅ Passou | 29/06 14:15 | Busca por CPF funcionando |
| CT006 | Buscar Inexistente | ✅ | ✅ Passou | 29/06 14:30 | Retorna -1 corretamente |
| CT007 | Lista Vazia | ✅ | ✅ Passou | 29/06 14:45 | Mensagem adequada para lista vazia |
| CT008 | Lista Preenchida | ✅ | ✅ Passou | 29/06 15:00 | Dados completos exibidos |
| CT009 | Alterar Nome | ✅ | ✅ Passou | 29/06 15:15 | Nome alterado com sucesso |
| CT010 | Alterar Email | ✅ | ✅ Passou | 29/06 15:30 | Email atualizado |
| CT011 | Alterar Endereço | ✅ | ✅ Passou | 29/06 15:45 | Endereço completo atualizado |
| CT012 | Excluir | ✅ | ✅ Passou | 29/06 16:00 | Exclusão lógica funcional |

## 📈 Métricas da Sprint
### Vendedores (Daniel)
- **Total de Casos**: 12
- **Executados**: 12
- **Sucesso**: 100%

### Compradores (Guilherme)
- **Total de Casos**: 12
- **Executados**: 12
- **Sucesso**: 100%

### Integração
- **Total de Casos**: 2
- **Executados**: 2
- **Sucesso**: 100%

## ✅ Definition of Done
- ✅ Módulo vendedores implementado (Daniel)
- ✅ Módulo compradores implementado (Guilherme)
- ✅ Documentação completa
- ✅ Casos de teste definidos e executados
- ✅ Relatórios individuais gerados
- ✅ Testes de integração realizados
- ✅ Bugs críticos corrigidos

## 🤝 Coordenação Entre Membros
### Daily Standups
- **O que fiz ontem?**
- **O que farei hoje?**
- **Há impedimentos?**

### Pontos de Sincronização
- Padrões de validação
- Formato de mensagens de erro
- Estilo de interface do usuário

## 🐛 Bugs Encontrados
**Nenhum bug crítico encontrado durante os testes.**

### Bugs Menores Corrigidos:
#### Módulo Vendedores (Daniel):
- ✅ **Validação de salário**: Implementado controle para valores negativos
- ✅ **Buffer de entrada**: Limpeza adequada após scanf
- ✅ **Formatação de comissões**: Ajustado para 2 casas decimais

#### Módulo Compradores (Guilherme):
- ✅ **Validação de CPF**: Implementado controle de formato básico
- ✅ **Campos obrigatórios**: Validação de strings vazias
- ✅ **Endereço completo**: Verificação de todos os campos obrigatórios

## 📝 Retrospectiva da Sprint
**Data da Retrospectiva**: 02/07/2025  
**Participantes**: Daniel, Guilherme, Lucas (apoio), Gustavo (coordenação)

### Daniel (Vendedores)
**Pontos Positivos**:
- ✅ **Implementação eficiente**: Módulo concluído dentro do prazo
- ✅ **Coordenação efetiva**: Excelente sincronização com Guilherme
- ✅ **Padrões mantidos**: Consistência com módulo de produtos
- ✅ **Testes abrangentes**: Cobertura completa de funcionalidades

**Desafios Enfrentados**:
- ⚠️ **Sincronização de padrões**: Alinhamento de validações com Guilherme
- ⚠️ **Complexidade de comissões**: Integração futura com vendas

**Lições Aprendidas**:
- 💡 **Comunicação constante**: Fundamental para manter consistência
- 💡 **Documentação detalhada**: Facilita integração posterior

### Guilherme (Compradores)  
**Pontos Positivos**:
- ✅ **Estrutura robusta**: Endereço completo implementado
- ✅ **Validações eficazes**: CPF único e dados obrigatórios
- ✅ **Trabalho em equipe**: Coordenação perfeita com Daniel
- ✅ **Base sólida**: Preparação adequada para vendas

**Desafios Enfrentados**:
- ⚠️ **Complexidade de endereço**: Múltiplos campos obrigatórios
- ⚠️ **Validações avançadas**: CPF e email poderiam ser mais rigorosos

**Lições Aprendidas**:
- 💡 **Estrutura de dados**: Importância de planejamento detalhado
- 💡 **Validações graduais**: Implementar básico primeiro, depois avançado

### Integração
**Sucessos da Sprint**:
- ✅ **Padrões harmonizados**: Interface consistente entre módulos
- ✅ **Preparação para vendas**: Dados estruturados adequadamente
- ✅ **Trabalho coordenado**: Daniel e Guilherme trabalharam sincronizados
- ✅ **Base consolidada**: Fundação sólida para próximas sprints

**Pontos de Melhoria**:
- 📈 **Validações mais rigorosas**: CPF, email, telefone
- 📈 **Testes de integração**: Mais cenários de teste conjunto
- 📈 **Documentação de interface**: Melhor especificação de contratos
