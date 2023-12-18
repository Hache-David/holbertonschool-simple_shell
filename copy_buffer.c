#include "main.h"

char *buff_copy(char *buffer_copy, int length, char *buffer , int index)
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
