/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:50:48 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/09 22:24:42 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "./parssing/get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>

#define TILE_SIZE 200
# define M_PI 3.14159265358979323846
# define ESC_KEY 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define SPACE 32
#define LEFT_ARROW  65361   // XK_Left
#define RIGHT_ARROW 65363   // XK_Right
typedef struct s_state
{
	int			i;
	int			cw;
	int			start;
	int			end;
	int			k;
	char		**two_d;
}				t_state;

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}				t_gc;

typedef struct s_map
{
	int			line_count;
	int			grid_lines_count; //lines count of the pure map
	char		**map_two_d;//this the entire map file including textures and colors
	char		**map_grid;//this is the pure map
	float		player_x;
	float		player_y;
	char		player_dir;
	int			map_width;//width of pure map
	int			map_height;//height of pure map
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int has_no, has_so, has_we, has_ea;
	int has_floor, has_ceiling;
	int floor_r, floor_g, floor_b;
	int ceiling_r, ceiling_g, ceiling_b;
}				t_map;

typedef struct s_game
{
	void *mlx; // MLX connection
	void *win; // Window
	int			win_width;
	int			win_height;
	float angle; //depends on what direction the player is facing
	float cos_angle;
	float sin_angle;
	float ray_x;
	float ray_y;
	float angle_speed;
	float move_speed;
	bool  key_up;
    bool  key_down;
    bool  key_left;
    bool  key_right;
    bool  rot_left;
    bool  rot_right;
	t_map map; // Map data you already parsed
	 void    *img;           // ↖ your drawing surface
    char    *data_addr;     // ↖ pointer to its pixel data
    int     bpp;            // ↖ bits per pixel
    int     line_len;       // ↖ bytes per scanline
    int     endian;   
	double		player_x;
	double		player_y;
	double dir_x; // Player direction vector (for raycasting)
	double		dir_y;
	double plane_x; // 2D camera plane
	double		plane_y;
	void		*wall_no;
	void		*wall_so;
	void		*wall_we;
	void		*wall_ea;
}				t_game;
/******  SPLIT   ****** */
char			*ftt_free(char **arr);
char			*ft_strncopy(char *str, int start, int end);
int				count_word(char *args, char sep);
void			init_state(t_state *state, char *args, char sep);
char			**split_lines(char *args, char sep);
/******  TEXTURES   ****** */
void			check_path(char *path);
char			*trim_spaces_end(char *str);
void			assign_texture(t_map *map, char *line, char **dest, char *id);
void			parse_textures_and_colors(char **lines, int *i, t_map *map);
/******  COLORS   ****** */
int				parse_rgb(char *line, int *r, int *g, int *b);
void			set_floor_color(t_map *map, char *line);
void			set_ceiling_color(t_map *map, char *line);
/******  ARGV1  ****** */
void			parssing(t_map *map, int argc, char **argv);
void			check_map_content(char **content, t_map *map);
void			check_if_file_exist(char *argv);
void			check_extention(char *argv);
void			check_argc(int argc);
/******  MAP_CONTENT  ****** */
int				nbr_of_lines(char *filename);
void			get_cub_content(char *argv, t_map *map);
/******  PARSE_MAP  ****** */
int				count_map_lines(char **content, int start);
void			trim_newline(char *str);
int				contains_zero(char *line);
void			store_map_lines(char **content, int start, t_map *map);
int				is_valid_map_char(char c);
void			validate_map_chars(t_map *map);
void			validate_walls(t_map *map);
int				ft_check_is_player(char c);
void			parse_map(t_map *map, char **content, int start);
/******  UTILS  ****** */
char			*ft_ssstrjoin(char *save, char *buff);
int				ft_strcmp(char *s1, char *s2);
int				ft_strcmp(char *s1, char *s2);
void			error_exit(char *msg);
int				is_blank(char *s);
void			check_no_blank_lines_inside_map(char **content, int start);
char			*ftt_strdup(const char *s1);
/******  GARBAGE_COLLECTOR ****** */
void			add(t_gc **gc, t_gc *new);
t_gc			*create(void *ptr);
void			fr_ee(t_gc *gc);
void			*ft_gc(size_t n, char flag);

/******  DRAW_MAP ****** */
void	draw_map_and_player(t_game *game, t_map *map);
void	draw_tile(t_game *g, int x, int y, int color);
void	draw_player(t_game *game, t_map *map);
void	put_pixel(t_game *g, int x, int y, int color);
int	render_frame(t_game *game);
/******  LOAD_IMAGES ****** */
void	image_failed_to_load(t_game *game);
void	load_images(t_game *game, t_map *map);
/******  LOAD_IMAGES ****** */
void	init_game(t_game *game, t_map *map);


#endif