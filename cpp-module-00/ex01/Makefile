SHELL := /bin/sh

OBJDIR   := objdir

CXXFLAGS += -Wall -Wextra -Werror -std=c++98
LDFLAGS  +=
LDLIBS   +=
CXX      ?= g++

SRCS     := main.cpp PhoneBook.cpp Contact.cpp
OBJS     := $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPS     := $(OBJS:.o=.d)
NAME     := phonebook

.PHONY: all clean fclean re options

all: $(NAME)

$(NAME): $(OBJS)
	$(LINK.cpp) $(OUTPUT_OPTION) $^

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
