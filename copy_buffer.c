#include "main.h"
/**
 * buff_copy - copy entry first word in new string
 *
 * @buffer_copy: empty new string
 * @length: length of the word of the command.
 * @buffer: string contain the command line input.
 * @index: index use in "for" loop.
 *
 * Return: new string contain the first word.
*/
char *buff_copy(char *buffer_copy, int length, char *buffer, int index)
{
	while (buffer[length] != ' ' && buffer[length] != '\0')
		length++;

	buffer_copy = malloc(sizeof(char) * (length + 1));
	if (buffer_copy == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	for (index = 0; index < length; index++)
		buffer_copy[index] = buffer[index];
	buffer_copy[length] = '\0';

	return (buffer_copy);
}
