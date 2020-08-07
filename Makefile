all: lookforzero

.PHONY: clean

clean:
	rm lookforzero

lookforzero: lookforzero.c
	gcc -O2 -o lookforzero lookforzero.c

