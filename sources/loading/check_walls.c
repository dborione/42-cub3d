/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:10:41 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/21 14:35:09 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/libft.h"

int	ft_has_west_wall(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (0);
		if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_has_east_wall(char *line)
{
	return (ft_endswith(line, "1"));
}
