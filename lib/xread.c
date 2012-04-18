/*
** xread.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Sat Apr  7 01:15:37 2012 igor morenosemedo
** Last update Sat Apr  7 01:16:43 2012 igor morenosemedo
*/

#include "lib.h"

int	xread(int fd, void *buf, int count)
{
  int	x_re;

  x_re = read(fd, buf, count);
  if (x_re == -1)
    {
      fprintf(stderr, "Error read\n");
      exit(EXIT_FAILURE);
    }
  return (x_re);
}
