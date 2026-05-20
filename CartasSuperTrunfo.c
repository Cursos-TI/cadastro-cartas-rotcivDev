// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades
// utilizando scanf para entrada de dados e printf para exibir as informações.

#include <stdio.h>

#define PROMPT_CARTA "Insira os dados da Carta %d:\n"
#define MULTIPLICADOR_CONVERSOR_BILHOES 1000000000.00

// funcao para controle de residuos no stdin
void limpa_residuo_stdin() {
  // * eh um caracter de supressao que permite ao scanf nao armazenar em nenhuma
  // variavel
  // "%*[^\n]" -> consuma tudo ate um caracter de nova linha
  // "%*c" -> consuma o \n que sobra
  scanf("%*[^\n]");
  scanf("%*c");
}

// funcoes de controle e gravacao de input
// uso a sintaxe *<recicipente> que eh a sintaxe de referencia para armazenar os
// valores diretamente no destino
// O espaco antes da declaracao dos formatos diz ao scanf para ignorar qualquer
// residuo de input do stdin.
// Formatos para scanf com limitador de leitura para evitar segfault.
// ex: scanf(" 2%s", &var);
// O digito 2 diz ao scanf para limitar a captura da string para 2 bytes,
// lembrando que sempre se deve contar com 1 byte para o caracter \0. Ou seja,
// neste caso a var precisa alocar [3]. 
// [^\n] -> formato para que o scanf leita ate a quebra de linha (scanset),
// evitando que ele quebre o input no \s, armazenando somente a primeira palavra
// deixando o restante como residuo no stdin.
// ex "Sao Paulo" -> se o formato fosse %s seria gravado apenas Sao para cidade
// e Paulo ficaria "sobrando" no stdin;
void coleta_estado(char *destino) {
  printf("Defina uma letra para o Estado (A-F):\n");
  scanf(" %1s", destino);
  limpa_residuo_stdin();
}
void coleta_codigo(char *destino) {
  printf("Defina um codigo para o Estado (01-04):\n");
  scanf(" %2s", destino);
  limpa_residuo_stdin();
}
void coleta_cidade(char *destino) {
  printf("Defina o nome da Cidade:\n");
  scanf(" %24[^\n]", destino);
  limpa_residuo_stdin();
}
void coleta_populacao(unsigned long int *destino) {
  printf("Defina o numero de habitantes:\n");
  scanf(" %ld", destino);
  limpa_residuo_stdin();
}
void coleta_area(float *destino) {
  printf("Defina a area em km2:\n");
  scanf(" %f", destino);
  limpa_residuo_stdin();
}
void coleta_pib(float *destino) {
  printf("Defina o PIB:\n");
  scanf(" %f", destino);
  limpa_residuo_stdin();
}
void coleta_pontos_turisticos(int *destino) {
  printf("Defina a quantidade de pontos turisticos:\n");
  scanf(" %d", destino);
  limpa_residuo_stdin();
}

// Funcoes para calculos numericos com retorno de valores
float calcula_densidade_populacional(int populacao, float area) {
  return (float) populacao / area;
}
float calcula_pib_per_capta(float pib, int populacao) {
  // converte PIB de bilhoes de reais para reais.
  return (float) (pib * MULTIPLICADOR_CONVERSOR_BILHOES) / populacao;
}
// Calculo sem normalizacao pois nao fazia parte dos requisitos do desfio.
// Aplica inversao para calculo da densidade.
float calcula_super_poder(int populacao, float area, float pib, int pontos_turisticos,
                          float densidade_populacional, float pib_per_capta) {
  return (float)populacao + area + pib + pontos_turisticos + (1 / densidade_populacional) +
         pib_per_capta;
}

void imprime_carta(short numero_carta, char *estado, char *codigo, char *cidade,
                   unsigned long int populacao, float area, float pib,
                   int pontos_turisticos, float densidade_populacional,
                   float pib_per_capta, float super_poder){
  printf("########################### Carta %d ############################\n", numero_carta);
  printf("Estado: %s\n\n", estado);
  printf("Código: %s%s\n\n", estado, codigo);
  printf("Nome da Cidade: %s\n\n", cidade);
  printf("População: %ld\n\n", populacao);
  printf("Área: %.2f km²\n\n", area);
  printf("PIB: %.2f bilhões de reais\n\n", pib);
  printf("Número de Pontos Turísticos: %d\n\n", pontos_turisticos);
  printf("Densidade Populacional: %.2f hab/km²\n\n", densidade_populacional);
  printf("PIB per Capita: %.2f reais\n\n", pib_per_capta);
  printf("Super Poder: %.2f\n", super_poder);
  printf("----------------------------------------------------------------\n\n");
}

// Lookup Table para Resultados sem uso de condicional
char *map_resultado[] = {"Carta 2 venceu (0)", "Carta 1 venceu (1)"};

void imprime_comparacao_cartas(unsigned long int populacao1,
                               unsigned long int populacao2, float area1,
                               float area2, float pib1, float pib2,
                               int pontos_turisticos1, int pontos_turisticos2,
                               float densidade_populacional1,
                               float densidade_populacional2,
                               float pib_per_capta1, float pib_per_capta2,
                               float super_poder1, float super_poder2) {
  printf("########################### Comparação de Cartas ############################\n");
  printf("População: %s\n",
         map_resultado[(populacao1 > populacao2)]);
  printf("Área: %s\n", map_resultado[(area1 > area2)]);
  printf("PIB: %s\n", map_resultado[(pib1 > pib2)]);
  printf("Pontos Turísticos: %s\n",
         map_resultado[(pontos_turisticos1 > pontos_turisticos2)]);
  printf("Densidade Populacional: %s\n",
         map_resultado[(densidade_populacional1 <
                        densidade_populacional2)]);
  printf("PIB per Capta: %s\n",
         map_resultado[(pib_per_capta1 > pib_per_capta2)]);
  printf("Super Poder: %s\n", map_resultado[(super_poder1 > super_poder2)]);
  printf("--------------------------------------------------------------------------\n\n");
}

// Seguindo as recomendacoes de nao utilizar validacoes ou lacos, fiz o maximo
// para preservar o sistema contra Fuzzing no I/O podendo causar buffer
// overflow, bleeding e segfault.
// Tambem implementei sanitizacao do stdin utilizando a funcao
// limpa_residuo_stdin.
// Existem casos em que o programa pode travar devido a escolha de como limpar
// os residuos do stdin, caso o buffer de entrada ja esteja limpo ou restando
// apenas \n. 
// No meu ambiente, o comportamento da glibc demonstrou que o scanf nao causou
// travamento (hang) quando o buffer esta limpo. Ao inves de esperar, ele
// reporta uma falha de correspondencia (nao encontrou nada a nao ser \n), e
// retorna o valor 0.
int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado_1[2], estado_2[2];
  char codigo_1[3], codigo_2[3];
  char cidade_1[25], cidade_2[25];
  unsigned long int populacao_1, populacao_2;
  float area_1, area_2;
  float pib_1, pib_2;
  int pontos_turisticos_1, pontos_turisticos_2;
  float densidade_populacional_1, densidade_populacional_2;
  float pib_per_capta_1, pib_per_capta_2;
  float super_poder_1, super_poder_2;
  
  // Área para entrada de dados
  printf(PROMPT_CARTA, 1);
  coleta_estado(estado_1);
  coleta_codigo(codigo_1);
  coleta_cidade(cidade_1);
  coleta_populacao(&populacao_1);
  coleta_area(&area_1);
  coleta_pib(&pib_1);
  coleta_pontos_turisticos(&pontos_turisticos_1);
  densidade_populacional_1 =
    calcula_densidade_populacional(populacao_1, area_1);
  pib_per_capta_1 = calcula_pib_per_capta(pib_1, populacao_1);
  super_poder_1 =
      calcula_super_poder(populacao_1, area_1, pib_1, pontos_turisticos_1,
                          densidade_populacional_1, pib_per_capta_1);
  
  printf(PROMPT_CARTA, 2);
  coleta_estado(estado_2);
  coleta_codigo(codigo_2);
  coleta_cidade(cidade_2);
  coleta_populacao(&populacao_2);
  coleta_area(&area_2);
  coleta_pib(&pib_2);
  coleta_pontos_turisticos(&pontos_turisticos_2);
  densidade_populacional_2 =
    calcula_densidade_populacional(populacao_2, area_2);
  pib_per_capta_2 = calcula_pib_per_capta(pib_2, populacao_2);
  super_poder_2 = calcula_super_poder(populacao_2, area_2, pib_2, pontos_turisticos_2, densidade_populacional_2, pib_per_capta_2);

  // Área para exibição dos dados da cidade
  imprime_carta(1, estado_1, codigo_1, cidade_1, populacao_1, area_1, pib_1,
                pontos_turisticos_1, densidade_populacional_1, pib_per_capta_1,
                super_poder_1);

  imprime_carta(2, estado_2, codigo_2, cidade_2, populacao_2, area_2, pib_2,
                pontos_turisticos_2, densidade_populacional_2, pib_per_capta_2,
                super_poder_2);

  imprime_comparacao_cartas(populacao_1, populacao_2, area_1, area_2, pib_1,
                            pib_2, pontos_turisticos_1, pontos_turisticos_2,
                            densidade_populacional_1, densidade_populacional_2,
                            pib_per_capta_1, pib_per_capta_2, super_poder_1,
                            super_poder_2);
  
  return 0;
}


