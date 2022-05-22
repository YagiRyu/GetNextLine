/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-yagi <r-yagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:44:43 by r-yagi            #+#    #+#             */
/*   Updated: 2022/05/22 23:06:58 by r-yagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_malloc_error(char *file_value)
{
	free(file_value);
	return (NULL);
}

static char	*ft_read_file_until_end(int fd)
{
	char	*file_value;
	size_t	i;
	int		rc;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_value = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!file_value)
		return (ft_malloc_error(file_value));
	rc = read(fd, file_value, BUFFER_SIZE);
	if (rc == -1)
		return (ft_malloc_error(file_value));
	return (file_value);
}

char	*get_next_line(int fd)
{
	static char	*static_save;
	char		*file_value;

	file_value = ft_read_file_until_end(fd);
	if (!file_value)
		return (NULL);
	// while (file_char[i] == '\n' || file_char[i])
	// 	i++;
	// free(static_save);
	// static_save = malloc(sizeof(char *) * (i + 1));
	// if (!static_save)
	// {
	// 	free(static_save);
	// 	return (NULL);
	// }
	// while (j < i)
	// {
	// 	static_save[j] = file_char[j];
	// 	j++;
	// }
	return (static_save);
}

int	main(void)
{
	int	fd = open("./text.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	return (0);
}
