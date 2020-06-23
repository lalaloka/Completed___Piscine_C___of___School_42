/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* - Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */

/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


 Reproduce the behavior of the function strcmp (man strcmp).
 Воспроизвести поведение функции strcmp (man strcmp).


 ******************************************************************************


 ft_strcmp – сравнение строк.


 Аргументы:

 s1, s2 – указатели на сравниваемые строки.

 Возвращаемое значение:

 0 – если сравниваемее строки идентичны.

 Положительное число – если строки отличаются и код первого отличающегося символа в
 строке s1 больше кода символа на той же позиции в строке s2.

 Отрицательное число – если строки отличаются и код первого отличающегося символа в
 строке s1 меньше кода символа на той же позиции в строке s2.

 Описание:

 Функция побайтно сравнивает коды символов двух строк, на которые указывают аргументы
 функции. Сравнение продолжается до встречи первого отличающегося символа или пока не
 будут проверены все символы строк.

 Если все символы строк совпали, то возвращается 0.

 Если при сравнении встретились отличающиеся символы, то сравнение прекращается и
 возвращается отрицательное или положительное число, в зависимости от того больше
 или меньше код символа строки s1, кода символа строки s2 на той же позиции
 (см. возвращаемые значения).

 Если строки разной длины, возвращается положительное число, если строка s1
длиннее строки s2, или отрицательное число, если строка s2 длиннее строки s1.


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++)
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
	return (*--s1 - *--s2);
}


/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
