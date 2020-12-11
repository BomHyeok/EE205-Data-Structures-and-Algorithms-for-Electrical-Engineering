CC = g++
CFLAGS = -W -Wall
TARGET = main
OBJECTS = main.o student.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm *.o
