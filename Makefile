LDFLAGS=-lOpenCL

all: example

example: example.c
	$(CC) $+ $(LDFLAGS) -o $@
