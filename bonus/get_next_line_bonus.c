/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_spe(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] && str[i] == c)
		i++;
	return (i);
}

char	*free_and_return_null(char	**m1, char **m2, char **m3, char **m4)
{
	if (m1 && *m1)
	{
		free(*m1);
		*m1 = NULL;
	}
	if (m2 && *m2)
	{
		free(*m2);
		*m2 = NULL;
	}
	if (m3 && *m3)
	{
		free(*m3);
		*m3 = NULL;
	}
	if (m4 && *m4)
	{
		free(*m4);
		*m4 = NULL;
	}
	return (NULL);
}

void	*ft_memcpy_spe(void *dst, const void *src, int *i, char c)
{
	char	*ddst;
	char	*ssrc;

	*i = 0;
	if (!dst && !src)
		return (dst);
	ddst = (char *)dst;
	ssrc = (char *)src;
	while (ssrc[*i] && ssrc[*i] != c)
	{
		ddst[*i] = ssrc[*i];
		(*i)++;
	}
	ddst[*i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*line;
	static char	*tp[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (free_and_return_null(&line, &tp[fd], NULL, NULL));
	line[0] = '\0';
	if (!tp[fd])
	{
		tp[fd] = malloc(1);
		if (!tp[fd])
			return (free_and_return_null(&line, &tp[fd], NULL, NULL));
		tp[fd][0] = '\0';
	}
	if (tp[fd] && (ft_strlen_spe(tp[fd], '\n') != ft_strlen_spe(tp[fd], '\0')))
		return (deal_with_temp_that_still_holds_nl(&tp[fd], line));
	bytes_read = 1;
	line = while_loop(fd, &bytes_read, &line, &tp[fd]);
	if (!line)
		return (free_and_return_null(&line, &tp[fd], NULL, NULL));
	return (finishers(bytes_read, &tp[fd], line));
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	
	fd1 = open("x.txt", O_RDONLY);
	fd2 = open("x2.txt", O_RDONLY);

	char *res = get_next_line(fd1);
	//int	i = 1;
	printf("gnl1_01 is : |%s|\n", res);
	// while (res)
	// {
	// 	free(res);
	// 	res = get_next_line(fd1);
	// 	i++;
	// 	printf("gnl%d is : |%s|\n", i, res);
	// }
	// free(res);
	

	printf("\n\n\n");

	char *res2 = get_next_line(fd2);
	//i = 2;
	printf("gnl2_01 is : |%s|\n", res2);
	// while (res2)
	// {
	// 	free(res2);
	// 	res2 = get_next_line(fd2);
	// 	i++;
	// 	printf("gnl%d is : |%s|\n", i, res2);
	// }
	// free(res2);

	res = get_next_line(fd1);
	printf("gnl1_02 is : |%s|\n", res);

	res2 = get_next_line(fd2);
	printf("gnl2_02 is : |%s|\n", res2);

	close(fd1);
	close(fd2);
}
*/