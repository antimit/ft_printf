#include "ft_printf.h"


int	print_hexadecimal(char character, unsigned int num)
{
	char	*x;
	char	*X;
	char	c;
	int		count;

	x = "0123456789abcdef";
	X = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		count += print_hexadecimal(character, num / 16);
	}
	if (character == 'x')
		c = x[num % 16];
	else
		c = X[num % 16];
	count += write(1, &c, 1);
	return (count);
}

int	print_hex_digit(unsigned char digit)
{
	int		count;
	char	hex_chars[] = "0123456789abcdef";

	count = write(1, &hex_chars[digit], 1);
	return (count);
}
int	print_address(void *ptr)
{
	int				count;
	unsigned long	address;
	int				leading_zero;
	char			prefix[] = "0x";
	int				i;
	unsigned char	digit;

	leading_zero = 1;
	address = (unsigned long)ptr;
	count = write(1, prefix, 2);
	i = (sizeof(address) * 2) - 1;
	while (i >= 0)
	{
		digit = (address >> (i * 4)) & 0x0F;
		if (digit != 0)
		{
			leading_zero = 0;
		}
		if (!leading_zero)
			count += print_hex_digit(digit);
		i--;
	}
	if (leading_zero)
		write(1, "0", 1);
	return (count);
}
