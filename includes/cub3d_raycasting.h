#ifndef CUB3D_RAYCASTING
# define CUB3D_RAYCASTING
# include "cub3d.h"
# include "../libft/libft.h"

# include <math.h>
# include <limits.h>

# define FOV 0.70;

typedef struct s_line
{
    float   wall_hit_x;
    int     height;
    int     bottom;
    int     top;
    int     texture_x;
    int     texture_y;
    float   texture_pos;
    float   step;
}   t_line;

typedef struct s_ray
{
    float   camera_pos_x; // la position du ray sur la plane de caméra
    float   dir_x; // les vecteurs de direction x et y du ray
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
    float   ray_to_wall_dist;
}   t_ray;

typedef struct s_raycaster
{
    float   player_pos_x;
    float   player_pos_y;
    float   player_dir_x; // -1 pour N, 1 pour S, 0 pour E/W
    float   player_dir_y; // -1 pour W, 1 pour E, 0 pour S/N
    float   camera_plane_x; // 0.66 pour E, -0.66 pour W, 0 pour S/N
    float   camera_plane_y; // 0.66 pour N, -0.66 pour S, 0 pour E/W
    t_ray   *ray;
    t_line  *line;
}   t_raycaster;



void        ft_dda_loop(t_game *game, t_raycaster *raycaster);
t_raycaster *ft_init_raycaster(t_game *game, t_raycaster *raycaster);
t_ray       *ft_init_ray(void);
t_line      *ft_init_line(void);
void        ft_get_wall_infos(t_raycaster *raycaster);
void        ft_get_texture_pos(t_raycaster *raycaster);
void        ft_draw_imgs(t_game *game, t_raycaster *raycaster);

 /* TESTS */
void    ft_draw_test_line(t_game *game, t_raycaster *raycaster);

#endif