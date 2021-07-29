NAME = 	libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = Libft/ft_strlen \
      	Libft/ft_strdup \
      	Libft/ft_strchr \
      	Libft/ft_atoi \
      	Libft/ft_isdigit \
      	Libft/ft_toupper \
      	Libft/ft_putchar_fd \
      	Libft/ft_putstr_fd \
      	Libft/ft_itoa \
	  	Libft/ft_substr \
		Libft/ft_isalpha\
	  	ft_printf \
	  	handle_types \
		extra_printf \
	 	writf

FILES_B = Libft/ft_strlen \
      	Libft/ft_strdup \
      	Libft/ft_strchr \
      	Libft/ft_atoi \
      	Libft/ft_isdigit \
      	Libft/ft_toupper \
      	Libft/ft_putchar_fd \
      	Libft/ft_putstr_fd \
      	Libft/ft_itoa \
	  	Libft/ft_substr \
		Libft/ft_isalpha \
		ft_printf \
		handle_types \
		extra_printf \
		writf  

S = ./
SRCS = $(addprefix $(S), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(S), $(addsuffix .c, $(FILES_B)))

O = ./
OBJS = $(addprefix $(S), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(S), $(addsuffix .o, $(FILES_B)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^
#	$(MAKE) ../Libft

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean: 
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
