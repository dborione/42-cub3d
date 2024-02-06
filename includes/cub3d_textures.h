/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:26:19 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/06 11:21:08 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURES_H
# define CUB3D_TEXTURES_H

/* Défini des codes pour les zones sur la map */

# define CUB3D_OUTSIDE 32
# define CUB3D_EMPTY 48
# define CUB3D_WALL 49
# define CUB3D_SPAWN_NORTH 78
# define CUB3D_SPAWN_SOUTH 83
# define CUB3D_SPAWN_WEST 87
# define CUB3D_SPAWN_EAST 69

/* Taille de murs */

# define WALL_HEIGHT 480 // voir pour les tailles les plus opti
# define WALL_WIDTH 720 // ici j'ai mis une basse résolution en 16:9

/* Type RGB pour définir les couleurs */

typedef struct s_rgb
{
	int	alpha;
	int	red;
	int green;
	int blue;
}				t_rgb;

/* Enregistre toutes les textures nécessaire */

typedef struct	s_cub3d_images
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data;
}				t_cub3d_images;

typedef struct	s_cub3d_textures
{
	void	*north_texture;
	void	*south_texture;
	void	*west_texture;
	void	*east_texture;
	void	*test;
	void	*frame;
	int		floor;
	int		ceiling;
	char	**map;
}				t_cub3d_textures;

#endif