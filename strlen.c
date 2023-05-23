/**
 * my_strlen - my implementation.
 * @s: str to count
 */

unsigned int my_strlen(const char *s)
{
	unsigned int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
