#include  <unistd.h>
#include <stdlib.h>



int get_size(char *str)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if(str[i] != '_')
			count++;
		i++;
	}
	return count;
}
void	toCamel(char* str)
{
	int size;
	size = get_size(str);
	char *new_str = malloc((size+1)*sizeof(char));
	int i = 0;
	int j = 0;
	int in_und = 0;
	while(str[i] != '\0')
	{
		if (in_und)
		{
			if(str[i] != '_') //e uma letra
			{
				new_str[j] = 'A' + (str[i] - 'a');
				j++;
				in_und = 0;
			}
		}
		else
		{
			if(str[i] == '_')
				in_und = 1;
			else//e uma letra
			{
				new_str[j] = str[i];
				j++;
			}
		}
		i++;
	}
	new_str[j+1] = '\0';
	int k = 0;
	while(new_str[k] != '\0')
	{
		write(1,&new_str[k],1);
		k++;
	}
}
int main(int argc,char  **argv)
{

	if(argc == 2)
	{
		char *str = argv[1];
		toCamel(str);
		write(1,"\n",1);
	}
	else
		write(1,"\n",1);
}
