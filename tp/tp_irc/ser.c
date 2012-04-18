/*
** ser.c for  in /home/moreno_i//afs/renduLocal/projets/irc/tp/tp_irc
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Mon Apr 16 18:17:09 2012 igor morenosemedo
** Last update Mon Apr 16 18:44:41 2012 igor morenosemedo
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FD_FREE		0
#define FD_CLIENT	1
#define FD_SERVER	2

#define MAX_FD		_POSIX_OPEN_MAX

typedef void (*fct)();

typedef struct	s_env
{
  char	fd_type[MAX_FD];
  fct	fct_read[MAX_FD];
  fct	fct_write[MAX_FD];
  int	port;
}t_env;

void client_read(t_env *e, int fd)
{
  int   r;
  char buf[4096];

  r = read(fd, buf, 4096);
  if (r > 0)
    {
      buf[r] = '\0';
      printf("fd: [%d]  | buf: [%s]\n", fd,  buf);
    }
  else
    {
      printf("fd: [%d] - Connexon Closed\n", fd);
      e->fd_type[fd] = FD_FREE;
    }
}

void add_client(t_env *e, int s)
{
  int cs;
  struct sockaddr_in    client_sin;
  int                   client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin,
	      (socklen_t *)&client_sin_len);
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = NULL;
}

void server_read(t_env *e, int fd)
{
  puts("New client\n");
  add_client(e, fd);
}

void add_server(t_env *e)
{
  int                    s;
  struct sockaddr_in    sin;

  s = socket(PF_INET, SOCK_STREAM, 0);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  bind(s, (struct sockaddr*)&sin, sizeof(sin));
  listen(s, 42);
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = server_read;
  e->fct_write[s] = NULL;
}

int	main(int  ac, char  **av)
{
  t_env	e;
  int i, fd_max;
  fd_set	fd_read;
  struct timeval	tv;

  if (ac != 2)
    {
      puts("Et le port?");
      exit (0);
    }
  memset(e.fd_type, FD_FREE, MAX_FD);
  e.port = atoi(av[1]);
  add_server(&e);
  tv.tv_sec = 5;
  tv.tv_usec = 0;
  while (1)
    {
      FD_ZERO(&fd_read);
      fd_max = 0;
      for (i = 0; i < MAX_FD; i++)
	if (e.fd_type[i] != FD_FREE)
	  {
	    FD_SET(i, &fd_read);
	    fd_max = i;
	  }
      if (select(fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
	puts("select");
      for (i = 0; i < MAX_FD; i++)
	if (FD_ISSET(i, &fd_read))
	  e.fct_read[i](&e, i);
    }
  return (0);
}
