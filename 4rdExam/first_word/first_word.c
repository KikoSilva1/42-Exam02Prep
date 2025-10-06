#include <unistd.h>

int is_space(char c)
{
	if((c <= 13 && c >= 7)|| c == ' ')
		return 1;
	return 0;
}

int is_on_end(char *str,char *origin)
{
	if (str == origin)
		return 0;
	if (is_space(*(str--)))
		return 1;
	else return(0);
}


void print_word(char *str,char *end)
{
	while(str < end)
	{
		write(1,str,1);
		str++;
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
		char *start;
		int i = 0;
		int in_word = 0;
		while(argv[1][i] != '\0')
		{
			if(in_word)
			{
				if(is_space(argv[1][i]))
				{
					print_word(start,&argv[1][i]);
					write(1,"\n",1);
					return(1);
				}
			}
			else
			{
				if(!is_space(argv[1][i]))
				{
					start = &argv[1][i];
					in_word = 1;
				}
			}
			i++;
		}
		if(in_word)
		{
			print_word(start,&argv[1][i]);
			write(1,"\n",1);
			return(1);
		}
		write(1,"\n",1);
	}
}

