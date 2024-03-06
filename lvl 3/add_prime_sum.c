/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:59:28 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/13 11:02:29 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

long    get_sum(long nb)
{
    long sum;
    long primo;
    long aux;

    sum = 0;
    /* 4 ---->  7 / 7 = 0 7 / 1 0
    nb % 2   5 / 2 = 2   5 % 2 1  */
      // iterar desde nb a 0 buscando todos los primos sumarselo a sum
    while (nb > 0)
    {
        aux = 1;
        primo = 0;
        while (aux <= nb)
        {
            if (nb % aux == 0)
                primo++;
            aux++;
        }
        if (primo == 2)
            sum += nb;
        nb -= 1;
    }
    return(sum);
}


void    put_nbr(long nb)
{
    char c;


    if (nb > 9)
    {
        put_nbr(nb / 10);
        c = nb % 10 + '0';
        write(1, &c, 1);
    }
    else
    {    
        c = nb + '0';
        write(1, &c, 1);
    }
}


long ft_atoi(char *str)
{
    long nb;
    long i;

    i = 0;
    nb = 0;
    while (str[i] != '\0')
    {
        if (str[i] > '9' || str[i] < '0')
            return (-1);
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    if (nb > INT_MAX)
        return (-1);
    return (nb);
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, "0", 1);
        write(1, "\n", 1);
        return(0);
    }
    long nb;
    nb = ft_atoi(argv[1]);
    if (nb == -1)
    {
        write(1, "0", 1);
        write(1, "\n", 1);
        return(0);
    }
    long sum = get_sum(nb);
    put_nbr(sum);
    write(1, "\n", 1);
    return (0);
}
