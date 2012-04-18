/*
** xclose.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Sat Apr  7 01:11:57 2012 igor morenosemedo
** Last update Sat Apr  7 01:17:13 2012 igor morenosemedo
*/

#include "lib.h"

int	xclose(int fd)
{
  int	i;

  i = close(fd);
  if (i == -1)
    {
      fprintf(stderr, "Closing error\n");
      exit(EXIT_FAILURE);
    }
  return (i);
}
