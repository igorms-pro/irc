/*
** xopen.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Sun Apr  8 12:43:20 2012 igor morenosemedo
** Last update Sun Apr  8 12:47:25 2012 igor morenosemedo
*/

#include "lib.h"

int	xopen(const char *pathname, int flags, mode_t mode)
{
  int	xo;

  xo = open(pathname, flags, mode);
  if (xo == -1)
    {
      fprintf(stderr, "Error open\n");
      exit (EXIT_FAILURE);
    }
  return (xo);
}
