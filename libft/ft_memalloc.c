#include <stdlib.h>
#include "libft.h"

void  *ft_memalloc(size_t size)
{
  void *memory;
  if (!(memory = (void *)malloc(sizeof(void) * size)))
    return (NULL);
  ft_bzero(memory, size);
  return (memory);
}
