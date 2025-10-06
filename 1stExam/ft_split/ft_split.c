#include <stdlib.h>

int count_words(char* str)
{
	int j = 0;
	int in_word = 0;
	int wc = 0;
	while(str[j] != '\0')
	{
		if (in_word)
		{
			if(str[j] == ' ' || str[j] == '\0')
			{
				in_word = 0;
				wc++;
			}
		}
		else
			if(str[j] != ' ' && str[j] != '\0')
				in_word = 1;
		j++;
	}
	if(in_word)
		wc++;
	return wc;
}
void	ft_strncpy(char* src, char* dest,int size)
{
	int i = 0;
	while (i<size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
void	free_split(char **split_str,int i)
{
	int j = 0;
	while(j <= i)
	{
		free(split_str[j]);
		j++;
	}
	free(split_str);
}
void	fill_str(char **split_str,char *str)
{
	int i = 0;
	int start = 0;
	int j = 0;
	int in_word = 0;
	char* curr_word;
	while(str[j] != '\0')
	{
		if(in_word)
		{
			if(str[j] == ' ' || str[j] == '\0')
			{
				if(j>start)
				{
					curr_word = malloc(((j-start)+1) * sizeof(char));
					if(curr_word == NULL)
						free_split(split_str,i);
					ft_strncpy(&str[start],curr_word,j-start);
					split_str[i] = curr_word;
					i++;
				}
				in_word = 0;
			}
			else
				j++;
		}
		else
		{
			if(str[j] == ' ' || str[j] == '\0')
				j++;
			else
			{
				in_word = 1;
				start = j;
			}
		}
	}
	if(in_word)
	{
		curr_word = malloc(((j-start)+1) * sizeof(char));
		if(curr_word == NULL)
		free_split(split_str,i);
		ft_strncpy(&str[start],curr_word,j-start);
		split_str[i] = curr_word;
	}

}
char **ft_split(char* str)
{
	int wc = count_words(str);
	char **split_str = malloc((wc+1) * sizeof(char*));
	split_str[wc] = NULL;
	fill_str(split_str,str);
	return split_str;
}

