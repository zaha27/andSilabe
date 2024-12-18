CC = clang
CFLAGS = -Wall

OBJS = functii.o main.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

functii.o: functii.c header.h
	$(CC) -c functii.c

main.o: main.c header.h
	$(CC) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)
