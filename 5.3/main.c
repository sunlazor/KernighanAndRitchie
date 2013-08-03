/*
* pg. 62
* strcat: ������������ ������ t � ����� s; 
* � s ������ ���� ���������� �����
*/
/*
* Ex. 5.3 K&R pg 119
* ���������� 5.3.
* �������� ���� ������ ������� streat,
* �������������������� � ����� 2,
* � ����������� ����������. ����������,
* ��� strcat (s, t) �������� ������ t
* � ����� ������ s. 
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
