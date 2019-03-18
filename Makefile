all:
	gcc cat.c -o cat
	clang -g -shared -fPIC hijack.c -o hijack.so

