/*
 * The getfloat function.
 *
 * Reads the next number from input, and puts it into *fp.  Returns EOF for
 * end of file, zero if the next input is not a number, and a positive
 * value of the input contains a valid number.
 *
 * Based heavily on the getint function from K&R2.
 */

#include <ctype.h>
#include <math.h>

int getfloat(float *fp)
{
        int ch;
        int sign;
        int fraction;
        int digits;

        while (isspace(ch = getch()))   /* skip white space */
                ;

        if (!isdigit(ch) && ch != EOF && ch != '+'
                        && ch != '-' && ch != '.') {
                ungetch(ch);
                return 0;
        }

        sign = (ch == '-') ? -1 : 1;
        if (ch == '+' || ch == '-') {
                ch = getch();
                if (!isdigit(ch) && ch != '.') {
                        if (ch == EOF) {
                                return EOF;
                        } else {
                                ungetch(ch);
                                return 0;
                        }
                }
        }

        *fp = 0;
        fraction = 0;
        digits = 0;
        for ( ; isdigit(ch) || ch == '.' ; ch = getch()) {
                if (ch == '.') {
                        fraction = 1;
                } else {
                        if (!fraction) {
                                *fp = 10 * *fp + (ch - '0');
                        } else {
                                *fp = *fp + ((ch - '0') / pow(10, fraction));
                                fraction++;
                        }
                        digits++;
                }
        }

        *fp *= sign;

        if (ch == EOF) {
                return EOF;
        } else {
                ungetch(ch);
                return (digits) ? ch : 0;
        }
}
