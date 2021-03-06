#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    where_am_i.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#              #
#    Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#																			   #
#	• Напишите файл where_am_i.sh, который будет отображать на стандартном	   #
#	выходе ip или ip (в формате IPV4) аппарата в сети. Вы будете отображать    #
#	один IP в каждой строке.												   #
#																			   #
#	• В случае, если IP не найден, вы должны будете показать, что я потерян!   #
#																			   #
# **************************************************************************** #


var=$(ifconfig | grep "inet " | cut -d ' ' -f2)
if test -z "$var"
then
	echo "Je suis perdu!"
else
	echo $var | tr ' ' '\n'
fi



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #



CMD=`ifconfig | grep "inet " | cut -d' ' -f2`
NUM=`ifconfig | grep "inet " | cut -d' ' -f2 | wc -l | tr -d ' '`

if [ "$NUM" -eq "2" ]; then
	echo "Je suis perdu!"
else
	echo "$CMD"
fi




# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #



out=$(ifconfig | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}')

if [[ $out ]]; then
	echo $out
else
	echo "Je suis perdu!"
fi



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #

#!/bin/sh
RET=`ifconfig | grep -o -E '([0-9]{1,3}\.){3}[0-9]{1,3}' | grep -v -e '^0.' | grep -v -e '^127.' | grep -v -e '255$'`
if [[ -z $RET ]]
then
	echo "Je suis perdu!"
else
	echo $RET
fi


# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #



#!/bin/bash

ip_list=$(ifconfig | grep "inet " | cut -d' ' -f2)

if (test -z "$ip_list")
  then
    echo "Je suis perdu!"
  else
    echo $ip_list | (tr ' ' '\n')
fi



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #
