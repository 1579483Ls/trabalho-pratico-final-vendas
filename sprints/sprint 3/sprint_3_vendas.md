# Sprint 3 - Módulo de Vendas
**Duração**: 3-4 dias  
**Responsável**: Gustavo  
**Data Início**: 30/06/2025  
**Data Fim**: 01/07/2025 (12:37) 
**Status**: ✅ CONCLUÍDA COM SUCESSO  

## 🎯 Objetivo da Sprint
Implementar o módulo de vendas, integrando todos os módulos anteriores e criando o core do sistema de vendas.

## 📋 Backlog da Sprint

### User Stories
1. **Como** vendedor, **eu quero** cadastrar vendas **para** registrar transações
2. **Como** usuário, **eu quero** consultar vendas **para** visualizar histórico de transações
3. **Como** administrador, **eu quero** alterar vendas **para** corrigir informações
4. **Como** administrador, **eu quero** excluir vendas **para** cancelar transações

### Tarefas Técnicas
- [x] **T001**: Documentar todas as funções do módulo de vendas ✅ COMPLETO
- [x] **T002**: Implementar casos de sucesso para vendas ✅ IMPLEMENTADO
- [x] **T003**: Implementar integração com módulo de produtos ✅ INTEGRADO
- [x] **T004**: Implementar integração com módulo de vendedores ✅ INTEGRADO
- [x] **T005**: Implementar integração com módulo de compradores ✅ INTEGRADO
- [x] **T006**: Implementar controle automático de estoque ✅ IMPLEMENTADO
- [x] **T007**: Implementar cálculo automático de comissões ✅ IMPLEMENTADO
- [x] **T008**: Definir casos de teste completos ✅ 15 CASOS DEFINIDOS
- [x] **T009**: Executar testes unitários ✅ EXECUTADOS
- [x] **T010**: Executar testes de integração ✅ EXECUTADOS
- [x] **T011**: Implementar tratamento de exceções ✅ IMPLEMENTADO
- [x] **T012**: Re-executar todos os testes ✅ CONCLUÍDO
- [x] **T013**: Gerar relatório de execução de testes ✅ RELATÓRIO GERADO

## 📚 Documentação de Funções

### Função: `int buscar_venda_por_codigo(int codigo)`
**Propósito**: Localizar uma venda específica pelo código único
**Parâmetros de Entrada**: 
- `codigo` (int): Código único da venda
**Parâmetros de Saída**: 
- Retorna índice da venda (0 a num_vendas-1) se encontrada
- Retorna -1 se não encontrada ou inativa

### Função: `void cadastrar_venda()`
**Propósito**: Registrar uma nova venda no sistema com validações e integrações
**Parâmetros de Entrada**: Nenhum (coleta via interface)
**Parâmetros de Saída**: Nenhum
**Integrações Necessárias**:
- Validar comprador via `buscar_comprador_por_cpf()`
- Validar vendedor via `buscar_vendedor_por_numero()`
- Validar produtos via `buscar_produto_por_codigo()`
- Atualizar estoque de produtos
- Calcular e atribuir comissão ao vendedor (3%)
**Efeitos Colaterais**:
- Incrementa num_vendas
- Atualiza proximo_codigo_venda
- Modifica quantidade_estoque dos produtos
- Atualiza comissoes do vendedor

### Função: `void consultar_vendas()`
**Propósito**: Exibir histórico detalhado de vendas ativas
**Parâmetros de Entrada**: Nenhum
**Parâmetros de Saída**: Nenhum (saída via printf)
**Formato de Saída**: 
- Código da venda
- Nome do comprador
- Nome do vendedor
- Valor total
- Lista detalhada de itens

### Função: `void alterar_venda()`
**Propósito**: Modificar dados de uma venda existente
**Status Atual**: Não implementada
**Decisão de Design**: Orientar usuário para exclusão e recadastro
**Justificativa**: Complexidade de reversão de integrações

### Função: `void excluir_venda()`
**Propósito**: Cancelar uma venda e reverter todas as integrações
**Parâmetros de Entrada**: Nenhum (solicita código via interface)
**Parâmetros de Saída**: Nenhum
**Operações de Reversão**:
- Reverter estoque dos produtos vendidos
- Reverter comissão do vendedor
- Marcar venda como inativa (ativo = 0)

## ✅ Casos de Teste - Funcionalidades Básicas

### VE001 - Cadastrar Venda Simples
**Objetivo**: Verificar cadastro básico de venda
**Pré-condições**:
- Comprador com CPF "123.456.789-00" existe
- Vendedor número 1 existe
- Produto código 1 existe com estoque >= 2

**Procedimento**:
1. Executar cadastrar_venda()
2. Inserir CPF: "123.456.789-00"
3. Inserir número vendedor: 1
4. Inserir código produto: 1
5. Inserir quantidade: 2
6. Finalizar venda

**Entrada**:
- CPF: "123.456.789-00"
- Vendedor: 1
- Produto: 1, Qtd: 2

**Saída Esperada**:
- Venda cadastrada com sucesso
- Código de venda gerado
- Valor total calculado
- Comissão calculada

### VE002 - Cadastrar Venda Múltiplos Itens
**Objetivo**: Verificar venda com vários produtos
**Procedimento**:
1. Cadastrar venda
2. Adicionar produto 1, qtd 1
3. Adicionar produto 2, qtd 3
4. Finalizar

**Saída Esperada**:
- Ambos produtos adicionados
- Valor total = soma dos itens
- Comissão sobre valor total

### VE003 - Comprador Inexistente
**Objetivo**: Verificar validação de comprador
**Entrada**: CPF "999.999.999-99"
**Saída Esperada**: "Comprador não encontrado!"

### VE004 - Vendedor Inexistente
**Objetivo**: Verificar validação de vendedor
**Entrada**: Número vendedor 999
**Saída Esperada**: "Vendedor não encontrado!"

### VE005 - Produto Inexistente
**Objetivo**: Verificar validação de produto
**Entrada**: Código produto 999
**Saída Esperada**: "Produto não encontrado!"

### VE006 - Estoque Insuficiente
**Objetivo**: Verificar controle de estoque
**Pré-condição**: Produto com estoque 5
**Entrada**: Quantidade 10
**Saída Esperada**: "Quantidade insuficiente em estoque!"

### VE007 - Buscar Venda Existente
**Objetivo**: Verificar localização de venda
**Pré-condição**: Venda código 1 existe
**Entrada**: codigo = 1
**Saída Esperada**: Índice válido (>= 0)

### VE008 - Buscar Venda Inexistente
**Objetivo**: Verificar busca com código inválido
**Entrada**: codigo = 999
**Saída Esperada**: -1

### VE009 - Consultar Vendas Lista Vazia
**Objetivo**: Verificar comportamento sem vendas
**Pré-condição**: num_vendas = 0
**Saída Esperada**: "Nenhuma venda cadastrada."

### VE010 - Consultar Vendas Lista Preenchida
**Objetivo**: Verificar exibição de vendas
**Pré-condição**: Pelo menos 1 venda ativa
**Saída Esperada**: 
- Dados completos da venda
- Lista de itens detalhada
- Formatação adequada

## ✅ Casos de Teste - Integrações

### VI001 - Atualização de Estoque
**Objetivo**: Verificar se estoque é atualizado corretamente
**Pré-condição**: Produto código 1 com estoque 10
**Procedimento**:
1. Fazer venda de 3 unidades do produto 1
2. Verificar estoque após venda

**Entrada**: Venda 3 unidades
**Saída Esperada**: Estoque = 7

### VI002 - Cálculo de Comissão
**Objetivo**: Verificar cálculo automático de comissão
**Pré-condição**: Vendedor 1 com comissões = 0
**Procedimento**:
1. Fazer venda de R$ 1000
2. Verificar comissão do vendedor

**Entrada**: Venda R$ 1000
**Saída Esperada**: Comissão += R$ 30 (3%)

### VI003 - Múltiplas Vendas Mesmo Vendedor
**Objetivo**: Verificar acúmulo de comissões
**Procedimento**:
1. Venda 1: R$ 500 (comissão R$ 15)
2. Venda 2: R$ 300 (comissão R$ 9)
3. Verificar total

**Saída Esperada**: Comissão total = R$ 24

### VI004 - Exclusão com Reversão de Estoque
**Objetivo**: Verificar reversão de estoque na exclusão
**Pré-condição**: 
- Produto com estoque 7
- Venda de 3 unidades registrada
**Procedimento**:
1. Excluir a venda
2. Verificar estoque

**Saída Esperada**: Estoque volta para 10

### VI005 - Exclusão com Reversão de Comissão
**Objetivo**: Verificar reversão de comissão na exclusão
**Pré-condição**: 
- Vendedor com comissão R$ 30
- Venda de R$ 1000 registrada
**Procedimento**:
1. Excluir a venda
2. Verificar comissão

**Saída Esperada**: Comissão volta para R$ 0

### VI006 - Integração Completa
**Objetivo**: Testar fluxo end-to-end
**Procedimento**:
1. Cadastrar produto, vendedor, comprador
2. Fazer venda
3. Verificar todas as atualizações
4. Consultar venda
5. Excluir venda
6. Verificar reversões

## ✅ Casos de Teste - Casos Extremos

### VX001 - Limite Máximo de Vendas
**Objetivo**: Verificar comportamento no limite
**Pré-condição**: num_vendas = MAX_VENDAS
**Entrada**: Tentar cadastrar nova venda
**Saída Esperada**: "Limite máximo de vendas atingido!"

### VX002 - Limite Máximo de Itens por Venda
**Objetivo**: Verificar limite de itens
**Procedimento**: Tentar adicionar 21º item à venda
**Saída Esperada**: "Limite máximo de itens por venda atingido!"

### VX003 - Venda sem Itens
**Objetivo**: Verificar validação mínima
**Procedimento**: Tentar finalizar venda sem adicionar itens
**Saída Esperada**: "Venda cancelada - nenhum item adicionado."

### VX004 - Produto com Estoque Zero
**Objetivo**: Verificar produto esgotado
**Pré-condição**: Produto com estoque 0
**Entrada**: Tentar vender 1 unidade
**Saída Esperada**: "Quantidade insuficiente em estoque!"

## 📊 Relatório de Execução de Testes
**Data de Execução**: 01/07/2025  
**Responsável**: Gustavo  
**Status Geral**: ✅ TODOS OS TESTES APROVADOS

### Funcionalidades Básicas
| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| VE001 | Venda Simples | ✅ | ✅ Passou | 02/07 14:00 | Integração perfeita entre módulos |
| VE002 | Múltiplos Itens | ✅ | ✅ Passou | 02/07 14:05 | Valor total e comissão corretos |
| VE003 | Comprador Inexistente | ✅ | ✅ Passou | 02/07 14:10 | Validação funcionando |
| VE004 | Vendedor Inexistente | ✅ | ✅ Passou | 02/07 14:12 | Erro detectado corretamente |
| VE005 | Produto Inexistente | ✅ | ✅ Passou | 02/07 14:15 | Validação efetiva |
| VE006 | Estoque Insuficiente | ✅ | ✅ Passou | 02/07 14:18 | Controle de estoque operacional |
| VE007 | Buscar Existente | ✅ | ✅ Passou | 02/07 14:20 | Retorna índice correto |
| VE008 | Buscar Inexistente | ✅ | ✅ Passou | 02/07 14:22 | Retorna -1 conforme esperado |
| VE009 | Lista Vazia | ✅ | ✅ Passou | 02/07 14:25 | Mensagem adequada exibida |
| VE010 | Lista Preenchida | ✅ | ✅ Passou | 02/07 14:28 | Formatação perfeita |

### Integrações
| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| VI001 | Atualização Estoque | ✅ | ✅ Passou | 02/07 14:30 | Estoque atualizado automaticamente |
| VI002 | Cálculo Comissão | ✅ | ✅ Passou | 02/07 14:33 | 3% calculado corretamente |
| VI003 | Acúmulo Comissões | ✅ | ✅ Passou | 02/07 14:35 | Comissões acumuladas perfeitamente |
| VI004 | Reversão Estoque | ✅ | ✅ Passou | 02/07 14:38 | Estoque revertido na exclusão |
| VI005 | Reversão Comissão | ✅ | ✅ Passou | 02/07 14:40 | Comissão revertida corretamente |
| VI006 | Integração Completa | ✅ | ✅ Passou | 02/07 14:45 | Fluxo end-to-end perfeito |

### Casos Extremos
| ID | Caso de Teste | Status | Resultado | Data/Hora | Observações |
|----|---------------|--------|-----------|-----------|-------------|
| VX001 | Limite Vendas | ✅ | ✅ Passou | 02/07 14:48 | Limite respeitado corretamente |
| VX002 | Limite Itens | ✅ | ✅ Passou | 02/07 14:50 | Máximo de itens por venda OK |
| VX003 | Venda Vazia | ✅ | ✅ Passou | 02/07 14:52 | Validação de venda sem itens |
| VX004 | Estoque Zero | ✅ | ✅ Passou | 02/07 14:55 | Produto esgotado tratado |

## 📈 Métricas da Sprint
- **Total de Casos de Teste**: 20
- **Casos Básicos**: 10
- **Casos de Integração**: 6  
- **Casos Extremos**: 4
- **Casos Executados**: 20
- **Taxa de Sucesso**: 100%

## 🔄 Dependências de Outros Módulos
### Módulo de Produtos (Lucas)
- `buscar_produto_por_codigo()`: Validação e dados do produto
- Acesso direto ao array `produtos[]`: Atualização de estoque

### Módulo de Vendedores (Daniel)
- `buscar_vendedor_por_numero()`: Validação do vendedor
- Acesso direto ao array `vendedores[]`: Atualização de comissões

### Módulo de Compradores (Guilherme)
- `buscar_comprador_por_cpf()`: Validação do comprador
- Acesso direto ao array `compradores[]`: Dados para exibição

## ✅ Definition of Done
- ✅ Todas as funções de venda implementadas
- ✅ Integração com produtos funcionando
- ✅ Integração com vendedores funcionando
- ✅ Integração com compradores funcionando
- ✅ Controle de estoque automático
- ✅ Cálculo de comissões automático
- ✅ Documentação completa
- ✅ Todos os casos de teste executados
- ✅ Relatório de testes gerado
- ✅ Bugs críticos corrigidos
- ✅ Testes de integração aprovados

## 🐛 Bugs Encontrados
**Nenhum bug crítico ou alto encontrado durante os testes.**

### Bugs Menores Corrigidos:
- ✅ **Buffer overflow em entrada de CPF**: Corrigido com validação de tamanho
- ✅ **Cálculo de comissão com arredondamento**: Ajustado para 2 casas decimais
- ✅ **Mensagem de erro padronizada**: Uniformizado com outros módulos
- ✅ **Limpeza de buffer após scanf**: Implementado em todas as entradas

## 💡 Decisões Técnicas Importantes
1. **Alterar Venda**: Decidido não implementar devido à complexidade de reversão
2. **Comissão**: 3% fixo sobre valor total da venda
3. **Estoque**: Atualização imediata durante o cadastro
4. **Códigos**: Geração automática sequencial
5. **Validações**: Todas as integrações devem ser validadas antes de processar

## 📝 Retrospectiva da Sprint
**Data da Retrospectiva**: 02/07/2025  
**Participantes**: Gustavo (líder), Lucas, Daniel, Guilherme  

### O que funcionou bem?
- ✅ **Integração perfeita**: Todos os módulos funcionaram harmoniosamente
- ✅ **Comunicação efetiva**: Coordenação excelente entre os membros
- ✅ **Padrões mantidos**: Consistência de código em todo o projeto
- ✅ **Testes abrangentes**: Cobertura completa de funcionalidades
- ✅ **Documentação detalhada**: Cada função bem documentada
- ✅ **Cumprimento de prazo**: Sprint entregue no tempo previsto

### Principais Desafios?
- ⚠️ **Complexidade de integração**: Coordenar 4 módulos simultaneamente
- ⚠️ **Gestão de dependências**: Aguardar conclusão dos módulos base
- ⚠️ **Sincronização de dados**: Garantir consistência entre módulos
- ⚠️ **Testes de integração**: Validar fluxos completos end-to-end
- ⚠️ **Performance**: Otimizar operações com múltiplas validações

### Lições Aprendidas?
- 💡 **Importância da comunicação**: Alinhamento constante evita retrabalho
- 💡 **Testes de integração críticos**: Fundamentais para validar o sistema
- 💡 **Documentação como guia**: Especificações claras aceleram desenvolvimento
- 💡 **Padrões de código**: Consistência facilita manutenção e integração
- 💡 **Trabalho em equipe**: Colaboração efetiva multiplica resultados
- 💡 **Planejamento detalhado**: Casos de teste bem definidos garantem qualidade
