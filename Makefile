SRC =	pipex.c	utils.c	utils2.c	error_check.c getNext/get_next_line.c	getNext/get_next_line_utils.c 

NAME = pipex

INC = Libft/libft.a

all: ${NAME}

${NAME}: ${SRC}
	@make -C ./Libft
	@cc -Wall -Wextra -Werror $^ ${INC} -o $@ -D M=1

clean:
	@make clean -C ./Libft

fclean: clean
	@make fclean -C ./Libft
	@rm -f ${NAME} checker

bonus: ${SRC}
	@make -C ./Libft
	@cc -Wall -Wextra -Werror $^ ${INC} -o ${NAME} -D M=0

re: fclean all

.PHONY: all clean fclean bonus re