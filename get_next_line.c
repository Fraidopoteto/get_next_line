/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:17:53 by jschmunk          #+#    #+#             */
/*   Updated: 2026/10/29 10:40:15 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_readbuff(fd, save);
	if (!save)
		return (NULL);
	line = ft_getline(save);
	save = ft_restofline(save);
	return (line);
}

char	*ft_readbuff(int fd, char *save)
{
	char	*buffer;
	int		byts_read;

	byts_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (byts_read != 0 && !ft_strchr(save, '\n'))
	{
		byts_read = read(fd, buffer, BUFFER_SIZE);
		if (byts_read == -1)
		{
			free(save);
			free (buffer);
			return (NULL);
		}
		buffer[byts_read] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*ft_getline(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc((i + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_restofline(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(save) - i + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i++;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}
