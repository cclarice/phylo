# **************************************************************************** #
#                                                                              #
#        ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::   #
#      :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+:  #
#     +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+   #
#    +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:    #
#   +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+            #
#  #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#      #
#   ######    ######  ############## ###    ### ###   ######    #######        #
#                                                                              #
# **************************************************************************** #
#                                                                              #
#    Makefile                                 cclarice@student.21-school.ru    #
#                                                                              #
#    Created/Updated: 2021/06/29 22:44:28  /  2021/06/29 23:47:52 @cclarice    #
#                                                                              #
# **************************************************************************** #

# Header & Name
NAME = philo
HEAD = src/philo.h

# Sources
SRCF = src
SRC  = main.c utils.c philo.c write.c
SRCS = $(addprefix $(SRCF)/, $(SRC))

# Objects
OBJF = obj
OBJS = $(patsubst $(SRCF)/%.c, $(OBJF)/%.o, $(SRCS))

# Compile
FLAG = -Wall -Wextra -Werror -O3
MKDR = mkdir -p
SAY  = echo -e
RM   = rm -rf
CC   = clang

# Compile Rule
all: $(OBJF) $(NAME)

$(OBJF):
	@if [ ! -a "${OBJF}" ]; then $(MKDR) $(OBJF); $(MKDR) $(OBJFS) ;\
	$(SAY) "Created \033[33m$(OBJF) $(OBJFS)\033[0m"; fi

obj/%.o: src/%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	@$(SAY) "Compilng \033[33m$< \033[0mto \033[36m$@\033[0m"

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@$(SAY) "Compilng \033[35m$(NAME)\033[0m"
	@$(SAY) "Makefile \033[32mDone!\033[0m"

# Clean and recompile rules
clean:
	@if [ -a "${OBJF}" ]; then $(RM) $(OBJF); \
	$(SAY) "Removing \033[31m$(OBJF)\033[0m"; fi

fclean: clean
	@if [ -a "${NAME}" ]; then $(RM) $(NAME); \
	$(SAY) "Removing \033[31m$(NAME)\033[0m"; fi

re: fclean all
