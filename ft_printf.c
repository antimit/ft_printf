#include "ft_printf.h"

#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += print_format(*(++format), ap); // This
		}
		else
			count += write(STDOUT_FILENO, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	// int result = 0;

// 	// result = ft_printf("%p\n", (void *)&result);
// 	// printf("%p", (void *)&result);
// 	// printf("%i",052);

// 	// ft_printf("%i",0x2A);
// 	// ft_printf("%d",0x2A);
// 	// printf("%u\n", -100);
// 	// ft_printf("%u", 100);
// 	// ft_printf("%x",10);
// 	// ft_printf("The discount is 20%% off!\n");
// 	ft_printf("%x", 100);
// 	return (0);
// }