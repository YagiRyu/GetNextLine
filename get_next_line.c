/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-yagi <r-yagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:44:43 by r-yagi            #+#    #+#             */
/*   Updated: 2022/06/07 16:55:46 by r-yagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *save, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(save, buf);
	free(save);
	return (tmp);
}

char	*ft_content_save(char *save)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(save) - i + 1), sizeof(char));
	i++;
	while (save[i])
		line[j++] = save[i++];
	free(save);
	return (line);
}

char	*ft_read_until_eof_or_return(char *save)
{
	size_t	i;
	char	*buf;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	buf = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		buf[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		buf[i++] = '\n';
	return (buf);
}

char	*ft_read(int fd, char *save)
{
	char	*buf;
	int		read_file;

	if (!save)
		save = ft_calloc(1, 1);
	read_file = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (read_file > 0)
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if (read_file == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_file] = '\0';
		save = ft_free(save, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_read_until_eof_or_return(save);
	save = ft_content_save(save);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("./text.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
