/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:09:35 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putstr(char *str)		/* функция печати строки */
{
	while (*str)
		ft_putchar(*str++);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)	/* Принимаем адреса строк в s1  и адреса s2 */
{
	int i;									/* обьявляем переменную для счетчика */

	i = 0;									/* инициализируем счетчик для старта с нулевой позиции */
	while(src[i])							/* цикл будет копировать второй массив в первый пока не дойдет до '\0' */
	{
		dest[i] = src[i];					/* копируем символ из нулевой позиции первой строки в нулевую 
											 * позицию второй строки и дальше по мере увеличения переменной i */
		i++;								/* увеличиваем счетчик для перехода к след ячейке массива */
	}
	dest[i] = src[i];						/* если дошли до сюда значит содержимое массива скопировано и в следующей 
											 * ячейке массива нужно поставить завершающий символ */
	return (dest);							/* Завершаем функцию и возвращаем адресс строки в которую мы копировали данные */
}

int 	main(void)
{
	char	r[] = {"Fuck"};					/* Создадим строку(массив символов) которую будем копировать */
	char	t[7];							/* Создадим пустую строку(массив символо) длинной в 7 ячеек для копирования в нее строки r[] */
	char	*p;								/* Обьявим указатель для хранения адреса строки(массива символов), который будет возвращен в нее 
											 * функцией после копирования */


	p = ft_strcpy(t, r);					/* Вызываем функцию отправляя в нее адреса итоговой строки, исходной строки */

	ft_putstr(p);							/* Напечатаем строку(массив символов), адресс которой мы получили из функции и сохранили в указателе */
	return (0);								/* Возвращаем 0 и завершаем программу */
}
