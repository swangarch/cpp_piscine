CPPC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

INCLUDES = -I.

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = RPN

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPC) $(CFLAG) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CPPC) $(INCLUDES) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re