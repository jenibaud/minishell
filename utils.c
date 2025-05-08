char	*remove_quotes(char *str)
{
	int		i;
	int		quotes;
	char	*res;

	i = 0;
	quotes = 0;
	res = str;
	while (str[i] != '\0')
	{
		if (str[i] == 34 || str[i] == 39)
			quotes++;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		
	}
}
