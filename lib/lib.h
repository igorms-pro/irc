/*
** lib.h for  in /home/moreno_i//afs/renduLocal/projets/ftp/lib
**
** Made by igor morenosemedo
** Login   <moreno_i@epitech.net>
**
** Started on  Fri Apr  6 18:47:48 2012 igor morenosemedo
** Last update Wed Apr 18 13:51:30 2012 igor morenosemedo
*/

#ifndef _LIB_H_
# define _LIB_H_

# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <limits.h>

FILE		*xpopen(const char *command, const char *type);
int		xpclose(FILE *stream);
FILE		*xfopen(const char *path, const char *mode);
int		xopen(const char *pathname, int flags, mode_t mode);
int		xwrite(int fd, const void *buf, size_t count);
int		xread(int fd, void *buf, int count);
int		xclose(int fd);
void		*xmalloc(int n);
pid_t		xfork(void);
int		xsocket(int domain, int type, int protocol);
int		xbind(int sockfd, const struct sockaddr *addr,
		      socklen_t addrlen);
int		xlisten(int sockfd, int backlog);
int		xaccept(int sockfd, struct sockaddr *addr,
			socklen_t *addrlen);
int		xconnect(int sockfd, const struct sockaddr *addr,
			 socklen_t addrlen);
int		xsetsockopt(int sockfd, int level, int optname,
			   const void *optval, socklen_t optlen);
void		error(char *s);
void		error_file(char *s1, char *s);
struct protoent	*xgetprotobyname(const char *name);

#endif
