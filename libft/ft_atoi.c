#include <ctype.h>

int	ft_atoi(const char *str)
{
  int i;
  int sign;
  int num;

  i = 0;
  sign = 1;
  num = 0;//запихнуть эти табы в цикл while
  if (*str == '\t' || *str == '\n' || *str == ' ' || *str == '+'\
      || *str == ' ')
    str++;
  if (*str == '-')
    {
      sign = -1;
      str++;
    }
  while (*str)
    {
      if (*str == '\t' || *str == '\n' || *str == ' ' || *str == '+'\
	  || *str == ' ')
	str++;
      if (*str == '-')
	{
	  sign = -1;
	  str++;
	}
      num = 10 * num + (*str - '0'); 
      str++;
    }
  num *= sign;
  return (num);
}
