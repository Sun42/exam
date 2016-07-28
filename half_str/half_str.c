#include <unistd.h>
void	half_str(char *str);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_putchar(char c);

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main(int ac, char **av)
{
  int	i;

  i = 1;
  
  if (ac < 2)
    {
      my_putstr("\n");
      return (0);
    }
  while (i < ac)
    {
      half_str(av[i]);
      my_putstr("\n");
      i++;
    }
  return (0);
}

void	half_str(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(i % 2))
	my_putchar(str[i]);
      i++;
    }
  
}
