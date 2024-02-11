CC=clang
CFLAG=-ggdb 
LINK=/usr/local/include
LIBS=/usr/local/lib

main:main.c
	${CC} -I${LINK} -o main main.c -L${LIBS} -lraylib -lm

run: main
	${CC} -I${LINK} -o main main.c -L${LIBS} -lraylib -lm && ./main
