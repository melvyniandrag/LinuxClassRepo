CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lncurses

TARGET = finalexam 
SRC = finalexam.c

all: $(TARGET)

$(TARGET): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm $(TARGET)
