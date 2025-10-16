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

unsigned int get_color(t_game *game, int row)
{
	char	*color;
    int index;

    index = game->textures->index;

	if (game->textures->column < 0 || 
        game->textures->column > game->textures[index].width || row < 0
        || row > game->textures[index].height)
		return (0);
	color = game->textures[index].address
        + (row * game->textures[index].lenght) + game->textures->column
		* (game->textures[index].bpp / 8);
	return (*(unsigned int *)color);
}

void get_column(t_game *game)
{
    int index;

    index = game->textures->index;
    if (game->flag)
		game->textures->column = (int)game->dist->h_hitx % TILE_SIZE
			* (game->textures[index].height / TILE_SIZE);
	if (!game->flag)
		game->textures->column = (int)game->dist->v_hity % TILE_SIZE
			* (game->textures[index].height / TILE_SIZE);
}

int get_index(t_game *game)
{
    get_column(game);
    if (up(game->cur_angle) && game->flag)
        return (3);
    else if (down(game->cur_angle) && game->flag)
        return (1);
    else if (right(game->cur_angle) && !game->flag)
        return (0);
    else
        return (2);
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
    int             row;
    
    start = (WINDOW_HEIGHT / 2) - (game->height_wall / 2);
    end = start + game->height_wall;
    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        if (i >= start && i <= end)
        {
            game->textures->index = get_index(game);
            row = (i - start) * (game->textures[game->textures->index].height
					/ game->height_wall);
            put_pix(game, i, get_color(game, row));
        }
        else if (i < start)
            put_pix(game, i, game->map->ceiling_color);
        else
            put_pix(game, i, game->map->floor_color);
        i++;
    }
}
