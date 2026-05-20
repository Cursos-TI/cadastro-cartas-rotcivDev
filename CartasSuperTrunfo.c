#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.
#define IMPRIME_CABECALHO "################################### Carta %d ####################################\n"
#define IMPRIME_SEPARADOR "--------------------------------------------------------------------------------\n\n"

#define PROMPT_ESTADO "Defina uma letra para o Estado (A-F):\n"
#define PROMPT_CODIGO "Defina um codigo para o Estado (01-04):\n"
#define PROMPT_CIDADE "Defina o nome da Cidade:\n"
#define PROMPT_POPULACAO "Defina o numero de habitantes:\n"
#define PROMPT_AREA "Defina a area em km2:\n"
#define PROMPT_PIB "Defina o PIB:\n"
#define PROMPT_PONTOS_TURISTICOS "Defina a quantidade de pontos turisticos:\n"
#define PROMPT_CARTA "Insira os dados da %s:\n"

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
#define FORMATO_LEITURA_ESTADO " %1s"
#define FORMATO_LEITURA_CODIGO " %2s"
#define FORMATO_LEITURA_CIDADE " %24[^\n]"
#define FORMATO_LEITURA_POPULACAO " %d"
#define FORMATO_LEITURA_AREA " %f"
#define FORMATO_LEITURA_PIB " %f"
#define FORMATO_LEITURA_PONTOS_TURISTICOS " %d"

#define IMPRIME_ESTADO "Estado: %s\n\n"
#define IMPRIME_CODIGO "Código: %s%s\n\n"
#define IMPRIME_CIDADE "Nome da Cidade: %s\n\n"
#define IMPRIME_POPULACAO "População: %d\n\n"
#define IMPRIME_AREA "Área: %.2f km²\n\n"
#define IMPRIME_PIB "PIB: %.2f bilhões de reais\n\n"
#define IMPRIME_PONTOS_TURISTICOS "Número de Pontos Turísticos: %d\n\n"
#define IMPRIME_DENSIDADE_POPULACIONAL "Densidade Populacional: %.2f hab/km²\n\n"
#define IMPRIME_PIB_PERCAPTA "PIB per Capita: %.2f reais\n"

void limpa_residuo_stdin() {
  // * eh um caracter de supressao que permite ao scanf nao armazenar em nenhuma
  // variavel
  // "%*[^\n]" -> consuma tudo ate um caracter de nova linha
  // "%*c" -> consuma o \n que sobra
  scanf("%*[^\n]");
  scanf("%*c");
}

float calcula_densidade_populacional(int populacao, float area) {
  return (float) populacao / area;
}

float calcula_pib_per_capta(float pib, int populacao) {
  // converte PIB de bilhoes de reais para reais
  return (float) (pib * 1000000000.00) / populacao;
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
  int populacao_1, populacao_2;
  float area_1, area_2;
  float pib_1, pib_2;
  int pontos_turisticos_1, pontos_turisticos_2;
  float densidade_populacional_1, densidade_populacional_2;
  float pib_percapta_1, pib_percapta_2;
  
  // Área para entrada de dados
  printf(PROMPT_CARTA, "Carta 1");
  printf(PROMPT_ESTADO);
  scanf(FORMATO_LEITURA_ESTADO, estado_1);
  limpa_residuo_stdin();
  printf(PROMPT_CODIGO);
  scanf(FORMATO_LEITURA_CODIGO, codigo_1);
  limpa_residuo_stdin();
  printf(PROMPT_CIDADE);
  scanf(FORMATO_LEITURA_CIDADE, cidade_1);
  limpa_residuo_stdin();
  printf(PROMPT_POPULACAO);
  scanf(FORMATO_LEITURA_POPULACAO, &populacao_1);
  limpa_residuo_stdin();
  printf(PROMPT_AREA);
  scanf(FORMATO_LEITURA_AREA, &area_1);
  limpa_residuo_stdin();
  printf(PROMPT_PIB);
  scanf(FORMATO_LEITURA_PIB, &pib_1);
  limpa_residuo_stdin();
  printf(PROMPT_PONTOS_TURISTICOS);
  scanf(FORMATO_LEITURA_PONTOS_TURISTICOS, &pontos_turisticos_1);
  limpa_residuo_stdin();

  printf(PROMPT_CARTA,"Carta 2");
  printf(PROMPT_ESTADO);
  scanf(FORMATO_LEITURA_ESTADO, estado_2);
  limpa_residuo_stdin();
  printf(PROMPT_CODIGO);
  scanf(FORMATO_LEITURA_CODIGO, codigo_2);
  limpa_residuo_stdin();
  printf(PROMPT_CIDADE);
  scanf(FORMATO_LEITURA_CIDADE, cidade_2);
  limpa_residuo_stdin();
  printf(PROMPT_POPULACAO);
  scanf(FORMATO_LEITURA_POPULACAO, &populacao_2);
  limpa_residuo_stdin();
  printf(PROMPT_AREA);
  scanf(FORMATO_LEITURA_AREA, &area_2);
  limpa_residuo_stdin();
  printf(PROMPT_PIB);
  scanf(FORMATO_LEITURA_PIB, &pib_2);
  limpa_residuo_stdin();
  printf(PROMPT_PONTOS_TURISTICOS);
  scanf(FORMATO_LEITURA_PONTOS_TURISTICOS, &pontos_turisticos_2);
  limpa_residuo_stdin();

  // Area para atribuicao de variaveis computadas
  densidade_populacional_1 =
    calcula_densidade_populacional(populacao_1, area_1);
  pib_percapta_1 = calcula_pib_per_capta(pib_1, populacao_1);

  densidade_populacional_2 =
    calcula_densidade_populacional(populacao_2, area_2);
  pib_percapta_2 = calcula_pib_per_capta(pib_2, populacao_2);

  // Área para exibição dos dados da cidade
  printf(IMPRIME_CABECALHO, 1);
  printf(IMPRIME_ESTADO, estado_1);
  printf(IMPRIME_CODIGO, estado_1, codigo_1);
  printf(IMPRIME_CIDADE, cidade_1);
  printf(IMPRIME_POPULACAO, populacao_1);
  printf(IMPRIME_AREA, area_1);
  printf(IMPRIME_PIB, pib_1);
  printf(IMPRIME_PONTOS_TURISTICOS, pontos_turisticos_1);
  printf(IMPRIME_DENSIDADE_POPULACIONAL, densidade_populacional_1);
  printf(IMPRIME_PIB_PERCAPTA, pib_percapta_1);
  printf(IMPRIME_SEPARADOR);

  printf(IMPRIME_CABECALHO, 2);
  printf(IMPRIME_ESTADO, estado_2);
  printf(IMPRIME_CODIGO, estado_2, codigo_2);
  printf(IMPRIME_CIDADE, cidade_2);
  printf(IMPRIME_POPULACAO, populacao_2);
  printf(IMPRIME_AREA, area_2);
  printf(IMPRIME_PIB, pib_2);
  printf(IMPRIME_PONTOS_TURISTICOS, pontos_turisticos_2);
  printf(IMPRIME_DENSIDADE_POPULACIONAL, densidade_populacional_2);
  printf(IMPRIME_PIB_PERCAPTA, pib_percapta_2);
  printf(IMPRIME_SEPARADOR);
  
  return 0;
} 
