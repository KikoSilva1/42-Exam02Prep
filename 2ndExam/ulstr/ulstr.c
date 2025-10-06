#include <unistd.h>


int	is_lower(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (0);
	if (c <= 'z' && c >= 'a')
		return(1);
	return (2);
}


void change_str(char* str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(is_lower(str[i]) == 1)
			str[i] = 'A' + (str[i] - 'a');
		else if(is_lower(str[i]) == 0)
			str[i] = 'a' + (str[i] - 'A');
		write(1,&str[i],1);
		i++;
	}
}

int main(int argc, char**argv)
{
	if(argc == 2)
	{
		char *str = argv[1];
		change_str(str);
		write(1,"\n",1);
	}

	else
		write(1,"\n",1);
}
