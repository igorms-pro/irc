/*
** serveur.c for  in /home/moreno_i//afs/renduLocal/projets/irc/tp/tp_irc
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Mon Apr 16 18:16:22 2012 igor morenosemedo
** Last update Mon Apr 16 18:16:23 2012 igor morenosemedo
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/syslimits.h>
#include <unistd.h>

#define FD_FREE0
#define FD_CLIENT1
#define FD_SERVER2

#define MAX_FDOPEN_MAX

typedef void(*fct)();

typedef structs_env
{
  charfd_type[MAX_FD];
  fctfct_read[MAX_FD];
  fctfct_write[MAX_FD];
  intport;
}t_env;

voidclient_read(t_env *e, int fd)
{
  int   r;
  charbuf[4096];

  r = read(fd, buf, 4096);
  if (r > 0)
    {
      buf[r] = '\0';
      my_putnbr(fd);
      my_putstr(": ");
      my_putstr(buf);
      my_putstr("\n");
    }
  else
    {
      my_putnbr(fd);
      my_putstr(": ");
      my_putstr("Connexion closed\n");
      close(fd);
      e->fd_type[fd] = FD_FREE;
    }
}

voidadd_client(t_env *e, int s)
{
  intcs;
  struct sockaddr_in    client_sin;
  int                   client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = NULL;
}

voidserver_read(t_env *e, int fd)
{
  my_putstr("New client\n");
  add_client(e, fd);
}

voidadd_server(t_env *e)
{
  int                   s;
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

intmain(int argc, char **argv)
{
  t_enve;
  inti, fd_max;
  fd_setfd_read;
  struct timevaltv;

  memset(e.fd_type, FD_FREE, MAX_FD);
  e.port = atoi(argv[1]);
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
	aff_err("select");
      for (i = 0; i < MAX_FD; i++)
	if (FD_ISSET(i, &fd_read))
	  e.fct_read[i](&e, i);
      my_putstr("waiting...\n");
    }
  return (0);
}
