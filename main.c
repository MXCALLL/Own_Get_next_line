/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:07:52 by muidbell          #+#    #+#             */
/*   Updated: 2024/11/29 13:08:47 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <time.h>

void f()
{
		system("leaks a.out");
}

int main()
{
    // Start measuring time
    // clock_t start = clock();

    char  *s;
    int fd = open("giant_line.txt", O_RDONLY);
    printf("%d",fd);

    s = get_next_line(fd);
    while (s != NULL)
    {
        printf("%s",s);
        s = get_next_line(fd);
        free(s);
    }

    // Calculate and print execution time
    // clock_t end = clock();
    // double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}