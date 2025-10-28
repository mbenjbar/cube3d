/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:15:39 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/28 15:49:15 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	up(double angle)
{
	return ((angle < M_PI));
}

int	down(double angle)
{
	return (angle > M_PI);
}

int	right(double angle)
{
	return ((angle < 0.5 * M_PI) || (angle > 1.5 * M_PI));
}

int	left(double angle)
{
	return ((angle > 0.5 * M_PI) && (angle < 1.5 * M_PI));
}
