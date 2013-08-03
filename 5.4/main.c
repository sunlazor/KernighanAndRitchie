/*
* Упражнение 5.4.
* Напишите функцию strend(s,t),
* которая бы возвращала 1, если
* строка t присутствует в конце
* строки s, и 0 в противном случае.
*/


#include <stdio.h>

int strend(char *s, char *t);

int main(void)
{
    char where[] = "I love C";
    char what[] = " C";

    printf("%d\n", strend(where, what));
    printf("%d\n", strend(what, where));

    return 0;
}

int strend(char *s, char *t)
{
    int lent = 0;
    while ( *t != '\0')
    {
        t++;
        lent++;
    }
    while ( *s != '\0')
        s++;
        
    while (lent--)
    {
        if(*--s != *--t)
            return 0;
    }
    return 1;
}
