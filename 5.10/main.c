/*
* ”пражнение 5.10.
* Ќапишите программу ехрr, котора€
* бы вычисл€ла выражение в обратной польской
* записи из командной строки;
* каждый операнд и знак операции должен 
* быть отдельным аргументом. Ќапример,
* следующа€ командна€ строка задает  
* вычисление выражени€ 2х(3+4): 
* ехрг 2 3 4 + * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv)
{
    int numbers[100];
    char symbols[99], s;
    int i = 0;
    int j = 0;

    --argc;
    ++argv;

    while(--argc)
    {
        if(isdigit(*--argv))
        {
            s = *argv;
            numbers[i++] = atoi(s);
        }
        else
            symbols[j++] = *argv;
    }

    for(; i != 0; --i)
        printf("%d ", numbers[i]);
    printf("\n");
    for(; j != 0; --i)
        printf("%c ", symbols[i]);
        
    return 0;
}
