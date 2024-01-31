/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:09:15 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/31 18:11:22 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_utils.h"

static int	ft_hexlen(unsigned int number)
{
	int	len;

	if (!number)
		return (3);
	len = 0;
	while (number)
	{
		number = number / 16;
		len++;
	}
	return (len);
}

static char	*ft_hexformater(unsigned int number, char *base)
{
	char	*hexstr;
	int		len;
	int		i;

	if (number == 0)
		return (ft_strdup("0"));
	len = ft_hexlen(number);
	hexstr = malloc(sizeof(char) * (len + 1));
	if (!hexstr)
		return (NULL);
	hexstr[len] = '\0';
	i = len - 1;
	while (number)
	{
		hexstr[i--] = base[number % 16];
		number /= 16;
	}
	return (hexstr);
}

char	*ft_int_to_hex(unsigned int number)
{
	char	*res;
	char	*base;

	base = ft_strdup("0123456789ABCDEF");
	if (!base)
		return (NULL);
	res = ft_hexformater(number, base);
	free(base);
	if (!res)
		return (NULL);
	return (res);
}
