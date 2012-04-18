/*
** xfopen.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Sat Apr  7 09:51:57 2012 igor morenosemedo
** Last update Sun Apr  8 13:18:40 2012 igor morenosemedo
*/

#include "lib.h"

FILE	*xfopen(const char *path, const char *mode)
{
  FILE	*xf;

  xf = fopen(path, mode);
  if (xf == NULL)
    {
      fprintf(stderr, "Error fopen\n");
      exit (EXIT_FAILURE);
    }
  return (xf);
}
