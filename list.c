/*
** list.c for  in /home/moreno_i//afs/renduLocal/projets/irc
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Wed Apr 18 11:37:32 2012 igor morenosemedo
** Last update Wed Apr 18 14:09:00 2012 igor morenosemedo
*/

#include "the_irc.h"

void		raz_chan(t_log **el)
{
  int		i;

  i = 0;
  (*el)->_chan[49] = -1;
  while ((*el)->_chan[i] != -1)
    {
      (*el)->_chan[i] = 0;
      ++i;
    }
}

int		put_chan_in_list(t_log **c, int fd)
{
  t_log		*el;

  el = malloc(sizeof(*el));
  el->_fd = fd;
  el->_name = NULL;
  el->_chan = malloc(50 * sizeof(int));
  el->next = *c;
  raz_chan(&el);
  *c = el;
  return (0);
}

void		del_elem_at_front(t_log **pos)
{
  t_log		*p;

  if (*pos)
    {
      p = *pos;
      *pos = (*pos)->next;
      free(*pos);
    }
}

int			del_elem_at_position(t_log **log, int fd)
{
  t_log	*tmp;
  t_log	*prev;

  tmp = *log;
  prev = NULL;
  while ((*log)->_fd != fd)
    {
      if ((*log)->next == NULL && (*log)->_fd != fd)
	return (-1);
      prev = *log;
      *log = (*log)->next;
    }
  if (prev != NULL)
    {
      prev->next = (*log)->next;
      free((*log)->_name);
      *log = tmp;
    }
  else
    {
      tmp = *log;
      *log = (*log)->next;
      free(tmp->_name);
    }
  return (0);
}

void	list_free(t_log **p)
{
  while (*p != NULL)
    del_elem_at_front(p);
}

void		show_list(t_log *c)
{
  t_log		*el;

  el = c;
  while (el != NULL)
    {
      printf("LOGIN-> %s\n", el->_name);
      el = el->next;
    }
}
