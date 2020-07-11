/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** *
 *
 * 
 *	• Создайте функцию "ft_list_push_params", которая создает новый список,
 *	включающий аргументы командной строки.
 *	
 *
 *	• Первый аргумент должен быть в конце списка.
 *	
 * 
 *	• Возвращается адрес первой ссылки в списке.
 *
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *							t_list	*ft_list_push_params(int ac, char **av)
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*tmp;
	t_list	*list;
	int		i;

	i = 1;
	list = ft_create_elem(av[0]);
	tmp = list;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = tmp;
		tmp = list;
		i++;
	}
	return (list);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *current;
	t_list *last;
	int i;

	i = 0;
	last = 0;
	while (++i < ac)
	{
		current = ft_create_elem(av[i]);
		current->next = last;
		last = current;
	}
	return (current);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*tmp;

	i = 0;
	tmp = (void *)0;
	list = (void *)0;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = tmp;
		tmp = list;
		i++;
	}
	return (list);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_list.h"

t_list	*add_link(t_list *list, void *data)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = data;
		tmp->next = list;
	}
	return (tmp);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 2;
	if (ac == 1)
		return ((void *)0);
	list = ft_create_elem(av[1]);
	while (i < ac)
	{
		list = add_link(list, av[i]);
		i++;
	}
	return (list);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
