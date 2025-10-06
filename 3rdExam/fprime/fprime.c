#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_prime_fact(int nmb)
{
	int initial_nmb = nmb;
	int i = 2;
	int result = 1;
	if(nmb == 1)
	{
		printf("1\n");
		return;
	}
	if(nmb <= 0)
	{
		write(1,"\n",1);
		return;
	}
	while(i <= nmb)
	{
		if(nmb%i == 0)
		{
			result = result * i;
			if(result == initial_nmb || i== initial_nmb)
			{
				printf("%d\n",i);
				break;
			}
			else
			printf("%d*",i);
			nmb = nmb / i;
		}
		else
			i++;
	}
}

int main(int argc,char **argv)
{
	if(argc == 2)
	{
		char *str_nmb = argv[1];
		int nmb = atoi(str_nmb);
		print_prime_fact(nmb);
	}
	else
	{
		write(1,"\n",1);
		return(2);
	}
}
