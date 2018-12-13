#include "libft.h"

char  *ft_strmap(char const *s, char (*f)(char))
{
  int i;
  int len;
  char b;
  i = 0;
  b = 'q';
  char *str = "fgrfg";

  len = ft_strlen(s);
  while (i < len)
  {
      (*f)(b);
      i++;
      s++;
  }
  return (str);
}
