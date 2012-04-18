/*
** xgetprotobyname.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 19:47:36 2012 igor morenosemedo
** Last update Sat Apr  7 01:17:30 2012 igor morenosemedo
*/

#include "lib.h"

struct protoent		*xgetprotobyname(const char *name)
{
  struct protoent	*xg;

  xg = getprotobyname(name);
  if (xg == NULL)
    {
      fprintf(stderr, "Error getprotobyname\n");
      exit (EXIT_FAILURE);
    }
  return (xg);
}
