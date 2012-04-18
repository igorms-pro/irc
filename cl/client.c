/*
** client.c for  in /home/moreno_i//afs/renduLocal/projets/irc
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Tue Apr 17 10:39:41 2012 igor morenosemedo
** Last update Tue Apr 17 22:41:51 2012 igor morenosemedo
*/

#include "../the_irc.h"

static int	read_buff(int cs1, int cs2)
{
  int		rd;
  char		buf[MAX_BUFF];

  rd = MAX_BUFF;
  while (rd == MAX_BUFF)
    {
      rd = read(cs1, buf, MAX_BUFF);
      write(cs2, buf, rd);
      if (rd == 0)
	return (-1);
    }
  return (0);
}

static void		client_name(int fd)
{
  char			*str;

  str = strdup(getenv("USERNAME"));
  write(fd, str, strlen(str));
  write(fd, "\n", 1);
}

static void		fillsockcl(t_tcp *s, int port, char *str)
{
  s->sin.sin_family = AF_INET;
  s->sin.sin_port = htons(port);
  s->sin.sin_addr.s_addr = inet_addr(str);
}

static void		raz(int fd, fd_set *fdr)
{
  FD_ZERO(fdr);
  FD_SET(fd, fdr);
  FD_SET(0, fdr);
}

static int		my_isset(int fd, fd_set *fdr)
{
  if (FD_ISSET(fd, fdr))
    if (read_buff(fd, 1) == -1)
      return (0);
  if (FD_ISSET(0, fdr))
    if (read_buff(0, fd) == -1)
      return (0);
  return (1);
}

static int		launch_cl(t_tcp *s)
{
  char			rbuf[MAX_BUFF];

  client_name(s->fd_s);
  while (42)
    {
      s->tv.tv_usec = 1;
      s->tv.tv_sec = 1;
      raz(s->fd_s, &(s->set_fd));
      select(s->fd_s + 1, &(s->set_fd), NULL, NULL, &(s->tv));
      my_isset(s->fd_s, &(s->set_fd));
      memset(rbuf, '\0', MAX_BUFF);
      memset(s->buf, '\0', MAX_BUFF);
    }
  return (0);
}

int			main(int ac, char **av)
{
  t_tcp			*t;
  int			port;

  t = malloc(sizeof(t));
  if (ac != 3)
    error(USAGE_CL);
  port = atoi(av[2]);
  t->p = getprotobyname("TCP");
  t->fd_s = socket(AF_INET, SOCK_STREAM, t->p->p_proto);
  fillsockcl(t, port, av[1]);
  connect(t->fd_s, (const struct sockaddr *)&t->sin, sizeof(t->sin));
  launch_cl(t);
  close(t->fd_s);
  return (0);
}
