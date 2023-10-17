
/*
    Filename:                       Credit.c
    Dependencies:                   Look at the include.
    Author:                         Vinicius Baradel.
    github:                         https://github.com/Eusouovinii .
    Date :                          15/10/2023.

    File description: Checks whether a credit card is valid and whether it is AMEX, VISA or MASTERCARD.

    Change History
    1.0 15/10/2033 First Version
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Pre declaration of function.

bool isvalid(char number[]);
void typeCard(char numbercc[]);

int main()
{

// Declaration of credit variable as array.

    char credit[17];

// Receives input from the user.

    printf("Insira o número do cartão de crédito: ");
    scanf("%s", credit);

// If the card is valid, check its brand.

    if (isvalid(credit)) 
    {
        typeCard(credit);
    }

    return 0;
}

// The following function just applies the Luhn Algorithm using a for loop.

bool isvalid(char numbercc[])
{

    long soma = 0;

    for (int i = 0, n = strlen(numbercc); i < n; i++)
    {
        int digito = numbercc[i] - '0';  // Converts the character to an integer digit.

        if ((strlen(numbercc) - i) % 2 == 0)
        {
            digito *= 2;
            if (digito > 9)
            {
                digito -= 9;
            }
        }
        soma += digito;
    }

    if (soma % 10 == 0)
    {
        printf("O número do cartão de crédito é válido.\n");
        return true;
    }
    else
    {
        printf("O número do cartão de crédito é inválido.\n");
        return false;
    }
}

// The following function checks the card type (AMEX, VISA or MASTERCARD) based on standards provided by the cs50 course.

void typeCard(char numbercc[])
{

    const char primeiro =       numbercc[0];
    const char segundo =        numbercc[1];
    const char ultimo =         numbercc[15];
    const char penultimo =      numbercc[14];
    const char antepenultimo =  numbercc[13];

    if (ultimo == '\0')
    {
        if (primeiro == '3' && ((segundo == '4') || segundo == '7'))
        {
            printf("AMEX\n");
        }
        else if (penultimo == '\0' && antepenultimo == '\0' && primeiro == '4')
        {
            printf("VISA\n");
        }
        else
        {
            printf("Numeração válida mas tipo do cartão não\n");
        }
    }
    else if (primeiro == '4')
    {
        printf("VISA\n");
    }
    else if (primeiro == '5' && (segundo >= '1' && segundo <= '5'))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("Numeração válida mas tipo do cartão não\n");
    }
}
