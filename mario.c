#include <cs50.h>
#include <stdio.h>

void marioPyramid (void);

int main(void)
{
    marioPyramid();
}

void marioPyramid (void)
{
    int n;
    do
    {
        n = get_int("Height: ");    
    }
    while (n < 1 || n > 8);
    
    for (int i = 1; i < n + 1; i++)
    {
        for (int k = n; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
