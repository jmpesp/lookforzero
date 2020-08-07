all: test

.PHONY: clean test test1 test2

clean:
	rm lookforzero

lookforzero: lookforzero.c
	gcc -O2 -o lookforzero lookforzero.c

test: test1 test2
	@echo "Tests passed"

test1: lookforzero
	@./lookforzero ftest1

test2: lookforzero
	@./lookforzero ftest2 2>/dev/null && exit 1 || { exit 0; }

