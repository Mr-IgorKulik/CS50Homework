#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    int count = 0;
    float dollars = 0.0;
    while (dollars <= 0)
    {
        dollars = get_float("Change owed: ");
    }
    int coins = round (dollars * 100);
    while (coins >= 25)
    {
        coins -= 25;
        count++;
    }
    while (coins >= 10)
    {
        coins -= 10;
        count++;
    }
    while (coins >= 5)
    {
        coins -= 5;
        count++;
    }
    while (coins >= 1)
    {
        coins -= 1;
        count++;
    }
    printf ("%i", count);
}
