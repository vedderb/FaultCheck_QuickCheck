CC=gcc
AR=ar
RM = rm -f

vpath %.c src

# C-flags
CFLAGS  = -g -O2 -Wall -fPIC -coverage
CFLAGS += -ffreestanding -nostdlib

# Includes
CFLAGS += -Iinc -I$(FAULTPATH)

# Libraries
CFLAGS += -L$(FAULTPATH)

# Sources
SRCS = Crc.c E2E.c E2E_P01.c E2E_P02.c

OBJS = $(SRCS:.c=.o)
LIBNAME = libautosare2e.a

all: $(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBNAME): $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	${RM} $(OBJS) $(LIBNAME)
	${RM} *.gcov *.gcda *.gcno
	
