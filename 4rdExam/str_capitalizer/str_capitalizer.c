#include <unistd.h>

int is_space(char c)
{
	if((c <= 13 && c >= 7)|| c == ' ')
		return 1;
	return 0;
}

int is_letter(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}
void	capitalize(char *c)
{
	if((*c >= 'a' && *c <= 'z'))
	{
		*c = 'A' + (*c - 'a');
	}
}

void	lowerlize(char *c)
{
	if((*c >= 'A' && *c <= 'Z'))
	{
		*c = 'a' + (*c - 'A');
	}
}


int main(int argc, char **argv)
{
	if(argc < 2)
	{
		write(1,"\n",1);
		return (2);
	}
	else
	{
		int i = 1;
		while(argv[i] != NULL)
		{
			int j = 0;
			while(argv[i][j] != '\0')
			{
				if(is_letter(argv[i][j]))
				{
					if(&argv[i][j] == argv[i]) //on start
					{
						capitalize(&argv[i][j]);
						write(1,&argv[i][j],1);
					}
					else
					{
						if(is_space(argv[i][j-1]))
						{
							capitalize(&argv[i][j]);
							write(1,&argv[i][j],1);
						}
						else
						{
							lowerlize(&argv[i][j]);
							write(1,&argv[i][j],1);
						}
					}
				}
				else
					write(1,&argv[i][j],1);
				j++;
			}
			write(1,"\n",1);
			i++;
		}
	}

}

