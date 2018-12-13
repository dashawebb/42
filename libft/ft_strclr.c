#include "libft.h"

void  ft_strclr(char *s)
{
  int i;
  int len;

  i = 0;
  len = ft_strlen(s);
  if (s == NULL)
    return ;
  while (i < len)
  {
    s[i] = '\0';
    i++;
  }
}
