CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = cartas_super_trunfo
SRC = CartasSuperTrunfo.c

# permite rodar apenas make sem especificar target
all: $(TARGET)

# $@ referencia o target -> cartas_super_trunfo
# $^ referencia o source -> CartasSuperTrunfo.c
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# regra para remover binario gerado 
limpa:
	rm -f $(TARGET)

teste: limpa $(TARGET)
	./teste.sh ./$(TARGET)

# reserva o nome dos comandos para nao confundir com nome de pastas
.PHONY: all limpa teste_novato
