/*
** xwrite.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Sun Apr  8 11:17:42 2012 igor morenosemedo
** Last update Sun Apr  8 16:57:11 2012 igor morenosemedo
*/

#include "lib.h"

int	xwrite(int fd, const void *buf, size_t count)
{
  int	xw;

  xw = write(fd, buf, count);
  if (xw == -1)
    {
      fprintf(stderr, "Error write\n");
      exit (EXIT_FAILURE);
    }
  return (xw);
}
