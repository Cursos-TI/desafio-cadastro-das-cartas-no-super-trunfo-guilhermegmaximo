#include <stdio.h>
#include <string.h>

// Definindo a estrutura da cidade
struct Cidade {
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    int quantidade;

    printf("Digite a quantidade de cidades para cadastrar: ");
    scanf("%d", &quantidade);
    getchar(); // Limpa o buffer do teclado após o scanf

    // Vetor de cidades
    struct Cidade cidades[quantidade];

    // Cadastro das cidades
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastro da cidade %d ---\n", i + 1);

        printf("Codigo da cidade: ");
        scanf("%d", &cidades[i].codigo);
        getchar(); // Limpa buffer

        printf("Nome da cidade: ");
        fgets(cidades[i].nome, sizeof(cidades[i].nome), stdin);
        // Remove o '\n' se estiver no final
        size_t len = strlen(cidades[i].nome);
        if (len > 0 && cidades[i].nome[len - 1] == '\n') {
            cidades[i].nome[len - 1] = '\0';
        }

        printf("Populacao da cidade: ");
        scanf("%d", &cidades[i].populacao);

        printf("Area da cidade (em km²): ");
        scanf("%f", &cidades[i].area);

        printf("PIB da cidade (em bilhoes): ");
        scanf("%f", &cidades[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cidades[i].pontosTuristicos);
        getchar(); // Limpa buffer
    }

    // Exibição dos dados das cidades
    printf("\n====== Dados das Cidades Cadastradas ======\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Cidade %d ---\n", i + 1);
        printf("Codigo: %d\n", cidades[i].codigo);
        printf("Nome: %s\n", cidades[i].nome);
        printf("Populacao: %d habitantes\n", cidades[i].populacao);
        printf("Area: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhoes\n", cidades[i].pib);
        printf("Pontos Turisticos: %d\n", cidades[i].pontosTuristicos);
    }

    return 0;
}
