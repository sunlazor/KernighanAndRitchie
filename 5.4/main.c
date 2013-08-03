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

int strend(char *where, char *what)
{
    int iWhereLength = 0;
    int iWhatLength = 0;
    while ( *where != '\0')
    {
        where++;
        iWhereLength++;
    }
    while ( *what != '\0')
    {
        what++;
        iWhatLength++;
    }

    if(iWhatLength > iWhereLength)
        return 0;
        
    while (iWhatLength--)
    {
        if(*--where != *--what)
            return 0;
    }
    return 1;
}
