#include "main.h"

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	struct stat buffer;
	int switch_1 = 0, switch_2 = 0;
	pid_t child_p;

	if (argv)
	{
		/* get the command */
		command = argv[0];
		printf("in the execute func >>>>> %s \n", command);
		if (stat(command, &buffer) == 0)
		{
			switch_1 = 1;
			printf("In the absolute_path condition>>\n");
		}
		/* generate the path to this command before passing it to execve */
		else if (actual_command == get_location(command))
		{
			switch_1 = 1;
			switch_2 = 1;
			printf("In the path_finding condition>>\n");
			command = actual_command;
		}
		else
		{
			 perror("Error");
		}

		/*actual_command = get_location(argv[0]);*/
		if (switch_1)
		{
			/* execute the command with execve */
			child_p = fork();
			if (child_p == 0)
			{
				execve(command, argv, NULL);
			}
			wait(NULL);
			if (switch_2)
			{
				free(command);
			}
		}
	}

}
