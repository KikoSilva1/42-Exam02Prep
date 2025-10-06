#include <unistd.h>

int ft_exp(int base,int exp)
{
	int result = 1;
	while (exp)
	{
		result = result * base;
		exp--;
	}
	return result;
}
void	print_bits(unsigned char octet)
{
	unsigned char mask;
	int i = 8;
	while(i > 0)
	{
		mask = 1 << (i-1);
		if((mask & octet) == ft_exp(2,i-1))
			write(1,"1",1);
		else
			write(1,"0",1);
		i--;
	}
}
