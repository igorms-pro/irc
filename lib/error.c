/*
** error.c for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Sun Apr  8 15:41:21 2012 igor morenosemedo
** Last update Sun Apr  8 16:07:00 2012 igor morenosemedo
*/

#include "lib.h"

void		error_file(char *s1, char *s)
{
  fprintf(stderr, "\033[1;33m%s - %s\033[0m", s1, s);
  return ;
}

void		error(char *s)
{
  fprintf(stderr, "%s\n", s);
  exit (EXIT_FAILURE);
}

