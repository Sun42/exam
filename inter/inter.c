#include <stdlib.h>
#include <stdio.h>

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	inter(char *str1, char *str2);
int	match(char c, char *str2);
int	already(char *str, int i);

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      if ((av[1] != NULL) && (av[2] != NULL))
	inter(av[1], av[2]);
    }
  my_putstr("\n");
  return(0);
}


void	inter(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0')
    {
      if (match(str1[i], str2) && !already(str1, i))
	my_putchar(str1[i]);
      i++;
    }
}

int	already(char *str, int i)
{
  char	c;
  int	j;

  j = 0;
  c = str[i];

  while (j < i)
    {
      if (str[j] == c)
	return (1);
      j++;
    }
  return (0);
}

int	match(char c, char *str2)
{
  int	j;

  j = 0;

  while (str2[j] != '\0')
    {
      if (str2[j] == c)
	return (1);
      j++;
    }
  return (0);
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
