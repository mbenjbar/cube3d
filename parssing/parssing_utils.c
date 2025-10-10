/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:53:07 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/10 21:50:09 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_blank(char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

void	check_no_blank_lines_inside_map(char **content, int start)
{
	int	i;
	int	map_started;

	i = start;
	map_started = 0;
	while (content[i])
	{
		if (is_blank(content[i]))
		{
			if (map_started)
			{
				ftt_free(content);
				error_exit("Map contains empty line inside", NULL);
			}
		}
		else
			map_started = 1;
		i++;
	}
}
