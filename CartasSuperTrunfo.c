#include <stdio.h>
#include <string.h>

struct Cidade {
    char estado;
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

int main() {
    struct Cidade carta1, carta2;

    // ===== Cadastro da Carta 1 =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    scanf(" %c", &carta1.estado);
    getchar();

    printf("Codigo da carta: ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    carta1.codigo[strcspn(carta1.codigo, "\n")] = '\0';

    printf("Nome da cidade: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = '\0';

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta1.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    getchar();

    // ===== Cadastro da Carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    scanf(" %c", &carta2.estado);
    getchar();

    printf("Codigo da carta: ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = '\0';

    printf("Nome da cidade: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = '\0';

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta2.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    getchar();

    // ===== Cálculos das Cartas =====

    // Densidade Populacional
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    // PIB per capita
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    // Super Poder
    carta1.superPoder = 
        (float)carta1.populacao + 
        carta1.area + 
        carta1.pib + 
        (float)carta1.pontosTuristicos + 
        carta1.pibPerCapita + 
        (1.0 / carta1.densidadePopulacional);

    carta2.superPoder = 
        (float)carta2.populacao + 
        carta2.area + 
        carta2.pib + 
        (float)carta2.pontosTuristicos + 
        carta2.pibPerCapita + 
        (1.0 / carta2.densidadePopulacional);

    // ===== Exibição dos Dados =====
    printf("\n====== Carta 1 ======\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nome);
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);
    printf("Super Poder: %.2f\n", carta1.superPoder);

    printf("\n====== Carta 2 ======\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);
    printf("Super Poder: %.2f\n", carta2.superPoder);

    // ===== Comparação =====
    printf("\n====== Comparacao de Cartas ======\n");

    printf("Populacao: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", carta1.pontosTuristicos > carta2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidadePopulacional < carta2.densidadePopulacional); // MENOR vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pibPerCapita > carta2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.superPoder > carta2.superPoder);

    return 0;
}
