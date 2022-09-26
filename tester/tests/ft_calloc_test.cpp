extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_calloc\t: ")

	void *p = ft_calloc(2, 2);
	if (!p)
		return (2);
	bool c = false;
	c = !memcmp(p, (void *)((char []){0, 0, 0, 0}), 4);
	/* 1 */ check(c);
	/* 2 */ mcheck(p, 4); free(p); showLeaks();
	/* 3 */ check(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL);
	write(1, "\n", 1);
	return (0);
}
