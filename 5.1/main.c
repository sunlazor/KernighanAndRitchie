/*
 * Test module.
 */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main(void)
{
        int ret;

        do {
                int f;

                fputs("Enter a number: ", stdout);
                fflush(stdout);
                ret = getint(&f);
                if (ret > 0) {
                        printf("You entered: %d\n", f);
                }
        } while (ret > 0);

        if (ret == EOF) {
                puts("Stopped by EOF.");
        } else {
                puts("Stopped by bad input.");
        }
        
        return 0;
}
