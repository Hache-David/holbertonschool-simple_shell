#include "main.h"
/**
 * PATH_analyse - Function that check if the command in 'buffer' exists
 *		in the directories listed in the PATH environment variable.
 * @buffer: The command to check
 *
 * Return: 1 if the command is found , 0 otherwise
*/
int PATH_analyse(char *buffer)
{
	DIR *directory;
	struct dirent *entry;
	char *path_dirs = getenv("PATH");
	char *path_copy, *dir;

	path_copy = strdup(path_dirs);
	if (path_copy == NULL)
	{
		perror("strdup");
		return (0); }
	if (strncmp(buffer, "\\", 1))
	{
		free(path_copy);
		return (1); }
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		directory = opendir(dir);
		if (directory == NULL)
		{
			perror("opendir");
			free(path_copy);
			return (0); }

		while ((entry = readdir(directory)) != NULL)
		{
			if (strcmp(entry->d_name, buffer) == 0)
			{
				closedir(directory);
				free(path_copy);
				return (1);
			}
		}
		closedir(directory);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}
