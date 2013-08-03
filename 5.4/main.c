/*
* ���������� 5.4.
* �������� ������� strend(s,t),
* ������� �� ���������� 1, ����
* ������ t ������������ � �����
* ������ s, � 0 � ��������� ������.
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
