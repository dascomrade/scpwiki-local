
NAME = "The SCP Wiki"


COMPILER = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`



${NAME}: MainPage.c
	${COMPILER} ${CFLAGS} -o ${NAME} MainPage.c ${LIBS}
	${COMPILER} ${CFLAGS} -o template templatepage.c ${LIBS}
