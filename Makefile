#Suketu Shah
#JoaoPaulo Rodgrigues

NAME = test
SRC = cs562.cpp
OBJ = $(SRC:.c=.o)
RM = rm -f
LIBS = -ggdb -lpq
CCFLAGS = -std=c++0x

all: $(OBJ) 
	g++ $(LIBS) $(SRC) -o $(NAME)

clean:
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)
	
re: fclean all
