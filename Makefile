##
## Makefile for  in /home/moreno_i//afs/renduLocal/projets/irc
## 
## Made by igor morenosemedo
## Login   <moreno_i@epitech.net>
## 
## Started on  Tue Apr 17 22:00:37 2012 igor morenosemedo
## Last update Tue Apr 17 22:01:48 2012 igor morenosemedo
##

CC		=	gcc

NAME_CL		=	client

#NAME_SV		=	serveur

CL		=	cl/

##SV		=	sv/

LIB		=	lib/

SRC_CL		=	$(LIB)xaccept.c			\
			$(LIB)xbind.c			\
			$(LIB)xconnect.c		\
			$(LIB)xlisten.c			\
			$(LIB)xsocket.c			\
			$(LIB)xgetprotobyname.c 	\
			$(LIB)xfork.c			\
			$(LIB)xsetsockopt.c		\
			$(LIB)xclose.c			\
			$(LIB)xmalloc.c			\
			$(LIB)xread.c			\
			$(LIB)xfopen.c			\
			$(LIB)xwrite.c			\
			$(LIB)xopen.c			\
			$(LIB)error.c			\
			$(LIB)xpfunc.c			\
			$(CL)client.c


#SRC_SV		=	$(LIB)xaccept.c			\
			$(LIB)xbind.c			\
			$(LIB)xconnect.c		\
			$(LIB)xlisten.c			\
			$(LIB)xsocket.c			\
			$(LIB)xgetprotobyname.c		 \
			$(LIB)xfork.c			\
			$(LIB)xsetsockopt.c		\
			$(LIB)xclose.c			\
			$(LIB)xmalloc.c			\
			$(LIB)xread.c			\
			$(LIB)xfopen.c			\
			$(LIB)xwrite.c			\
			$(LIB)xopen.c			\
			$(LIB)error.c			\
			$(LIB)xpfunc.c			\
			$(SV)serveur.c			\
			$(SV)check_serv.c		\
			$(SV)my_cd_serv.c		\
			$(SV)exchange_serv.c

OBJ_CL		=	$(SRC_CL:.c=.o)

#OBJ_SV		=	$(SRC_SV:.c=.o)

CFLAGS		=	-Wall -Wextra -W -Werror

RM		=	rm -f


all		:	$(NAME_CL)
#all		:	$(NAME_SV) $(NAME_CL)

$(NAME_CL)	:	$(OBJ_CL)
			@$(CC) -o $(NAME_CL) $(OBJ_CL) $(CFLAGS)
			@echo -e "\033[32mclient ok\033[0m"

#$(NAME_SV)	:	(OBJ_SV)
#			@$(CC) -o $(NAME_SV) $(OBJ_SV) $(CFLAGS)
#			@echo -e "\033[32mserveur ok\033[0m"

clean		:
#			@$(RM) $(SV)*.o *~
			@$(RM) $(LIB)*.o *~
			@$(RM) $(CL)*.o *~
			@echo -e "\033[32mclean you all\033[0m"

fclean		:	clean
			@$(RM) $(NAME_CL)
#			@$(RM) $(NAME_SV)
			@echo -e "\033[32mfclean ok\033[0m"

re		:	fclean all