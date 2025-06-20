# Sprint 2 - Módulos de Vendedores e Compradores
**Duração**: 3-4 dias  
**Responsáveis**: Daniel (Vendedores) + Guilherme (Compradores)  
**Data Início**: [A definir]  
**Data Fim**: [A definir]  

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
- [ ] **T001**: Documentar funções do módulo de vendedores
- [ ] **T002**: Implementar casos de sucesso para vendedores
- [ ] **T003**: Definir casos de teste para vendedores
- [ ] **T004**: Executar testes de vendedores
- [ ] **T005**: Implementar tratamento de exceções
- [ ] **T006**: Gerar relatório de testes de vendedores

### Tarefas Técnicas - Guilherme (Compradores)
- [ ] **T007**: Documentar funções do módulo de compradores
- [ ] **T008**: Implementar casos de sucesso para compradores
- [ ] **T009**: Definir casos de teste para compradores
- [ ] **T010**: Executar testes de compradores
- [ ] **T011**: Implementar tratamento de exceções
- [ ] **T012**: Gerar relatório de testes de compradores

### Tarefas de Integração
- [ ] **T013**: Testar integração entre módulos
- [ ] **T014**: Validar dados para futuras vendas
- [ ] **T015**: Documentar pontos de integração

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
<!-- A ser preenchido -->

| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| VT001 | Cadastrar Automático | [ ] | Passou/Falhou | | |
| VT002 | Cadastrar Manual | [ ] | Passou/Falhou | | |
| VT003 | Número Duplicado | [ ] | Passou/Falhou | | |
| VT004 | Salário Inválido | [ ] | Passou/Falhou | | |
| VT005 | Buscar Existente | [ ] | Passou/Falhou | | |
| VT006 | Buscar Inexistente | [ ] | Passou/Falhou | | |
| VT007 | Lista Vazia | [ ] | Passou/Falhou | | |
| VT008 | Lista Preenchida | [ ] | Passou/Falhou | | |
| VT009 | Alterar Nome | [ ] | Passou/Falhou | | |
| VT010 | Alterar Salário | [ ] | Passou/Falhou | | |
| VT011 | Excluir Sim | [ ] | Passou/Falhou | | |
| VT012 | Excluir Não | [ ] | Passou/Falhou | | |

## 📊 Relatório de Execução - Compradores (Guilherme)
<!-- A ser preenchido -->

| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| CT001 | Cadastrar Completo | [ ] | Passou/Falhou | | |
| CT002 | CPF Duplicado | [ ] | Passou/Falhou | | |
| CT003 | Dados Vazios | [ ] | Passou/Falhou | | |
| CT004 | Endereço Incompleto | [ ] | Passou/Falhou | | |
| CT005 | Buscar Existente | [ ] | Passou/Falhou | | |
| CT006 | Buscar Inexistente | [ ] | Passou/Falhou | | |
| CT007 | Lista Vazia | [ ] | Passou/Falhou | | |
| CT008 | Lista Preenchida | [ ] | Passou/Falhou | | |
| CT009 | Alterar Nome | [ ] | Passou/Falhou | | |
| CT010 | Alterar Email | [ ] | Passou/Falhou | | |
| CT011 | Alterar Endereço | [ ] | Passou/Falhou | | |
| CT012 | Excluir | [ ] | Passou/Falhou | | |

## 📈 Métricas da Sprint
### Vendedores (Daniel)
- **Total de Casos**: 12
- **Executados**: [A preencher]
- **Sucesso**: [A preencher]%

### Compradores (Guilherme)
- **Total de Casos**: 12
- **Executados**: [A preencher]
- **Sucesso**: [A preencher]%

### Integração
- **Total de Casos**: 2
- **Executados**: [A preencher]
- **Sucesso**: [A preencher]%

## ✅ Definition of Done
- [ ] Módulo vendedores implementado (Daniel)
- [ ] Módulo compradores implementado (Guilherme)
- [ ] Documentação completa
- [ ] Casos de teste definidos e executados
- [ ] Relatórios individuais gerados
- [ ] Testes de integração realizados
- [ ] Bugs críticos corrigidos

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
<!-- Documentar problemas por módulo -->

## 📝 Retrospectiva da Sprint
### Daniel (Vendedores)
<!-- Feedback específico -->

### Guilherme (Compradores)  
<!-- Feedback específico -->

### Integração
<!-- Pontos de integração que funcionaram/falharam -->
