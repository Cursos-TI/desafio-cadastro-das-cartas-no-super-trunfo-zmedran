#include <stdio.h>

typedef struct  //Meio de organização das variaveis
{
    char Estado;
    char Codigocarta[5];          
    char Cidade[50];
    unsigned long int Populacao;
    int Pontos_turisticos, Numcarta;
    float Area, Densidadepopu, PIB_percap, SuperPoder;
    double PIB;

} Carta; //Variavel que ira carregar as anteriores, para que nao haja a necessidade de repitir

void EntradaDados(Carta *carta) { //estrutura que o usario ira inserir as cartas no codigo 
     printf("digite o estado de (A-H): ");
     scanf(" %c", &carta->Estado);
     printf("Digite o numero da carta (01 a 04): ");
     scanf("%d", &carta->Numcarta);
     carta->Numcarta = ((carta->Numcarta - 1) % 4) + 1; //meio de previnir que apareça algo acima ou baixo de 1 ou 4, e adiciona um 0 caso nao for inserido
     sprintf(carta->Codigocarta, "%c%02d", carta->Estado, carta->Numcarta); //junta os dados para gerar o codigo da carta
     printf("digite a cidade da primeira carta: ");
     scanf(" %[^\n]", carta->Cidade);
     printf("digite a populacao: ");
     scanf("%lu", &carta->Populacao);
     printf("digite a area em km: ");
     scanf("%f", &carta->Area);
     printf("diigite o PIB: ");
     scanf("%lf", &carta->PIB);
     printf("digite a quantidade de turisticos: ");
     scanf("%d", &carta->Pontos_turisticos);
    }


    void CalculoVariavel(Carta *carta) { //local onde fica os calculos das cartas 

   carta->Densidadepopu = (float)carta->Populacao / carta->Area;  //calcula a densidade das cartas

    carta->PIB_percap = carta->PIB *1e9 / (float)carta->Populacao;  //calcula a PIB percap das cartas e adiciona 9 zeros no pib para que o calculo sai de maneira correta

    carta->SuperPoder = (float)carta->Populacao + carta->Area + carta->PIB + carta->Pontos_turisticos + carta->PIB_percap + (carta->Area/carta->Populacao); //calcula o super poder
}

void Exibir_Carta_Dados(Carta carta) { //impreme os dados das cartas
     printf("\n--- Dados da Carta ---\n");
     printf("Estado: %c\n", carta.Estado);
     printf("Codigo da Carta: %s\n", carta.Codigocarta);
     printf("Cidade: %s\n", carta.Cidade);
     printf("Populacao: %lu\n", carta.Populacao);
     printf("Area: %.2f km²\n", carta.Area);
     printf("Densidade Populacional: %.2f hab/km\n", carta.Densidadepopu);
     printf("PIB: R$ %.2f bilhoes\n", carta.PIB);
     printf("PIB Percap: R$ %.2f bilhoes\n", carta.PIB_percap);
     printf("Pontos turisticos: %d\n", carta.Pontos_turisticos);
     printf("Super Poder:%.2f\n", carta.SuperPoder);
}        
void Comparar_Cartas (Carta carta1, Carta carta2) { // compara as cartas
    const char *resultado[] = {"carta 2 venceu", "empate", "carta 1 venceu" }; //cria um arry que calcula qual resultado ira ser aplicado se baseado em 0, 1 e 2
    printf("\nBatalha das Cartas:\n ");
    printf("Populacao: %s\n", resultado[1 + (carta1.Populacao > carta2.Populacao) - (carta1.Populacao < carta2.Populacao)]);
    printf("Area em km: %s\n", resultado[1 + (carta1.Area > carta2.Area) - (carta1.Area < carta2.Area)]);
    printf("Densidade Populacional: %s\n", resultado[1 + (carta1.Densidadepopu > carta2.Densidadepopu) - (carta1.Densidadepopu < carta2.Densidadepopu)]);
    printf("PIB: %s\n", resultado[1 + (carta1.PIB > carta2.PIB) - (carta1.PIB < carta2.PIB)]);
    printf("PIB per cap: %s\n", resultado[1 + (carta1.PIB_percap > carta2.PIB_percap) - (carta1.PIB_percap < carta2.PIB_percap)]);
    printf("Pontos turisticos: %s\n", resultado[1 + (carta1.Pontos_turisticos > carta2.Pontos_turisticos) - (carta1.Pontos_turisticos < carta2.Pontos_turisticos)]);
    printf("Super Poder: %s\n", resultado[1 + (carta1.SuperPoder > carta2.SuperPoder) -  (carta1.SuperPoder < carta2.SuperPoder)]);

}
int main() {
    Carta carta1, carta2; //faz com que tenha duas cartas sem a necessidade de repetir o codigo varias vezes
    
    printf("Insara os dados da primeira carta:\n"); //informa qual carta ira ser inserida
    EntradaDados(&carta1); //atribui o valor pra uma carta
    printf("Insara os dados da primeira carta:\n");
    EntradaDados(&carta2);

    printf("\nDados da primeira carta:");
    Exibir_Carta_Dados(carta1);
    printf("\nDados da segunda carta:");  
    Exibir_Carta_Dados(carta2); //imprime o vencendor em cada rodada

    Comparar_Cartas(carta1, carta2); //funçao 

    return 0;
}