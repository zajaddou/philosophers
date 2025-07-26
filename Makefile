
NAME= philo

CC= cc -Wall -Wextra -Werror 

CFLAG= -fsanitize=address -g3

MDR = main.c parse.c init.c static.c

OBJ_M= $(MDR:%.c=%.o)

all: $(NAME) clean

$(NAME): $(OBJ_M) 
	$(CC) $(CFLAG) $(OBJ_M) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rif $(OBJ_M)
	clear

fclean: clean
	rm -rif $(NAME)
	clear

push: fclean
	@git add .
	@git commit -m "update"
	@git push

run: philo clean
	clear && ./philo

re: fclean all
	clear
