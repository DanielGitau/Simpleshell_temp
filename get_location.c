#include "main.h"
/**
 * get_location - Retrieves the location of a command executable.
 * @command: The command for which the location,
 * of the executable is retrieved.
 * Return: Returns the full path of the command executable
 * as a dynamically allocated string.
 * If the executable is not found or an error occurs,
 * it returns NULL.
 * **/
char *get_location(char *command)
{
	char *path, *path_token, *file_path, *path_copy;
	int command_length;
	struct stat buffer;

	path = getenv("PATH");
	path_copy = _strdup(path);
	command_length = _strlen(command);
	/* Let's break down the path variable and get all the directories available*/
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		/*
		 *  allocate memory for storing the command_path and build
		 *  the path for the command we call the directory_path function
		 */
		file_path = directory_path(command_length, path_token, command);
		/*
		 * let's test if this file path actually exists and return
		 * it if it does, otherwise try the next directory
		 */
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
		/* free up the file_path memory so we can check for another path*/
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	/*
	 * if we don't get any file_path that exists for the command,
	 * we return NULL but we need to free up memory for path_copy
	 */
	free(path_copy);
	return (NULL);
}
