/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:35 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/27 14:20:16 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	cmnd1(t_prog *prog, int fd_pipe);
static int	cmnd2(t_prog *prog, int fd_pipe);
static void	child_proccess(t_prog prog, int fd_read, int fd_write, char **args);
static int	perent_procces(t_prog *prog, pid_t pid, int close_fd);

int	main(int ac, char **av, char **env)
{
	t_prog	prog;

	if (!init_prog(&prog))
		return (0);
	if (!parse(&prog, ac, av, env))
		return (free_prog(&prog), 0);
	if (pipe(prog.fd_pipe) == -1)
		return (free_prog(&prog), perror("Pipe error"), 1);
	if (!cmnd1(&prog, prog.fd_pipe[1]))
		return (free_prog(&prog), 0);
	close(prog.fd_file1);
	if (!cmnd2(&prog, prog.fd_pipe[0]))
		return (free_prog(&prog), 0);
	free_prog(&prog);
	return (0);
}

static int	cmnd1(t_prog *prog, int fd_pipe)
{
	pid_t	pid;

	if (!prog)
		return (0);
	pid = fork();
	if (pid == -1)
		return (perror("Fork error"), 0);
	if (pid == 0)
		child_proccess(*prog, prog->fd_file1, fd_pipe, prog->commands[0]->args);
	else
	{
		if (!perent_procces(prog, pid, fd_pipe))
			return (0);
	}
	return (1);
}

static int	cmnd2(t_prog *prog, int fd_pipe)
{
	pid_t	pid;

	if (!prog)
		return (0);
	pid = fork();
	if (pid == -1)
		return (perror("Fork error"), 0);
	if (pid == 0)
		child_proccess(*prog, fd_pipe, prog->fd_file2, prog->commands[1]->args);
	else
	{
		if (!perent_procces(prog, pid, fd_pipe))
			return (0);
	}
	return (1);
}

static void	child_proccess(t_prog prog, int fd_read, int fd_write, char **args)
{
	if (!args || !*args)
	{
		free_prog(&prog);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_read, 0) == -1 || dup2(fd_write, 1) == -1)
	{
		free_prog(&prog);
		perror("Dup2 error");
		exit(EXIT_FAILURE);
	}
	close_fd(&prog);
	if (execve(*args, args, NULL) == -1)
	{
		free_prog(&prog);
		perror("Execve failed");
		exit(EXIT_FAILURE);
	}
}

static int	perent_procces(t_prog *prog, pid_t pid, int close_fd)
{
	int		status;
	pid_t	child_pid;

	if (!prog)
		return (0);
	close(close_fd);
	child_pid = waitpid(pid, &status, 0);
	if (child_pid == -1)
		return (perror("Waitpid error"), 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			return (0);
	}
	return (1);
}
