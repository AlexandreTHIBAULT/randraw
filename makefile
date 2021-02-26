all: randraw

randraw: randraw.c
	gcc randraw.c -o randraw

clean:
	rm randraw