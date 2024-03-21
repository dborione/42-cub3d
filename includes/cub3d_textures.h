/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:26:19 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/19 15:21:56 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURES_H
# define CUB3D_TEXTURES_H

/* Taille des murs */

# define WALL_HEIGHT 64
# define WALL_WIDTH 64

/* Type RGB pour définir les couleurs */

typedef struct s_rgb
{
	int	alpha;
	int	red;
	int	green;
	int	blue;
}				t_rgb;

/* Enregistre toutes les textures nécessaire */

typedef struct s_cub3d_images
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*pointer;
	char	*data;
}				t_cub3d_images;

typedef struct s_cub3d_textures
{
	void			*north_texture;
	void			*south_texture;
	void			*west_texture;
	void			*east_texture;
	t_cub3d_images	*frame;
	t_rgb			*floor;
	t_rgb			*ceiling;
	char			**map;
	size_t			map_height;
	size_t			map_width;
}				t_cub3d_textures;

#endif
