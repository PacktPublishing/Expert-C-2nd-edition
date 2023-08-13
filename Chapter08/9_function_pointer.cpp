#include <stdio.h>

typedef void (*PF)(int);
void foo(int arg)
{
	// do something with arg
	printf("Value of arg in foo: %d\n", arg);
}

int bar(int arg, PF f)
{
	f(arg);
	return arg;
}

int main()
{
	bar(42, foo);
	return 0;
}
