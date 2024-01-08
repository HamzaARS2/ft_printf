#include "ft_printf.h"

size_t writechar(char c)
{
    return (write(1, &c, 1));
}