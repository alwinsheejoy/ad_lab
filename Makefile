SOURCES=$(wildcard *.c)

EXECS=$(SOURCES:%.c=%)

all: $(EXECS)

run: $(EXECS)
	./$(EXECS)

%: %.c
	gcc $< -o $@

clean:
	rm $(EXECS)
	rm *.out
	rm *.txt

random:
	gcc rangen/aio.c -o aio
	./aio

randrun:
	./a.out < ascending.txt
	./a.out < random.txt
	./a.out < descending.txt
