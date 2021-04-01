NAME= push_swap
SRC_PATH= srcs
HDR_PATH= includes
OBJ_PATH= obj
LIB_PATH= libft
TOOLS_PATH=$(OBJ_PATH)/tools
SHARED_PATH=$(OBJ_PATH)/shared

SRC_TOOLS= tools/ft_abs.c tools/min.c tools/max.c tools/size_arg.c tools/list.c tools/check_sort.c
SRC_NAME=push_swap.c checker.c shared/push_a.c $(SRC_TOOLS)
HDR_NAME=push_swap.h 

OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB= libft.a
# FLAGS= -Wall -Wextra -Werror
# LDFLAGS=`sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a -lncurses
H_FLAG= -I $(HDR_PATH)

COMP= gcc

all: lib  $(NAME) 

$(NAME) : $(LIB_PATH)/$(LIB) $(OBJ) $(LDFLAGS)
	@rm -rf push_swap
	@$(COMP) -g $(H_FLAG) $(OBJ) $(LLIB_FLAG) -o $@
	@echo "						Compilation of $(NAME):  \033[1;32mOK\033[m"

lib:
	@make -sC $(LIB_PATH)

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) $(TOOLS_PATH) $(SHARED_PATH)
	@$(COMP) -g $(FLAGS) $(H_FLAG) -g -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;31m>> $(NAME) && all obbjects are deleted.\033[0m" 

re : fclean all
