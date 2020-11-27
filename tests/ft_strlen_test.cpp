extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"

int main(void)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LGRAY << "ft_strlen : ";
	if (ft_strlen("123") != 3 || ft_strlen("") != 0)
		cout << FG_RED << "KO";
	else
		cout << FG_GREEN << "OK";
	cout << ENDL;
	return (0);
}