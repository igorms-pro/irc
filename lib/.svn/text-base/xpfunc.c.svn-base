/*
** xpfunc.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Sun Apr  8 18:25:03 2012 igor morenosemedo
** Last update Sun Apr  8 20:53:50 2012 igor morenosemedo
*/

#include "lib.h"

FILE	*xpopen(const char *command, const char *type)
{
  FILE	*xop;

  xop = popen(command, type);
  if (xop == NULL)
    {
      fprintf(stderr, "Error popen\n");
      exit (EXIT_FAILURE);
    }
  return (xop);
}

int	xpclose(FILE *stream)
{
  int	xpc;

  xpc = pclose(stream);
  if (xpc == -1)
    {
      fprintf(stderr, "Error pclose\n");
      exit (EXIT_FAILURE);
    }
  return (xpc);
}
