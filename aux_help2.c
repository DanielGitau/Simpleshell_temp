#include "main.h"

/**
 * aux_help_info - Help information for the builtin help.
 * Return: no return
 */
void aux_help_info(void)
{
	char *helper = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, helper, _strlen(helper));
}
/**
 * aux_help_alias_info - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_alias_info(void)
{
	char *helper = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, helper, _strlen(helper));
}
/**
 * aux_help_cd_info - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_cd_info(void)
{
	char *helper = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, helper, _strlen(helper));
}
