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

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (!src)
		return (dest);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	print_hex_digit(unsigned char digit)
{
	int		count;
	char	hex_chars[16];

	ft_strcpy(hex_chars, "0123456789abcdef");
	count = write(1, &hex_chars[digit], 1);
	return (count);
}

static int	print_hex_address(unsigned long address)
{
	int				count;
	int				leading_zero;
	int				i;
	unsigned char	digit;

	count = 0;
	leading_zero = 1;
	i = (sizeof(address) * 2) - 1;
	while (i >= 0)
	{
		digit = (address >> (i * 4)) & 0x0F;
		if (digit != 0)
			leading_zero = 0;
		if (!leading_zero)
			count += print_hex_digit(digit);
		i--;
	}
	if (leading_zero)
		count += write(1, "0", 1);
	return (count);
}

int	print_address(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	address = (unsigned long)ptr;
	count = write(1, "0x", 2);
	count += print_hex_address(address);
	return (count);
}

// int	print_address(void *ptr)
// {
// 	int				count;
// 	unsigned long	address;
// 	int				leading_zero;
// 	char			prefix[] = "0x";
// 	int				i;
// 	unsigned char	digit;

// 	if (ptr == NULL)
// 		return (write(1, "(nill)", 5));
// 	leading_zero = 1;
// 	address = (unsigned long)ptr;
// 	count = write(1, prefix, 2);
// 	i = (sizeof(address) * 2) - 1;
// 	while (i >= 0)
// 	{
// 		digit = (address >> (i * 4)) & 0x0F;
// 		if (digit != 0)
// 			leading_zero = 0;
// 		if (!leading_zero)
// 			count += print_hex_digit(digit);
// 		i--;
// 	}
// 	if (leading_zero)
// 		write(1, "0", 1);
// 	return (count);
// }
