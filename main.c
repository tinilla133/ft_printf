/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:49:00 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/11 12:46:42 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <semaphore.h>
#include "ft_printf.h"

void	test1(int *printf_count, int *ftprintf_count);
void	test2();

int	main(void)
{
	int		nbr;
	int		printf_count;
	int		ftprintf_count;

	printf_count = 0;
	ftprintf_count = 0;
	nbr = 42;
	printf("\nPuntero\n");
	ftprintf_count += ft_printf("%p", &nbr);
	printf("\n");
	printf_count += printf("%p", &nbr);
	printf("\n");
	printf("\nPuntero NULL\n");
	ftprintf_count += ft_printf("%p", NULL);
	printf("\n");
	printf_count += printf("%p", NULL);
	printf("\n");
	printf("\nft_printf(\"\\001\\002\\007\\v\\010\\f\\r\\n\")\n");
	ft_printf("\001\002\007\v\010\f\r\n");
	test1(&printf_count, &ftprintf_count);
	printf("\n");
	printf("Numero de caracteres impresos por ft_printf() %d", ftprintf_count);
	printf("\n");
	printf("Numero de caracteres impresos por printf() %d", printf_count);
	printf("\n");
	test2();
}

void	test1(int *printf_count, int *ftprintf_count)
{
	printf("\nAlgunas pruebas que hacen los test de francinette:\n");
	*ftprintf_count += ft_printf(" %%");
	printf("\n");
	*printf_count += printf(" %%");
	printf("\n");
	*ftprintf_count += ft_printf("%%c");
	printf("\n");
	*printf_count += printf("%%c");
	printf("\n");
	*ftprintf_count += ft_printf("%%%%%%");
	printf("\n");
	*printf_count += printf("%%%%%%");
	printf("\n");
	*ftprintf_count += ft_printf("%%%c", 'x');
	printf("\n");
	*printf_count += printf("%%%c", 'x');
	printf("\n");
	*ftprintf_count += ft_printf("%c", 'x');
	printf("\n");
	*printf_count += printf("%c", 'x');
	printf("\n");
	*ftprintf_count += ft_printf("  %X %X %X %X %X %X %X", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	*printf_count += printf("  %X %X %X %X %X %X %X", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	printf("\nOtras pruebas:\n");
	*ftprintf_count += ft_printf("Cero en hexa minúsculas %x", 0);
	printf("\n");
	*printf_count += printf("Cero en hexa minúsculas %x", 0);
	printf("\n");
	*ftprintf_count += ft_printf("NULL %s NULL", NULL);
	printf("\n");
	*printf_count += printf("NULL %s NULL", NULL);
	printf("\n");
}
void	test2()
{
	int	error;

	error = ft_printf("\001\002\007\v\010\f\r\n");
	printf("Caracteres impresos ====> %d\n", error);
	error = printf("\001\002\007\v\010\f\r\n");
	printf("Caracteres impresos ====> %d\n", error);
	printf("\nHOLA\n");
	error = ft_printf("o,9?%c;UH>Sj%c2h:jYD%s\rqd;?#GR\f%X\r!{XC%sXlS\nu%uc/\m\nu%i9", 320217853, -450119245, "|^`U[Q~>HW0n78s pBh\v\r8J?\nlmu\vtJ@3Eu|r11W]]~hS$B\fOCY[5", 56438883, "09}", 967802697, -140519593);
	printf("\nCaracteres impresos ====> %d\n", error);
	error = printf("o,9?%c;UH>Sj%c2h:jYD%s\rqd;?#GR\f%X\r!{XC%sXlS\nu%uc/\m\nu%i9", 320217853, -450119245, "|^`U[Q~>HW0n78s pBh\v\r8J?\nlmu\vtJ@3Eu|r11W]]~hS$B\fOCY[5", 56438883, "09}", 967802697, -140519593);
	printf("\nCaracteres impresos ====> %d\n", error);
	error = ft_printf("(&q&E1c%c%d0:q9:,Mg%i", 1544804724, 671876632, 1034788635);
	printf("\nCaracteres impresos ====> %d\n", error);
	error = printf("(&q&E1c%c%d0:q9:,Mg%i", 1544804724, 671876632, 1034788635);
	printf("\nCaracteres impresos ====> %d\n", error);
}