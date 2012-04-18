/*
** xfork.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 20:07:34 2012 igor morenosemedo
** Last update Sat Apr  7 01:17:23 2012 igor morenosemedo
*/

#include "lib.h"

pid_t		xfork(void)
{
  pid_t		xf;

  xf = fork();
  if (xf == -1)
    {
      fprintf(stderr, "Error fork\n");
      exit(EXIT_FAILURE);
    }
  return (xf);
}
