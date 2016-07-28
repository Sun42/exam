#include <unistd.h>

int	already(int i, char *str);
void	inter(char *str1, char *str2);
int	my_strlen(char *str);
void	my_putchar(char c);
void	my_putstr(char *str);
int	match(char c, char *str);

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
      i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	main(int ac, char **av)
{

  if (ac == 3)
    inter(av[1], av[2]);
  my_putchar('\n');
  return (0);
}

void	inter(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0')
    {
      if (match(str1[i], str2)  && !already(i, str1))
	my_putchar(str1[i]);
      i++;
    }
}


int	already(int i, char *str1)
{
  int	j;

  j = 0;
  while (j < i)
    {
      if (str1[j] == str1[i])
	return (1);
      j++;
    }
  return (0);
}

int	match(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}
