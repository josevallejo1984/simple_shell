#include "shell.h"

/**
 * _execev - executa a external funtion
 * @argvs: arguments
 * Return: double pointer to string
 */
int _execev(char **argvs)
{
	pid_t c_pid, pid;
	int status;
	char *path = "/bin/";

	/* allocated memory for double pointer */
	char *buf = (char *)malloc(sizeof(char) * strlen(argvs[0]) + 6);

	if (buf == NULL)
		return (-1);

	_strcat(buf, path);
	_strcat(buf, argvs[0]);

	/* forking the process for exce call funtion */
	c_pid = fork();
	if (c_pid == 0)
	{
		if (execve(buf, argvs, NULL) == -1)
			perror("Error: execve");
	}
	else if (c_pid > 0)
	{
		pid = wait(&status);
		if (pid < 0)
		{
			perror("wait");
			_exit(1);
		}
	}
	else
	{
		perror("fork failed");
		_exit(1);
	}
	return (0);
}

