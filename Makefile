NAME    = philo

CC      = cc
CFLAGS  = -Wall -Wextra -Werror 

SRC     = philo.c \
          functions/parse.c \
          functions/init.c \
          functions/monitor.c \
          functions/print.c \
          functions/philo_life.c \
          functions/static.c \
          functions/static2.c

OBJ     = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: all clean

push: fclean
	@git add .
	@git commit -m "update"
	@git push

run: all
	clear && ./philo 4 410 200 200 3
