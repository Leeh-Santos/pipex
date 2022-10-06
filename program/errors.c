/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:38:28 by learodri          #+#    #+#             */
/*   Updated: 2022/10/06 20:43:41 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	boom(char	*str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	not_found(char	*str, char **cmd)
{
	perror(str);
	free_split(cmd);
	exit(EXIT_FAILURE);
}

void	file_not_found(char	*str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_split(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}
