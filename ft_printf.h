#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	print_hexadecimal(char character, unsigned int num);
int	print_hex_digit(unsigned char digit);
int	print_address(void *ptr);
int	print_char(int c);
int	print_str(char *str);
int	print_nbr(int num);
int	unsigned_print_nbr(unsigned int num);
int	print_format(char character, va_list ap);
int	ft_printf(const char *format, ...);

#endif