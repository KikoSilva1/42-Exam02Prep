#include <unistd.h>

int ft_islower(char letter)
{
	if(letter >= 'a' && letter <= 'z')
		return 1;
	else if (letter >= 'A' && letter <= 'z')
		return 0;
	else
		return 2;
}
char mirror(char mid_letter,char letter)
{
	int dist_to_mid;
	if (letter > mid_letter)
	{
		dist_to_mid = letter - mid_letter;
		return (mid_letter - dist_to_mid + 1);
	}
	else
	{
		dist_to_mid = mid_letter - letter;
		return (mid_letter + dist_to_mid + 1);
	}
}
char	*alpha_mirror(char *str)
{
	char small_mid_letter = 'a' + (('z' - 'a')/ 2);
	char big_mid_letter = 'A' + (('Z' - 'A')/ 2);
	int i = 0;
	while(str[i])
	{
		if(ft_islower(str[i]) == 1)
			str[i] = mirror(small_mid_letter,str[i]);
		else if (ft_islower(str[i]) == 0)
			str[i] = mirror(big_mid_letter,str[i]);
		i++;
	}
	return str;
}
int main(int c,char **argv)
{
	if (c == 2)
	{
		char* str = argv[1];
		alpha_mirror(str);
		while(*str != '\0')
		{
			write(1,str,1);
			str++;
		}
		write(1,"\n",1);
	}
	else
		write(1,"\n",1);
}


int main()
{

	char *str= "three words apart";
	char **split_str;
	split_str = ft_split(str);
	split_str[0][0] = 'o';
}
int main()
{

	char *str= "three words apart";
	char **split_str;
	split_str = ft_split(str);
	split_str[0][0] = 'o';
}
