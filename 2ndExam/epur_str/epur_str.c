#include <unistd.h>
#include <stdlib.h>

int is_space(char c)
{
	if((c >= 7 && c <= 13) || c == ' ')
		return 1;
	else
		return 0;
}

int is_on_end(char *str)
{
	int i = 1;
	while(str[i] != '\0')
	{
		if(is_space(str[i]) == 0)
			return(0);
		i++;
	}
	return(1);
}
int get_next_pos(char* str)
{
	int i = 0;
	while(str[i] !=0)
	{
		if (is_space(str[i]) == 0)
			return i;
		else
			i++;
	}
	return (i);
}

void change_str(char* str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(is_space(str[i]))
		{
			if(&str[i] == str) //esta no inicio, atualizo o start
				str++;
			else if(is_on_end(&str[i]))
				break;
			else
			{
				write(1," ",1);
				i = i + get_next_pos(&str[i]);
			}
		}
		else
		{
			if(is_on_end(&str[i]))
			{
				write(1,&str[i],1);
				break;
			}
			else
			{
				write(1,&str[i],1);
				i++;
			}
		}
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
