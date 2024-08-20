NAME =	Bureaucrat

SRCS =	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp

OBJS =	$(SRCS:.cpp=.o)

CC =	c++

CFLAGS =	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re:all  clean