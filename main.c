#include <stdio.h>

int main()
{
    int tabuleiro[10][10] = 
    //
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    // Declaração de Variáveis de Posição
    // Vetores (arrays unidimensionais) para representar os navios:
    int navioVertical [3]= {3, 3, 3};
    int navioHorizontal [3]= {3, 3, 3}; 
    
    int linhaVertical = 0;      
    int linhaHorizontal = 3; // Linha onde o navio horizontal será colocado (0-9)

    int colunaVertical = 4; // Coluna onde o navio vertical será colocado (0-9)
    int colunaHorizontal = 6; // Coluna de início do navio horizontal (0-9)      
    
    
    // --- Posicionamento do Navio Vertical (Começa na linha 0, coluna 4) ---
    for(int i = 0; i < 3; i++)
    {
        // verifica se está DENTRO dos limites 
        // verifica se a posição está VAZIA 
        if (linhaVertical + i < 10 && tabuleiro[linhaVertical + i][colunaVertical] == 0)
        {
            // Atribui o valor do vetor navioVertical à posição do tabuleiro
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        } 
        else if (linhaVertical + i >= 10) // Posição fora dos limites
        {
            printf("\n Erro! Posição fora dos limites do tabuleiro. Navio Vertical na linha %d.\n", linhaVertical + i);
            break; // Sai do loop se estiver fora do limite
        } 
        else // Posição já ocupada (colisão)
        {
            printf("\n Erro! Posição (%d, %d) já possui um navio. Navio Vertical.\n", linhaVertical + i, colunaVertical);
            break; // Sai do loop em caso de colisão
        }
    }
    
    // --- Posicionamento do Navio Horizontal (Começa na linha 3, coluna 6) ---
    for(int j = 0; j < 3; j++)
    {   
        // verifica se está DENTRO dos limites
        // verifica se a posição está VAZIA
        if (colunaHorizontal + j < 10 && tabuleiro[linhaHorizontal][colunaHorizontal + j] == 0)
        {
            // Atribui o valor do vetor navioHorizontal à posição do tabuleiro
            tabuleiro[linhaHorizontal][colunaHorizontal + j] = navioHorizontal[j];
        } 
        else if (colunaHorizontal + j >= 10) // Posição fora dos limites
        {
            printf("\n Erro! Posição fora dos limites do tabuleiro. Navio Horizontal na coluna %d.\n", colunaHorizontal + j);
            break; // Sai do loop se estiver fora do limite
        } 
        else // Posição já ocupada (colisão)
        {
            printf("\n Erro! Posição (%d, %d) já possui um navio. Navio Horizontal.\n", linhaHorizontal, colunaHorizontal + j);
            break; // Sai do loop em caso de colisão
        }
    }

    //Imprime o tabuleiro na tela
    printf("*** Jogo Batalha Naval***\n");
    
    printf("\n");

    printf("   ");
    //cabeçalho      
    char letra = 'A'; // inicialização da variável letra com a letra A
    for (int j = 0; j < 10; j++) // encrementa mais 1 enquanto j for menor que 10
    {
        printf("%c ", letra); // imprime letra de A a J
        ++letra;
    }

    printf("\n");

    //tabuleiro
    for (int i = 0; i < 10; i++)
    {
        
        printf("%d |", i); //linha para refência das coordenadas


        for (int j = 0; j < 10; j++) //percorre colunas
        {
            printf("%d ", tabuleiro[i][j]);// imprime valores 0 (água) ou 3 (navio)
        }
        printf("\n"); 
    }
    printf("\n");
    return 0;
}
