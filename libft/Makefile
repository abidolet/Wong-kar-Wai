NAME := libft.a
MODE ?= default
PRETTY ?= 1
LOG_LEVEL ?= 1

CC := cc
CWARNS := -Wall -Wextra -pedantic -Wshadow -Wconversion -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Waggregate-return -Wfloat-equal -Wvla
CFLAGS := -Werror $(CWARNS) -Iincludes -MD -DPRETTY=$(PRETTY) -DLOG_LEVEL=$(LOG_LEVEL)

ifeq ($(MODE), debug)
	CFLAGS := $(CWARNS) -Iincludes -MD -DPRETTY=$(PRETTY) -DLOG_LEVEL=$(LOG_LEVEL) -g3
endif

VPATH :=	srcs/algo		\
			:srcs/ft_printf	\
			:srcs/is		\
			:srcs/lst		\
			:srcs/map		\
			:srcs/math		\
			:srcs/mem		\
			:srcs/node		\
			:srcs/print		\
			:srcs/rbn		\
			:srcs/rbt		\
			:srcs/read		\
			:srcs/set		\
			:srcs/str		\
			:srcs/to		\
			:srcs/vec		\

BUILD_DIR := .build-$(MODE)

SRCS_ALGO :=	ft_binary_search.c		\
				ft_linear_search.c		\
				ft_qsort.c				\
				ft_reverse.c			\
				ft_rotate.c				\
				ft_swap.c				\
				ft_unique.c				\

SRCS_PRINTF :=	run.c					\

SRCS_IS :=		ft_isalnum.c			\
				ft_isalpha.c			\
				ft_isascii.c			\
				ft_isblank.c			\
				ft_iscntrl.c			\
				ft_isdigit.c			\
				ft_isgraph.c			\
				ft_islower.c			\
				ft_isprint.c			\
				ft_ispunct.c			\
				ft_isspace.c			\
				ft_isupper.c			\
				ft_isxdigit.c			\

SRCS_LST :=		ft_lstadd_back.c		\
				ft_lstadd_front.c		\
				ft_lstclear.c			\
				ft_lstdelone.c			\
				ft_lstdestroy.c			\
				ft_lstiter.c			\
				ft_lstlast.c			\
				ft_lstmap.c				\
				ft_lstmerge.c			\
				ft_lstnew.c				\
				ft_lstremove_if.c		\
				ft_lstreverse.c			\
				ft_lstsize.c			\
				ft_lstsort.c			\

SRCS_MAP :=		ft_mapat.c				\
				ft_mapclear.c			\
				ft_mapcontains.c		\
				ft_mapempty.c			\
				ft_maperase.c			\
				ft_mapfind.c			\
				ft_mapinsert.c			\
				ft_mapiter.c			\
				ft_mapnew.c				\
				ft_mapsize.c			\

SRCS_MATH :=	ft_abs.c				\
				ft_cabs.c				\
				ft_cclamp.c				\
				ft_ceil.c				\
				ft_ceilf.c				\
				ft_clamp.c				\
				ft_cmax.c				\
				ft_cmin.c				\
				ft_dabs.c				\
				ft_dclamp.c				\
				ft_dmax.c				\
				ft_dmin.c				\
				ft_fabs.c				\
				ft_fclamp.c				\
				ft_floor.c				\
				ft_floorf.c				\
				ft_fmax.c				\
				ft_fmin.c				\
				ft_labs.c				\
				ft_lclamp.c				\
				ft_lmax.c				\
				ft_lmin.c				\
				ft_luclamp.c			\
				ft_lumax.c				\
				ft_lumin.c				\
				ft_max.c				\
				ft_min.c				\
				ft_round.c				\
				ft_roundf.c				\
				ft_sabs.c				\
				ft_sclamp.c				\
				ft_smax.c				\
				ft_smin.c				\
				ft_trunc.c				\
				ft_truncf.c				\
				ft_ucclamp.c			\
				ft_uclamp.c				\
				ft_ucmax.c				\
				ft_ucmin.c				\
				ft_umax.c				\
				ft_umin.c				\
				ft_usclamp.c			\
				ft_usmax.c				\
				ft_usmin.c				\
				ft_zdabs.c				\
				ft_zdclamp.c			\
				ft_zdmax.c				\
				ft_zdmin.c				\
				ft_zuclamp.c			\
				ft_zumax.c				\
				ft_zumin.c				\

SRCS_MEM :=		ft_bzero.c				\
				ft_calloc.c				\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memcpy.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_realloc.c			\

SRCS_NODE :=	ft_nodeis_leaf.c		\
				ft_nodeis_root.c		\
				ft_nodenew.c			\

SRCS_PRINT :=	ft_asprintf.c			\
				ft_dprintf.c			\
				ft_log.c				\
				ft_printf.c				\
				ft_putchar_fd.c			\
				ft_putendl_fd.c			\
				ft_putnbr_fd.c			\
				ft_putstr_fd.c			\
				ft_snprintf.c			\
				ft_sprintf.c			\
				ft_vasprintf.c			\
				ft_vdprintf.c			\
				ft_vprintf.c			\
				ft_vsnprintf.c			\
				ft_vsprintf.c			\

SRCS_RBN :=		ft_node_to_rbn.c		\
				ft_rbnattach.c			\
				ft_rbnclear.c			\
				ft_rbndel.c				\
				ft_rbndetach.c			\
				ft_rbnget_child.c		\
				ft_rbnget_color.c		\
				ft_rbnget_data.c		\
				ft_rbnget_grandparent.c	\
				ft_rbnget_left.c		\
				ft_rbnget_parent.c		\
				ft_rbnget_right.c		\
				ft_rbnget_sibling.c		\
				ft_rbnget_uncle.c		\
				ft_rbnis_black.c		\
				ft_rbnis_leaf.c			\
				ft_rbnis_left_child.c	\
				ft_rbnis_line.c			\
				ft_rbnis_nil.c			\
				ft_rbnis_red.c			\
				ft_rbnis_right_child.c	\
				ft_rbnis_root.c			\
				ft_rbnis_triangle.c		\
				ft_rbnmax.c				\
				ft_rbnmin.c				\
				ft_rbnnew.c				\
				ft_rbnnext.c			\
				ft_rbnrecolor.c			\
				ft_rbnreplace.c			\
				ft_rbnrotate_left.c		\
				ft_rbnrotate_right.c	\
				ft_rbnrotate.c			\
				ft_rbnset_color.c		\
				ft_rbnset_data.c		\
				ft_rbnset_left.c		\
				ft_rbnset_parent.c		\
				ft_rbnset_right.c		\

SRCS_RBT :=		ft_rbtat.c				\
				ft_rbtclear.c			\
				ft_rbtdelete.c			\
				ft_rbtempty.c			\
				ft_rbterase.c			\
				ft_rbtfind.c			\
				ft_rbtheight.c			\
				ft_rbtinit.c			\
				ft_rbtinsert.c			\
				ft_rbtiter.c			\
				ft_rbtmax.c				\
				ft_rbtmin.c				\
				ft_rbtnew.c				\
				ft_rbtsize.c			\
				ft_rbttransplant.c		\

SRCS_READ :=	ft_checkextension.c		\
				ft_getdelim.c			\
				ft_getfile.c			\
				ft_getline.c			\
				ft_readfile.c			\
				get_next_line.c			\

SRCS_SET := 	ft_setat.c				\
				ft_setback.c			\
				ft_setclear.c			\
				ft_setcontains.c		\
				ft_setempty.c			\
				ft_seterase.c			\
				ft_setfind.c			\
				ft_setfront.c			\
				ft_setinsert.c			\
				ft_setiter.c			\
				ft_setnew.c				\
				ft_setsize.c			\

SRCS_STR :=		ft_split.c				\
				ft_strchr.c				\
				ft_strcmp.c				\
				ft_strcpy.c				\
				ft_strdup.c				\
				ft_striteri.c			\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlcpy.c			\
				ft_strlen.c				\
				ft_strmapi.c			\
				ft_strncmp.c			\
				ft_strndup.c			\
				ft_strnjoin.c			\
				ft_strnstr.c			\
				ft_strrchr.c			\
				ft_strtrim.c			\
				ft_substr.c				\

SRCS_TO :=		ft_atoi_base.c			\
				ft_atoi.c				\
				ft_atol.c				\
				ft_itoa.c				\
				ft_strtoi.c				\
				ft_strtol.c				\
				ft_tolower.c			\
				ft_toupper.c			\

SRCS_VEC :=		ft_vecassign.c			\
				ft_vecat.c				\
				ft_vecback.c			\
				ft_vecclear.c			\
				ft_vecempty.c			\
				ft_vecend.c				\
				ft_vecerase.c			\
				ft_vecfind_sorted.c		\
				ft_vecfind.c			\
				ft_vecfront.c			\
				ft_vecinit.c			\
				ft_vecinsert.c			\
				ft_veciter.c			\
				ft_vecmap.c				\
				ft_vecmerge.c			\
				ft_vecnew.c				\
				ft_vecpop_back.c		\
				ft_vecpush_back.c		\
				ft_vecremove_if.c		\
				ft_vecreserve.c			\
				ft_vecresize.c			\
				ft_vecreverse.c			\
				ft_vecrotate.c			\
				ft_vecshrink_to_fit.c	\
				ft_vecsize.c			\
				ft_vecsort.c			\
				ft_vecunique.c			\

SRCS :=	$(SRCS_ALGO)	\
		$(SRCS_PRINTF)	\
		$(SRCS_IS)		\
		$(SRCS_LST)		\
		$(SRCS_MAP)		\
		$(SRCS_MATH)	\
		$(SRCS_MEM)		\
		$(SRCS_NODE)	\
		$(SRCS_PRINT)	\
		$(SRCS_RBN)		\
		$(SRCS_RBT)		\
		$(SRCS_READ)	\
		$(SRCS_SET)		\
		$(SRCS_STR)		\
		$(SRCS_TO)		\
		$(SRCS_VEC)		\

OBJS := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

RESET	:= \033[0m
GRAY	:= \033[90m
RED 	:= \033[31m
GREEN 	:= \033[32m
YELLOW 	:= \033[33m
BLUE 	:= \033[34m

all: $(NAME)

debug:
		$(MAKE) MODE=debug

$(NAME): $(BUILD_DIR) $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(BUILD_DIR):
		mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
		$(CC) $(CFLAGS) -c $< -o $@
ifeq ($(PRETTY), 1)
	printf "$(GRAY)compiling: $(BLUE)%-40s $(GRAY)[%d/%d]$(RESET)\n" "$<" "$$(ls $(BUILD_DIR) | grep -c '\.o')" "$(words $(SRCS))"
endif

clean:
		rm -rf .build-*

fclean: clean
		rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all debug clean fclean re bonus

ifeq ($(PRETTY), 1)
.SILENT:
MAKEFLAGS += --no-print-directory
endif

-include $(DEPS)
