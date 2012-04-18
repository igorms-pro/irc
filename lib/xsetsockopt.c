/*
** xsetsockopt.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 22:51:12 2012 igor morenosemedo
** Last update Sat Apr  7 01:14:32 2012 igor morenosemedo
*/

#include "lib.h"

int	xsetsockopt(int sockfd, int level, int optname,
		   const void *optval, socklen_t optlen)
{
  int	xs;

  xs = setsockopt(sockfd, level, optname, optval, optlen);
  if (xs == -1)
    {
      fprintf(stderr, "Error setsockopt\n");
      xclose(sockfd);
      exit (EXIT_FAILURE);
    }
  return (xs);
}
