#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool alpha = true;  //только буквы ли введены
        int k [strlen(argv[1])]; //массив ключей переведенных в числа

        //проверка все ли введенные символы ключа являюся буквами
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                alpha = false;
            }
        }

        //запись введенного ключа в массив по одной цифре
        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            k[i] = shift(argv[1][i]);
        }


        /*АЛГОРИТМ ШИФРОВАНИЯ ---- ШИФР ВИЖЕНЕРА*/
        //проверка что ключ - это буквы
        if (alpha)
        {
            string pt = get_string("plaintext: ");
            char ct [strlen(pt)];
            printf("ciphertext: ");
            int j = -1;
            
            //шифрование букв нижнего регистра
            for (int i = 0, n = strlen(pt); i < n; i++)
            {
                if (j >= strlen(argv[1]) - 1)
                {
                    j = -1;
                }
                if (isalpha(pt[i]))
                {
                    j += 1;
                }
                
                int key =  k[j];
                
                if (pt[i] > 96 && pt[i] < 123)
                {

                    if((pt[i] + key) > 122)
                    {
                        printf("%c", (96 + (key % 26) - (123 - pt[i]) + 1));
                    }else
                    {
                        printf("%c", pt[i] + key);
                    }
                }
                
                //шифрование букв верхнего регистра
                if (pt[i] > 64 && pt[i] < 91)
                {
                    if((pt[i] + key) > 90)
                    {
                        printf("%c", (64 + (key % 26)) - (91 - pt[i]) + 1);
                    }else
                    {
                        printf("%c", pt[i] + key);
                    }
                }
                
                //вывод без изменений небуквенных символов
                if (!(pt[i] > 96 && pt[i] < 123) &&
                   !(pt[i] > 64 && pt[i] < 91))
                {
                    printf("%c", pt[i]);
                }

            }
            printf("\n");
            return 0;
        }
        else 
        {
            printf("Usage: %s keyword\n", argv[0]);
            return 1;
        }
    }else
    {
        printf("Usage: %s keyword\n", argv[0]);
        return 1;
    }
    
}

int shift (char c)
{
    int key = 0;
    if (c > 64 && c  < 91)
    {
        key = (int) c - 65;
    }
    if (c > 96 && c < 123)
    {
        key = (int) c - 97;
    }
    
    return key;
}
