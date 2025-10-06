#include <unistd.h>

int is_prime(int nmb)
{
	int nmb_of_div = 0;
	double double_div;
	int int_div;
	int i = 1;
	if (nmb == 0)
		return (0);
	if (nmb == 1)
		return (0);
	if (nmb == 2)
		return (1);
	while(i < nmb)
	{
		double_div = (double) nmb / i;
		int_div = nmb/i;
		if(double_div == int_div)
			nmb_of_div++;
		i++;
	}
	if(nmb_of_div <= 1)
		return (1);
	return (0);
}

int calculate_prime_sum(int nmb)
{
	int sum = 0;
	int i = 0;
	if (nmb == 1)
		return 0;
	while(i <= nmb)
	{
		if(is_prime(i))
			sum = sum + i;
		i++;
	}
	return (sum);
}
int ft_exp(int base,int exp)
{
	int result = 1;
	while(exp)
	{
		result = result * base;
		exp--;
	}
	return result;
}
int ft_strlen(char *str)
{
	int c = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		c++;
		i++;
	}
	return c;
}
int ft_atoi(char *str)
{
	int result = 0;
	int len = ft_strlen(str);
	while(len)
	{
		int digit = str[len-1] - '0';
		result = result + (digit * ft_exp(10,len-1));
		len--;
	}
	return result;
}
void	print_number(int nbr)
{
	if(nbr / 10 == 0)
	{
		char d = '0' + nbr % 10;
		write(1,&d,1);
		return;
	}
	else
	{
		print_number(nbr/10);
		char d = '0' + nbr % 10;
		write(1,&d,1);
	}
}

int main(int argc, char** argv)
{
	int nmb;
	int result;
	if (argc == 2)
	{
		nmb = ft_atoi(argv[1]);
		if(nmb > 0)
		{
			result = calculate_prime_sum(nmb);
			print_number(result);
			write(1,"\n",1);
		}
		else
		{
			write(1,"0",1);
			write(1,"\n",1);
		}
	}
	else
	{
		write(1,"0",1);
		write(1,"\n",1);
	}
}


