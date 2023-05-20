#include <stdio.h>

int copy_str(char str[100],char copy_str[100])
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		copy_str[i] = str[i];
	}
	copy_str[i] = '\0';

	return (0);
}
