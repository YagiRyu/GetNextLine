/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-yagi <r-yagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:44:43 by r-yagi            #+#    #+#             */
/*   Updated: 2022/05/21 21:17:15 by r-yagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*file_char;
	int		rc;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	file_char = malloc(BUFFER_SIZE + 1);
	if (!file_char)
	{
		free(file_char);
		return (NULL);
	}
	rc = read(fd, file_char, BUFFER_SIZE);
	if (rc == -1)
		return (NULL);
	return (file_char);
}

int	main(void)
{
	int	fd = open("./text.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	return (0);
}
