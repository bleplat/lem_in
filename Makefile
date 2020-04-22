# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:05:04 by bleplat           #+#    #+#              #
#    Updated: 2020/03/10 19:35:47 by jthierce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################
###   B I N A R I E S   ###
###########################

NAME        = lem-in


###########################
###  L I B R A R I E S  ###
###########################

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBFTMO     = libftmo.so


###########################
###    S O U R C E S    ###
###########################

FNT =		li_main.c \
			li_perror.c \
			li_board.c \
			li_room.c \
			li_link.c \
			li_parse_input.c \
			li_parse_ants.c \
			li_parse_room.c \
			li_parse_link.c \
			li_parsing_finalize_rooms.c \
			li_parsing_should_line_be_ignored.c \
			li_parse_start_end.c \
			li_room_find.c \
			li_make_link.c \
			li_board_add_output.c \
			li_print_input.c \
			li_print_result.c \
			li_print_singleround_result.c \
			li_print_move.c \
			li_print_result_from_choices.c \
			li_board_pop_output.c \
			li_resolve.c \
			li_matrice.c \
			li_ini_matrice_link.c \
			li_memrealloc.c \
			li_bfs.c \
			li_bfs_body.c \
			li_create_path.c \
			li_calc_steps.c \
			li_insertion_sort.c \
			li_print_matrice.c \
			li_reset_bfs.c \
			li_pathes.c \
			li_ant_choices_create.c \
			li_distance_path.c \
			li_compute_rounds_needed.c


###########################
###    F O L D E R S    ###
###########################

INCLUDES = includes
SRC_DIR  = srcs
OBJ_DIR  = .obj
DEP_DIR  = $(OBJ_DIR)

SRC = $(patsubst %, $(SRC_DIR)/%, $(FNT))
DEP = $(patsubst %, $(DEP_DIR)/%.d, $(FNT))
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT))


###########################
###   C O M P I L E R   ###
###########################

CC = gcc

DEFINES = _DARWIN_USE_64_BIT_INODE
CDEFINES = $(patsubst %, -D%, $(DEFINES))

CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(CDEFINES)
CFLAGS += -I $(INCLUDES)
CFLAGS += -I $(LIBFT_DIR)/includes
#CFLAGS += -o3

LDFLAGS += -L $(LIBFT_DIR) -lft


###########################
###      R U L E S      ###
###########################

.PHONY: all
all: $(NAME)

.PHONY: update
update:
	@printf "\e[95m" || true
	git remote update
	git status -uno
	@printf "\e[0m" || true

.PHONY: upgrade
upgrade:
	@printf "\e[95m" || true
	git pull
	@printf "\e[0m" || true

.PHONY: debug
debug: LDFLAGS += -L. -lftmo -rdynamic
debug: $(LIBFTMO) all

.PHONY: optimized
optimized: CFLAGS += -o3
optimized: all

$(NAME): $(LIBFT) $(OBJ)
	@printf "\e[92m" || true
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "\e[0m" || true

$(OBJ_DIR):
	@printf "\e[94m" || true
	mkdir -p $@
	@printf "\e[0m" || true

$(OBJ_DIR)/%.o: $(SRC_DIR)/% | $(OBJ_DIR)
	@printf "\e[96m" || true
	$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\e[0m" || true

$(LIBFT):
	@printf "\e[35m" || true
	make -C $(LIBFT_DIR) libft.a
	@printf "\e[0m" || true

$(LIBFTMO):
	@printf "\e[35m" || true
	make -C $(LIBFT_DIR) libftmo.so
	@printf "\e[35m" || true
	cp $(LIBFT_DIR)/libftmo.so $@
	@printf "\e[0m" || true

.PHONY: clean
clean:
	@printf "\e[93m" || true
	rm -f $(OBJ)
	rm -f $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR) || true
	make -C $(LIBFT_DIR) $@
	@printf "\e[0m" || true

.PHONY: fclean
fclean: clean
	@printf "\e[91m" || true
	rm -f $(NAME)
	rm -f $(LIBFTMO)
	make -C $(LIBFT_DIR) $@
	@printf "\e[0m" || true

.PHONY: re
re: fclean all
	@printf "\e[0m" || true


###########################
###  D O C   R U L E S  ###
###########################

.PHONY: geterror
geterror:
	grep _ERROR_ includes/li.h

.PHONY: help
help:
	@printf "\e[0mUSAGE:\n\e[0m" || true
	@printf "\e[0m\t./lem_in < MAP_FILE\n\e[0m" || true
	@printf "\e[0m\t./generator [OPTIONS] | ./lem_in\n\e[0m" || true
