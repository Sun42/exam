#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF 4096

int	size_lines(char buf[], int max);
int	count_nblines(char buf[], int max);
char	**mk_tab(char buf[], int taillel, int nbl);
void	my_strncpy(char *str1, char *str2, int max);
void	aff_tab(char **tab);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	str_x(char *str);
int	exist_x(char **tab);
char	**transform(char **tab, int taillel, int nbl);
void	propage(char **tab, int cpt, int taillel, int nbl);
void	my_recurs(char ***tab, int cpt, int taillel, int nbl, int i, int j);

void	count_island(char *filename)
{
  int		fd;
  int		sizeline;
  int		nbline;
  char		buf[BUF];
  struct stat	st;
  char		**tab;
  
 if ((fd = open(filename, O_RDONLY)) == -1)
    return ;

 if (fstat(fd, &st) == -1)
   return ;
  if (read(fd, buf, st.st_size) == -1)
    return ;


  sizeline = size_lines(buf, st.st_size);
  nbline = count_nblines(buf, st.st_size);
  printf("taille dune ligne :%i \n", sizeline);
  printf("Nombre de lignes :%i \n", nbline);
  tab = mk_tab(buf, sizeline, nbline);
  aff_tab(tab);
  transform(tab, sizeline, nbline);
  close(fd);
}


char	**transform(char **tab, int taillel, int nbl)
{

  int	cpt;

  cpt = 0;
  propage(tab, cpt, taillel, nbl);
  
  return (tab);
}


void	propage(char **tab, int cpt, int taillel, int nbl)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (i < nbl)
    {
      j = 0;
      while (j < my_strlen(tab[i]))
	{
	  if (tab[i][j] == 'X')
	    {
	      my_recurs(&tab, cpt, taillel, nbl, i, j);
	      cpt++;
	    }
	  j++;
	}
      i++;
    }
  printf("\n");
  aff_tab(tab);
}

void	my_recurs(char ***tab, int cpt, int taillel, int nbl, int i, int j)
{
  char **tab2;

  tab2 = *tab;
  tab2[i][j] = cpt + '0';
  if (i < (nbl - 1) && (tab2[i + 1][j] == 'X'))
    my_recurs(tab, cpt, taillel, nbl, i + 1, j);
  if ((i > 0) && (tab2[i - 1][j] == 'X'))
    my_recurs(tab, cpt, taillel, nbl, i - 1, j);
 if ((j > 0) && (tab2[i][j - 1] == 'X'))
   my_recurs(tab, cpt, taillel, nbl, i, j - 1);

 if ((j < (taillel - 1)) && (tab2[i][j + 1] == 'X'))
   my_recurs(tab, cpt, taillel, nbl, i, j + 1);

}

int	exist_x(char **tab)
{
  int	i;

  i = 0;

  while (tab[i] != 0)
    {
      i++;
      if (str_x(tab[i]) == 1)
	return (1);
    }
  return (0);
}

int	str_x(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == 'X')
	return (1);
	i++;
    }
  return(0);
}

char	**mk_tab(char buf[], int taillel, int nbl)
{
  char	**tab;
  int	i;

  i = 0;
  tab = malloc(sizeof(*tab) * (nbl + 1));
  tab[nbl] = 0;
  while (i < nbl)
    {
      tab[i] = malloc(sizeof(**tab) * taillel);
      my_strncpy(tab[i], buf, taillel);
      i++;
      buf += taillel + 1;
    }
  return (tab);
}

void	my_strncpy(char *str1, char *str2, int max)
{
  int	i;

  i = 0;
  while (i < max)
    {
      str1[i] = str2[i];
      i++;
    }
  str1[max] = '\0';
}


void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i++;
    }

}


int	count_nblines(char buf[], int max)
{
  int	i;
  int	cpt;

  cpt = 0;
  i = 0;
  while ((buf[i] != '\0') && (i <= max))
    {
      if (buf[i] == '\n')
	cpt++;
      i++;
    }
  return (cpt);
}

int	size_lines(char buf[], int max)
{
  int	i;

  i = 0;
  while ((buf[i] != '\0') && (i <= max))
    {
      if (buf[i] == '\n')
	break ;
      i++;
    }
  return (i);
}


int	main(int ac, char **av)
{
  if (ac == 2)
    {
      count_island(av[1]);
    }
}


void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
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
