/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-yagi <r-yagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:44:43 by r-yagi            #+#    #+#             */
/*   Updated: 2022/06/01 23:29:37 by r-yagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int		rd;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		save = ft_free(save, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	line = "";
// 	fd = open("./text.txt", O_RDONLY);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	return (0);
// }
