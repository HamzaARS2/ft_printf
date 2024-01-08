/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:26:17 by helarras          #+#    #+#             */
/*   Updated: 2024/01/08 15:28:00 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t writearg(char c, va_list ap)
{
    size_t ccount;

    ccount = 0;
    if (c == 'c')
        ccount += writechar(va_arg(ap, int));
    else if (c == 's')
        ccount += writestr(va_arg(ap, char *));
    else if (c == 'i' || c == 'd')
        ccount += writenbr(va_arg(ap, int));
    else if (c == 'u')
        ccount += writeunbr(va_arg(ap, unsigned int));
    else if (c == 'x')
        ccount += writeul_base(va_arg(ap, unsigned int),"0123456789abcdef", 16);
    else if (c == 'X')
        ccount += writeul_base(va_arg(ap, unsigned int),"0123456789ABCDEF", 16);
    else if (c == 'p')
    {
        ccount += write(1, "0x", 2);
        ccount += writeul_base(va_arg(ap, unsigned long),"0123456789abcdef", 16);
    }
    else if (c == '%')
        ccount += write(1, "%", 1);
        
    return (ccount);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    size_t  i;
    size_t  ccount;
    
    i = 0;
    ccount = 0;
    va_start(ap,  str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 0)
                return (ccount);
            ccount += writearg(str[++i], ap);
        }
        else
            ccount += write(1, str + i, 1);
        i++;
    }
    va_end(ap);
    return (ccount);
}

