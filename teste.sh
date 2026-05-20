#!/bin/bash
# espera receber o binario como argumento
SUT=$1

# Carta 1:
ESTADO1=A
CODIGO1=01
CIDADE1="São Paulo"
POPULACAO1=12325000
AREA1=1521.11
PIB1=699.28
PONTOS_TURISTICOS1=50
 
#Carta 2:
ESTADO2=B
CODIGO2=02
CIDADE2="Rio de Janeiro"
POPULACAO2=6748000
AREA2=1200.25
PIB2=300.50
PONTOS_TURISTICOS2=30

# valida se o argumento foi passado/existe

if [ -z "$SUT" ] || [ ! -f "$SUT" ]; then
    echo "ERR: SUT nao fornecido ou nao encontrado!"
    exit
fi
	
$SUT <<EOF
$ESTADO1
$CODIGO1
$CIDADE1
$POPULACAO1
$AREA1
$PIB1
$PONTOS_TURISTICOS1
$ESTADO2
$CODIGO2
$CIDADE2
$POPULACAO2
$AREA2
$PIB2
$PONTOS_TURISTICOS2
EOF
