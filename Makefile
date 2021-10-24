# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/10/24 19:22:42 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol
CC = 	clang -Wall -Werror -Wextra
AR =	ar rcs
RM = 	rm -rf
FLAGS =	-O2# -g# -fsanitize=address

# GRAPHICAL LFGLAGS (for linux):
ifeq ($(shell uname), Linux)
	LDFLAGS		+=	-lXext -lX11
else
	LDFLAGS		+=	-lmlx -framework OpenGL -framework AppKit
# -lmlx

# LDFLAGS (math.h)
LDFLAGS		+=	-lm

# **************************************************************************** #

MAKEFLAGS += --silent

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LBPATH =	./libft/
LBNAME =	$(LBPATH)libft.a
LBINC =		-I$(LBPATH)

ifeq ($(shell uname), Linux)
	MLXPATH =	./mlx/
else
	MLXPATH	=	./mlx_macos/
endif

MLXNAME =	$(MLXPATH)libmlx.a
MLXINC =	-I$(MLXPATH)

# **************************************************************************** #

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCSNAME =	main.c \
			ft_arg.c \
			ft_render.c color.c \
			ft_display.c \
			fractal_set/julia.c fractal_set/julia_s.c \
			fractal_set/mandelbrot.c fractal_set/ma_set.c \
			fractal_set/mandelbar.c fractal_set/burning_ship.c \
			free.c zoom.c keypress.c \
			utils/ft_is_double.c utils/ft_is_num.c \
			utils/help.c utils/ft_init.c

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
OBJSNAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJSPATH), $(notdir $(OBJSNAME)))

%.o: %.c
	$(CC) $(FLAGS) -Imlx $(BUFFER) -I$(INC) -c $< -o $(OBJSPATH)$(notdir $@)

# *************************************************************************** #

all:		$(NAME)

$(NAME):	objs_dir $(OBJSNAME) lib mlx
	#@$(AR) $(NAME) $(OBJS)
	@$(CC) $(FLAGS) $(LDFLAGS) $(OBJS) $(LBNAME) $(MLXNAME) -o $(NAME)
	@echo "$(B)$(MAG)$(NAME) compiled$(D)"

objs_dir:
	@mkdir $(OBJSPATH) 2> /dev/null || true
	
lib:
	@make -C $(LBPATH)

mlx:
	@make -C $(MLXPATH)

clean:
	@$(RM) $(OBJSNAME)
	@make clean -C $(LBPATH)
	@make clean -C $(MLXPATH)
	@echo "$(B)Cleared.$(D)"


fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME)
	@make fclean -C $(LBPATH)

re:			fclean all

.PHONY: all clean fclean re objs_dir lib mlx

# **************************************************************************** #
