/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:06:11 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/16 22:00:57 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void get_column(t_game *game)
{
    int index;

    index = game->text_index;
    if (game->flag)
		game->text_column = (int)game->dist->h_hitx % TILE_SIZE
			* (game->textures[index].width / TILE_SIZE);
	if (!game->flag)
		game->text_column = (int)game->dist->v_hity % TILE_SIZE
			* (game->textures[index].width / TILE_SIZE);
}

unsigned int get_color(t_game *game, int row)
{
	char	*color;
    int     index;

    index = game->text_index;
	if (game->text_column < 0 || 
        game->text_column > game->textures[index].width || row < 0
        || row > game->textures[index].height)
		return (0);
	color = game->textures[index].address
        + (row * game->textures[index].lenght) + game->text_column
		* (game->textures[index].bpp / 8);
	return (*(unsigned int *)color);
}

int get_index(t_game *game)
{
    if (game->flag) // horizontal wall
    {
        if (up(game->cur_angle))
            return 3; // north
        else
            return 1; // south
    }
    else // vertical wall
    {
        if (right(game->cur_angle))
            return 0; // east
        else
            return 2; // west
    }
}

void    put_pix(t_game *game, int i, unsigned int color)
{
    char *address;

    address = game->data_addr + (i * game->line_len) + (game->cur_column * (game->bpp / 8));
    *(unsigned int *)address = color;
}

void    draw(t_game *game)
{
    int             start;
    int             end;
    int             i;
    unsigned int    color;
    int             row;
    
    start = (WINDOW_HEIGHT / 2) - (game->height_wall / 2);
    // printf("%lf\n", game->height_wall);
    end = start + game->height_wall;
    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        if (i >= start && i <= end)
        {
            game->text_index = get_index(game);
            // printf("%d\n", game->text_index);
            get_column(game);
            // printf("%d\n", game->text_column);
            row = (i - start) * (game->textures[game->text_index].height
					/ game->height_wall);
            // printf("%d\n", row);
            color = get_color(game, row);
            put_pix(game, i, color);
        }
        else if (i < start)
            put_pix(game, i, game->map->ceiling_color);
        else
            put_pix(game, i, game->map->floor_color);
        i++;
    }
}
