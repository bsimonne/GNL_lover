/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_replace_malloc_with_fake_malloc.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:01:27 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/21 02:04:52 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_tests_utils.h"

int	main(int argc, char *argv[])
{
	int 	fd_test_me;
	char	*line;
	int		result;

	line = NULL;
	result = 1;
	if (argc != 2)
	{
		my_ft_putstr_fd("failed to provide the file to be opened as arg\n", 2);
		return (0);
	}
	if((fd_test_me = open(argv[1], O_RDONLY)) == -1)
	{
		my_ft_putstr_fd("failed to open", 2);
		my_ft_putstr_fd(argv[1], 2);
		my_ft_putstr_fd("filedescriptor.\n", 2);
		return (0);
	}
	while (result > 0)
	{
		result = get_next_line(fd_test_me, &line);
		if (result != -1)
		{
			my_ft_putstr_fd(line, 1);
			my_ft_putchar_fd('\n', 1);
		}
		free(line);
	}
	assert(result == -1);
	close(fd_test_me);
	return (0);
}
