/*
* ���������� 5.10.
* �������� ��������� ���r, �������
* �� ��������� ��������� � �������� ��������
* ������ �� ��������� ������;
* ������ ������� � ���� �������� ������ 
* ���� ��������� ����������. ��������,
* ��������� ��������� ������ ������  
* ���������� ��������� 2�(3+4): 
* ���� 2 3 4 + * 
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
