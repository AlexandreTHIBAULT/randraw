all: randraw

randraw: randraw.c
	gcc randraw -o randraw.c

clean:
	rm randraw