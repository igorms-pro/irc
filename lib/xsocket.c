/*
** xsocket.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 18:41:06 2012 igor morenosemedo
** Last update Fri Apr  6 18:46:57 2012 igor morenosemedo
*/

#include "lib.h"

int	xsocket(int domain, int type, int protocol)
{
  int	xs;

  xs = socket(domain, type, protocol);
  if (xs == -1)
    {
      fprintf(stderr, "socket error\n");
      exit (EXIT_FAILURE);
    }
  return (xs);
}

