#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	dest = (void *)src;
	((unsigned char*)dest)[0] = n;
	return (0);
}
