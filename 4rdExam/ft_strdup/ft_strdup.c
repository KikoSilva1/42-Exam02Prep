
char *ft_strdup(const char* s)
{
	int size = 0;
	while(s[size] != '\0')
	{
		size++;
	}
	char *str = malloc((size+1) *sizeof(char*));
	int i = 0;
	while(i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return str;
}
