# Casos de Teste - Sistema de Vendas

## 📋 Visão Geral
Documento consolidado com todos os casos de teste do sistema de vendas, organizados por módulo e tipo de teste.

## 🏷️ Convenções
- **ID**: Identificador único do caso de teste
- **Módulo**: Produtos (P), Vendedores (V), Compradores (C), Vendas (VE), Auxiliares (A), Integração (I)
- **Tipo**: Funcional (F), Integração (I), Extremo (E)
- **Prioridade**: Alta, Média, Baixa

---

## 📦 Módulo de Produtos (Lucas)

### P-F-001: Cadastrar Produto com Código Automático
**Prioridade**: Alta  
**Objetivo**: Verificar cadastro com geração automática de código  
**Pré-condições**: Sistema inicializado  
**Dados de Entrada**:
- Nome: "Smartphone Samsung Galaxy"
- Código: Automático (opção 1)
- Estoque: 15
- Preço: 1299.99

**Procedimento**:
1. Acessar menu Produtos → Cadastrar produto
2. Inserir nome do produto
3. Escolher opção 1 (código automático)
4. Inserir quantidade em estoque
5. Inserir preço de venda
6. Confirmar cadastro

**Resultado Esperado**:
- Mensagem "Produto cadastrado com sucesso! Código: X"
- Produto aparece na consulta
- Código gerado sequencialmente

### P-F-002: Cadastrar Produto com Código Manual
**Prioridade**: Alta  
**Objetivo**: Verificar cadastro com código definido manualmente  
**Dados de Entrada**:
- Nome: "Notebook Dell Inspiron"
- Código: 100 (opção 2)
- Estoque: 8
- Preço: 2499.00

**Resultado Esperado**:
- Produto cadastrado com código 100
- proximo_codigo_produto atualizado para 101

### P-F-003: Validar Código Duplicado
**Prioridade**: Alta  
**Objetivo**: Verificar rejeição de código duplicado  
**Pré-condições**: Produto com código 1 já existe  
**Dados de Entrada**: Código: 1  
**Resultado Esperado**: 
- Mensagem "Código já existe! Digite outro código."
- Solicitar novo código

### P-F-004: Buscar Produto Existente
**Prioridade**: Alta  
**Objetivo**: Verificar localização de produto válido  
**Dados de Entrada**: buscar_produto_por_codigo(1)  
**Resultado Esperado**: Retorno >= 0

### P-F-005: Buscar Produto Inexistente
**Prioridade**: Média  
**Objetivo**: Verificar comportamento com código inválido  
**Dados de Entrada**: buscar_produto_por_codigo(999)  
**Resultado Esperado**: Retorno = -1

### P-F-006: Consultar Lista Vazia
**Prioridade**: Média  
**Objetivo**: Verificar comportamento sem produtos  
**Pré-condições**: num_produtos = 0  
**Resultado Esperado**: "Nenhum produto cadastrado."

### P-F-007: Consultar Lista Preenchida
**Prioridade**: Alta  
**Objetivo**: Verificar exibição de produtos  
**Pré-condições**: Pelo menos 1 produto ativo  
**Resultado Esperado**: Tabela formatada com produtos

### P-F-008: Alterar Nome do Produto
**Prioridade**: Média  
**Objetivo**: Verificar alteração de nome  
**Dados de Entrada**: Código: 1, Novo nome: "Produto Alterado"  
**Resultado Esperado**: Nome alterado com sucesso

### P-F-009: Alterar Estoque do Produto
**Prioridade**: Alta  
**Objetivo**: Verificar alteração de estoque  
**Dados de Entrada**: Código: 1, Nova quantidade: 50  
**Resultado Esperado**: Estoque atualizado

### P-F-010: Alterar Preço do Produto
**Prioridade**: Média  
**Objetivo**: Verificar alteração de preço  
**Dados de Entrada**: Código: 1, Novo preço: 199.99  
**Resultado Esperado**: Preço atualizado

### P-F-011: Excluir Produto com Confirmação
**Prioridade**: Alta  
**Objetivo**: Verificar exclusão confirmada  
**Dados de Entrada**: Código: 1, Confirmação: 's'  
**Resultado Esperado**: Produto inativo

### P-E-012: Limite Máximo de Produtos
**Prioridade**: Baixa  
**Objetivo**: Verificar limite do sistema  
**Pré-condições**: num_produtos = MAX_PRODUTOS  
**Resultado Esperado**: Mensagem de limite atingido

---

## 👥 Módulo de Vendedores (Daniel)

### V-F-001: Cadastrar Vendedor Código Automático
**Prioridade**: Alta  
**Dados de Entrada**:
- Nome: "Carlos Vendedor Silva"
- Número: Automático
- Salário: 2500.00

**Resultado Esperado**: Vendedor cadastrado com número gerado

### V-F-002: Cadastrar Vendedor Código Manual
**Prioridade**: Alta  
**Dados de Entrada**:
- Nome: "Ana Vendedora Santos"
- Número: 50
- Salário: 3000.00

**Resultado Esperado**: Vendedor cadastrado com número 50

### V-F-003: Validar Número Duplicado
**Prioridade**: Alta  
**Pré-condições**: Vendedor número 1 existe  
**Dados de Entrada**: Número: 1  
**Resultado Esperado**: Erro de duplicação

### V-F-004: Validar Salário Inválido
**Prioridade**: Média  
**Dados de Entrada**: Salário: 0  
**Resultado Esperado**: Erro de validação

### V-F-005: Buscar Vendedor Existente
**Prioridade**: Alta  
**Dados de Entrada**: buscar_vendedor_por_numero(1)  
**Resultado Esperado**: Índice válido

### V-F-006: Consultar Vendedores
**Prioridade**: Média  
**Resultado Esperado**: Tabela com número, nome, salário, comissões

### V-F-007: Alterar Nome Vendedor
**Prioridade**: Média  
**Dados de Entrada**: Novo nome: "Carlos Silva Junior"  
**Resultado Esperado**: Nome alterado

### V-F-008: Alterar Salário Vendedor
**Prioridade**: Média  
**Dados de Entrada**: Novo salário: 3500.00  
**Resultado Esperado**: Salário alterado

### V-F-009: Excluir Vendedor
**Prioridade**: Alta  
**Dados de Entrada**: Confirmação: 's'  
**Resultado Esperado**: Vendedor inativo

### V-F-010: Inicialização de Comissões
**Prioridade**: Média  
**Objetivo**: Verificar comissões = 0.0 no cadastro  
**Resultado Esperado**: Comissões iniciadas em zero

---

## 🛒 Módulo de Compradores (Guilherme)

### C-F-001: Cadastrar Comprador Completo
**Prioridade**: Alta  
**Dados de Entrada**:
- Nome: "Maria da Silva Santos"
- CPF: "111.222.333-44"
- Email: "maria@email.com"
- Endereço: Todos os campos preenchidos

**Resultado Esperado**: Comprador cadastrado com sucesso

### C-F-002: Validar CPF Duplicado
**Prioridade**: Alta  
**Pré-condições**: CPF já existe  
**Resultado Esperado**: Erro de duplicação

### C-F-003: Validar Dados Obrigatórios
**Prioridade**: Alta  
**Dados de Entrada**: Nome ou email vazio  
**Resultado Esperado**: Erro de validação

### C-F-004: Validar Endereço Completo
**Prioridade**: Média  
**Dados de Entrada**: Campos de endereço vazios  
**Resultado Esperado**: Erro de validação

### C-F-005: Buscar por CPF Existente
**Prioridade**: Alta  
**Dados de Entrada**: buscar_comprador_por_cpf("123.456.789-00")  
**Resultado Esperado**: Índice válido

### C-F-006: Consultar Compradores
**Prioridade**: Média  
**Resultado Esperado**: Dados pessoais + endereço

### C-F-007: Alterar Nome Comprador
**Prioridade**: Média  
**Resultado Esperado**: Nome alterado

### C-F-008: Alterar Email Comprador
**Prioridade**: Média  
**Resultado Esperado**: Email alterado

### C-F-010: Validar Endereço Incompleto
**Prioridade**: Média  
**Dados de Entrada**: Campos de endereço vazios  
**Resultado Esperado**: Erro de validação

### C-F-011: Excluir Comprador
**Prioridade**: Alta  
**Resultado Esperado**: Comprador inativo

---

## 💰 Módulo de Vendas (Gustavo)

### VE-F-001: Cadastrar Venda Simples
**Prioridade**: Alta  
**Pré-condições**: Comprador, vendedor e produto existem  
**Dados de Entrada**:
- CPF: "123.456.789-00"
- Vendedor: 1
- Produto: 1, Quantidade: 2

**Resultado Esperado**: 
- Venda cadastrada
- Estoque atualizado
- Comissão calculada

### VE-F-002: Venda Múltiplos Itens
**Prioridade**: Alta  
**Dados de Entrada**: 2 produtos diferentes  
**Resultado Esperado**: Ambos produtos na venda

### VE-F-003: Comprador Inexistente
**Prioridade**: Alta  
**Dados de Entrada**: CPF inexistente  
**Resultado Esperado**: "Comprador não encontrado!"

### VE-F-004: Vendedor Inexistente
**Prioridade**: Alta  
**Dados de Entrada**: Número vendedor inexistente  
**Resultado Esperado**: "Vendedor não encontrado!"

### VE-F-005: Produto Inexistente
**Prioridade**: Alta  
**Dados de Entrada**: Código produto inexistente  
**Resultado Esperado**: "Produto não encontrado!"

### VE-F-006: Estoque Insuficiente
**Prioridade**: Alta  
**Pré-condições**: Produto com estoque 5  
**Dados de Entrada**: Quantidade 10  
**Resultado Esperado**: "Quantidade insuficiente em estoque!"

### VE-F-007: Consultar Vendas
**Prioridade**: Média  
**Resultado Esperado**: Lista detalhada de vendas

### VE-F-008: Excluir Venda
**Prioridade**: Alta  
**Resultado Esperado**: Venda inativa, reversões aplicadas

---

## 📄 Módulo Auxiliar (Gustavo)

### A-F-001: Calcular Frete Baixo
**Prioridade**: Alta  
**Dados de Entrada**: valor = 50.00  
**Resultado Esperado**: 30.00

### A-F-002: Calcular Frete Médio
**Prioridade**: Alta  
**Dados de Entrada**: valor = 200.00  
**Resultado Esperado**: 20.00

### A-F-003: Calcular Frete Grátis
**Prioridade**: Alta  
**Dados de Entrada**: valor = 400.00  
**Resultado Esperado**: 0.00

### A-F-004: Emitir Nota Fiscal
**Prioridade**: Alta  
**Pré-condições**: Venda registrada  
**Resultado Esperado**: Nota fiscal formatada

---

## 🔗 Testes de Integração

### I-I-001: Fluxo Completo
**Prioridade**: Alta  
**Objetivo**: Testar produto→vendedor→comprador→venda→nota  
**Resultado Esperado**: Fluxo sem erros

### I-I-002: Atualização de Estoque
**Prioridade**: Alta  
**Objetivo**: Verificar controle automático de estoque  
**Resultado Esperado**: Estoque atualizado corretamente

### I-I-003: Cálculo de Comissões
**Prioridade**: Alta  
**Objetivo**: Verificar cálculo automático de comissões  
**Resultado Esperado**: 3% sobre valor da venda

---

---

## 📊 Matriz de Rastreabilidade

| Módulo | Total Casos | Funcionais | Integração | Extremos |
|--------|-------------|------------|------------|----------|
| Produtos | 12 | 11 | 0 | 1 |
| Vendedores | 10 | 10 | 0 | 0 |
| Compradores | 11 | 11 | 0 | 0 |
| Vendas | 8 | 8 | 0 | 0 |
| Auxiliares | 4 | 4 | 0 | 0 |
| Integração | 3 | 0 | 3 | 0 |
| **Total** | **48** | **44** | **3** | **1** |

## 📋 Template de Execução de Teste

```
=== EXECUÇÃO DE TESTE ===
ID: [ID do teste]
Data/Hora: [DD/MM/AAAA HH:MM]
Executado por: [Nome do responsável]
Ambiente: [Ambiente de teste]

DADOS DE ENTRADA:
[Dados utilizados]

PROCEDIMENTO EXECUTADO:
[Passos realizados]

RESULTADO OBTIDO:
[Resultado real]

STATUS: [ ] PASSOU [ ] FALHOU

OBSERVAÇÕES:
[Comentários adicionais]

EVIDÊNCIAS:
[Screenshots, logs, etc.]
```

## 📈 Critérios de Aceitação

### Para Aprovação do Teste
- [x] Resultado obtido = Resultado esperado
- [x] Sem erros inesperados
- [x] Performance adequada
- [x] Interface funcional

### Para Aprovação do Módulo
- [x] 100% dos casos funcionais aprovados
- [x] 90%+ dos casos de integração aprovados
- [x] Bugs críticos corrigidos
- [x] Documentação completa
