#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[80];
    int poder;
    int defesa;
    int vida;
} personagem;

// ex1
void status(personagem x)
{
    printf("Nome: %s\n", x.nome);
    printf("Poder: %i\n", x.poder);
    printf("Defesa: %i\n", x.defesa);
    printf("Vida: %i\n", x.vida);
    printf("\n");
}

// ex2
void ataque(personagem x, personagem y)
{
    int dano = x.poder - y.defesa;
    if (dano > 0)
    {
        printf("O dano de %s em %s foi de %i pontos de vida\n", x.nome, y.nome,
               dano);
    }
    if (dano <= 0)
    {
        printf("O ataque não foi efetivo");
    }
}

// ex4
personagem inimigo()
{
    personagem z = {"Zed", 20 + rand() % (30 - 20 + 1),
                    10 + rand() % (30 - 10 + 1), 20 + rand() % (50 - 20 + 1)};
    return z;
}

int main(void)
{
    personagem x = {"Xil", 54, 12, 100};
    personagem y = {"Yen", 40, 20, 100};
    int dano = 0;

    // ex1
    status(x);
    status(y);

    // ex2
    ataque(x, y);
    ataque(y, x);

    // ex3
    printf("\n");
    while (x.vida > 0 & y.vida > 0)
    {
        if (x.vida > 0)
        {
            ataque(x, y);
            y.vida = y.vida - (x.poder - y.defesa);
            printf("Os pontos de vida de %s são %i\n\n", y.nome, y.vida);
        }

        if (y.vida > 0)
        {
            ataque(y, x);
            x.vida = x.vida - (y.poder - x.defesa);
            printf("Os pontos de vida de %s são %i\n\n", x.nome, x.vida);
        }
    }
    if (x.vida <= 0)
    {
        printf("O personagem %s está morto\n", x.nome);
        printf("O personagem %s saiu vitorioso\n", y.nome);
    }
    if (y.vida <= 0)
    {
        printf("O personagem %s está morto\n", y.nome);
        printf("O personagem %s saiu vitorioso\n", x.nome);
    }

    // ex 4
    srand(1);
    printf("\n");
    printf("Xil usou uma poção e agora possui 100 pontos de vida\n\n");
    x.vida = 100;

    personagem z1 = inimigo();
    personagem z2 = inimigo();
    personagem z3 = inimigo();
    personagem z4 = inimigo();
    personagem z5 = inimigo();
    personagem zeds[5] = {z1, z2, z3, z4, z5};
    for (int c = 0; c < 5; c++)
    {
        while (x.vida > 0 & zeds[c].vida > 0)
        {
            if (x.vida > 0)
            {
                ataque(x, zeds[c]);
                zeds[c].vida = zeds[c].vida - (x.poder - zeds[c].defesa);
                printf("Os pontos de vida de %s são %i\n", zeds[c].nome, zeds[c].vida);
                if (zeds[c].vida > 0)
                {
                    ataque(zeds[c], x);
                    x.vida = x.vida - (zeds[c].poder - x.defesa);
                    printf("Os pontos de vida de %s são %i\n", x.nome, x.vida);
                }
                if (zeds[c].vida < 0)
                {
                    printf("O personagem %s está morto\n\n", zeds[c].nome);
                }
            }
        }
    }
    if (x.vida > 0)
    {
        printf("O personagem %s saiu vitorioso", x.nome);
    }
}