# Sistema de Vendas - Trabalho Prático Final

Este repositório contém o sistema de vendas desenvolvido como trabalho prático final da disciplina.

## 📋 Descrição do Projeto

Sistema de vendas em C que permite gerenciar produtos, vendedores, compradores e vendas.

## 👤 Branch do Gustavo - Módulo de Vendas e Integração

Você está na branch **`gustavo`** responsável pelo desenvolvimento do **Módulo de Vendas e Integração**.

### 🎯 Suas responsabilidades:
- Implementar estruturas de dados para vendas
- Funções de registro, listagem e busca de vendas
- Integração entre produtos, vendedores e compradores
- Relatórios de vendas
- Validações de regras de negócio
- Menu principal do sistema
- Coordenação entre todos os módulos

### 📝 Arquivos principais do seu módulo:
- `codigo/sistema_vendas.c` - Funções principais e integração
- `membros/gustavo/modulo_vendas_integracao.md` - Sua documentação específica
- `testes/testes automatizados/test_vendas.c` - Testes do módulo

## 👥 Equipe

- **Lucas** - Módulo de Produtos
- **Daniel** - Módulo de Vendedores
- **Guilherme** - Módulo de Compradores
- **Gustavo** - Módulo de Vendas e Integração 👈 **VOCÊ ESTÁ AQUI**

## 🌿 Estrutura de Branches

- `main` - Branch principal para entrega final
- `lucas` - Desenvolvimento do módulo de produtos
- `daniel` - Desenvolvimento do módulo de vendedores
- `guilherme` - Desenvolvimento do módulo de compradores
- `gustavo` - **SUA BRANCH** - Desenvolvimento do módulo de vendas e integração

## 🚀 Como trabalhar na sua branch

### Comandos básicos para você (Gustavo):

```bash
# Já está na sua branch, mas caso precise:
git checkout gustavo

# Para sincronizar com as últimas mudanças:
git pull origin gustavo

# Para fazer commit das suas alterações:
git add .
git commit -m "Implementa sistema de vendas e integração"
git push origin gustavo

# Para integrar suas mudanças na main:
# Crie um Pull Request no GitHub

# Para integrar trabalho dos outros membros:
git merge origin/lucas    # Quando precisar do módulo de produtos
git merge origin/daniel   # Quando precisar do módulo de vendedores
git merge origin/guilherme # Quando precisar do módulo de compradores
```

### Para compilar e testar seu módulo:

```bash
# Compilar o sistema principal
gcc -o sistema codigo/sistema_vendas.c

# Executar testes específicos do seu módulo
cd "testes/testes automatizados"
make test_vendas

# Executar todos os testes (integração)
make test
```

### 📊 Sprint Atual - Vendas e Integração

Consulte: [Sprint 3 - Vendas](sprints/sprint_3_vendas.md) para detalhes das suas tarefas.

## 📁 Estrutura do Projeto

```
├── codigo/                    # 👈 SEU FOCO PRINCIPAL - INTEGRAÇÃO
├── dados exemplo/            # Dados de exemplo para testes
├── docs/                     # Documentação do projeto
├── membros/gustavo/          # 👈 SUA DOCUMENTAÇÃO
├── sprints/                  # Planejamento das sprints
└── testes/                   # 👈 TESTES DE INTEGRAÇÃO
```

## 📖 Documentação

- [Funcionalidades](docs/funcionalidades.md) - Descrição das funcionalidades
- [Product Backlog](docs/product_backlog.md) - Backlog do produto
- [Seu Módulo](membros/gustavo/modulo_vendas_integracao.md) - **SUA DOCUMENTAÇÃO**

## 🏃‍♂️ Sprints

1. [Sprint 1 - Produtos](sprints/sprint_1_produtos.md)
2. [Sprint 2 - Vendedores e Compradores](sprints/sprint_2_vendedores_compradores.md)
3. [Sprint 3 - Vendas](sprints/sprint_3_vendas.md) - **SUA SPRINT PRINCIPAL**
4. [Sprint 4 - Finalização](sprints/sprint_4_finalizacao.md) - **SUA RESPONSABILIDADE FINAL**

---

**🔗 Repositório:** https://github.com/1579483Ls/trabalho-pratico-final-vendas
