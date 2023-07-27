#include "main.h"

/**
 * aux_help_env_info - Help information for the builtin env
 * Return: no return
 */
void aux_help_env_info(void)
{
	char *helper = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, helper, _strlen(helper));

}
/**
 * aux_help_setenv_info - Help information for the builtin setenv
 * Return: no return
 */
void aux_help_setenv_info(void)
{

	char *helper = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "int replace)\n\t";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, helper, _strlen(helper));
}
/**
 * aux_help_unsetenv_info - Help information for the builtin unsetenv
 * Return: no return
 */
void aux_help_unsetenv_info(void)
{
	char *helper = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, helper, _strlen(helper));
}


/**
 * aux_help_general_info - Entry poin for help info for the help builtin
 * Return: no return
 */
void aux_help_general_info(void)
{
	char *helper = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "unsetenv [variable]\n";
	write(STDOUT_FILENO, helper, _strlen(helper));
}
/**
 * aux_help_exit_info - Help information fot the builint exit
 * Return: no return
 */
void aux_help_exit_info(void)
{
	char *helper = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, helper, _strlen(helper));
	helper = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, helper, _strlen(helper));
}
