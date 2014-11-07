calc.so : lcalc.c
	gcc -g -o $@ --shared $^  -I/usr/local/include -L/usr/local/bin -llua
