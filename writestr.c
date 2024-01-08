#include "ft_printf.h"

size_t writestr(char *str)
{
    size_t i;

    if (!str)
        return (write(1, "(null)", 6));
    i = 0;
    while (str[i])
        write(1, str + (i++), 1);
    return (i);
}