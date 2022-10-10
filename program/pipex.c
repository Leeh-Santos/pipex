/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:29:15 by learodri          #+#    #+#             */
/*   Updated: 2022/10/10 19:15:21 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kid1(int *pipefd, int *filefd, char **av, char **envp)
{
	char	**cmd1;
	pid_t	id;

	id = fork();
	if (id < 0)
		boom("not able to fork, try a spoon");
	if (id == 0)
	{
		filefd[0] = open(av[1], O_RDONLY);
		if (filefd[0] < 0)
			file_not_found("file1 error");
		cmd1 = ft_split(av[2], ' ');
		close(pipefd[0]);
		if (dup2(filefd[0], STDIN_FILENO) < 0
			|| dup2(pipefd[1], STDOUT_FILENO) < 0)
			boom("dup2 problem dude, Im sorry");
		if (cmd1[0] && find_path(cmd1[0], envp))
		{
			execve(find_path(cmd1[0], envp), cmd1, envp);
			free_split(cmd1);
		}
		else
			not_found("cmd1 error ", cmd1);
	}
}

void	kid2(int *pipefd, int *filefd, char **av, char **envp)
{
	char	**cmd2;
	pid_t	id;

	id = fork();
	if (id < 0)
		boom("not able to fork, try a spoon");
	if (id == 0)
	{
		filefd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (filefd[1] < 0)
			file_not_found("file2 error");
		cmd2 = ft_split(av[3], ' ');
		close(pipefd[1]);
		if (dup2(filefd[1], STDOUT_FILENO) < 0
			|| dup2(pipefd[0], STDIN_FILENO) < 0)
			boom("dup2 problem, try again");
		if (cmd2[0] && find_path(cmd2[0], envp))
		{
			execve(find_path(cmd2[0], envp), cmd2, envp);
			free_split(cmd2);
		}
		else
			not_found("cmd2 error ", cmd2);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	filefd[2];
	int	pipefd[2];
	int	kid_status;

	if (ac != 5)
	{
		write(2, "goes like this: ./pipex file1 cmd1 cmd2 file2", 46);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) < 0)
		boom("pipe failed bro, try again");
	kid1(pipefd, filefd, av, envp);
	kid2(pipefd, filefd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &kid_status, 0);
	waitpid(-1, &kid_status, 0);
	return (0);
}
