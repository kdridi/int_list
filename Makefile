##
## EPITECH PROJECT, 2020
## int_list
## File description:
## int_list make rules
##

CC			=	gcc --coverage
CFLAGS		=	-W -Wall -Wextra -Werror
LDFLAGS		=	-lcriterion

SRC			=	$(wildcard *.c)
OBJ			=	$(SRC:.c=.o)

TARGET		=	int_list_tests

all			:	$(TARGET)
			./$(TARGET)
			gcovr -r . --branches --exclude *_tests.c --html --html-details -o $(TARGET).html

$(TARGET)	:	$(OBJ)
			@ $(CC) -o $@ $^ $(LDFLAGS)

clean		:
			$(RM) *~
			$(RM) #*#
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) *.html
			$(RM) $(TARGET)
			$(RM) $(OBJ:.o=.gcda)
			$(RM) $(OBJ:.o=.gcno)

re			:	fclean all