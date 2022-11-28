NAME =	Containers

SRCS =	main.cpp\

CC = c++

OBJS_PATH = objects/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS:.cpp=.o}}

CFLAGS = -Wall -Werror -Wextra -std=c++98

${OBJS_PATH}%.o: ${SRCS_PATH}%.cpp
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

all:        $(NAME)

$(NAME):    $(OBJS)
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re