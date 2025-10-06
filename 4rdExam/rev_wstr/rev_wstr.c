#include <unistd.h>


int is_space(char c)
{
	if((c <= 13 && c >= 7)|| c == ' ')
		return 1;
	return 0;
}

void print_word(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		write(1,&str[i],1);
		i++;
	}
}
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		write(1,"\n",1);
		return (2);
	}
	else
	{
		int i = 0;
		while(argv[1][i] !='\0')
		{
			i++;
		}
		i--;
		while(&argv[1][i] >=  argv[1])
		{
			if(is_space(argv[1][i]))
			{
				print_word(&argv[1][i+1]);
				argv[1][i] = '\0';
				write(1," ",1);
			}
			i--;
		}
		print_word(&argv[1][i+1]);
		write(1,"\n",1);
	}

}

