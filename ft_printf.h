#ifndef LIBFT_PRINTF
# define LIBFT_PRINTF

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
int ft_printf(const char *, ...);
size_t writestr(char *str);
size_t writechar(char c);
size_t writenbr(int nbr);
size_t writeunbr(unsigned int nbr);
size_t writeul_base(unsigned long number, char *base, size_t nbase);
#endif