CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -g
TARGET = echo_server
OBJS = echo_server_main.o tcp_server.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

echo_server_main.o: echo_server_main.c tcp_server.h
	$(CC) $(CFLAGS) -c echo_server_main.c

tcp_server.o: tcp_server.c tcp_server.h
	$(CC) $(CFLAGS) -c tcp_server.c

clean:
	rm -f *.o $(TARGET)
