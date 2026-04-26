NAME := 2048
MODE ?= default
PRETTY ?= 1
LOG_LEVEL ?= 2

BUILD_DIR := .build-$(MODE)
INCLUDES := -Iincludes -Ilibft/includes

CC := cc
CFLAGS = -Wall -Werror -Wextra -MD $(INCLUDES) -DPRETTY=$(PRETTY) -DLOG_LEVEL=$(LOG_LEVEL)
LDFLAGS := -lncurses

ifeq ($(MODE), debug)
	CFLAGS := -Wall -Wextra -MD $(INCLUDES) -g3
endif

VPATH := srcs

SRCS :=	main.c			\
		draw.c			\
		draw_screens.c	\
		update.c		\
		utils.c			\
		move.c			\
		init.c			\

OBJS := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

RESET	:= \033[0m
GRAY	:= \033[90m
RED 	:= \033[31m
GREEN 	:= \033[32m
YELLOW 	:= \033[33m
BLUE 	:= \033[34m

all:
	$(MAKE) libft
	mkdir -p $(BUILD_DIR)
	$(MAKE) $(NAME)

libft:
	$(MAKE) -C libft 1>/dev/null

debug:
	$(MAKE) -C libft debug
	$(MAKE) MODE=debug all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
ifeq ($(PRETTY), 1)
	printf "$(GRAY)compiling: $(BLUE)%-40s $(GRAY)[%d/%d]$(RESET)\n" "$<" "$$(ls $(BUILD_DIR) | grep -c '\.o')" "$(words $(SRCS))"
endif

clean:
	$(MAKE) -C libft clean
	rm -rf .build-*

fclean:
	$(MAKE) -C libft fclean
	rm -rf .build-*
	rm -f $(NAME)

re: fclean all

.PHONY: all libft debug clean fclean re

ifeq ($(PRETTY), 1)
.SILENT:
MAKEFLAGS += --no-print-directory
endif

-include $(DEPS)
