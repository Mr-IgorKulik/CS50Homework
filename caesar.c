#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool digits = true;  //только числа ли введены
        int v [strlen(argv[1])]; //массив цифр введенного числа

        //проверка все ли введенные символы ключа являюся цифрами
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                digits = false;
            }
        }

        //запись введенного ключа в массив по одной цифре
        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            v[i] = argv[1][i] % 16;
        }

        //преобразование массива цифр ключа в число int 
        int key = 0;
        for (int i = strlen(argv[1]) - 1, k = 1; i >= 0; i--)
        {
            key += v[i] * k;
            k *= 10;
        }

        /*АЛГОРИТМ ШИФРОВАНИЯ ---- ШИФР ЦЕЗАРЯ*/
        //проверка что ключ - это число
        if (digits)
        {
            string pt = get_string("plaintext: ");
            char ct [strlen(pt)];
            printf("ciphertext: ");
            
            while (key > 26)
            {
                key -= 26;
            }
            //шифрование букв нижнего регистра
            for (int i = 0, n = strlen(pt); i < n; i++)
            {
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
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    
}
