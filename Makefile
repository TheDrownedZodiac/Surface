NAME	=	surface

SRCS	=	src/set_line.c		\
		src/set_pixel.c		\
		src/mk_colour.c		\
		src/clear_pixelarray.c	\
		src/main.c		\
		src/get_ratio.c		\
		src/get_value.c		\
		src/refresh.c		\
		src/project_paralell.c	\
		src/surface.c		\
		src/relief.c		\
		src/height_z.c		\
		src/project_isometric.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=	-llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

save:
	git status
	git add Makefile src/*.c include/*.h
	git commit -m "$(NAME) sauvegarde"
	git push

exe:
	make
	./surface
	make fclean

mclean:
	rm src/*.c~ src/*.o include/*.h~

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re
