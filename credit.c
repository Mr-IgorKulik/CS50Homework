#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int count = 0;
    bool algorithm = false;
    
    long j;
    long card = get_long("Number: ");
    j = card;
    
    //считаем количество цифр
    while (j != 0)
    {
        j /= 10;
        count++;
    }
    
    int card_arr [count];
    int new_arr [count];
    
    //записываем номер карты по цифре в массив
    for (int i = 0; i < count; i++)
    {
        card_arr [i] = card % 10;
        new_arr [i] = card_arr [i];
        card /= 10;
    }
  
    //умножаем каждую вторую цифру на 2
    for (int i = 1; i < count; i += 2)
    {
        new_arr [i] *= 2;
    }
    int temp_arr [2];
    int sum = 0;
    
    //суммируем все цифры
    for (int i = 1; i < count; i += 2)
    {
       if (new_arr[i] <= 9)
       {
           sum += new_arr[i];
       }else
       {
           for (int k = 0; k < 2; k++)
           {
               sum += new_arr[i] % 10;
               new_arr[i] /= 10;
           }
       }
    }
    
    int fsum = 0;
    
    //сумма всех четных цифр карты
    for (int i = 0; i < count; i += 2)
    {
        fsum += card_arr[i];
    }
    fsum += sum;
    
    //проверка контрольной суммы
    if (fsum % 10 == 0)
    {
        algorithm = true;
    }
    
    //проверка AmericanExpress
    if (count == 15 && 
        algorithm == true &&
        ((card_arr[count-1] == 3 && 
         card_arr[count-2] == 4) || 
         (card_arr[count-1] == 3 && 
          card_arr[count-2] == 7)))
    {
        printf("AMEX\n");
        return 0;
    }
    
    //проверка MasterCard
    if (count == 16 && 
        algorithm == true &&
        ((card_arr[count-1] == 5 && 
        (card_arr[count-2] == 1 ||
        card_arr[count-2] == 2 ||
        card_arr[count-2] == 3 ||
        card_arr[count-2] == 4 ||
        card_arr[count-2] == 5))))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    
    //проверка VISA
    if ((count == 13 ||
         count == 16) && 
        algorithm == true &&
        card_arr[count-1] == 4)
    {
        printf("VISA\n");
        return 0;
    }else
    {
        printf("INVALID\n");
        return 0;
    }
}
