COMP = gcc
TARGET = main
CFLAGS = -ansi -pedantic -Wall -Werror -I./include/
CK = -c
LDK = -o
FILES = main.c bmp_reading.c bmp_writing.c bmp_rotate.c
OFILES = main.o bmp_reading.o bmp_writing.o bmp_rotate.o

main: main.c
	$(COMP) $(CK) $(FILES)
	$(COMP) $(LDK) $(TARGET) $(CFLAGS) $(OFILES) -lm

clean:
	rm -f $(TARGET) *.o
