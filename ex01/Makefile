PROG := ex01

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += -std=c++98
SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp

OBJS := $(SRCS:.cpp=.o)

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

all: $(PROG)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(PROG)

re:	fclean all

.PHONY:	all clean fclean re
