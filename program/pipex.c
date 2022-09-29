/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:29:15 by learodri          #+#    #+#             */
/*   Updated: 2022/09/29 21:55:45 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	filefd[2];
	int	pipefd[2];

	if (av != 5)
	{
		write(2, "goes like this: ./pipex file1 cmd1 cmd2 file2", 46);
		exit(EXIT_FAILURE);
	}
	
	if (pipe(pipefd) < 0)
		boom("pipefailed");
		
	return (0);
}
