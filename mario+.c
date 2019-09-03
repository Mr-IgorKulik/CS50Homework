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
    while (n <= 0 || n > 8);
    
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int v = 0; v < i; v++)
        {
            printf("#");
        }
        printf("\n");
    }
}
