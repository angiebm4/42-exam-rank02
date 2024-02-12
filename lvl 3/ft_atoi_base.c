/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:44:27 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/12 09:43:46 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define MAX_BASE "0123456789ABCDEF"
#define MIN_BASE "0123456789abcdef"

int	ft_pow(int base, int nb_al_que_elevas)
{
	int i;
	int nb;
	
	i = 0;
	nb = base;
	if (nb_al_que_elevas == 0)
		return (1);
	while (--nb_al_que_elevas)
	{
		nb = nb * base;
	}
	return(nb);
}

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

int	ft_nose(char c)
{
	char *str = MIN_BASE;
	char *str2 = MAX_BASE;
	int i; 
	i = 0;
	while (c != str[i] && c != str2[i])
		i++;
	return (i);
}
int	ft_atoi_base(const char *str, int str_base)
{
	FILE *file = fopen("/Users/abarrio-/cursus/examrank2/log.txt", "a");
	if (file)
	{
		fprintf(file, "> %s - %d\n", str, str_base);
		fclose(file);
	}

	int sign = 1;
	int nb;
	int  len ;

	int i = 0;
	len = 0;
	nb = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		len = -1;
	}
	len += ft_strlen(str) - 1;
	while (str[i] != '\0')
	{
		// printf("=> %d * (%d^%d) --> %d\n", ft_nose(str[i]), str_base, len, ft_pow(str_base, len));
		nb += ft_nose(str[i]) * ft_pow(str_base, len);
		i++;
		len--;
	}
	return (nb * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("11101101", 2)); // 237
	printf("%d\n", ft_atoi_base("FF", 16)); // 255
	printf("%d\n", ft_atoi_base("fe", 16)); // 255
	return (0);
}