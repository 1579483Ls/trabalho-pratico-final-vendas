# Makefile para Testes Automatizados do Sistema de Vendas
# Utiliza a biblioteca munit para testes unitários

# Configurações do compilador
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = 

# Arquivos necessários
MUNIT_FILES = munit.c munit.h
TEST_FILES = test_produtos_exemplo.c test_vendedores.c test_compradores.c test_vendas.c
TEST_RUNNER_FILE = test_runner.c
MAIN_SOURCE = ../sistema_vendas.c

# Executáveis
TEST_RUNNER = test_runner
PRODUTO_TEST = test_produtos
VENDEDOR_TEST = test_vendedores
COMPRADOR_TEST = test_compradores
VENDA_TEST = test_vendas

# Regra padrão
all: setup $(PRODUTO_TEST) $(VENDEDOR_TEST) $(COMPRADOR_TEST) $(VENDA_TEST) $(TEST_RUNNER)

# Download dos arquivos munit (apenas se não existirem)
setup:
	@echo "=== Verificando arquivos munit ==="
	@if [ ! -f munit.h ]; then \
		echo "Baixando munit.h..."; \
		curl -s -O https://raw.githubusercontent.com/nemequ/munit/master/munit.h; \
	fi
	@if [ ! -f munit.c ]; then \
		echo "Baixando munit.c..."; \
		curl -s -O https://raw.githubusercontent.com/nemequ/munit/master/munit.c; \
	fi
	@echo "Arquivos munit OK!"

# Compilar teste de produtos (standalone)
$(PRODUTO_TEST): $(MUNIT_FILES) test_produtos_exemplo.c
	@echo "=== Compilando testes de produtos ==="
	$(CC) $(CFLAGS) -DCOMPILE_STANDALONE -o $(PRODUTO_TEST) munit.c test_produtos_exemplo.c

# Compilar teste de vendedores (standalone)
$(VENDEDOR_TEST): $(MUNIT_FILES) test_vendedores.c
	@echo "=== Compilando testes de vendedores ==="
	$(CC) $(CFLAGS) -DCOMPILE_STANDALONE -o $(VENDEDOR_TEST) munit.c test_vendedores.c

# Compilar teste de compradores (standalone)
$(COMPRADOR_TEST): $(MUNIT_FILES) test_compradores.c
	@echo "=== Compilando testes de compradores ==="
	$(CC) $(CFLAGS) -DCOMPILE_STANDALONE -o $(COMPRADOR_TEST) munit.c test_compradores.c

# Compilar teste de vendas (standalone)
$(VENDA_TEST): $(MUNIT_FILES) test_vendas.c
	@echo "=== Compilando testes de vendas ==="
	$(CC) $(CFLAGS) -DCOMPILE_STANDALONE -o $(VENDA_TEST) munit.c test_vendas.c

# Compilar runner principal (todos os módulos)
$(TEST_RUNNER): $(MUNIT_FILES) $(TEST_FILES) $(TEST_RUNNER_FILE)
	@echo "=== Compilando runner principal ==="
	$(CC) $(CFLAGS) -o $(TEST_RUNNER) munit.c test_produtos_exemplo.c test_vendedores.c test_compradores.c test_vendas.c test_runner.c

# Executar apenas testes de produtos
test-produtos: $(PRODUTO_TEST)
	@echo "=== Executando testes de produtos ==="
	./$(PRODUTO_TEST)

# Executar apenas testes de vendedores
test-vendedores: $(VENDEDOR_TEST)
	@echo "=== Executando testes de vendedores ==="
	./$(VENDEDOR_TEST)

# Executar apenas testes de compradores
test-compradores: $(COMPRADOR_TEST)
	@echo "=== Executando testes de compradores ==="
	./$(COMPRADOR_TEST)

# Executar apenas testes de vendas
test-vendas: $(VENDA_TEST)
	@echo "=== Executando testes de vendas ==="
	./$(VENDA_TEST)

# Executar todos os testes
test-all: $(TEST_RUNNER)
	@echo "=== Executando TODOS os testes ==="
	./$(TEST_RUNNER)

# Executar testes com verbosidade
test-verbose: $(PRODUTO_TEST)
	@echo "=== Executando testes de produtos (verbose) ==="
	./$(PRODUTO_TEST) --verbose

# Executar testes específicos
test-cadastro: $(PRODUTO_TEST)
	@echo "=== Executando testes de cadastro ==="
	./$(PRODUTO_TEST) --filter "*cadastrar*"

test-busca: $(PRODUTO_TEST)
	@echo "=== Executando testes de busca ==="
	./$(PRODUTO_TEST) --filter "*buscar*"

# Limpeza
clean:
	@echo "=== Limpando arquivos compilados ==="
	rm -f $(PRODUTO_TEST) $(VENDEDOR_TEST) $(COMPRADOR_TEST) $(VENDA_TEST) $(TEST_RUNNER)
	rm -f *.exe *.o

# Limpeza completa (incluindo arquivos munit)
clean-all: clean
	@echo "=== Limpando arquivos munit ==="
	rm -f munit.h munit.c

# Mostrar ajuda
help:
	@echo "=== Sistema de Testes - Sistema de Vendas ==="
	@echo "Comandos disponíveis:"
	@echo "  make                 - Compilar todos os testes"
	@echo "  make setup           - Baixar arquivos munit"
	@echo "  make test-produtos   - Executar testes de produtos"
	@echo "  make test-vendedores - Executar testes de vendedores"
	@echo "  make test-compradores- Executar testes de compradores"
	@echo "  make test-vendas     - Executar testes de vendas"
	@echo "  make test-all        - Executar TODOS os testes"
	@echo "  make test-verbose    - Executar testes com verbosidade"
	@echo "  make clean           - Limpar arquivos compilados"
	@echo "  make clean-all       - Limpeza completa"
	@echo "  make help            - Mostrar esta ajuda"

# Verificar se tudo está funcionando
check: $(TEST_RUNNER)
	@echo "=== Verificação rápida do sistema de testes ==="
	@./$(TEST_RUNNER) --brief
	@echo "✅ Sistema de testes funcionando!"

# Estatísticas de teste
stats:
	@echo "=== Estatísticas dos testes ==="
	@echo "Testes por módulo:"
	@echo -n "- Produtos: "
	@grep -c "static MunitResult test_" test_produtos_exemplo.c
	@echo -n "- Vendedores: "
	@grep -c "static MunitResult test_" test_vendedores.c
	@echo -n "- Compradores: "
	@grep -c "static MunitResult test_" test_compradores.c
	@echo -n "- Vendas: "
	@grep -c "static MunitResult test_" test_vendas.c
	@echo -n "- Integração: "
	@grep -c "static MunitResult test_" test_runner.c

# Regras que não geram arquivos
.PHONY: all setup test-produtos test-vendedores test-compradores test-vendas test-all test-verbose clean clean-all help check stats

# Para Windows (PowerShell)
setup-windows:
	@echo "=== Verificando arquivos munit (Windows) ==="
	@powershell -Command "if (-not (Test-Path 'munit.h')) { Invoke-WebRequest -Uri 'https://raw.githubusercontent.com/nemequ/munit/master/munit.h' -OutFile 'munit.h' }"
	@powershell -Command "if (-not (Test-Path 'munit.c')) { Invoke-WebRequest -Uri 'https://raw.githubusercontent.com/nemequ/munit/master/munit.c' -OutFile 'munit.c' }"
	@echo "Arquivos munit OK!"
