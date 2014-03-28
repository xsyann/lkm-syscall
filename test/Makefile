##
## Makefile for lkm-syscall
## 
## Made by xsyann
## Contact <contact@xsyann.com>
## 
## Started on  Wed Mar 26 13:48:49 2014 xsyann
## Last update Fri Mar 28 15:01:37 2014 xsyann
##

TARGET 	= test
SRC	= test.c
OBJ	= $(SRC:.c=.o)
CC	= gcc
CFLAGS += -W -Wall
RM	= rm -vf

$(TARGET) : $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

all	: $(TARGET)

clean	:
	$(RM) $(OBJ) *~ \#*#

fclean	: clean
	$(RM) $(TARGET)

re	: fclean all clean

.PHONY: clean fclean re