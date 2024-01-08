#include "ft_printf.h"

static size_t	powerof(long nbr)
{
	size_t	power;

	power = 1;
	nbr /= 10;
	while (nbr)
	{
		nbr /= 10;
		power *= 10;
	}
	return (power);
}

static void	putnumber(long number, size_t power, size_t *ccount)
{
	long	n;

	if (number < 0)
	{
		*ccount += write(1, "-", 1);
		number *= -1;
	}
	while (power)
	{
		n = (number / power) + 48;
		*ccount += write(1, &n, 1);
		number %= power;
		power /= 10;
	}
}

size_t writenbr(int nbr)
{
    size_t	power;
    size_t ccount;

	ccount = 0;
	power = powerof(nbr);
	putnumber(nbr, power, &ccount);
    return (ccount);
}