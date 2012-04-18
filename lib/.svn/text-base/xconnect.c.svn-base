/*
** xconnect.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 18:44:51 2012 igor morenosemedo
** Last update Sat Apr  7 01:14:53 2012 igor morenosemedo
*/

#include "lib.h"

int	xconnect(int sockfd, const struct sockaddr *addr,
		 socklen_t addrlen)
{
  int	xc;

  xc = connect(sockfd, addr, addrlen);
  if (xc == -1)
    {
      fprintf(stderr, "connect error\n");
      xclose(sockfd);
      exit (EXIT_FAILURE);
    }
  return (xc);
}
