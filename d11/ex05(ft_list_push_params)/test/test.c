/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */



#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, ((((((&c)))))), 1);
}

/* ************************************************************************** */

void		ft_putstr(char *str)		/* Функция печати строки */
{
	while (*str)
		write(1, str++, 1);
}

/* ************************************************************************** */

void		ft_put_list(t_list *list)	/* Функция печати связанных между собой экземпляров структуры типа 't_list' */
{
	while (list)
	{
		ft_putstr((char *)list->data);
		list = list->next;
	}
}

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адресс из указателя data
										 * в первый элемент экземпляра структуры, нулевой адрес во второй элемент экземпляра структуры. И в 
										 * конце функция его возвращает адрес созданого экземпляра структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адресс выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адресс принятого
										 * в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}

/* ************************************************************************** */

t_list	*ft_list_last(t_list *begin_list)/* Функция находит последний экземпляр структуры среди связанных между собой последовательно экземпляров 
										 * структур начиная с адреса текущего экземпляра полученого в аргументах */
{
	if (begin_list)						/* Проверяем содержимое указателя если там есть адресс то запускаем код ниже */
	{
		while (begin_list->next)		/* Запускаем цикл который пройдется вглубь цепочки связанных между собой экземпляров структуры типа 't_list' 
										 * пока не дойдет до того экземпляра структуры, который окажется последним в этой цепочке связанных собой 
										 * экземпляров структур. */
			begin_list = begin_list->next;

	/* Если мы дошли до сюда, значит цикл закончился и мы достигли последнего экемпляра структуры */
		return (begin_list);			/* Завершаем функцию и возвращаем адресс посленего экземпляра структуры сохраненного в указателе 'begin_list' */
	}
	return ((void *)0);					/* Если содержимое указателя не хранит адрес экземпляра  структуры завершае функцию и возвращаем нулевой адресс */
}

/* ************************************************************************** */

t_list	*ft_list_push_params(int ac, char **av) /* Функция разбирает массив строк и заполняет каждой из этих строк экземпляры структуры типа 't_list' соединяя их 
										 * между собой в цепь связанных между собой структур в порядке убывания. Т.Е. соединяя их так чтобы экземпляры структур,
										 * которые были созданы первыми и хранят первые строки массива строк были в конце, а те экземпляры которые были 
										 * созданы последними и хранят последние строки массива строк, оказались первыми в цепи связанных между собой 
										 * экземпляров структуры типа 't_list' */
{
	t_list	*tmp;						/* Обьявим указатель на экземпляр структуры типа t_list */
	t_list	*list;						/* Обьявим указатель на экземпляр структуры типа t_list */
	int		i;							/* Обьявим целочисленную переменную для счетчика */

	i = 1;								/* Инициализируем счетчик нулем */
	tmp = ft_create_elem(av[0]);		/* Создадим первый экземпляр структуры, записав в одном из его элементов адресс нулевой строки массива строк 'av' */
	while (i < ac)						/* Запускаем цикл который создаст цепь из связанных между собо экземпляров структур, каждый из которых мы по
										 * очереди заполним строкой из массива строк 'av', до тех пор пока мы не дойдем до конца массива строк */ 
	{
		list = ft_create_elem(av[i]);	/* Создадим следующий экземпляр структуры, записав в одном из его элементов адресс текущей строки массива строк 'av' */
		list->next = tmp;				/* В элементе 'next' созданной нами только что структуры мы сохраним адресс предыдущей структуры */
		tmp = list;						/* А адрес текущей структуры мы сохраним во временном указателе чтобы потом сохранить его в элементе 'next' другой 
										 * структуры чтобы выстроить расположение последующих экземпляров структуры таким образом чтобы экземпляры структур,
										 * которые были созданы первыми и хранят первые строки массива строк были в конце, а те экземпляры которые были 
										 * созданы последними и хранят последние строки массива строк, оказались первыми в цепи связанных между собой 
										 * экземпляров структуры типа 't_list' хранящий строки массива строк 'av' */
		i++;							/* Увеличиаем счетчик для перехода к след строке массива строк 'av' и инициализации с помощью него нового экземпляра
										 * структуры. И так до тех пор пока строки масива строк 'av' не закончатся */
	}
	return (list);						/* Завершаем функцию и возвращаем адресс первого экземпляра структуры цепи связанных между собой структур типа 't_list' */
}


/*

Команда для компиляции кода и одновременного запуска программы с аргументами:

gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out 'hello ' 'my ' 'friend '

*/
int			main(int argc, char *argv[])
{
	if (argc > 1)						/* Если кроме имени программы в аргументах есть другие строки то запускаем код ниже */
	{
		ft_put_list(ft_list_push_params(argc, argv)); /* Запустим функцию которая найдет последний экземпляр структуры среди связанных между собой последовательно
													   * экземпляров структур начиная с адреса текущего экземпляра */
		ft_putchar('\n');				/* Печатаем символ переноса строки для кореектного отображения вывода */
	}
	return (0);							/* Завершаем функцию и возвращаем ноль */
}