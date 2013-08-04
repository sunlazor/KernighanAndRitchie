/*
* Упражнение 5.5. 
* Применяя указатели, напишите ваши версии 
* библиотечных функций strncpy, strncat и strnemp, 
* которые обрабатывают не более чем п первых  символов 
* своих строковых аргументов. Например, функция 
* strncpy (s, t,n) копирует не более п символов из строки t в строку s. 
*
*/

#include <stdio.h>

void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);
void my_strncpy(char *dst, char *src, int n);

int main(void)
{
    char to[100] = "ABCDEFG";
    char what[] = "HIJKL";
    char awhat[] = "HIJKK";

    my_strncat(to, what, 20);
    printf("%s\n", to);

    my_strncpy(to, what, 3);
    printf("%s\n", to);
    
    printf("%d\n", my_strncmp(to, what, 55));
    printf("%d\n", my_strncmp(what, to, 55));
    printf("%d\n", my_strncmp(awhat, what, 55));
    printf("%d\n", my_strncmp(awhat, what, 4));
    
    return 0;
}

void my_strncpy(char *dst, char *src, int n)
{
    while ( *dst != '\0' && *src != '\0' && n != 0)
    {
        *dst = *src;
        src++;
        dst++;
        n--;
    }
}

int my_strncmp(char *s, char *t, int n)
{
    while ( *t != '\0' && *s != '\0' && n != 0)
    {
        if(*s != *t)
            return *s > *t ? 1 : -1;
        t++;
        s++;
        n--;
    }
    return 0;
}

void my_strncat(char *s, char *t, int n)
{
    while ( *s != '\0')
        ++s;
        
    while ( *t != '\0' && n != 0)
    {
        *s = *t;
        ++s;
        ++t;
        --n;
    }
}
