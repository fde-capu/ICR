# ********************************************* #
#                                               #
#                      ::|:||:||::|:|:|||:||||  #
#  Makefile            :|:|::|::||:|:::|::::||  #
#                      :::|||::||||||::::::|:|  #
#                                               #
#                                               #
#  C20201111080450 :|:||:                       #
#  U20201111121728 ||:|:|                       #
#                                               #
# ********************************************* #

NAME	=	icr.a
CC		=	clang -Wall -Werror -Wextra -g
VALG	=	valgrind --leak-check=full --show-leak-kinds=all
SRCS	=	icr.c prints.c builds.c navigation.c helpers.c
HEAD	=	header.h
OBJS	=	$(SRCS:.c=.o)

all		:	$(HEAD) $(NAME)

$(SRCS)	:
	$(CC) -o $(OBJS) $(SRCS)

$(NAME)	:	$(OBJS) $(HEAD)
	$(CC) -o $(NAME) $(OBJS)

t		:	re
	$(VALG) ./$(NAME) 111111

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all
