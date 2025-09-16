CPPC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98 -I.

SRCS = main.cpp Contact.class.cpp PhoneBook.class.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = PhoneBook

all : $(NAME)

$(NAME): $(OBJS)
	$(CPPC) $(CFLAG) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CPPC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	

