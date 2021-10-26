/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:08:36 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/25 21:12:36 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_args	init_args(char **av)
{
	t_args	args;

	args.infile = av[1];
	args.infile_fd = open(args.infile, O_RDONLY);
	if (args.infile_fd < 0)
		ft_exit(1, "Error: wrong filepath\n");
	args.cmd_1 = av[2];
	args.cmd_2 = av[3];
	args.outfile = av[4];
	args.outfile_fd = open(args.outfile, O_RDWR);
	if (args.outfile_fd < 0)
		ft_exit(1, "Error: wrong filepath\n");
	return (args);
}
