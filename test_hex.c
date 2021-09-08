#include <stdio.h>

int main()
{
	char	*s;
	char	s1[4];
	int		i;
	int		x;
	int		z;

	i = 0;
	s = "0123456789abcdef";
	x = 852;
	z = x;
	while (z)
	{
		z = z / 16;
		i++;
	}
	z = i;
	s1[z] = '\0';
	while (z)
	{
		z--;
		s1[z] = s[(x % 16)];
		printf("%c ", s1[z]);
		x = x / 16;
		//printf("%d\n", x);
	}
	printf("\nHexadecimal: %s\n", s1);
	return (0);
}
