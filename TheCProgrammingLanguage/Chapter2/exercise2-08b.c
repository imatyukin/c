// Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
// to the right by n positions.

/*  rightrot: rotate x to the right by n positions                  */
unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    unsigned rbits;

    if ((n = n % wordlength()) > 0) {
        rbits = ~(~0 << n) & x;     /*  n rightmost bits of x       */
                                    /*  n rightmost bits to left    */
        rbits = rbits << (wordlength() - n);
        x = x >> n;                 /*  x shifted n positions right */
        x = x | rbits;              /*  rotation completed          */
    }
    return x;
}

/*  wordlength: computes word length of the machine         */
int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
