/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:40:12 by learodri          #+#    #+#             */
/*   Updated: 2022/09/19 20:59:14 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];
	int	fd[2];
	int	status;

	errno = 0;
	if (ac != 5)
		usage();
	if (pipe(pipefd) < 0)
		terminate(NULL);
	child_one(pipefd, fd, av, envp);
	child_two(pipefd, fd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}