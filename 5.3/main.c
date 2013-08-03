/*
* pg. 62
* strcat: присоедин€ет строку t к концу s; 
* в s должно быть достаточно места
*/
/*
* Ex. 5.3 K&R pg 119
* ”пражнение 5.3.
* Ќапишите свою версию функции streat,
* продемонстрированной в главе 2,
* с применением указателей. Ќапоминаем,
* что strcat (s, t) копирует строку t
* в конец строки s. 
*/

#include <stdio.h>

void strcat(char *s, char *t);

int main(void)
{
    char to[100] = "I love";
    char what[] = " C";

    strcat(to, what);

    printf("%s", to);

    return 0;
}

void strcat(char *s, char *t)
{
    while ( *s != '\0')
        ++s;
        
     while ( *t != '\0')
     {
         *s = *t;
         ++s;
         ++t;
     }
}

//thx to tehten
