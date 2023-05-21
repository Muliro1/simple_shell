/**
 * copy_str - copies strings
 * Return: start
 * @source: str to be copied
 * @destination: duplicate str
 */

char *copy_str(char *destination, char *source)
{
	char *start = destination;

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}
