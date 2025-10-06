#include <unistd.h>

int is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= 'A' && c <= 'Z')
		return 0;
	else
		return 2;
}
void rep(char *str)
{
	int i = 0;
	int times;
	while(str[i] != '\0')
	{
		if(is_lower(str[i]) == 1)
			times =  (str[i] - 'a') + 1;
		else if (is_lower(str[i]) == 0)
			times =  (str[i] - 'A') + 1;
		else
			times = 1;
		while(times)
		{
			write(1,&str[i],1);
			times--;
		}
		i++;
	}
	write(1,"\n",1);
}
int main(int argc, char** argv)
{
	if(argc != 2)
	{
		write(1,"\n",1);
		return 1;
	}
	else
	{
		char *str = argv[1];
		rep(str);
	}
}
