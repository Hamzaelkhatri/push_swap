NAME_PUSH_SWAP= push_swap
NAME_CHECKER= checker
SRC_PATH= srcs
HDR_PATH= includes
OBJ_PATH= obj
LIB_PATH= libft
TOOLS_PATH=$(OBJ_PATH)/tools
SHARED_PATH=$(OBJ_PATH)/shared

SRC_SHARED= shared/push_a.c shared/check_digit.c shared/check_colors.c shared/debug.c shared/shared.c shared/algo_1.c shared/free.c shared/medieum.c shared/pivot.c shared/print.c shared/push_b.c shared/rotate_a.c shared/rotate_b.c shared/rotate.c shared/swap_a.c shared/swap_b.c shared/swap_s.c shared/algo_2.c shared/index.c
SRC_TOOLS= tools/ft_abs.c tools/min.c tools/max.c tools/check.c tools/size_arg.c tools/list.c tools/check_sort.c tools/strdup_2d.c tools/ft_strcmp.c tools/ft_atol.c
SRC_NAME=push_swap.c  debugger.c $(SRC_SHARED) $(SRC_TOOLS) 
SRC_CHECKER= checker.c $(SRC_SHARED) $(SRC_TOOLS)
HDR_NAME=push_swap.h 

OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ_NAME_CHECKER= $(SRC_CHECKER:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_CHECKER= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME_CHECKER))

LIB= libft.a
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_FLAG= -I $(HDR_PATH)

COMP= gcc

# FLAGS = -Wall -Wextra -Werror

all: lib $(NAME_CHECKER) $(NAME_PUSH_SWAP) 

$(NAME_PUSH_SWAP) : $(LIB_PATH)/$(LIB) $(OBJ)
	@rm -rf push_swap
	@$(COMP) -g $(H_FLAG) $(OBJ) $(LLIB_FLAG) -o $@
	@echo "						Compilation of $(NAME_PUSH_SWAP):  \033[1;32mOK\033[m"

$(NAME_CHECKER) : $(LIB_PATH)/$(LIB) $(OBJ_CHECKER)
	@rm -rf checker
	@$(COMP) -g $(H_FLAG) $(OBJ_CHECKER) $(LLIB_FLAG) -o $@
	@echo "						Compilation of $(NAME_CHECKER):  \033[1;32mOK\033[m"

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
	@rm -rf $(NAME_PUSH_SWAP) $(NAME_CHECKER)
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;31m>> $(NAME_PUSH_SWAP) $(NAME_CHECKER) && all obbjects are deleted.\033[0m" 

re : fclean all
