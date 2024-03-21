/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:26:19 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 17:03:10 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURES_H
# define CUB3D_TEXTURES_H

/* Les codes pour les zones sur la map */

# define CUB3D_OUTSIDE 32
# define CUB3D_EMPTY 48
# define CUB3D_WALL 49
# define CUB3D_SPAWN_NORTH 78
# define CUB3D_SPAWN_SOUTH 83
# define CUB3D_SPAWN_WEST 87
# define CUB3D_SPAWN_EAST 69

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
	void			*test;
	t_cub3d_images	*frame;
	t_rgb			*floor;
	t_rgb			*ceiling;
	char			**map;
	size_t			map_height;
	size_t			map_width;
}				t_cub3d_textures;

#endif
