SRCS = server.c client.c
OBJS = ${SRCS:.c=.o}
bSRCS = server_bonus.c client_bonus.c
bOBJS = ${bSRCS:.c=.o}
sNAME = server
cNAME = client
bsNAME = server_bonus
bcNAME = client_bonus
INC = minitalk.h 
LIB = ft_printf/libftprintf.a
CC = cc
CFLAGS =  -Wall -Wextra -Werror
RM = rm -vf
MK =  make --directory=ft_printf/


all: $(sNAME) $(cNAME)
bonus: $(bsNAME) $(bcNAME)
$(sNAME): $(sNAME).o $(LIB)
	$(CC) $(CFLAGS) $(sNAME).o  $(LIB) -o $(sNAME) 
$(cNAME): $(cNAME).o $(LIB)
	$(CC) $(CFLAGS) $(cNAME).o $(LIB) -o $(cNAME) 
$(bsNAME): $(bsNAME).o $(LIB)
	$(CC) $(CFLAGS) $(bsNAME).o $(LIB) -o $(bsNAME) 
$(bcNAME): $(bcNAME).o $(LIB)
	$(CC) $(CFLAGS) $(bcNAME).o $(LIB) -o $(bcNAME) 
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIB):
	$(MK)
clean:
	$(RM) $(OBJS) $(bOBJS) 
	$(MK) clean
fclean:
	$(RM) $(sNAME) $(cNAME) $(OBJS) $(bOBJS) $(bsNAME) $(bcNAME)
	$(MK) fclean
re: fclean all
.PHONY: fclean all re clean
