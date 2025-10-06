#include <unistd.h>
int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return i;
}
void print_number(int nmb)
{
	int digit;
	char char_digit;
	if(nmb/10 == 0)
	{
		digit = nmb%10;
		char_digit = '0' + digit;
		write(1,&char_digit,1);
		return;
	}
	else
	{
		print_number(nmb/10);
		digit = nmb%10;
		char_digit = '0' + digit;
		write(1,&char_digit,1);
	}
}
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
int ft_atoi(char *str)
{
	int result = 0;
	int size = ft_strlen(str);
	int i = 0;
	while(size)
	{
		result = result + ((str[i] - '0') * ft_exp(10,size-1));
		size--;
		i++;
	}
	return result;
}
int main(int argc, char**argv)
{
	if(argc == 2)
	{
		char *str_nmb = argv[1];
		int nmb = ft_atoi(str_nmb);
		int size = ft_strlen(str_nmb);
		int i = 1;
		int result;
		while (i <= 9)
		{
			result = i * nmb;
			print_number(i);
			write(1," ",1);
			write(1,"x",1);
			write(1," ",1);
			write(1,str_nmb,size);
			write(1," ",1);
			write(1,"=",1);
			write(1," ",1);
			print_number(result);
			write(1,"\n",1);
			i++;
		}
	}
	else
	{
		write(1,"\n",1);
		return(2);
	}
}
