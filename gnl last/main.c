/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:21:55 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/25 11:21:55 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*str;

	if (argc > 2)
		printf("Too many arguments.\n");
	else if (argc < 2)
		printf("File name missing.\n");
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Cannot read file.\n");
			return (1);
		}
		str = get_next_line(fd);
		if (!str)
			printf("Nula");
		while (str != NULL)
		{	
			printf("%s", str);
			str = get_next_line(fd);
		}
		if (close(fd) == -1)
		{
			printf("Cannot close file.\n");
			return (1);
		}
	}
	return (0);
}
