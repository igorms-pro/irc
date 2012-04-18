/*
** xbind.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 18:44:00 2012 igor morenosemedo
** Last update Sat Apr  7 01:15:01 2012 igor morenosemedo
*/

#include "lib.h"

int	xbind(int sockfd, const struct sockaddr *addr,
	      socklen_t addrlen)
{
  int	xb;

  xb = bind(sockfd, addr, addrlen);
  if (xb == -1)
    {
      fprintf(stderr, "bind error\n");
      xclose(sockfd);
      exit (EXIT_FAILURE);
    }
  return (xb);
}
