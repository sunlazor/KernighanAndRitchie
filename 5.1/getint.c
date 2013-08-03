/*
 * Exercise 5-2 from The C Programming Language, 2nd edition, by Kernighan
 * and Ritchie.
 *
 * "Write getfloat, the floating-point analog of getint. What type does
 * getfloat return as its function value?"
 */

/*
 * Here's the getint function, from section 5.2:
*/
/*
#define ALLOCSIZE 10000 /* объем имеющейся памяти */ 
/*static char allocbuf[ALLOCSIZE]; /* буфер памяти для alloc */ 
/*static char *allocp = allocbuf; /* следующая свободная позиция */ 
/*char *alloc(int n) /* возвращает указатель на п символов */ 
/*{ 
if (allocbuf + ALLOCSIZE - allocp >= n) { /* есть место */ 
/*allocp += n; 
return allocp - n; /* старый р */ 
/*} else /* недостаточно места в буфере */ 
/*return 0; 
} 
void afree(char *p) /* освобождение памяти по адресу р */ 
/*{ 
if (p >= allocbuf && p < allocbuf + ALLOCSIZE) 
allocp= p; 
} 



*/

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
        int c, sign;
        
        while (isspace(c = getch()))   /* skip white space */
                ;
        
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);  /* it is not a number */
                return 0;
        }
        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
                c = getch();
        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');
        *pn *= sign;
        if (c != EOF)
                ungetch(c);
        return c;
}
