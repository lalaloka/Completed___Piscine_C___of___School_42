/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

int		ft_cat(int argc, char **argv)
{
	int	i;

	g_progname = *argv;
	i = 0;
	while (++i < argc)
	{
		if (argc < 2 || argv[i][0] == '-')
			ft_display_file(argv[0]);
		else
			ft_display_file(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}
