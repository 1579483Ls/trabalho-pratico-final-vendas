# Product Backlog - Sistema de Vendas

## 📋 Épicos e User Stories

### Épico 1: Gerenciamento de Produtos (Lucas)
**Responsável**: Lucas Siqueira  
**Sprint**: 1

#### User Stories:
1. **Como** administrador, **eu quero** cadastrar produtos **para** manter o catálogo atualizado
   - **Critérios de Aceitação**:
     - Deve permitir entrada manual ou automática de código
     - Nome do produto é obrigatório
     - Quantidade em estoque deve ser >= 0
     - Preço deve ser > 0
     - Sistema deve validar duplicidade de códigos

2. **Como** usuário, **eu quero** consultar produtos **para** visualizar o catálogo disponível
   - **Critérios de Aceitação**:
     - Deve exibir apenas produtos ativos
     - Formato tabular com código, nome, estoque e preço
     - Deve informar se não há produtos cadastrados

3. **Como** administrador, **eu quero** alterar dados de produtos **para** manter informações atualizadas
   - **Critérios de Aceitação**:
     - Deve buscar produto por código
     - Permitir alteração de nome, estoque e preço
     - Não deve permitir alterar código

4. **Como** administrador, **eu quero** excluir produtos **para** remover itens descontinuados
   - **Critérios de Aceitação**:
     - Deve buscar produto por código
     - Solicitar confirmação antes da exclusão
     - Exclusão lógica (ativo = 0)

---

### Épico 2: Gerenciamento de Vendedores (Daniel)
**Responsável**: Daniel  
**Sprint**: 2

#### User Stories:
1. **Como** administrador, **eu quero** cadastrar vendedores **para** gerenciar a equipe de vendas
   - **Critérios de Aceitação**:
     - Deve permitir entrada manual ou automática de número
     - Nome do vendedor é obrigatório
     - Salário fixo deve ser > 0
     - Comissões iniciam em 0
     - Sistema deve validar duplicidade de números

2. **Como** usuário, **eu quero** consultar vendedores **para** visualizar a equipe disponível
   - **Critérios de Aceitação**:
     - Deve exibir apenas vendedores ativos
     - Mostrar número, nome, salário fixo e comissões acumuladas
     - Deve informar se não há vendedores cadastrados

3. **Como** administrador, **eu quero** alterar dados de vendedores **para** manter informações atualizadas
   - **Critérios de Aceitação**:
     - Deve buscar vendedor por número
     - Permitir alteração de nome e salário fixo
     - Não deve permitir alterar número nem comissões manualmente

4. **Como** administrador, **eu quero** excluir vendedores **para** remover funcionários desligados
   - **Critérios de Aceitação**:
     - Deve buscar vendedor por número
     - Solicitar confirmação antes da exclusão
     - Exclusão lógica (ativo = 0)

---

### Épico 3: Gerenciamento de Compradores (Guilherme)
**Responsável**: Guilherme  
**Sprint**: 2

#### User Stories:
1. **Como** administrador, **eu quero** cadastrar compradores **para** manter base de clientes
   - **Critérios de Aceitação**:
     - CPF é obrigatório e único
     - Nome, email e endereço completo são obrigatórios
     - Sistema deve validar duplicidade de CPF
     - Endereço deve ter todos os campos preenchidos

2. **Como** usuário, **eu quero** consultar compradores **para** visualizar a base de clientes
   - **Critérios de Aceitação**:
     - Deve exibir apenas compradores ativos
     - Mostrar dados pessoais e endereço completo
     - Deve informar se não há compradores cadastrados

3. **Como** administrador, **eu quero** alterar dados de compradores **para** manter informações atualizadas
   - **Critérios de Aceitação**:
     - Deve buscar comprador por CPF
     - Permitir alteração de nome, email e endereço
     - Não deve permitir alterar CPF

4. **Como** administrador, **eu quero** excluir compradores **para** remover clientes inativos
   - **Critérios de Aceitação**:
     - Deve buscar comprador por CPF
     - Solicitar confirmação antes da exclusão
     - Exclusão lógica (ativo = 0)

---

### Épico 4: Gerenciamento de Vendas (Gustavo)
**Responsável**: Gustavo  
**Sprint**: 3

#### User Stories:
1. **Como** vendedor, **eu quero** cadastrar vendas **para** registrar transações
   - **Critérios de Aceitação**:
     - Deve validar existência de comprador (CPF) e vendedor (número)
     - Permitir múltiplos itens por venda (máximo 20)
     - Verificar disponibilidade em estoque
     - Atualizar estoque automaticamente
     - Calcular comissão do vendedor (3%)
     - Gerar código de venda automaticamente

2. **Como** usuário, **eu quero** consultar vendas **para** visualizar histórico de transações
   - **Critérios de Aceitação**:
     - Deve exibir apenas vendas ativas
     - Mostrar dados do comprador, vendedor e itens
     - Calcular valor total da venda
     - Deve informar se não há vendas cadastradas

3. **Como** administrador, **eu quero** alterar vendas **para** corrigir informações
   - **Critérios de Aceitação**:
     - Funcionalidade marcada como "não implementada"
     - Deve orientar usuário a excluir e recadastrar

4. **Como** administrador, **eu quero** excluir vendas **para** cancelar transações
   - **Critérios de Aceitação**:
     - Deve buscar venda por código
     - Solicitar confirmação antes da exclusão
     - Reverter estoque dos produtos
     - Reverter comissão do vendedor
     - Exclusão lógica (ativo = 0)

---

### Épico 5: Funcionalidades Auxiliares (Gustavo)
**Responsável**: Gustavo  
**Sprint**: 4

#### User Stories:
1. **Como** usuário, **eu quero** emitir nota fiscal **para** documentar a venda
   - **Critérios de Aceitação**:
     - Deve buscar venda por código
     - Exibir dados completos do comprador
     - Listar todos os produtos vendidos
     - Calcular frete baseado no valor da venda
     - Mostrar subtotal, frete e total geral
     - Formato de apresentação adequado

2. **Como** sistema, **eu quero** calcular frete **para** compor o valor final da venda
   - **Critérios de Aceitação**:
     - Até R$ 100: R$ 30,00
     - R$ 100,01 a R$ 300: R$ 20,00
     - Acima de R$ 300: Grátis

---

## 📊 Distribuição por Sprint

### Sprint 1 (3-4 dias) - Produtos
- **Responsável**: Lucas
- **Entregáveis**:
  - Módulo completo de produtos
  - Documentação das funções
  - Casos de teste para produtos
  - Relatório de execução

### Sprint 2 (3-4 dias) - Vendedores e Compradores  
- **Responsáveis**: Daniel (Vendedores) + Guilherme (Compradores)
- **Entregáveis**:
  - Módulos completos de vendedores e compradores
  - Documentação das funções
  - Casos de teste para ambos módulos
  - Relatórios de execução

### Sprint 3 (3-4 dias) - Vendas
- **Responsável**: Gustavo
- **Entregáveis**:
  - Módulo completo de vendas
  - Integração com módulos anteriores
  - Documentação das funções
  - Casos de teste para vendas
  - Relatório de execução

### Sprint 4 (3-4 dias) - Finalização e Integração
- **Responsável**: Gustavo (com apoio da equipe)
- **Entregáveis**:
  - Nota fiscal e funcionalidades auxiliares
  - Testes de integração completos
  - Documentação final
  - Relatório consolidado
  - Apresentação do projeto

---

## 🎯 Definition of Done
Para uma user story ser considerada "Done", deve:
- ✅ Código implementado e funcionando
- ✅ Documentação da função criada
- ✅ Casos de teste definidos e executados
- ✅ Relatório de testes gerado
- ✅ Código revisado por outro membro
- ✅ Integração testada com outros módulos

---

## ✅ Status Final do Backlog
**Data de Conclusão**: 02/07/2025  
**Status Geral**: 🎉 **100% CONCLUÍDO**

### Épicos Finalizados:
- ✅ **Épico 1 - Produtos (Lucas)**: 4/4 User Stories implementadas
- ✅ **Épico 2 - Vendedores (Daniel)**: 4/4 User Stories implementadas  
- ✅ **Épico 3 - Compradores (Guilherme)**: 4/4 User Stories implementadas
- ✅ **Épico 4 - Vendas (Gustavo)**: 4/4 User Stories implementadas
- ✅ **Épico 5 - Auxiliares (Gustavo)**: 2/2 User Stories implementadas

### Métricas Finais:
- **Total de User Stories**: 18
- **User Stories Concluídas**: 18
- **Taxa de Conclusão**: 100%
- **Sprints Executadas**: 4/4
- **Casos de Teste Totais**: 77
- **Taxa de Sucesso dos Testes**: 100%

### Resultado Final:
🏆 **Sistema de Vendas Completo e Operacional**  
Todas as funcionalidades implementadas, testadas e integradas com sucesso!
