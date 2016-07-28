#include <stdlib.h>
#include <stdio.h>

void	my_putstr(char *str);
void	my_putchar(char c);
int	my_strlen(char *str);
char	**mktab(char *str);
void	aff_tab(char **tab);
int	my_strlen(char *str);
int	count_words(char *str);
int	is_alph(char c);
int	word_len(char *str);
void	my_strncpy(char *dest, char *src, int max);
void	ord_alphlong(char *str);
int	count_tab(char **tab);
char	**ordtab(char **tab);
int	my_strcmp(char *str, char *str2);
int	is_lower(char c);
char	mk_upper(char c);


int	main(int ac, char **av)
{
  if (ac == 2 && av[1] != NULL)
    ord_alphlong(av[1]);
  my_putchar('\n');
  return (0);
}


void	ord_alphlong(char *str)
{
  char	**tab;
  
  tab = mktab(str);
  tab = ordtab(tab);
  aff_tab(tab);
}

char	**ordtab(char **tab)
{
  int	i;
  int	j;
  int	max;
  char	*swap;


  max = count_tab(tab) - 1;
  for (i = max; i >= 0; i--)
    {
      for (j = 0; j < i; j++)
	{
	  if (my_strlen(tab[j]) > my_strlen(tab[j + 1]))
	    {
	      swap = tab[j];
	      tab[j] = tab[j + 1];
	      tab[j + 1] = swap;
	    }
	  if (my_strlen(tab[j]) == my_strlen(tab[j + 1]))
	    {
	      if (my_strcmp(tab[j], tab[j + 1]) > 0)
		{
		  swap = tab[j];
		  tab[j] = tab[j + 1];
		  tab[j + 1] = swap;
		}
	    }
	}
    }
  return (tab);
}


int	my_strcmp(char *str, char *str2)
{
  int	i;
  char	c1;
  char	c2;

  i = 0;
  while (str[i] != '\0')
    {
      c1 = str[i];
      c2 = str2[i];
      
      if (is_lower(c1))
	c1 = mk_upper(c1);
      if (is_lower(c2))      
	c2 = mk_upper(c2);
      if (c1 > c2)
	return (1);
      if (c1 < c2)
	return (-1);
      i++;
    }
  return (0);
}

char	mk_upper(char c)
{
  printf(" avant %c \n", c);
  c = c - ('a'- 'A');
  printf(" apres %c \n", c);
  return (c);
}

int	is_lower(char c)
{
  if ((c >= 'a') && (c <= 'z'))
    return (1);
  return (0);
}


int	count_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      i++;
    }
  return (i);
}

char	**mktab(char *str)
{
  char	**tab;
  int	nbwords;
  int	i;
  int	wordlen;

  i = 0;
  nbwords = count_words(str);
  tab = malloc(sizeof(*tab) * (nbwords + 1));
  tab[nbwords] = 0; 
  while (*str != '\0')
    {
      if (is_alph(*str))
	{
	  wordlen = word_len(str);
	  tab[i] = malloc(sizeof(**tab) * wordlen + 1);
	  my_strncpy(tab[i], str, wordlen);
	  i++;
	  str += wordlen;
	}
      else
	str++;
    }
  return (tab);
}

void	my_strncpy(char *dest, char *src, int max)
{
  int	i;

  i = 0;
  while (i < max)
    {
      dest[i] = src[i];
      i++;
    }
  dest[max] = '\0';
}

int	word_len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && is_alph(str[i]))
    {
      i++;
    }
    return (i);
}

int	count_words(char *str)
{
  int	cpt;
  int	flag;
  int	i;

  i = 0;
  flag = 0;
  cpt = 0;

  while (str[i] != '\0')
    {
      if (is_alph(str[i]))
	{
	  if (!flag)
	    cpt++;
	  flag = 1;
	}
      else
	{
	  flag = 0;
	}
      i++;
    }
  return (cpt);
}

int	is_alph(char c)
{
  if ((c >= 'a') && (c <= 'z'))
    return (1);
  if ((c >= 'A') && (c <= 'Z'))
    return (1);
  return (0);
}

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}


void	my_putchar(char c)
{
 write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
