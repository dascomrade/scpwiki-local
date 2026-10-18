
NAME = "The SCP Wiki"


COMPILER = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`



${NAME}: GtkMAINWINDOW.c
	${COMPILER} ${CFLAGS} -o ${NAME} GtkMAINWINDOW.c ${LIBS}
	${COMPILER} ${CFLAGS} -o template templatepage.c ${LIBS}
