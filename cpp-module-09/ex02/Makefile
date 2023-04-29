SHELL := /bin/sh

OBJDIR   := objdir

CXXFLAGS += -Wall -Wextra -Werror -std=c++98
LDFLAGS  +=
LDLIBS   +=
CXX      := c++
LINK.cpp := $(filter-out $(CXXFLAGS), $(LINK.cpp))

SRCS     := main.cpp PmergeMe.cpp
OBJS     := $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPS     := $(OBJS:.o=.d)
NAME     := PmergeMe

.PHONY: all clean fclean re options

all: $(NAME)

$(NAME): $(OBJS)
	$(LINK.cpp) $(LDLIBS) $(OUTPUT_OPTION) $^

$(OBJDIR)/%.o: %.cpp Makefile | $(OBJDIR)
	$(COMPILE.cpp) $(OUTPUT_OPTION) -MMD -MP $<

-include $(DEPS)

$(OBJDIR):
	mkdir $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

options:
	@echo "$(NAME) build options:"
	@echo "CXXFLAGS      = $(CXXFLAGS)"
	@echo "LDFLAGS       = $(LDFLAGS)"
	@echo "LDLIBS        = $(LDLIBS)"
	@echo "CXX           = $(CXX)"
