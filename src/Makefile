OBJS = tokenizer.o history.o main.o

CFLAGS = -g -O3

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)

clean:
	rm -f *.o tokenize

run: tokenize
	./tokenize
