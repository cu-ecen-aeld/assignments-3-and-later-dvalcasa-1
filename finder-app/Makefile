CC=$(CROSS_COMPILE)gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=writer

all: $(EXEC)

writer: writer.o
	$(CC) -o $@ $< $(LDFLAGS)
	
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -rf *.o
