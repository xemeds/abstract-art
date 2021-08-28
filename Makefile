CC=gcc

TARGET=abstract
IMAGE=image.png
COMMAND=abstract.c image.c -o $(TARGET)

all:
	$(CC) $(COMMAND)

clean:
	rm $(TARGET)
	rm $(IMAGE)
