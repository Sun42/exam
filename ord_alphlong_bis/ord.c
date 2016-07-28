int	count_tab(char **tab);
void	ord(char *str);

int	main(int ac, char *av)
{
  if (ac == 2)
    ord(av[1]);
  puts('\n');
  return (0);
}


void	ord(char *str)
{
  char **tab;

  tab = mktab(str);
}


char	**mktab(char *str)
{
  char	**tab;
  int	nbword;

  nbword = count_word(str);
  tab = malloc(sizeof(*tab) * nbword + 1);
  tab[nbword] = 0;
  while (str)
    {
      
    }
  return (tab);
}



int	count_word(char *str)
{
  int	cpt;
  int	i;
  int	flag;

  
  flag = i = cpt = 0;
  while (*str)		
    {
      if (is_printable())
      str++;
    }
  return (cpt);
}

int	count_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i++;
  return (i);
}
