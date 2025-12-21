/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:41:30 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/21 13:03:29 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *str)
{
	int		i;
	int		ii;
	char	temp;

	i = 0;
	ii = ft_strlen(str) - 1;
	while (i <= ii)
	{
		temp = str[i];
		str[i] = str[ii];
		str[ii] = temp;
		i++;
		ii--;
	}
}

static char	*ft_utoa(unsigned int n)
{
	char			*converted;
	int				counter;
	unsigned int	i;

	i = n;
	counter = 0;
	while (i != 0)
	{
		counter++;
		i /= 10;
	}
	if (counter == 0)
		return (ft_strdup("0"));
	converted = ft_calloc(counter + 1, sizeof(char));
	while (n != 0)
	{
		converted[i++] = (n % 10) + 48;
		n /= 10;
	}
	ft_swap(converted);
	return (converted);
}

static char	*ft_hex(unsigned long int n, char c)
{
	char		converted[20];
	char		*base;
	int			i;

	i = 0;
	base = "0123456789abcdef";
	ft_memset(converted, 0, 19);
	if (n == 0 && c == 'p')
		return (ft_strdup("(nil)"));
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0 && c != 'p')
	{
		converted[i++] = base[n % 16] - ((c == 'X' && base[n % 16] > 96) * 32);
		n /= 16;
	}
	while (n != 0 && c == 'p')
	{
		converted[i++] = base[n % 16];
		n /= 16;
	}
	ft_swap(converted);
	if (c == 'p')
		return (ft_strjoin("0x", converted));
	return (ft_strdup(converted));
}

static void	initializer(const char *str, int i, va_list ap, int *counter)
{
	char	*temp;

	temp = NULL;
	if (str[i] == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (str[i] == 's')
		temp = ft_strjoin(va_arg(ap, char *), "");
	else if (str[i] == 'p')
		temp = ft_hex(va_arg(ap, unsigned long int), str[i]);
	else if (str[i] == 'x' || str[i] == 'X')
		temp = ft_hex(va_arg(ap, unsigned int), str[i]);
	else if (str[i] == 'd' || str[i] == 'i')
		temp = ft_itoa(va_arg(ap, int));
	else if (str[i] == 'u')
		temp = ft_utoa(va_arg(ap, unsigned int));
	else if (str[i] == '%')
		ft_putchar_fd('%', 1);
	if (!temp && str[i] == 's')
		temp = ft_strdup("(null)");
	if (temp)
	{
		ft_putstr_fd(temp, 1);
		*counter += ft_strlen(temp) - 1;
		free(temp);
	}
}

int	ft_printf(const	char *str, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (!str || write(1, "", 0) == -1)
		return (-1);
	va_start(ap, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
			initializer(str, ++i, ap, &counter);
		else
			write(1, &str[i], 1);
		counter++;
		i++;
	}
	va_end(ap);
	return (counter);
}

// int	main(void)
// {
// 	void	*d1;
// 	char	c;
// 	char	*s;
// 	unsigned int		d;
// 	unsigned int u;

// 	c = 0;
// 	u = UINT_MAX;
// 	s = "Hello";
// 	d1 = "HelloWorld";
// 	d = 48659;
// 	printf("-----------------------WELCOME-----------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL DECIMAL (d) = %d\n", d));
// 	printf("%d ", ft_printf("HOMEMADE DECIMAL (d) = %d\n", d));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL INTEGER (i) = %i\n", d));
// 	printf("%d ", ft_printf("HOMEMADE INTEGER (i) = %i\n", d));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL STRING (s) = %s\n", s));
// 	printf("%d ", ft_printf("HOMEMADE STRING (s) = %s\n", s));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL CHARACTER (c) = %c\n", c));
// 	printf("%d ", ft_printf("HOMEMADE CHARACTER (c) = %c\n", c));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL HEX ADDRESS LOW (x) = %x\n", d));
// 	printf("%d ", ft_printf("HOMEMADE HEX ADDRESS LOW (x) = %x\n", d));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL POINTER TO ADDRESS (p) = %p\n", d1));
// 	printf("%d ", ft_printf("HOMEMADE POINTER TO ADDRESS (p) = %p\n", d1));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL HEX ADDRESS UP (X) = %X\n", d));
// 	printf("%d ", ft_printf("HOMEMADE HEX ADDRESS UP (X) = %X\n", d));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL PERCENT (percent) = %%\n"));
// 	printf("%d ", ft_printf("HOMEMADE PERCENT (percent) = %%\n"));
// 	printf("-------------------\n\n");
// 	printf("\t%d | ", printf("ORIGINAL UNSIGNED (u) = %u\n", u));
// 	printf("%d ", ft_printf("HOMEMADE UNSIGNED (u) = %u\n", u));
// 	printf("-------------------\n\n");
// 	return (0);
// }
