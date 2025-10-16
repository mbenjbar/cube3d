/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/16 21:28:53 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	exiter(void	*param)
{
	t_game *game;

	game = (t_game *)param;
	error_exit(NULL, game);
	return(0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;
			
	memset(&map, 0, sizeof(map));
	memset(&game, 0, sizeof(game));
	parssing(&map, argc, argv);
	//          print all information i got from parssing to ensure everything is good  //

	printf("%d\n", map.line_count);
	printf("%d\n", map.grid_lines_count);
	printf("%d\n", map.has_ceiling);
	printf("%d\n", map.has_floor);
	printf("%s\n", map.ea);
	printf("%s\n", map.no);
	printf("%s\n", map.so);
	printf("%s\n", map.we);
	printf("%d\n", map.floor_color);
	printf("%d\n", map.ceiling_color);
	printf("%d\n", map.map_width);
	printf("%c\n", map.player_dir);
	printf("%f\n", map.player_x);
	printf("%f\n", map.player_y);
	int i = 0;
	while (map.map_two_d[i])
	{
		printf("%s", map.map_two_d[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (map.map_grid[i])
	{
		printf("%s\n", map.map_grid[i]);
		i++;
	}

	// 				everything now is fine with parssing so let's go		//
	
	game.map = &map;
	game_init(&game);
	rendering(&game);
	mlx_hook(game.win, 17, 0, exiter, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	
	// mlx_loop_hook(game.mlx, render_frame, &game);

	mlx_loop(game.mlx);
	ft_gc(0, 'f');
	return (0);
}
