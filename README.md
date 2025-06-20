# Sistema de Vendas - Trabalho Prático Final

Este repositório contém o sistema de vendas desenvolvido como trabalho prático final da disciplina.

## 📋 Descrição do Projeto

Sistema de vendas em C que permite gerenciar produtos, vendedores, compradores e vendas.

## 👤 Branch do Lucas - Módulo de Produtos

Você está na branch **`lucas`** responsável pelo desenvolvimento do **Módulo de Produtos**.

### 🎯 Suas responsabilidades:
- Implementar estruturas de dados para produtos
- Funções de cadastro, listagem, busca e edição de produtos
- Validações de dados de produtos
- Integração com sistema de vendas

### 📝 Arquivos principais do seu módulo:
- `codigo/sistema_vendas.c` - Funções relacionadas a produtos
- `membros/lucas/modulo_produtos.md` - Sua documentação específica
- `testes/testes automatizados/test_produtos_exemplo.c` - Testes do módulo

## 👥 Equipe

- **Lucas** - Módulo de Produtos 👈 **VOCÊ ESTÁ AQUI**
- **Daniel** - Módulo de Vendedores  
- **Guilherme** - Módulo de Compradores
- **Gustavo** - Módulo de Vendas e Integração

## 🌿 Estrutura de Branches

- `main` - Branch principal para entrega final
- `lucas` - **SUA BRANCH** - Desenvolvimento do módulo de produtos
- `daniel` - Desenvolvimento do módulo de vendedores
- `guilherme` - Desenvolvimento do módulo de compradores
- `gustavo` - Desenvolvimento do módulo de vendas e integração

## 🚀 Como trabalhar na sua branch

### Comandos básicos para você (Lucas):

```bash
# Já está na sua branch, mas caso precise:
git checkout lucas

# Para sincronizar com as últimas mudanças:
git pull origin lucas

# Para fazer commit das suas alterações:
git add .
git commit -m "Implementa função de cadastro de produtos"
git push origin lucas

# Para integrar suas mudanças na main:
# Crie um Pull Request no GitHub
```

### Para compilar e testar seu módulo:

```bash
# Compilar o sistema principal
gcc -o sistema codigo/sistema_vendas.c

# Executar testes específicos do seu módulo
cd "testes/testes automatizados"
make test_produtos
```

### 📊 Sprint Atual - Produtos

Consulte: [Sprint 1 - Produtos](sprints/sprint_1_produtos.md) para detalhes das suas tarefas.

## 📁 Estrutura do Projeto

```
├── codigo/                    # 👈 SEU FOCO PRINCIPAL
├── dados exemplo/            # Dados de exemplo para testes
├── docs/                     # Documentação do projeto
├── membros/lucas/            # 👈 SUA DOCUMENTAÇÃO
├── sprints/                  # Planejamento das sprints
└── testes/                   # 👈 TESTES DO SEU MÓDULO
```

## 📖 Documentação

- [Funcionalidades](docs/funcionalidades.md) - Descrição das funcionalidades
- [Product Backlog](docs/product_backlog.md) - Backlog do produto
- [Seu Módulo](membros/lucas/modulo_produtos.md) - **SUA DOCUMENTAÇÃO**

## 🏃‍♂️ Sprints

1. [Sprint 1 - Produtos](sprints/sprint_1_produtos.md) - **SUA SPRINT PRINCIPAL**
2. [Sprint 2 - Vendedores e Compradores](sprints/sprint_2_vendedores_compradores.md)
3. [Sprint 3 - Vendas](sprints/sprint_3_vendas.md)
4. [Sprint 4 - Finalização](sprints/sprint_4_finalizacao.md)

---

**🔗 Repositório:** https://github.com/1579483Ls/trabalho-pratico-final-vendas