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
#    Created/Updated: 2021/07/10 01:23:40  /  2021/07/10 15:22:35 @cclarice    #
#                                                                              #
# **************************************************************************** #

# Header & Name
NAME = philo
HEAD = src/philo.h

# Sources
SRCF = src
SRC  = amour.c birth.c exist.c grave.c     philo.c     utils_time.c utils_args.c
SRCS = $(addprefix $(SRCF)/, $(SRC))

# Objects
OBJF = obj
OBJS = $(patsubst $(SRCF)/%.c, $(OBJF)/%.o, $(SRCS))

# Compile
FLAG = -Wall -Wextra -O3 #-Werror
MKDR = mkdir -p
SAY  = echo -e
RM   = rm -rf
CC   = clang

# Compile Rule
all: $(OBJF) $(NAME)

$(OBJF):
	@if [ ! -a "${OBJF}" ]; then $(MKDR) $(OBJF);\
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
