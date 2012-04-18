/*
** xlisten.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 18:46:32 2012 igor morenosemedo
** Last update Sat Apr  7 01:14:43 2012 igor morenosemedo
*/

#include "lib.h"

int	xlisten(int sockfd, int backlog)
{
  int	xl;

  xl = listen(sockfd, backlog);
  if (xl == -1)
    {
      fprintf(stderr, "listen error\n");
      xclose(sockfd);
      exit (EXIT_FAILURE);
    }
  return (xl);
}
