/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-yagi <r-yagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:44:43 by r-yagi            #+#    #+#             */
/*   Updated: 2022/05/24 21:30:52 by r-yagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_malloc_error(char *buf)
{
	free(buf);
	return (NULL);
}

static char	*ft_read_file_until_end(int fd)
{
	char	*buf;
	size_t	i;
	int		rc;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (ft_malloc_error(buf));
	rc = read(fd, buf, BUFFER_SIZE);
	if (rc == -1)
		return (ft_malloc_error(buf));
	if (*buf == '\0')
		buf = ft_calloc(1, sizeof(char));
	return (buf);
}

static char	ft_join_line_and_save(char *line, char *save)
{
	char	*tmp;
	char	*newline_ptr;

	newline_ptr = ft_strchr(save, '\n');
	if (!newline_ptr)
	{
		tmp = line;
		line = save;
		save = NULL;
		free(tmp);
	}
	else
	{
		tmp = line;
	}
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*line;
	size_t		i;

	i = 0;
	line = NULL;
	buf = ft_read_file_until_end(fd);
	if (!buf)
		return (NULL);
	if (save)

	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("./text.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) > 0)
// 	{
// 		printf("%s\n", line);
// 	}
// 	return (0);
// }
