# Sprint 4 - Finalização e Integração
**Duração**: 3-4 dias  
**Responsável**: Gustavo (com apoio da equipe)  
**Data Início**: [A definir]  
**Data Fim**: [A definir]  

## 🎯 Objetivo da Sprint
Finalizar o sistema com funcionalidades auxiliares, realizar testes de integração completos e preparar a entrega final do projeto.

## 📋 Backlog da Sprint

### User Stories
1. **Como** usuário, **eu quero** emitir nota fiscal **para** documentar a venda
2. **Como** sistema, **eu quero** calcular frete automaticamente **para** compor o valor final
3. **Como** equipe, **queremos** ter um sistema totalmente integrado e testado

### Tarefas Técnicas - Funcionalidades Auxiliares
- [ ] **T001**: Documentar função `calcular_frete()`
- [ ] **T002**: Documentar função `emitir_nota_fiscal()`
- [ ] **T003**: Implementar casos de sucesso para nota fiscal
- [ ] **T004**: Implementar integração nota fiscal com vendas
- [ ] **T005**: Implementar integração nota fiscal com compradores
- [ ] **T006**: Definir casos de teste para funcionalidades auxiliares
- [ ] **T007**: Executar testes de funcionalidades auxiliares

### Tarefas de Integração Final
- [ ] **T008**: Executar testes de integração end-to-end
- [ ] **T009**: Validar fluxos completos do sistema
- [ ] **T010**: Testar todos os cenários de uso
- [ ] **T011**: Verificar consistência de dados
- [ ] **T012**: Testar casos de recuperação de erro

### Tarefas de Finalização
- [ ] **T013**: Revisar toda a documentação
- [ ] **T014**: Consolidar relatórios de todas as sprints
- [ ] **T015**: Preparar apresentação do projeto
- [ ] **T016**: Criar manual do usuário
- [ ] **T017**: Gerar relatório final de testes

## 📚 Documentação de Funcionalidades Auxiliares

### Função: `float calcular_frete(float valor_venda)`
**Propósito**: Calcular o valor do frete baseado no valor total da venda
**Parâmetros de Entrada**: 
- `valor_venda` (float): Valor total da venda sem frete
**Parâmetros de Saída**: 
- Retorna valor do frete calculado (float)
**Regras de Negócio**:
- Valor até R$ 100,00: Frete R$ 30,00
- Valor de R$ 100,01 a R$ 300,00: Frete R$ 20,00
- Valor acima de R$ 300,00: Frete grátis (R$ 0,00)

### Função: `void emitir_nota_fiscal()`
**Propósito**: Gerar e exibir nota fiscal formatada de uma venda
**Parâmetros de Entrada**: Nenhum (solicita código da venda)
**Parâmetros de Saída**: Nenhum (saída via printf)
**Integrações Necessárias**:
- `buscar_venda_por_codigo()`: Localizar venda
- Acesso aos dados do comprador
- `calcular_frete()`: Valor do frete
**Formato de Saída**:
- Cabeçalho da nota fiscal
- Dados completos do comprador
- Lista detalhada de produtos vendidos
- Subtotal, frete e total geral
- Formatação profissional

## ✅ Casos de Teste - Funcionalidades Auxiliares

### FA001 - Calcular Frete Valor Baixo
**Objetivo**: Verificar cálculo para compras até R$ 100
**Entrada**: valor_venda = 50.00
**Saída Esperada**: 30.00

### FA002 - Calcular Frete Valor Limite Inferior
**Objetivo**: Verificar limite exato de R$ 100
**Entrada**: valor_venda = 100.00
**Saída Esperada**: 30.00

### FA003 - Calcular Frete Valor Médio
**Objetivo**: Verificar faixa intermediária
**Entrada**: valor_venda = 200.00
**Saída Esperada**: 20.00

### FA004 - Calcular Frete Valor Limite Superior
**Objetivo**: Verificar limite exato de R$ 300
**Entrada**: valor_venda = 300.00
**Saída Esperada**: 20.00

### FA005 - Calcular Frete Valor Alto (Grátis)
**Objetivo**: Verificar frete grátis
**Entrada**: valor_venda = 500.00
**Saída Esperada**: 0.00

### FA006 - Calcular Frete Valor Zero
**Objetivo**: Testar caso extremo
**Entrada**: valor_venda = 0.00
**Saída Esperada**: 30.00

### FA007 - Emitir Nota Fiscal Completa
**Objetivo**: Verificar nota fiscal com todos os dados
**Pré-condição**: 
- Venda registrada com múltiplos itens
- Comprador com endereço completo
**Procedimento**:
1. Executar emitir_nota_fiscal()
2. Inserir código de venda válido
3. Verificar formatação

**Saída Esperada**:
- Cabeçalho "NOTA FISCAL"
- Dados do comprador completos
- Lista de produtos com quantidades e valores
- Subtotal calculado corretamente
- Frete calculado conforme regras
- Total geral = subtotal + frete

### FA008 - Emitir Nota Venda Inexistente
**Objetivo**: Verificar tratamento de erro
**Entrada**: Código de venda 999 (inexistente)
**Saída Esperada**: "Venda não encontrada!"

### FA009 - Nota Fiscal com Frete Grátis
**Objetivo**: Verificar exibição de frete grátis
**Pré-condição**: Venda acima de R$ 300
**Saída Esperada**: 
- Linha "Frete: GRÁTIS"
- Total geral = subtotal

### FA010 - Nota Fiscal Formatação
**Objetivo**: Verificar alinhamento e apresentação
**Saída Esperada**: 
- Alinhamento correto das colunas
- Separadores visuais adequados
- Valores monetários com 2 decimais

## ✅ Casos de Teste - Integração Final

### IF001 - Fluxo Completo: Produto → Venda → Nota Fiscal
**Objetivo**: Testar integração completa
**Procedimento**:
1. Cadastrar produto
2. Cadastrar vendedor  
3. Cadastrar comprador
4. Realizar venda
5. Emitir nota fiscal
6. Verificar todos os dados

**Saída Esperada**: Fluxo sem erros, dados consistentes

### IF002 - Múltiplas Vendas e Comissões
**Objetivo**: Verificar acúmulo correto de comissões
**Procedimento**:
1. Realizar 3 vendas com mesmo vendedor
2. Verificar comissão acumulada
3. Emitir notas fiscais de todas

**Saída Esperada**: 
- Comissões somadas corretamente
- Notas fiscais individuais corretas

### IF003 - Controle de Estoque Múltiplas Vendas
**Objetivo**: Verificar controle de estoque
**Procedimento**:
1. Produto com estoque 10
2. Venda 1: 3 unidades
3. Venda 2: 4 unidades  
4. Tentar venda 3: 5 unidades

**Saída Esperada**: 
- Vendas 1 e 2 aceitas
- Venda 3 rejeitada (estoque insuficiente)
- Estoque final = 3

### IF004 - Exclusão e Reversões
**Objetivo**: Testar reversões completas
**Procedimento**:
1. Realizar venda
2. Verificar estoque e comissão
3. Excluir venda
4. Verificar reversões

**Saída Esperada**: 
- Estoque revertido
- Comissão revertida
- Venda inativa

### IF005 - Cenário Complexo de Negócio
**Objetivo**: Simular uso real do sistema
**Procedimento**:
1. Cadastrar 3 produtos
2. Cadastrar 2 vendedores
3. Cadastrar 2 compradores
4. Realizar 5 vendas diversificadas
5. Emitir todas as notas
6. Excluir 1 venda
7. Verificar consistência

### IF006 - Limites do Sistema
**Objetivo**: Testar comportamento nos limites
**Procedimento**:
1. Cadastrar produtos até o limite
2. Cadastrar vendedores até o limite
3. Realizar vendas até o limite
4. Verificar mensagens de limite

### IF007 - Recuperação de Erros
**Objetivo**: Testar robustez do sistema
**Procedimento**:
1. Tentar operações com dados inválidos
2. Verificar mensagens de erro
3. Verificar se sistema continua funcionando

## 📊 Relatório de Execução - Funcionalidades Auxiliares
<!-- A ser preenchido -->

| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| FA001 | Frete Baixo | [ ] | Passou/Falhou | | |
| FA002 | Frete Limite Inf | [ ] | Passou/Falhou | | |
| FA003 | Frete Médio | [ ] | Passou/Falhou | | |
| FA004 | Frete Limite Sup | [ ] | Passou/Falhou | | |
| FA005 | Frete Grátis | [ ] | Passou/Falhou | | |
| FA006 | Frete Zero | [ ] | Passou/Falhou | | |
| FA007 | Nota Completa | [ ] | Passou/Falhou | | |
| FA008 | Nota Inexistente | [ ] | Passou/Falhou | | |
| FA009 | Nota Frete Grátis | [ ] | Passou/Falhou | | |
| FA010 | Formatação | [ ] | Passou/Falhou | | |

## 📊 Relatório de Execução - Integração Final
<!-- A ser preenchido -->

| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| IF001 | Fluxo Completo | [ ] | Passou/Falhou | | |
| IF002 | Múltiplas Vendas | [ ] | Passou/Falhou | | |
| IF003 | Controle Estoque | [ ] | Passou/Falhou | | |
| IF004 | Exclusão Reversões | [ ] | Passou/Falhou | | |
| IF005 | Cenário Complexo | [ ] | Passou/Falhou | | |
| IF006 | Limites Sistema | [ ] | Passou/Falhou | | |
| IF007 | Recuperação Erros | [ ] | Passou/Falhou | | |

## 📈 Métricas Consolidadas do Projeto

### Resumo por Sprint
- **Sprint 1 (Produtos)**: [X] casos de teste, [Y]% sucesso
- **Sprint 2 (Vendedores/Compradores)**: [X] casos de teste, [Y]% sucesso  
- **Sprint 3 (Vendas)**: [X] casos de teste, [Y]% sucesso
- **Sprint 4 (Final)**: 17 casos de teste, [Y]% sucesso

### Totais do Projeto
- **Total de Casos de Teste**: [A calcular]
- **Total Executados**: [A preencher]
- **Total Aprovados**: [A preencher]
- **Taxa de Sucesso Geral**: [A calcular]%

### Métricas de Código
- **Linhas de Código**: ~1000+ linhas
- **Funções Implementadas**: 20+ funções
- **Módulos**: 4 módulos principais
- **Integrações**: 6 pontos de integração

## 📚 Entregáveis Finais

### Documentação
- [ ] README.md atualizado
- [ ] Product Backlog consolidado
- [ ] Documentação de funcionalidades completa
- [ ] Relatórios de todas as sprints
- [ ] Manual do usuário

### Código
- [ ] Código fonte completo e comentado
- [ ] Sistema compilado e executável
- [ ] Dados de exemplo para demonstração

### Testes
- [ ] Casos de teste consolidados
- [ ] Relatórios de execução de todas as sprints
- [ ] Relatório final de testes de integração
- [ ] Evidências de teste (screenshots opcionais)

### Apresentação
- [ ] Slides da apresentação
- [ ] Demonstração ao vivo preparada
- [ ] Roteiro de apresentação

## ✅ Definition of Done - Projeto Completo
- [ ] Todas as funcionalidades implementadas
- [ ] Todos os módulos integrados
- [ ] Nota fiscal funcionando perfeitamente
- [ ] Cálculo de frete implementado
- [ ] Todos os testes executados
- [ ] Documentação completa
- [ ] Relatórios consolidados
- [ ] Sistema pronto para demonstração
- [ ] Equipe preparada para apresentação

## 🤝 Atividades da Equipe

### Revisão Final (Todos)
- [ ] **Lucas**: Revisar módulo de produtos e documentação
- [ ] **Daniel**: Revisar módulo de vendedores e testes
- [ ] **Guilherme**: Revisar módulo de compradores e integração
- [ ] **Gustavo**: Consolidar vendas, nota fiscal e relatórios

### Preparação da Apresentação (Todos)
- [ ] Definir roteiro da apresentação
- [ ] Preparar demonstração ao vivo
- [ ] Treinar apresentação
- [ ] Preparar para perguntas

## 🐛 Bugs Críticos a Resolver
<!-- Lista de bugs que devem ser corrigidos antes da entrega -->

## 📝 Retrospectiva Final do Projeto
<!-- A ser preenchido pela equipe -->

### Sucessos do Projeto
<!-- O que funcionou bem durante todo o projeto -->

### Principais Desafios
<!-- Maiores dificuldades enfrentadas -->

### Lições Aprendidas
<!-- Conhecimentos adquiridos -->

### Melhorias para Projetos Futuros
<!-- Sugestões para próximos projetos -->
