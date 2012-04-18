/*
** xaccept.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 18:45:39 2012 igor morenosemedo
** Last update Sat Apr  7 01:13:38 2012 igor morenosemedo
*/

#include "lib.h"

int	xaccept(int sockfd, struct sockaddr *addr,
		socklen_t *addrlen)
{
  int	xa;

  xa = accept(sockfd, addr, addrlen);
  if (xa == -1)
    {
      fprintf(stderr, "accept error\n");
      xclose(sockfd);
      exit (EXIT_FAILURE);
    }
  return (xa);
}
