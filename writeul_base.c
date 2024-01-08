#include "ft_printf.h"

size_t writeul_base(unsigned long number, char *base, size_t nbase)
{
    size_t ccount;

    ccount = 0;
    if (number >= nbase)
        ccount += writeul_base(number / nbase, base, nbase);
    return (write(1, base + (number % nbase), 1) + ccount);
}