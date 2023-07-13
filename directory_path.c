#include "main.h"
char *directory_path(int command_length, char *path_token, char *command)
{
	char *file_path;
	int directory_length;
	
	/* Get the length of the directory*/
	directory_length = _strlen(path_token);
	/* allocate memory for storing the command name together with the directory name */
	file_path = malloc(command_length + directory_length + 2); /* NB: we added 2 for the slash and null character we will introduce in the full command */
	/* to build the path for the command, let's copy the directory path and concatenate the command to it */
	_strcpy(file_path, path_token);
	_strcat(file_path, "/");
	_strcat(file_path, command);
	_strcat(file_path, "\0");

	return (file_path);
}
