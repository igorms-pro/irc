/*
** serveur.c for  in /home/moreno_i//afs/renduLocal/projets/irc/tp/cours
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Mon Apr 16 16:00:17 2012 igor morenosemedo
** Last update Mon Apr 16 17:33:20 2012 igor morenosemedo
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define CLWRITE "Epitech cest shit\n"

void		do_client(int cs1, int cs2)
{
  char		buff[512];
  int		len;
  int		len2;

  len = read(cs1, buff, 512);
  if (len == -1)
    {
      fprintf(stderr, "read fail\n");
      exit (EXIT_FAILURE);
    }
  len2 = write(cs2, buff, len);
  if (len2 != -1)
    if (len2 < len)
    len2 = write(cs2, &buff[len2], len - len2);
}

int			main(int ac, char **av)
{
  struct protoent      *pe;
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_client;

  int			client_len;
  int			s;
  int			port;
  int			error;
  int			cs = 0;
  int			cs1;
  int			cs2;
  char			*str;
  fd_set		readfs;

  if (ac != 2)
    {
      printf("USAGE: ou est le port\n");
      exit (0);
    }
  port = atoi(av[1]);
  pe = getprotobyname("TCP");
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto); //n°du protocole
  if (s == -1)
    {
      write(2, "socket", strlen("socket"));
      exit(0);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  error = bind(s, (const struct sockaddr *)&sin, sizeof(sin));
  if (error == -1)
    {
      write(2, "bind error", strlen("bind error"));
      close(cs);
      exit(0);
    }
  error = listen(s, 42);
  if (error == -1)
    {
      write(2, "listen error", strlen("listen error"));
      close (s);
      exit(0);
    }
  client_len = sizeof(sin_client);
  cs1 = accept (s, (struct sockaddr *) &sin_client,
		  (socklen_t *)&client_len);
  cs2 = accept (s, (struct sockaddr *) &sin_client,
		  (socklen_t *)&client_len);
  if (cs1 == -1 || cs2 == -1)
    {
      write(2, "accept error", strlen("accept error"));
      close (s);
      exit(0);
    }
  error = 0;
  while (error != -1)
    {
      FD_ZERO(&readfs);
      FD_SET(cs1, &readfs);
      FD_SET(cs2, &readfs);

      if ((error = select(6, &readfs, NULL, NULL, NULL)) != -1)
	{
	  if (FD_ISSET(cs1, &readfs))
	    do_client(cs1, cs2);
	  if (FD_ISSET(cs2, &readfs))
	    do_client(cs2, cs1);
	}
    }
  close (s);
  close (cs1);
  close (cs2);
  return (0);
}
