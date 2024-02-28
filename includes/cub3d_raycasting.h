#ifndef CUB3D_RAYCASTING
# define CUB3D_RAYCASTING
# include "cub3d.h"
# include "../libft/libft.h"

# define FOV 0.70;

typedef struct s_ray
{
    float   camera_pos_x; // la position du ray sur la plane de caméra
    float   dir_x; // les vecteurs de direction x et y du ray:
    float   dir_y;
    int     map_pos_x; // les positions x et y de la case de la map où le vecteur est situé
    int     map_pos_y;
    float   tile_dist_x; // la distance que le ray doit parcourir entre sa position de depart et la première pos de la map x
    float   tile_dist_y; // la distance que le ray doit parcourir entre sa position de depart et la première pos de la map y
    float   delta_dist_x; // la distance que le ray doit parcourir entre une tile_pos_x et la prochaine intersection x
    float   delta_dist_y;
    int     hit;
    int     side; // mur NS ou EW 
    int     step_x;
    int     step_y;
}   t_ray;

typedef struct s_raycaster
{
    float   player_pos_x;
    float   player_pos_y;
    float   player_dir_x;
    float   player_dir_y;
    float   camera_plane_x;
    float   camera_plane_y;
    t_ray   *ray;
}   t_raycaster;


int ft_init_raycasting(t_game *game, t_raycaster *raycaster);
int ft_dda_loop(t_game *game, t_raycaster *raycaster);

#endif