#include <unistd.h>
#include <stdlib.h>

void	print_str(char *wrd)
{
	int i = 0;
	while(wrd[i] != '\0')
	{
		write(1,&wrd[i],1);
		i++;
	}
}
void	print_words(char **words)
{
	int i = 0;
	while(words[i] != NULL)
	{
		print_str(words[i]);
		if(words[i+1] != NULL)
			write(1," ",1);
		i++;
	}
}
void free_split(int i,char **words)
{
	while(i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
}
void ft_strncpy(char *src,char *dest,int size)
{
	int i =0;
	while(size)
	{
		dest[i] = src[i];
		size --;
		i++;
	}
	dest[i] = '\0';
}
int is_space(char c)
{
	if((c >= 7 && c <= 13) || c == ' ')
		return 1;
	else
		return 0;
}

int count_words(char* str)
{
	int i = 0;
	int wc = 0;
	int in_word = 0;
	while(str[i] != 0)
	{
		if(in_word)
		{
			if(is_space(str[i])) //its space
			{
				in_word = 0;
				wc++;
			}
		}
		else //in space
		{
			if(is_space(str[i]) == 0) //its a letter
			{
				in_word = 1;
			}
		}
		i++;
	}
	if(in_word)
		wc++;
	return wc;
}
char **ft_split(char *str) //change the void
{
	int wc = count_words(str);
	char *new_word;
	char **words = malloc((wc+1)*sizeof(char*));
	words[wc] = NULL;
	int i = 0;
	int j = 0;
	int in_word = 0;
	int start = 0;
	while(str[j] != '0')
	{
		if(in_word == 1)
		{
			if(is_space(str[j]))
			{
				//alocar espaco e copiar
				new_word = malloc((j-start)+1 * sizeof(char));
				if(new_word == NULL)
					free_split(i,words);
				else
				{
					ft_strncpy(&str[start], new_word, j-start);
					words[i] = new_word;
					i++;
					in_word = 0;
				}
			}
		}
		else
		{
			if(!is_space(str[j])) //not a space
			{
				in_word = 1;
				start = j;
			}
		}
		j++;
	}
	if(in_word)
	{
		new_word = malloc((j-start)+1 * sizeof(char));
		if(new_word == NULL)
			free_split(i,words);
		else
		{
			ft_strncpy(&str[start], new_word, j-start);
			words[i] = new_word;
		}
	}
	return(words);
}
int main(int argc, char**argv)
{
	char **words;
	if(argc >= 2)
	{
		char *str = argv[1];
		words = ft_split(str);
		int i = 0;
		int wc = count_words(str);
		words[wc] = NULL;
		if (wc >= 2)
		{
			char *first = words[0];
			while(words[i+1] != NULL)
			{
				words[i] = words[i+1];
				i++;
			}
			words[i] = first;
			print_words(words);
		}
		else
			print_words(words);
		write(1,"\n",1);
	}
	else
		write(1,"\n",1);
}
