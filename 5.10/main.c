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

int main(int argc, char **argv)
{
    int numbers[100];
    char symbols[99], *s;
    int i = 0;
    int j = 0;
    int c;
    float result = 0;

    --argc;
    ++argv;

//////////////Arg Control?/////////////////

///////////////////////////////////////////    

    while(argc)
    {
        if(isdigit(**argv))
        {
            s = *argv;
            numbers[i++] = atoi(s);
        }
        else
            symbols[j++] = **argv;

        ++argv;
        --argc;
    }

///////////////////////////////////////////
/*
    c = 0;
    for(; i != 0; --i)
        printf("%d ", numbers[c++]);
    printf("\n");
    c = 0;
    for(; j != 0; --j)
        printf("%c ", symbols[c++]);
*/

///////////////////////////////////////////

    result =+ numbers[--i];
    c = 0;

    while(c < j)
    {
        switch(symbols[c++])
        {
            case '+':
                result += numbers[--i];
                break;
            case '-':
                result = (numbers[--i] - result);
                break;
            case '*':
                result *= numbers[--i];
                break;
            case '/':
                result = (numbers[--i] / result);
                break;                                             
        }
    }

    printf("result = %.2f", result);

///////////////////////////////////////////    
        
    return 0;
}
