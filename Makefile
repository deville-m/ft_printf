NAME= libftprintf.a
AR= ar
ARFLAGS= rcs
CC= gcc
CFLAGS= -Wall -Wextra
INCLUDES= -I./
HEADER= ft_printf.h
SRC_DIR= srcs/

FT_PRINTSRC_DIR= $(addprefix $(SRC_DIR), ft_printsrc/)
FT_PRINTSRC= $(addprefix $(FT_PRINTSRC_DIR), \
			ft_printf.c \
			ft_fprintf.c \
			ft_vfprintf.c)

FT_PUTSRC_DIR= $(addprefix $(SRC_DIR), ft_putsrc/)
FT_PUTSRC= $(addprefix $(FT_PUTSRC_DIR), \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_put_llint_fd.c \
			ft_put_ullint_base_fd.c \
			ft_put_pointer_fd.c)

FT_UTILS_DIR= $(addprefix $(SRC_DIR), ft_utils/)
FT_UTILS= $(addprefix $(FT_UTILS_DIR), \
			base_8.c \
			base_10.c \
			base_16.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_llitoa.c \
			ft_ullitoa.c \
			ft_strcmp.c \
			ft_atoi.c \
			ft_strdup.c)

PARSER_DIR= $(addprefix $(SRC_DIR), parser/)
PARSER= $(addprefix $(PARSER_DIR), \
			parse_token.c \
			print_token.c)

SRC= $(FT_PRINTSRC) $(FT_PUTSRC) $(FT_UTILS) $(PARSER)
OBJ= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re
