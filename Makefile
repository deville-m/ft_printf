NAME= libftprintf.a
AR= ar
ARFLAGS= rcs
CC= gcc
CFLAGS= -Wall -Wextra
INCLUDES= -I./
HEADER= ft_printf.h
SRC_DIR= srcs/

FT_PRINTSRC_DIR= $(addprefix $(SRC_DIR), ft_printsrc/)
FT_PRINTSRC= $(addprefix $(FT_PRINTSRC_DIR), ft_printf.c ft_fprintf.c)

FT_PUTSRC_DIR= $(addprefix $(SRC_DIR), ft_putsrc/)
FT_PUTSRC= $(addprefix $(FT_PUTSRC_DIR), \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_put_intmax_base_fd.c \
			ft_put_uintmax_base_fd.c \
			ft_put_pointer.c)

FT_UTILS_DIR= $(addprefix $(SRC_DIR), ft_utils/)
FT_UTILS= $(addprefix $(FT_UTILS_DIR), \
				ft_strlen.c \
				ft_imaxtoa.c \
				ft_nbrlen.c)

SRC= $(FT_PRINTSRC) $(FT_PUTSRC)
OBJ= $(notdir $(SRC:.c=.o))

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re
