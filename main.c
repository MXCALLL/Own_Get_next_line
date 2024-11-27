/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:07:52 by muidbell          #+#    #+#             */
/*   Updated: 2024/11/27 16:13:52 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// void f()
// {
// 		system("leaks a.out");
// }

int main()
{
	char  *s;
	int fd = open("test.txt", O_RDWR);
	// write(fd, "hh\nhhh", 7);
	// lseek(fd, 0, SEEK_SET);

	s = get_next_line(fd);
	printf("%s",s);
	free(s);

	s = get_next_line(fd);
	printf("%s",s);
	free(s);
		s = get_next_line(fd);
	printf("%s",s);
	free(s);

	s = get_next_line(fd);
	printf("%s",s);
	free(s);

	// free(s);
	// atexit(f);
	return 0;
}