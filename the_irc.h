/*
** the_irc.h for  in /home/moreno_i//afs/renduLocal/projets/irc
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Tue Apr 17 22:02:45 2012 igor morenosemedo
** Last update Wed Apr 18 14:07:48 2012 igor morenosemedo
*/

#ifndef _THE_IRC_H_
# define _THE_IRC_H_

# include "./lib/lib.h"

#  define USAGE_CL	"Usage: ./client [IP] [PORT]\n"
#  define USAGE_SV	"Usage: ./serveur [PORT]\n"
#  define MAX_BUFF	512
#  define FD_FREE	0
#  define FD_CLIENT	1
#  define FD_SERVER	2
#  define MAX_FD	_POSIX_OPEN_MAX


typedef struct		s_tcp
{
  fd_set		set_fd;
  int			fd_s;
  char			buf[MAX_BUFF];
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_cl;
  struct protoent	*p;
  struct timeval	tv;
}		t_tcp;


typedef void (*fct)();

typedef struct	s_env
{
  char	fd_type[MAX_FD];
  fct	fct_read[MAX_FD];
  fct	fct_write[MAX_FD];
  int	port;
}t_env;

typedef struct	s_log
{
  int		_fd;
  char		*_name;
  int		*_chan;
  struct s_log *next;
}		t_log;


/* list.c */
void		raz_chan(t_log **el);
int		put_chan_in_list(t_log **c, int fd);
void		del_elem_at_front(t_log **pos);
int			del_elem_at_position(t_log **log, int fd);
void	list_free(t_log **p);
void		show_list(t_log *c);

#endif
