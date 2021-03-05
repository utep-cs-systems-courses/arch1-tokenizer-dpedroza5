#define variable $(OBJS) to list of object files
OBJS= tokenizer.o uimain.o

CFLAGS=-g -O3 #-g for debug, O3 for optimization

# first target
all: token

#prerequisites
tokenizer.o:tokenizer.h tokenizer.c

token: $(OBJS)
	cc -o token $(OBJS) $(CFLAGS)

#delete all files from compilation and token
clean:
	rm -f *.o *~ *.# token

run:token
	./token
