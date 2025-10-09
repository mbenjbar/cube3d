/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:55:36 by imiqor            #+#    #+#             */
/*   Updated: 2025/09/20 16:39:02 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	//line = malloc(i + 1);
	line=ft_gc(i+1,'m');
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_save(char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] && buff[i] == '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	str = malloc((ft_sstrlen(buff) - i) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = '\0';
	free(buff);
	return (str);
}

char	*read_from_file(char *save, int fd)
{
	char	*buff;
	ssize_t	readed;

	readed = 1;
	buff = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		save = ft_sstrjoin(save, buff);
		if (ft_sstrchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd, int flag)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (flag == 1)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = read_from_file(save, fd);
	if (!save)
		return (NULL);
	line = ft_extract_line(save);
	save = clean_save(save);
	if (!line)
		free(save);
	return (line);
}
